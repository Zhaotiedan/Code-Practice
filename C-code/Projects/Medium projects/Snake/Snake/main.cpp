#define _CRT_SECURE_NO_WARNINGS 1

#include <easyx.h>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <cmath>
#pragma comment( lib, "MSIMG32.LIB")
////////// 窗口大小 //////////
const short ScreenWidth = 640;
const short ScreenHeight = 480;
////////// 全局变量 //////////
long ret = 0;
MOUSEMSG msg;
const short gap = 20;
const short xSide = ScreenWidth / 2 + gap;
const short ySide = ScreenHeight / 2 + gap;
IMAGE* imgMap = new IMAGE(ScreenWidth * 4, ScreenHeight * 4);
const double PI = 3.1415926;
const short nodeSize = 17;
const short nodeGap = 16;
const short stepLen = 4;
const short frame = 4;
const short snakeSpecies = 20;
int killCount = 0;
int mapX = 0;
int mapY = 0;
typedef struct _FOOD
{
	int x;
	int y;
	int r;
	COLORREF c;
}Food;
Food* food;
short nFood = 520;
IMAGE imgFood(nodeSize, nodeSize);
const COLORREF mapMainColor = WHITE;
const COLORREF playerColor0 = RGB(120, 0, 0);
const COLORREF playerColor1 = RGB(200, 0, 0);
const COLORREF playerColor2 = RGB(255, 255, 0);
const COLORREF mapLineColor = RGB(225, 225, 225);
// 透明贴图函数：
// 参数：
//		x, y:	目标贴图位置
//		srcimg: 源 IMAGE 对象指针。NULL 表示默认窗体
//		dstimg: 目标 IMAGE 对象指针。NULL 表示默认窗体
//		transparentcolor: 透明色。srcimg 的该颜色并不会复制到 dstimg 上，从而实现透明贴图
void putTimage(int x, int y, IMAGE* srcimg, IMAGE* dstimg = NULL, UINT transparentcolor = 0)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	// 使用 Windows GDI 函数实现透明位图
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}
////////// 蛇基类 //////////
class SnakeBase
{
public:
	// 构造函数
	SnakeBase()
	{
		Count++;
		isDead = false;
		length = 50 + rand() % 50;
		nNode = length / 5;
		maxNode = 9999;
		imgHead = imgNode = imgTail = nullptr;
		headNode = tailNode = nullptr;
		nodeMsg = nullptr;
	}
	// 析构函数
	virtual ~SnakeBase()
	{
		Count--;
		Node* temp = headNode;
		while (temp != nullptr)
		{
			headNode = headNode->nextNode;
			delete temp;
			temp = headNode;
		}
		delete imgHead, imgNode, imgTail;
		if (nodeMsg != nullptr)
			delete[] nodeMsg;
	}
	// 设置image
	void SetImage(COLORREF headColor, COLORREF nodeColor, COLORREF tailColor)
	{
		imgHead = new IMAGE(nodeSize, nodeSize);
		imgNode = new IMAGE(nodeSize, nodeSize);
		imgTail = new IMAGE(nodeSize, nodeSize);
		SetWorkingImage(imgHead);
		setfillcolor(headColor);
		solidcircle(nodeSize / 2, nodeSize / 2, nodeSize / 2);
		setfillcolor(tailColor);
		solidcircle(nodeSize / 2, nodeSize / 2, 2);
		SetWorkingImage(imgNode);
		setfillcolor(nodeColor);
		solidcircle(nodeSize / 2, nodeSize / 2, nodeSize / 2);
		SetWorkingImage(imgTail);
		setfillcolor(tailColor);
		solidcircle(nodeSize / 2, nodeSize / 2, nodeSize / 2);
		SetWorkingImage();
	}
	// 创建各节点
	void Creat(int headX, int headY)
	{
		headNode = new Node;
		headNode->lastNode = nullptr;
		headNode->nextNode = nullptr;
		headNode->x = headX;
		headNode->y = headY;
		Node* temp = headNode;
		for (int i = 0; i < nNode - 1; i++)
		{
			Node* newNode = new Node;
			newNode->lastNode = temp;
			newNode->x = temp->x;
			newNode->y = temp->y;
			temp->nextNode = newNode;
			temp = newNode;
		}
		temp->nextNode = nullptr;
		tailNode = temp;
		temp = nullptr;
	}
	// 绘制蛇身
	void ShowBody()
	{
		int n = nNode % 2;
		Node* temp = tailNode;
		while (temp != headNode)
		{
			if (temp->x - nodeSize / 2 + mapX >= nodeSize * -1 && temp->x - nodeSize / 2 + mapX <= ScreenWidth
				&& temp->y - nodeSize / 2 + mapY >= nodeSize / -2 && temp->y - nodeSize / 2 + mapY <= ScreenHeight)
				putTimage(temp->x - nodeSize / 2 + mapX, temp->y - nodeSize / 2 + mapY, n % 2 == 0 ? imgNode : imgTail);
			temp = temp->lastNode;
			n++;
		}
		if (temp->x - nodeSize / 2 + mapX >= nodeSize * -1 && temp->x - nodeSize / 2 + mapX <= ScreenWidth
			&& temp->y - nodeSize / 2 + mapY >= nodeSize / -2 && temp->y - nodeSize / 2 + mapY <= ScreenHeight)
			putTimage(temp->x - nodeSize / 2 + mapX, temp->y - nodeSize / 2 + mapY, imgHead);
		temp = nullptr;
	}
	// 刷新数据
	void FlushData(short& n, int& dx, int& dy)
	{
		if (n == frame)
		{
			nodeMsg = new POINT[nNode];
			Node* temp = headNode;
			int i = 0;
			while (temp != nullptr)
			{
				nodeMsg[i].x = temp->x;
				nodeMsg[i].y = temp->y;
				temp = temp->nextNode;
				i++;
			}
		}
		Node* temp = tailNode;
		int i = nNode - 2;
		while (temp != headNode)
		{
			if (n == 1)
			{
				temp->x = nodeMsg[i].x;
				temp->y = nodeMsg[i].y;
			}
			else
			{
				temp->x += int(stepLen * cos(atan2(nodeMsg[i].y - temp->y, nodeMsg[i].x - temp->x)));
				temp->y += int(stepLen * sin(atan2(nodeMsg[i].y - temp->y, nodeMsg[i].x - temp->x)));
			}
			temp = temp->lastNode;
			i--;
		}
		temp = nullptr;
		headNode->x += dx;
		headNode->y += dy;
		if (n == 1)
		{
			delete[] nodeMsg;
			nodeMsg = nullptr;
		}
	}
	// 据长度添加节点
	void SetNode(int ex = 0)
	{
		int n = nNode;
		length += ex;
		n = length / 5 - n;
		if (n > 0)
		{
			while (nNode < maxNode && n != 0)
			{
				n--;
				nNode++;
				Node* newNode = new Node;
				newNode->lastNode = tailNode;
				newNode->nextNode = nullptr;
				newNode->x = tailNode->x;
				newNode->y = tailNode->y;
				tailNode->nextNode = newNode;
				tailNode = newNode;
				newNode = nullptr;
			}
		}
		else if (n < 0)
		{
			while (nNode > 10 && n != 0)
			{
				n++;
				nNode--;
				Node* temp = tailNode;
				tailNode = tailNode->lastNode;
				tailNode->nextNode = nullptr;
				delete temp;
				temp = nullptr;
			}
			if (nNode == 10)
				length = 50;
		}
	}
	// 吃到食物
	bool GetFood(int k, int x, int y)
	{
		int len = nodeGap + 5;
		if (x - headNode->x < len && headNode->x - x < len && y - headNode->y < len && headNode->y - y < len)
		{
			food[k].x = rand() % (imgMap->getwidth() - xSide * 2) + xSide;
			food[k].y = rand() % (imgMap->getheight() - ySide * 2) + ySide;
			food[k].r = rand() % 2 + 3;
			food[k].c = HSVtoRGB(float(rand() % 360), rand() % 1000 / 2000.0f + 0.5f, rand() % 1000 / 2000.0f + 0.5f);
			return true;
		}
		return false;
	}
protected:
	long length;
	int nNode;
	int maxNode;
	IMAGE* imgHead, *imgNode, *imgTail;
	POINT* nodeMsg;
public:
	// 蛇节点
	typedef struct _NODE
	{
		int x;
		int y;
		struct _NODE* lastNode;
		struct _NODE* nextNode;
	}Node;
	bool isDead;
	static int Count;
	Node* headNode, *tailNode;
};
int SnakeBase::Count = 0;
////////// Player 类 //////////
class Player :public SnakeBase
{
public:
	// 构造函数
	Player() :SnakeBase()
	{
		SetImage(playerColor0, playerColor1, playerColor2);
		int headX = rand() % (imgMap->getwidth() - xSide * 2 - nodeSize * 10) + xSide + nodeSize;
		int headY = rand() % (imgMap->getheight() - ySide * 2 - nodeSize * 12) + ySide + nodeSize;
		Creat(headX, headY);
		nt = frame;
	}
	// 是否死亡
	void IsDead()
	{
		if (headNode->x <= xSide || headNode->x >= imgMap->getwidth() - 1 - xSide || headNode->y <= ySide || headNode->y >= imgMap->getheight() - 1 - ySide)
			isDead = true;
		else
		{
			double radian = atan2(headNode->y - headNode->nextNode->y, headNode->x - headNode->nextNode->x);
			int x = ScreenWidth / 2 + int(nodeSize / 2 * cos(radian));
			int y = ScreenHeight / 2 + int(nodeSize / 2 * sin(radian));
			COLORREF c = getpixel(x, y);
			if (!(c == mapLineColor || c == mapMainColor))
				isDead = true;
			else
			{
				for (int i = 1; i < 8; i++)
				{
					x = ScreenWidth / 2 + int(nodeSize / 2 * cos(radian));
					y = ScreenHeight / 2 + int(nodeSize / 2 * sin(radian));
					c = getpixel(x, y);
					if (!(c == mapLineColor || c == mapMainColor))
					{
						isDead = true;
						break;
					}
					x = ScreenWidth / 2 + int(nodeSize / 2 * cos(radian));
					y = ScreenHeight / 2 + int(nodeSize / 2 * sin(radian));
					c = getpixel(x, y);
					if (!(c == mapLineColor || c == mapMainColor))
					{
						isDead = true;
						break;
					}
				}
			}
		}
	}
	// 移动
	void Move(int& ex, int& mapX, int& mapY, short& ddx, short& ddy)
	{
		int dx = int(stepLen * cos(atan2(ddy, ddx)));
		int dy = int(stepLen * sin(atan2(ddy, ddx)));
		mapX -= dx;
		mapY -= dy;
		FlushData(nt, dx, dy);
		for (int k = 0; k < nFood; k++)
			if (GetFood(k, food[k].x, food[k].y))
				ex += food[k].r / 2;
		nt--;
		if (nt <= 0)
		{
			nt = frame;
			while (MouseHit())
				msg = GetMouseMsg();
			ddx = msg.x - ScreenWidth / 2;
			ddy = msg.y - ScreenHeight / 2;
			SetNode(ex);
			ex = 0;
		}
	}
	// 打印成绩
	void Print()
	{
		settextcolor(BLACK);
		settextstyle(20, 0, _T("微软雅黑"));
		TCHAR str[32] = { 0 };
		_stprintf_s(str, _T("长度：%d"), length);
		outtextxy(5, 5, str);
		_stprintf_s(str, _T("节点：%d"), nNode);
		outtextxy(5, 25, str);
		_stprintf_s(str, _T("击杀：%d"), killCount);
		outtextxy(5, 45, str);
	}
public:
	short nt;
};
////////// AI 类 //////////
class AI :public SnakeBase
{
public:
	// 构造函数
	AI(Player* player)
	{
		p = player;
		COLORREF c0 = HSVtoRGB(float(rand() % 360), 1.0f, 0.4f);
		COLORREF c1 = HSVtoRGB(float(rand() % 360), 1.0f, 0.8f);
		COLORREF c2 = HSVtoRGB(float(rand() % 360), 1.0f, 1.0f);
		SetImage(c0, c1, c2);
		int headX = 0;
		int headY = 0;
		do
		{
			headX = rand() % (imgMap->getwidth() - xSide * 2 - nodeSize * 3) + xSide + nodeSize;
			headY = rand() % (imgMap->getheight() - ySide * 2 - nodeSize * 5) + ySide + nodeSize;
		} while (IsInPlayer(headX, headY));
		Creat(headX, headY);
		nt = frame;
		minLine = 3 * frame;
		curLine = minLine + (rand() % 12) * frame;
		ddx = (rand() % ScreenWidth) * (rand() % 1000 < 500 ? 1 : -1);
		ddy = (rand() % ScreenHeight) * (rand() % 1000 < 500 ? 1 : -1);
		dx = int(stepLen * cos(atan2(ddy, ddx)));
		dy = int(stepLen * sin(atan2(ddy, ddx)));
		isFast = false;
		ct = 0;
		exp = 0;
	}
	// 是否死亡
	bool IsDead(int& ex)
	{
		if (headNode->x <= xSide || headNode->x >= imgMap->getwidth() - 1 - xSide || headNode->y <= ySide || headNode->y >= imgMap->getheight() - 1 - ySide)
			return true;
		else
		{
			bool is_dead = IsInPlayer(headNode->x, headNode->y);
			if (is_dead)
			{
				killCount++;
				ex += nNode;
			}
			return is_dead;
		}
	}
	// 位置是否接触 player
	bool IsInPlayer(int headX, int headY)
	{
		Node* temp = p->headNode;
		while (temp != nullptr)
		{
			if (headX - temp->x < nodeSize && temp->x - headX < nodeSize && headY - temp->y < nodeSize && temp->y - headY < nodeSize)
				return true;
			temp = temp->nextNode;
		}
		return false;
	}
	// 移动
	void Move(int& ex)
	{
		if (curLine <= 0)
		{
			double rad = atan2(ddy, ddx);
			isFast = rand() % 1200 < 100 ? true : false;
			curLine = minLine + (rand() % 21) * frame;
			do
			{
				ddx = (rand() % ScreenWidth + 40) * (rand() % 1000 < 500 ? 1 : -1);
				ddy = (rand() % ScreenHeight + 30) * (rand() % 1000 < 500 ? 1 : -1);
			} while (fabs(atan2(ddy, ddx) - rad) > PI / 6 * 5);
			dx = int(stepLen * cos(atan2(ddy, ddx)));
			dy = int(stepLen * sin(atan2(ddy, ddx)));
		}
		FlushData(nt, dx, dy);
		for (int k = 0; k < nFood; k++)
			if (GetFood(k, food[k].x, food[k].y))
				exp += food[k].r / 2;
		nt--;
		curLine--;
		if (nt <= 0)
		{
			nt = frame;
			if (rand() % 1000 < 120)
			{
				SetNode(rand() % 5 + exp);
				exp = 0;
			}
			if (rand() % 1000 < 80)
				curLine = 0;
			if (rand() % 1000 < 900 && curLine > 0)		// 90% 概率避免出界
			{
				int deadX = headNode->x + int((rand() % 50 + nodeGap) * cos(atan2(ddy, ddx)));
				int deadY = headNode->y + int((rand() % 50 + nodeGap) * sin(atan2(ddy, ddx)));
				if (deadX <= xSide || deadX >= imgMap->getwidth() - 1 - xSide)
				{
					ddx *= -1;
					ddy += rand() % 30 + 30;
				}
				if (deadY <= ySide || deadY >= imgMap->getheight() - 1 - ySide)
				{
					ddy *= -1;
					ddx += rand() % 40 + 40;
				}
				dx = int(stepLen * cos(atan2(ddy, ddx)));
				dy = int(stepLen * sin(atan2(ddy, ddx)));
			}
			if (rand() % 1000 < rand() % 400 + 400 && curLine > 0)	// 40%-80%(也可以理解为60%) 概率躲避 player
			{
				int deadX = headNode->x + int((nodeGap + 5) * cos(atan2(ddy, ddx)));
				int deadY = headNode->y + int((nodeGap + 5) * sin(atan2(ddy, ddx)));
				if (IsInPlayer(deadX, deadY))
				{
					ddx = -1 * ddx + rand() % 40 + 40;
					ddy = -1 * ddy + rand() % 30 + 30;
				}
				dx = int(stepLen * cos(atan2(ddy, ddx)));
				dy = int(stepLen * sin(atan2(ddy, ddx)));
			}
		}
		isDead = IsDead(ex);
		if (isDead)
		{
			int n = nNode / 2;
			Node* temp = headNode->nextNode->nextNode;
			while (n--)
			{
				for (int k = 0; k < nFood; k++)
				{
					if (food[k].x < -1 * mapX - nodeSize * 2 || food[k].x > -1 * mapX + nodeSize * 2 + ScreenWidth
						|| food[k].y < -1 * mapY - nodeSize * 2 || food[k].y > -1 * mapY + nodeSize * 2 + ScreenHeight)
					{
						food[k].x = temp->x + (rand() % 5 + 3) * (rand() % 100 < 50 ? 1 : -1);
						food[k].y = temp->y + (rand() % 5 + 3) * (rand() % 100 < 50 ? 1 : -1);
						food[k].r = nodeSize / 2;
						food[k].c = HSVtoRGB(float(rand() % 360), rand() % 1000 / 2000.0f + 0.5f, rand() % 1000 / 2000.0f + 0.5f);
						break;
					}
					else if (k == nFood - 1)
					{
						n = 0;
						break;
					}
				}
				temp = temp->nextNode;
			}
			temp = nullptr;
		}
	}
private:
	short nt;
	int minLine;
	int curLine;
	int ddx, ddy;
	int dx, dy;
	Player* p;
public:
	bool isFast;
	clock_t ct;
	int exp;
};
////////// 游戏主体类 //////////
class Game
{
public:
	// 构造函数
	Game()
	{
		flushTime = 32;
		setbkmode(TRANSPARENT);
		BeginBatchDraw();
		SetWorkingImage(imgMap);
		setlinecolor(mapLineColor);
		setfillcolor(mapMainColor);
		setbkcolor(BROWN);
		cleardevice();
		solidrectangle(xSide, ySide, imgMap->getwidth() - 1 - xSide, imgMap->getheight() - 1 - ySide);
		for (int i = gap + xSide; i < imgMap->getwidth() - xSide; i += gap)
			line(i, ySide, i, imgMap->getheight() - 1 - ySide);
		for (int j = gap + ySide; j < imgMap->getheight() - ySide; j += gap)
			line(xSide, j, imgMap->getwidth() - 1 - xSide, j);
		SetWorkingImage();
		player = new Player;
		mapX = -1 * (player->headNode->x - ScreenWidth / 2);
		mapY = -1 * (player->headNode->y - ScreenHeight / 2);
		ai = new Ai;
		ai->ais = new AI(player);
		Ai* temp = ai;
		for (int i = 1; i < 15; i++)
		{
			temp->next = new Ai;
			temp = temp->next;
			temp->ais = new AI(player);
		}
		temp->next = ai;
		temp = nullptr;
		food = new Food[nFood];
		for (int k = 0; k < nFood; k++)
		{
			food[k].x = rand() % (imgMap->getwidth() - xSide * 2) + xSide;
			food[k].y = rand() % (imgMap->getheight() - ySide * 2) + ySide;
			food[k].r = rand() % 2 + 3;
			food[k].c = HSVtoRGB(float(rand() % 360), rand() % 1000 / 2000.0f + 0.5f, rand() % 1000 / 2000.0f + 0.5f);
		}
		Draw();
		outtextxy((ScreenWidth - textwidth(_T("左键或右键加速"))) / 2, ScreenHeight / 4 * 3 + 25, _T("左键或右键加速"));
		outtextxy((ScreenWidth - textwidth(_T("按任意键继续"))) / 2, ScreenHeight / 4 * 3 + 50, _T("按任意键继续"));
		FlushBatchDraw();
		ret = _getwch();
	}
	// 析构函数
	~Game()
	{
		EndBatchDraw();
		delete imgMap;
		delete player;
		if (ai != nullptr)
		{
			Ai* temp = ai->next;
			while (temp != ai)
			{
				delete temp->ais;
				temp = temp->next;
			}
			delete ai->ais;
			delete ai;
		}
	}
	// 绘制食物
	void DrawFood()
	{
		for (int k = 0; k < nFood; k++)
		{
			if (food[k].x - 9 + mapX >= 0 && food[k].x - 9 + mapX <= ScreenWidth && food[k].y - 9 + mapY >= 0 && food[k].y - 9 + mapY <= ScreenHeight)
			{
				if (food[k].r < 6)
				{
					setfillcolor(food[k].c);
					solidcircle(food[k].x + mapX, food[k].y + mapY, food[k].r);
				}
				else
				{
					SetWorkingImage(&imgFood);
					cleardevice();
					setfillcolor(food[k].c);
					solidcircle(nodeSize / 2, nodeSize / 2, nodeSize / 2);
					setfillcolor(BLACK);
					solidcircle(nodeSize / 2, nodeSize / 2, nodeSize / 5);
					SetWorkingImage();
					putTimage(food[k].x - nodeSize / 2 + mapX, food[k].y - nodeSize / 2 + mapY, &imgFood);
				}
			}
		}
	}
	// 绘制界面
	void Draw()
	{
		putimage(mapX, mapY, imgMap);
		DrawFood();
		Ai* temp = ai->next;
		while (temp != ai)
		{
			temp->ais->ShowBody();
			temp = temp->next;
		}
		temp->ais->ShowBody();
		player->IsDead();
		player->ShowBody();
		player->Print();
		FlushBatchDraw();
	}
	// 运行
	void Running()
	{
		short ddx = 0;
		short ddy = 0;
		time_t ct = clock() - time_t(100);
		Ai* temp = ai->next;
		while (temp != ai)
		{
			temp->ais->ct = clock();
			temp = temp->next;
		}
		temp->ais->ct = clock();
		temp = temp->next;
		int ex = 0;
		bool isFast = false;
		while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && !player->isDead)
		{
			if (GetAsyncKeyState('P') & 0x8000)
				ret = _getwch();
			if (clock() - ct > flushTime)
			{
				ct = clock();
				isFast = (msg.mkLButton || msg.mkRButton) ? true : false;
				player->Move(ex, mapX, mapY, ddx, ddy);
				if (isFast)
				{
					player->Move(ex, mapX, mapY, ddx, ddy);
					if (rand() % 1000 < 100)
						ex -= 2;
				}
				Draw();
			}
			if (clock() - temp->ais->ct > flushTime && !player->isDead)
			{
				temp->ais->ct = clock();
				temp->ais->Move(ex);
				if (temp->ais->isDead)
				{
					delete temp->ais;
					temp->ais = new AI(player);
					temp->ais->ct = clock();
				}
				else if (temp->ais->isFast)
				{
					temp->ais->Move(ex);
					if (temp->ais->isDead)
					{
						delete temp->ais;
						temp->ais = new AI(player);
						temp->ais->ct = clock();
					}
				}
				ai = ai->next;
				temp = temp->next;
			}
		}
	}
private:
	int flushTime;
	Player* player;
	typedef struct _AI
	{
		AI* ais;
		struct _AI* next;
	}Ai;
	Ai* ai;
};
////////// 主函数 //////////
int main()
{
	initgraph(ScreenWidth, ScreenHeight);
	srand((unsigned)time(NULL));
	Game game;
	game.Running();
	settextcolor(BLACK);
	settextstyle(50, 0, _T("微软雅黑"));
	outtextxy((ScreenWidth - textwidth(_T("游戏结束"))) / 2, ScreenHeight / 3, _T("游戏结束"));
	settextstyle(20, 0, _T("微软雅黑"));
	outtextxy((ScreenWidth - textwidth(_T("按任意键退出"))) / 2, ScreenHeight / 4 * 3 + 50, _T("按任意键退出"));
	FlushBatchDraw();
	while (_kbhit())
		ret = _getwch();
	ret = _getwch();
	closegraph();
	return 0;
}

//#include <graphics.h>      // 引用图形库头文件
//#include <conio.h>
//int main()
//{
//	initgraph(640, 480);   // 创建绘图窗口，大小为 640x480 像素
//	circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
//	_getch();              // 按任意键继续
//	closegraph();          // 关闭绘图窗口
//}
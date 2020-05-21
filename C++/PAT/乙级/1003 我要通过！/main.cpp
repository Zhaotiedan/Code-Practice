“答案正确”是自动判题系统给出的最令人欢喜的回复。
本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

#include<iostream>
using namespace std;
#include<string>

bool Judge(string s)
{
    int countP=0;//P的个数
    int countT=0;//T的个数
    int lp,lt=0;//P和T的位置
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='P' && s[i]!='A'&& s[i]!='T')
        {
            return false;
        }
        else if(s[i]=='P')
        {
            lp=i;
            countP++;
        }
        else if(s[i]=='T')
        {
            lt=i;
            countT++;
        }
    }
        
        //满足P前面的A的个数和P与T之间的A的个数相乘的积等于T后面的A的个数，也要求T在P后面，而且要包含一个T和一个P；
        if ((lt - 1 - lp) >= 1 && (lp*(lt - lp - 1) == (s.size() - lt - 1)) && countP == 1 && countT == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
}
int main()
{
    int n=0;
    cin>>n;
    while(n)
    {
        string s;
        cin>>s;
        if(Judge(s))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        n--;
    }
    return 0;
}

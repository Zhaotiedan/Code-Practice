/*
问题描述
　　给定当前的时间，请用英文的读法将它读出来。
　　时间用时h和分m表示，在英文的读法中，读一个时间的方法是：
　　如果m为0，则将时读出来，然后加上“o'clock”，如3:00读作“three o'clock”。
　　如果m不为0，则将时读出来，然后将分读出来，如5:30读作“five thirty”。
　　时和分的读法使用的是英文数字的读法，其中0~20读作：
　　0:zero, 1: one, 2:two, 3:three, 4:four, 5:five, 6:six, 7:seven, 8:eight, 9:nine, 10:ten, 11:eleven, 12:twelve, 13:thirteen, 14:fourteen, 15:fifteen, 16:sixteen, 17:seventeen, 18:eighteen, 19:nineteen, 20:twenty。
　　30读作thirty，40读作forty，50读作fifty。
　　对于大于20小于60的数字，首先读整十的数，然后再加上个位数。如31首先读30再加1的读法，读作“thirty one”。
　　按上面的规则21:54读作“twenty one fifty four”，9:07读作“nine seven”，0:15读作“zero fifteen”。
输入格式
　　输入包含两个非负整数h和m，表示时间的时和分。非零的数字前没有前导0。h小于24，m小于60。
输出格式
　　输出时间时刻的英文。
样例输入
0 15
样例输出
zero fifteen

//方法一：笨办法
#include<iostream>
using namespace std;
#include<string>

int main()
{
	int h = 0;
	int m = 0;
	string res;
	cin >> h >> m;
	switch (h)
	{
	case 0:
		res += "zero ";
		break;
	case 1:
		res += "one ";
		break;
	case 2:
		res += "two ";
		break;
	case 3:
		res += "three ";
		break;
	case 4:
		res += "four ";
		break;
	case 5:
		res += "five ";
		break;
	case 6:
		res += "six ";
		break;	
	case 7:
		res += "seven ";
		break;
	case 8:
		res += "eight ";
		break;
	case 9:
		res += "nine ";
		break;
	case 10:
		res += "ten ";
		break;
	case 11:
		res += "eleven ";
		break;
	case 12:
		res += "twelve ";
		break;
	case 13:
		res += "thirteen ";
		break;
	case 14:
		res += "fourteen ";
		break;
	case 15:
		res += "fifteen ";
		break;
	case 16:
		res += "sixteen ";
		break;
	case 17:
		res += "seventeen ";
		break;
	case 18:
		res += "eighteen ";
		break;
	case 19:
		res += "nineteen ";
		break;
	case 20:
		res += "twenty ";
		break;
	case 21:
		res += "twenty one ";
		break;
	case 22:
		res += "twenty two ";
		break;
	case 23:
		res += "twenty three ";
		break;
	default:
		break;
	}
	switch (m)
	{
	case 0:
		res += "o'clock";
		break;
	case 1:
		res += "one";
		break;
	case 2:
		res += "two";
		break;
	case 3:
		res += "three";
		break;
	case 4:
		res += "four";
		break;
	case 5:
		res += "five";
		break;
	case 6:
		res += "six";
		break;
	case 7:
		res += "seven";
		break;
	case 8:
		res += "eight";
		break;
	case 9:
		res += "nine";
		break;
	case 10:
		res += "ten";
		break;
	case 11:
		res += "eleven";
		break;
	case 12:
		res += "twelve";
		break;
	case 13:
		res += "thirteen";
		break;
	case 14:
		res += "fourteen";
		break;
	case 15:
		res += "fifteen";
		break;
	case 16:
		res += "sixteen";
		break;
	case 17:
		res += "seventeen";
		break;
	case 18:
		res += "eighteen";
		break;
	case 19:
		res += "nineteen";
		break;
	case 20:
		res += "twenty";
		break;
	case 21:
		res += "twenty one";
		break;
	case 22:
		res += "twenty two";
		break;
	case 23:
		res += "twenty three";
		break;
	case 24:
		res += "twenty four";
		break;
	case 25:
		res += "twenty five";
		break;
	case 26:
		res += "twenty six";
		break;
	case 27:
		res += "twenty seven";
		break;
	case 28:
		res += "twenty eight";
		break;
	case 29:
		res += "twenty nine";
		break;
	case 30:
		res += "thirty";
		break;
	case 31:
		res += "thirty one";
		break;
	case 32:
		res += "thirty two";
		break;
	case 33:
		res += "thirty three";
		break;
	case 34:
		res += "thirty four";
		break;
	case 35:
		res += "thirty five";
		break;
	case 36:
		res += "thirty six";
		break;
	case 37:
		res += "thirty seven";
		break;
	case 38:
		res += "thirty eight";
		break;
	case 39:
		res += "thirty nine";
		break;
	case 40:
		res += "forty";
		break;
	case 41:
		res += "forty one";
		break;
	case 42:
		res += "forty two";
		break;
	case 43:
		res += "forty three";
		break;
	case 44:
		res += "forty four";
		break;
	case 45:
		res += "forty five";
		break;
	case 46:
		res += "forty six";
		break;
	case 47:
		res += "forty seven";
		break;
	case 48:
		res += "forty eight";
		break;
	case 49:
		res += "forty nine";
		break;
	case 50:
		res += "fifty";
		break;
	case 51:
		res += "fifty one";
		break;
	case 52:
		res += "fifty two";
		break;
	case 53:
		res += "fifty three";
		break;
	case 54:
		res += "fifty four";
		break;
	case 55:
		res += "fifty five";
		break;
	case 56:
		res += "fifty six";
		break;
	case 57:
		res += "fifty seven";
		break;
	case 58:
		res += "fifty eight";
		break;
	case 59:
		res += "fifty nine";
		break;
	default:
		break;
	}
	cout << res << endl;
	system("pause");
	return 0;
}

//方法二：巧妙
#include <iostream>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    string arr[24] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
					"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three"};
	cout << arr[h] << " ";
    if (m == 0)
        cout << "o'clock";
    int t = m % 10;
    m = m / 10;
    switch(m) {
        case 2: cout << "twenty "; break;
        case 3: cout << "thirty "; break;
        case 4: cout << "forty "; break;
        case 5: cout << "fifty "; break;
        default: break;
    }
    if (m == 0 && t != 0) {
        cout << arr[t];
    }
    if (m == 1) {
        cout << arr[t + 10];
    }
    if (m != 0 && m != 1 && t!= 0) {
        cout << arr[t];
    }
    return 0;
}

*/

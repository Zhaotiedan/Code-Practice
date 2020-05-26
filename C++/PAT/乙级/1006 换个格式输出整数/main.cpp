让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

输入格式：
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。

输出格式：
每个测试用例的输出占一行，用规定的格式输出 n

输入样例 1：
234
输出样例 1：
BBSSS1234
输入样例 2：
23
输出样例 2：
SS123


#include<iostream>
using namespace std;
#include<string>

int main()
{
    string s;
    cin>>s;
    if(s.size()==3)//3位
    {
        int bai=s[0]-'0';
        int shi=s[1]-'0';
        int ge=s[2]-'0';
        while(bai)
        {
            cout<<"B";
            bai--;
        }
        while(shi)
        {
            cout<<"S";
            shi--;
        }
        for(int i=1;ge;ge--,i++)
        {
            cout<<i;
        }
    }
    else if(s.size()==2)//2位
    {
        int shi=s[0]-'0';
        int ge=s[1]-'0';
        while(shi)
        {
            cout<<"S";
            shi--;
        }
        for(int i=1;ge;ge--,i++)
        {
            cout<<i;
        }
    }
    else if(s.size()==1)
    {
        int ge=s[0]-'0';
        for(int i=1;ge;ge--,i++)
        {
            cout<<i;
        }
    }
    return 0;
}

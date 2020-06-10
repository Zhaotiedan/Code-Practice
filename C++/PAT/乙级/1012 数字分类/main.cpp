给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

A1 = 能被 5 整除的数字中所有偶数的和；
A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1−n2+n3−n4
A3 = 被 5 除后余 2 的数字的个数；
A4  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A5 = 被 5 除后余 4 的数字中最大数字。
输入格式：

每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的 N 个正整数，按题目要求计算 A1 ~A5 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 N。

输入样例 1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：

30 11 2 9.7 9
输入样例 2：

8 1 2 4 5 6 7 9 16
输出样例 2：

N 11 2 N 9
  
  
#include<iostream>
using namespace std;
#include<vector>
#include<iomanip>

int sum=1;//-1的标志
int temp=0;//算a4时每一次的总值
int count=0;//算a4时每次满足条件的数字数量
int flag=0;//判断a2是否存在的标志

int main()
{
    int a1=0,a2=0,a3=0,a5=0;
    float a4=0;
    int num=0;//测试点个数
    cin>>num;
    vector<int> v(num);
    
    //输入测试用例
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    
    //遍历数组
    for(int i=0;i<v.size();i++)
    {
        //能被5整除的，所有偶数的和 a1
        if(v[i]%5==0)
        {
            if(v[i]%2==0)
            {
                a1+=v[i];
            }
        }
        //被 5 除后余 1 的数字按给出顺序进行交错求和 a2
        else if(v[i]%5==1)
        {
            flag=1;
            a2+=sum*v[i];
            sum=-sum;
        }
        //被5除后余2的数字个数 a3
        else if(v[i]%5==2)
        {
            a3++;
        }
        //被5除后余3 的平均数
        else if(v[i]%5==3)
        {
            count++;
            temp+=v[i];
            a4=temp*1.0/count;
        }
        //被5除后余4 的最大数字
        else if(v[i]%5==4)
        {
            if(a5<v[i])
            {
                a5=v[i];
            }
        }
    }
    
    //输出
    if(a1)
    {
        cout<<a1<<" ";
    }
    else
    {
        cout<<"N"<<" ";
    }
    
    if(flag)
    {
        cout<<a2<<" ";
    }
    else
    {
        cout<<"N"<<" ";
    }
    
    if(a3)
    {
        cout<<a3<<" ";
    }
    else
    {
        cout<<"N"<<" ";
    }
    
    if(a4)
    {
       cout<<setiosflags(ios::fixed)<<setprecision(1)<<a4<<" ";
    }
    else
    {
        cout<<"N"<<" ";
    }
    
    if(a5)
    {
        cout<<a5;
    }
    else
    {
        cout<<"N";
    }
    
    return 0;
}

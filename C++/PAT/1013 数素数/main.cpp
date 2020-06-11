令 Pi表示第 i 个素数。现任给两个正整数 M≤N≤10^4
请输出 PM 到 PN 的所有素数。

输入格式：

输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：

输出从 PM 到 PN 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：

5 27
输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

  
 #include<iostream>
using namespace std;
#include<math.h>
#include<vector>

bool IfPrime(int num)
{
    if(num==1)
    {
        return false;
    }
    if(num==2)
    {
        return true;
    }
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int m=0;
    int n=0;
    int time=0;//标记当前行打印数字个数
    cin>>m>>n;
    vector<int> v(n);
    int num=1;//当前数字
  
  //往数组中打印直到第n个素数
    for(int i=0;i<v.size();i++)
    {
        while(!IfPrime(num))//不是素数
        {
            num++;
        }
        //跳出循环后是素数
        v[i]=num;
        num++;//让num再前进一位
    }
    

    //输出
    for(int i=m-1;i<n;i++)
    {
        time++;
        cout<<v[i];
        if((time<10)&&(i!=n-1))//不够10个 打印空格
        {
            cout<<" ";
        }
        if(time==10)//满10个 换行
        {
            cout<<endl;
            time=0;//记得time清0
        }
    }
    return 0;
}

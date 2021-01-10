大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，
因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；
第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；
后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：

在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，
即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。
题目输入保证每个测试存在唯一解。

输入样例：

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：

THU 14:04
  
  //本代码牛客测试用例全过，pat（16/20）

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<cmath>

int main()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int p1=0;//s1和s2第一个相同大写字母下标
    int p2=0;//s1和s2第二个相同的大写字母下标
    int p3=0;//s3和s4第一对相同的英文字母出现的位置
    int temp=0;
    
    int flag=1;//标志一下s1和s2是当前的第几个相同的字母
    
    string v[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    //搜索s1
    for(int i=0;i<s1.size();i++)
    {
        if((s1[i]>=65&&s1[i]<=71)&&(flag==1))//星期的情况 在A~G之间  
        {
            //搜索s2
            for(int j=0;j<s2.size();j++)
            {
                //找到了 第一个
                if(s2[j]==s1[i]&&(i==j)&&(flag==1))
                {
                    flag=2;
                    p1=s2[j]-65;//在v中的下标
                    temp=j+1;//
                    i++;
                    cout<<v[p1]<<" ";
                    //cout<<temp;
                }
            }
        }
        else if((flag==2) && ((s1[i]>=48&&s1[i]<=57) || (s1[i]>=65&&s1[i]<=78)))//钟头的情况,已经输出了星期
        {
            //数字0~9
            if(s1[i]>=48&&s1[i]<=57)
            {
                for(int k=temp;k<s2.size();k++)
                {
                    
                    if((s2[k]==s1[i])&&(k==i))
                    {
                        cout<<"0"<<s1[i]<<":";
                        flag=3;
                        break;
                    }
                }
                
            }
            //字母
            else if(s1[i]>=65&&s1[i]<=78)
            {
                
                for(int t=temp;t<s2.size();t++)
                {
                    if((s2[t]==s1[i])&&(t==i))
                    {
                        p2=s2[t]-65;
                        cout<<p2+10<<":";
                        flag=3;
                        break;
                    }
                }
            }
        }
    }
    
    //搜索s3
    for(int i=0;i<s3.size();i++)
    {
        //只要是英文字母
        if( (s3[i]>=65&&s3[i]<=90) || (s3[i]>=97&&s3[i]<=122) )
        {
            if((s4[i]==s3[i])&&(flag==3))
            {
                p3=i;
                if(p3<10)
                {
                    cout<<"0"<<p3;
                    flag=4;
                }
                else
                {
                    cout<<p3;
                    flag=4;
                }
            }
        }
    }
    return 0;
}

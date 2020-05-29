一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即将A中的数据由（A1,A2...An变成Ai+1，Ai+2...Ai+n)
（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6
输出样例:
5 6 1 2 3 4
  
  
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    int number,k=0;
    cin>>number;
    cin>>k;
    vector<int> v(number);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    //注意当k大于数组长度时，数组移动情况和k%6是一样的，因为每移动6次就会回到原点
    while(k>=v.size())
    {
        k=k%v.size();
    }
    reverse(v.begin(),v.end());//先整体逆置
    reverse(v.begin(),v.begin()+k);//再逆置前k端
    reverse(v.begin()+k,v.end());//逆置后半段
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
        if(i!=v.size()-1)
        {
            cout<<" ";
        }
    }
    return 0;
}

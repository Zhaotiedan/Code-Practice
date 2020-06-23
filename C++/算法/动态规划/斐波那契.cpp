难度：Easy
备注：斐波那契数列，出自《剑指offer》
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为
0）。n<=39

来源：https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

1.常见递归
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0)
        {
            return 0;
        }
        if(n==1||n==2)
        {
            return 1;
        }
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
};

2. 动归一解
状态定义：斐波那契数列的第i项的值
状态方程：F(i)=F(i-1)+F(i-2)
状态初始化：F(0)=0,F(1)=1
返回值：F(n)

class Solution {
public:
    int Fibonacci(int n) {
    
        int* F=new int[n+1];//用来保存每一次结果的值
        
        //初始化
        F[0]=0;
        F[1]=1;
        for(int i=2;i<=n;i++)
        {
            F[i]=F[i-1]+F[i-2];
        }
        return F[n];
    }
};

3. 动归二解
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0)
        {
            return 0;
        }
        if(n==1||n==2)
        {
            return 1;
        }
        //初始化
        int first=1,second=1;
        int fn=0;
        for(int i=3;i<=n;i++)
        {
            fn=first+second;
            first=second;
            second=fn;
        }
        return fn;
    }
};

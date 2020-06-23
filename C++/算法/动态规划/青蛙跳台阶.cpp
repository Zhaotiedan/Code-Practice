难度：Easy
备注：需要C基础，排列，出自《剑指offer》
题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

来源：https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

状态定义:跳上第i级台阶的方法数
状态转移方程：F(i)=2*F(i-1)
状态初始化：F(1)=1
返回值：F(n)

class Solution {
public:
    int jumpFloorII(int number) {
        if(number<=0)
        {
            return 0;
        }
        //初始化
        int f1=1;
        //状态定义
        int fn=f1;
        for(int i=2;i<=number;i++)
        {
            //转换方程
            fn=fn*2;
        }
        //返回值
        return fn;
    }
};

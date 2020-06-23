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


扩展1：
上述问题为变态青蛙跳台阶，太疯狂，这只青蛙像是吃了大力丸 身上充满了无穷的力量。现在让它变成一个正常的青蛙，限制它 一次只能跳1阶或者2阶，现在该如何解答

状态定义:跳上第i级台阶的方法数
状态转移方程：F(i)=F(i-1)+F(i-2)
状态初始化：F(1)=1
返回值：F(n)
变成了斐波那契数列的求解。

扩展2：矩形覆盖
 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 
 状态定义:跳上第i级台阶的方法数
状态转移方程：F(i)=横放F(i-2)+竖放F(i-1)
状态初始化：F(1)=1
返回值：F(n)
变成了斐波那契数列的求解。

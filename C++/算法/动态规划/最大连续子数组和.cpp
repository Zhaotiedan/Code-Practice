难度：Easy
备注：出自《剑指offer》
题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式
识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是
否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0
个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少
是1)

来源：https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

状态定义：
F(i) 以第i个元素结尾的最大连续和
状态方程：
F(i)=max(F(i)+arr[i],arr[i])
初始化：
F(0)=arr[0]
返回值：
max(F(i))   i<n

//解法一：开辟数组保存每次当前元素结尾的最大连续和F(i)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        
        vector<int> F(array.size());//用于保存每次以当前元素结尾的最大连续和F(i)
        //初始化
        F[0]=array[0];
        
        for(int i=1;i<F.size();i++)
        {
            //转移方程
            F[i]=max(F[i-1]+array[i],array[i]);
        }
        
        int maxsum=F[0];//用于保存F(i)的最大值
        for(int i=1;i<F.size();i++)
        {
            maxsum=max(maxsum,F[i]);
        }
        //返回值
        return maxsum;
    }
};

//解法二，无需开辟数组，每次更新最大连续子数组和
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        //初始化
        int cursum=array[0];//代表当前的连续子数组和
        int maxsum=array[0];//最大连续子数组和
        for(int i=1;i<array.size();i++)
        {
            //转移方程
            cursum=max(cursum+array[i],array[i]);
            //更新每次最大的子数组和
            maxsum=max(maxsum,cursum);
        }
        //返回值
        return maxsum;
    }
};

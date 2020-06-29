难度：Medium
备注：出自leetcode
题目描述
给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
例如:
给定s=“leetcode”；
dict=["leet", "code"].
返回true，因为"leetcode"可以被分割成"leet code".

来源：https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking

状态定义：F（i）s的前i个字符是否可以被成功分割
状态转移方程：substr[1,j]可以被分割，substr[j+1,i]能否被分割
初始化：F(0) 一个辅助状态，相当于"""leetcode"
返回：保存结果的数组的最后一个值F(s.size())
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())
        {
            return false;
        }
        vector<bool> v(s.size()+1,false);
        //初始化
        v[0]=true;//初始辅助状态
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                //状态方程
                if(v[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    v[i]=true;
                    break;
                }
            }
        }
        //返回值
        return v[s.size()];
    }
};

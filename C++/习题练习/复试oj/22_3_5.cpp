1.牛客--二维数组中的查找
在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
给定 target = 7，返回 true。
给定 target = 3，返回 false。
数据范围：矩阵的长宽满足  ， 矩阵中的值满足 
进阶：空间复杂度  ，时间复杂度 

法一：暴力美学
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for(int i=0;i<array.size();i++)
        {
            for(int j=0;j<array[i].size();j++)
            {
                if(array[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

法二：效率更高法--找最左下元素(列最大，行最小)为标准
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i=array.size()-1;
        int j=0;
        while((i>=0)&&j<array[0].size())
        {
            if(target<array[i][j])//指定元素在该元素上方
            {
                i--;
            }
            else if(target>array[i][j])//指定元素在该元素右边
            {
                j++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

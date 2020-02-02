
//1.leetcode27
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//csdn：https://blog.csdn.net/qq_42913794/article/details/104026252

//双指针法：一个指针用于寻找，跳过值为val的位置。一个指针用于放入非val的值
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        for(int fast=0;fast<nums.size();fast++)
        {
            if(nums[fast]!=val)
            {
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

/*remove和erase搭配用法：remove负责将所有非val的元素放到vector的首部，值为val的元素放到vector的尾部，返回新的end()值（相当于val部分的begin）。
                      //erase负责将尾部去除。*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(),nums.end(),val),nums.end());
        return nums.size();
    }
};

//2.leetcode58
给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
如果不存在最后一个单词，请返回 0 。说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。
示例:
输入: "Hello World"
输出: 5

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        int num = s.size();
        while ((s[num - 1] == ' ') && (num >= 0)) {
            num--;
            }
        string str = s.substr(0,num);
        size_t pos=str.rfind(' ');
        int length=0;
        if(pos!=s.npos)
        {
            for(int i=pos;i<str.size()-1;i++)
            {
                length++;
            }
            return length;
        }
        else
        {
            return num;
        }
    }
};	

//3.leetcode88
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素

#include<algorithm>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.size()>=m+n)
        {
            nums1.erase(nums1.begin()+m,nums1.end());//注意不能将所有0都删除
            for(int i=0;i<nums2.size();i++)
            {
                nums1.push_back(nums2[i]);
            }
            sort(nums1.begin(),nums1.end());
        }
        else
        {
            return;
        }
    }
};

//leetcode 127
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

//1.个人暴力解法 可能超时
#include <algorithm>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        {
            return false;
        }
        int val=0;
        for(int i=0;i<nums.size();i++)
        {
            val=nums[i];
            if(find(nums.begin()+i+1,nums.end(),val)!=nums.end())
            {
                return true;
            }
        }
        return false;
    }
};

//2.将nums进行排序然后判断相邻是否有相同元素
class Solution {
    static bool cmp(const int &a,const int &b)
    {
        return a<b;
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};

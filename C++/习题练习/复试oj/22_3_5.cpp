1.牛客--二维数组中的查找  https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e
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



2.旋转数组的最小数字 
链接：https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，
变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。
请问，给定这样一个旋转数组，求数组中的最小值。
实际考察：二分查找


3.从尾到头打印链表
法一：遍历链表，值用栈存储，最后输出栈中元素

法二：遍历链表，值用数组存储，逆置数组后输出数组中元素

法三：递归打印第一个节点值需要先打印第二个，打印第二个节点值需要先打印第三个。
链表指针为空时，退出。在递归后面插入节点值到数组。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    void PrintList(ListNode* head,vector<int>& v)
    {
        if(head==nullptr)
        {
            return;
        }
        PrintList(head->next,v);
        v.insert(v.end(),head->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        PrintList(head,res);
        return res;
    }
};

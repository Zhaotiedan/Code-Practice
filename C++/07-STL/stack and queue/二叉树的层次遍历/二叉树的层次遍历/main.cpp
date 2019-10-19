#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<queue>

//给定一个二叉树，返回其按层次遍历的节点值。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;

		if (root == nullptr)
		{
			return result;
		}
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> level;
			int levelsize = q.size();
			for (size_t i = 0; i < levelsize; i++)
			{
				TreeNode* cur = q.front();
				level.push_back(cur->val);
				if (cur->left)
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}
				q.pop();
			}
			result.push_back(level);
		}
		return result;
	}
};
int main()
{

	system("pause");
	return 0;
}
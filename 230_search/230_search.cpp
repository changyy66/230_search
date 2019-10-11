// 230_search.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
3
/ \
1   4
\
   2
   输出: 1
   示例 2:

   输入: root = [5,3,6,2,4,null,null,1], k = 3
   5
   / \
   3   6
   / \
   2   4
   /
   1
   输出: 3
   进阶：
   如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
   著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"

/**
* Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int num;
	int search(TreeNode* root, int k) {
		if (root->left == NULL&&root->right == NULL)
		{
			if (k == 1)num = root->val;
			return 1;
		}
		int n = 0;
		if (root->left)
		{
			n = search(root->left, k);
			if (n >= k)return n;
		}
		if ((++n) == k)
		{
			num = root->val;
			return n;
		}
		if (root->right)
		{
			n += search(root->right, k - n);
			return n;
		}
		return n;

	}

	int kthSmallest(TreeNode* root, int k) {
		num = root->val;
		search(root, k);
		return num;
	}
};
int main()
{
    return 0;
}


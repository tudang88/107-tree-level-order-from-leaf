#include <iostream>
#include "BinaryTree.h"
using namespace std;

// TODO: solution breath first search
/**
 * traverser all level
*/
void Solution::dfs_traversal(TreeNode *currentNode, vector<vector<int>> &allLevels, int currentLevel)
{
    if (currentNode == nullptr) return;
    // pick node
    if (currentLevel >= allLevels.size()) {
        allLevels.push_back({currentNode->val});
    } else {
        allLevels.at(currentLevel).push_back(currentNode->val);
    }

    // traverser on left
    dfs_traversal(currentNode->left, allLevels, currentLevel + 1);
    // traverser on right
    dfs_traversal(currentNode->right, allLevels, currentLevel + 1);
}

/**
 * target function
*/
vector<vector<int>> Solution::levelOrder(TreeNode *root)
{
    vector<vector<int>> allLevels;
    dfs_traversal(root, allLevels, 0);
    return allLevels;
}

/**
 * traverser from leaf to root
*/
vector<vector<int>> Solution::levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> ans;
    dfs_traversal(root, ans, 0);
    std::reverse(ans.begin(), ans.end());
    return ans;
}
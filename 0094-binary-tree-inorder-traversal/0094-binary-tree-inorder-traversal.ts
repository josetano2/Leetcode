/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function inorderTraversal(root: TreeNode | null): number[] {
    let ans: number[] = [];
    
    function inorder(curr: TreeNode) {
        if(curr === null) {
            return;
        }

        inorder(curr.left);
        ans.push(curr.val);
        inorder(curr.right);
    }

    inorder(root);
    return ans;
};
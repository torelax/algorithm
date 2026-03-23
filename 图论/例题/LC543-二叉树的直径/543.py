# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def landr(self, l, r):
        self.left = l
        self.right = r

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0
        def depth(node):
            if not node:    return 0
            L = depth(node.left)
            R = depth(node.right)
            self.ans = max(self.ans, L+R+1)
            return max(L, R)+1
        depth(root)
        return self.ans-1
if __name__ == "__main__":
    t = TreeNode(5)
    t.landr(TreeNode(3), TreeNode(7))
    t.left.landr(TreeNode(4), None)
    s = Solution()
    print(t.left.left.val)
    print(s.diameterOfBinaryTree(t))
//HARSH KUMAR YADAV

//104
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};


//48
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    ranges::reverse(matrix);
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = i + 1; j < matrix.size(); ++j)
        swap(matrix[i][j], matrix[j][i]);
  }
};

//101
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    return isSymmetric(root, root);
  }

 private:
  bool isSymmetric(TreeNode* p, TreeNode* q) {
    if (!p || !q)
      return p == q;

    return p->val == q->val &&                //
           isSymmetric(p->left, q->right) &&  //
           isSymmetric(p->right, q->left);
  }
};


//103
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};
    bool isLeftToRight = true;

    while (!q.empty()) {
      const int size = q.size();
      vector<int> currLevel(size);
      for (int i = 0; i < size; ++i) {
        TreeNode* node = q.front();
        q.pop();
        const int index = isLeftToRight ? i : size - i - 1;
        currLevel[index] = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
};

//236
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q)
      return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr)
      return root;
    return left == nullptr ? right : left;
  }
};


//102
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(currLevel);
    }

    return ans;
  }
};


//230
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    const int leftCount = countNodes(root->left);

    if (leftCount == k - 1)
      return root->val;
    if (leftCount >= k)
      return kthSmallest(root->left, k);
    return kthSmallest(root->right, k - 1 - leftCount);  // leftCount < k
  }

 private:
  int countNodes(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};


//116
class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr)
      return nullptr;
    connectTwoNodes(root->left, root->right);
    return root;
  }

 private:
  void connectTwoNodes(Node* p, Node* q) {
    if (p == nullptr)
      return;
    p->next = q;
    connectTwoNodes(p->left, p->right);
    connectTwoNodes(q->left, q->right);
    connectTwoNodes(p->right, q->left);
  }
};


//404
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
      return 0;

    int ans = 0;

    if (root->left) {
      if (root->left->left == nullptr && root->left->right == nullptr)
        ans += root->left->val;
      else
        ans += sumOfLeftLeaves(root->left);
    }
    ans += sumOfLeftLeaves(root->right);

    return ans;
  }
};

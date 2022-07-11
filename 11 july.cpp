//c++ solution using queue and helper
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        queue<TreeNode *>q;
        q.push(root);
        if(!root) 
            return output;
        while(!q.empty())
        {
            vector <int>helper;
            int n = q.size();
            for(int i = 0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                helper.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            output.push_back(helper[n-1]);
        }
        return output;
    }
};


    // c++ solution using recursion method.
    // Time complexcity = O(n)
    // Space complexcity = O(h) where h = height of the tree
    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> output;
            recursion(root,0,output);
            return output;
        }
        void recursion(TreeNode* root,int level, vector<int>& output){
            if(root == NULL) return;
            if(output.size() == level) output.push_back(root->val);
            recursion(root->right,level+1,output);
            recursion(root->left,level+1,output);
        }
    };
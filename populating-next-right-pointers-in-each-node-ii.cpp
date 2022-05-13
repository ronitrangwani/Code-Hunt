class Solution {
public:
    Node* connect(Node* root) {
        Node *head = root;
        queue<Node*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            for(int i=0, n=q.size(); i<n; i++){
                root = q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                if(i != n-1)
                    root->next = q.front();
            }
        }
        return head;
    }
};

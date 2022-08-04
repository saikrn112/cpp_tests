class NumArray 
{
private:
    struct Node
    {
        int min; 
        int max;
        int sum;
        Node* root;
        Node* left;
        Node* right;
        Node() : min(0), max(0), sum(0)
        , root(nullptr), left(nullptr), right(nullptr)
        {
        }
        Node(int val, int index) : min(index), max(index), sum(val)
        , root(nullptr), left(nullptr), right(nullptr)
        {
        }
        
        update(int)
    };
    
    Node* root;
    
    Node* createTree(int min, int max,int depth)
    {
        if (depth == 0)
        {
            auto node = new Node();
            node->min = min;
            node->max = max;
            return new Node();
        }
        auto totalLeaves = std::pow(2,depth);
        auto left = createTree(min,(totalLeaves/2) -1,depth-1);
        auto right = createTree(totalLeaves/2,max,depth-1);
        auto node = new Node();
        node->left = left;
        node->right = right;
        node->min = min;
        node->max = max;
        return node;
    }
    
    Node* getNode(int index)
    {
        auto droot = root;
        while (droot->left != nullptr || droot->right != nullptr)
        {
            if (droot->left->min <= index && index <= droot->left->max)
            {
                droot = droot->left;
                continue;
            }
            if (droot->right->min <= index && index <= droot->right->max)
            {
                droot = droot->right;
                continue;
            }
        }
        return droot;
    }
    
public:
    NumArray(vector<int>& nums)
    : root (nullptr)
    {
        Node* tree = createTree(0,nums.size(),std::ceil(std::log2(nums.size())));
        for (int i = 0; i < nums.size(); i++)
        {
            update(i,nums[i]);
        }
    }
    
    void update(int index, int val) 
    {
        if (root == nullptr)
        {
            return;
        }
        auto node = getNode(index);
        node->val = val;
    }
    
    int sumRange(int left, int right) 
    {
        if (left < 0 || right < 0
           || left >= data.size() || right >= data.size())
        {
            return -1;
        }
        return std::accumulate(data.begin()+left,data.begin()+right+1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

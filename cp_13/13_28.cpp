#include <iostream>
#include <string>

class TreeNode
{
public:
    TreeNode() : value(std::string()), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& rnode) : value(rnode.vlaue), count(rnode.count), left(rnode.left), right(rnode.right) {++*count;}
    TreeNode& operator=(const TreeNode& node)
    {
        if(this == &node)
            return *this;
        ++*node.count;
        if(--*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
        value = node.value;
        count = node.count;
        left = node.left;
        right = node.right;
        return *this;
    }
    ~TreeNode()
    {
        if(--*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
    }
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
}
#include <iostream>
#include <vector>
#include <memory> 
using namespace std;

struct TreeNode {
    int value;
    unique_ptr<TreeNode> right;
    unique_ptr<TreeNode> left;

    TreeNode(int value) : value(value), right(nullptr), left(nullptr) {}
};

class BinaryTree {
    unique_ptr<TreeNode> root;

private:
    unique_ptr<TreeNode> insertNode(unique_ptr<TreeNode> node, int value) {
        if (!node) {
            return make_unique<TreeNode>(value);
        }
        if (value < node->value) {
            node->left = insertNode(move(node->left), value);
        }
        else if (value > node->value) {
            node->right = insertNode(move(node->right), value);
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left.get();
        }
        return node;
    }

    TreeNode* searchNode(TreeNode* node, int value) {
        if (!node || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return searchNode(node->left.get(), value);
        }
        else {
            return searchNode(node->right.get(), value);
        }
    }

    unique_ptr<TreeNode> deleteNode(unique_ptr<TreeNode> node, int value) {
        if (!node) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = deleteNode(move(node->left), value);
        }
        else if (value > node->value) {
            node->right = deleteNode(move(node->right), value);
        }
        else {
            if (!node->left) {
                return move(node->right);
            }
            else if (!node->right) {
                return move(node->left);
            }
            TreeNode* success = findMin(node->right.get());
            node->value = success->value;
            node->right = deleteNode(move(node->right), success->value);
        }
        return node;
    }

    void Show(TreeNode* node) const {
        if (node) {
            Show(node->left.get());
            cout << node->value << " ";
            Show(node->right.get());
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(move(root), value);
    }

    void remove(int value) {
        root = deleteNode(move(root), value);
    }

    void ShowTree() const {
        Show(root.get());
        cout << endl;
    }

    void search(int value) {
        TreeNode* res = searchNode(root.get(), value);
        if (res) {
            cout << "Your value " << value << " was found in the tree" << endl;
        }
        else {
            cout << "Your value " << value << " was not found" << endl;
        }
    }
};

class ComplexNode {
    int value;
    vector<shared_ptr<ComplexNode>> children;

public:
    ComplexNode(int val) : value(val) {
        cout << "ComplexNode created with value: " << value << endl;
    }

    ~ComplexNode() {
        cout << "ComplexNode with value " << value << " is being destroyed" << endl;
    }

    void addChild(shared_ptr<ComplexNode> child) {
        children.push_back(child);
        cout << "Added child with value " << child->value << " to node with value " << value << endl;
        cout << "Reference count for child node with value " << child->value << ": " << child.use_count() << endl;
    }

    void removeChild(shared_ptr<ComplexNode> child) {
        auto it = find(children.begin(), children.end(), child);
        if (it != children.end()) {
            children.erase(it);
            cout << "Removed child with value " << child->value << " from node with value " << value << endl;
            cout << "Reference count for child node with value " << child->value << ": " << child.use_count() << endl;
        }
    }

    void showStructure(int level = 0) const {
        for (int i = 0; i < level; ++i) cout << "  ";
        cout << value << " (refs: " << shared_ptr<const ComplexNode>(this, [](const ComplexNode*) {}).use_count() << ")" << endl;
        for (const auto& child : children) {
            child->showStructure(level + 1);
        }
    }
};

int main() 
{
    //ex1
    BinaryTree tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.ShowTree();

    tree.search(30);
    tree.search(31);

    tree.remove(30);

    tree.ShowTree();
    //Ex2
    auto rootNode = make_shared<ComplexNode>(1);
    auto childNode1 = make_shared<ComplexNode>(2);
    auto childNode2 = make_shared<ComplexNode>(3);
    auto grandchildNode1 = make_shared<ComplexNode>(4);
    auto grandchildNode2 = make_shared<ComplexNode>(5);

    rootNode->addChild(childNode1);
    rootNode->addChild(childNode2);

    childNode1->addChild(grandchildNode1);
    childNode2->addChild(grandchildNode2);

    cout << "\nStructure of the complex tree:" << endl;
    rootNode->showStructure();

    childNode1->removeChild(grandchildNode1);
    childNode2->removeChild(grandchildNode2);

    cout << "\nStructure of the complex tree after removing some children:" << endl;
    rootNode->showStructure();
   
}

    
   


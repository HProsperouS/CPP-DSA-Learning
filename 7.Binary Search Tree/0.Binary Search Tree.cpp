#include <iostream>
using namespace std;

template <typename T>
struct TreeNode{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
class BinarySearchTree{
private:
    TreeNode<T> *root;
    TreeNode<T>* insert(TreeNode<T> *node, T val);
    TreeNode<T>* remove(TreeNode<T> *node, T val);
    bool searchNode(TreeNode<T> *node, T val);
    void inOrder(TreeNode<T> *node);
public:
    BinarySearchTree() : root(NULL) {};
    ~BinarySearchTree();

    void insert(T val){
        root = insert(root, val);
    };

    void remove(T val){
        root = remove(root, val);
    };

    bool search(T val){
        return searchNode(root, val);
    };

    void inOrderTraversal(){
        inOrder(root);
    };
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    while(root != NULL){
        remove(root->val);
    }
};

template <typename T>
TreeNode<T>* BinarySearchTree<T>::insert(TreeNode<T> *node, T val){
    if(node == NULL){
        return new TreeNode<T>(val);
    }

    if(val < node->val){
        node->left = insert(node->left, val);
    }else{
        node->right = insert(node->right, val);
    }

    return node;
};

template <typename T>
TreeNode<T>* BinarySearchTree<T>::remove(TreeNode<T> *node, T val){
    if(node == NULL){
        return NULL;
    }

    if(val < node->val){
        node->left = remove(node->left, val);
    }else if(val > node->val){
        node->right = remove(node->right, val);
    }else{
        if(node->left == NULL && node->right == NULL){
            delete node;
            return NULL;
        }else if(node->left == NULL){
            TreeNode<T> *temp = node->right;
            delete node;
            return temp;
        }else if(node->right == NULL){
            TreeNode<T> *temp = node->left;
            delete node;
            return temp;
        }else{
            TreeNode<T> *temp = node->right;
            while(temp->left != NULL){
                temp = temp->left; // Find the leftmost node in the right subtree
            }
            node->val = temp->val;
            node->right = remove(node->right, temp->val); // Remove the leftmost node in the right subtree
        }
    }

    return node;
};

template <typename T>
bool BinarySearchTree<T>::searchNode(TreeNode<T> *node, T val){
    if(node == NULL){
        return false;
    }

    if(val < node->val){
        return searchNode(node->left, val);
    }else if(val > node->val){
        return searchNode(node->right, val);
    }else{
        return true;
    }
};

template <typename T>
void BinarySearchTree<T>::inOrder(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
};

int main(){
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    bst.inOrderTraversal();
    cout << endl;

    bst.remove(3);
    bst.inOrderTraversal();
    cout << endl;

    cout << bst.search(3) << endl;
    cout << bst.search(5) << endl;

    return 0;
}
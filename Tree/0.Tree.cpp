#include <iostream>
using namespace std;

template <typename T>
struct ListNode{
    T data;
    ListNode *next;
    ListNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
struct TreeNode{
    T data;
    ListNode<TreeNode<T>*> *childrenHead;
    TreeNode() : childrenHead(nullptr) {}
    void addChild(TreeNode<T> *node){
        ListNode<TreeNode<T>*> *childNode = new ListNode<TreeNode<T>*>(node);
        if(childrenHead == nullptr){
            childrenHead = childNode;
        }else{
            childNode->next = childrenHead;
            childrenHead = childNode;
        }
    }
};

template <typename T>
class Tree{
private:
    TreeNode<T> *nodes;
    TreeNode<T> *root;
public:
    Tree();
    Tree(int maxNodes);
    ~Tree();
    TreeNode<T>* GetTreeNode(int id);
    void SetRoot(int rootId);
    void AddChild(int parentId, int childId);
    void AssignData(int nodeId, T data);
    void Print(TreeNode<T> *node = NULL);
};

template <typename T>
Tree<T>::Tree(){
    nodes = new TreeNode<T>[100001];
}

template <typename T>
Tree<T>::Tree(int maxNodes){
    nodes = new TreeNode<T>[maxNodes];
}

template <typename T>
Tree<T>::~Tree(){
    delete[] nodes;
}

template <typename T>
TreeNode<T>* Tree<T>::GetTreeNode(int id){
    return &nodes[id];
}

template <typename T>
void Tree<T>::SetRoot(int rootId){
    root = GetTreeNode(rootId);
}

template <typename T>
void Tree<T>::AddChild(int parentId, int childId){
    TreeNode<T> *parentNode = GetTreeNode(parentId);
    TreeNode<T> *childNode = GetTreeNode(childId);
    parentNode->addChild(childNode);
}

template <typename T>
void Tree<T>::AssignData(int nodeId, T data){
    TreeNode<T> *node = GetTreeNode(nodeId);
    node->data = data;
}

template <typename T>
void Tree<T>::Print(TreeNode<T> *node){
    if(node == NULL){
        node = root;
    }
    cout << node->data << " ";
    ListNode<TreeNode<T>*> *child = node->childrenHead;
    while(child != nullptr){
        Print(child->data);
        child = child->next;
    }
}

int main(){
    Tree<char> tree(9);
    tree.SetRoot(0);
    tree.AssignData(0, 'a');
    tree.AssignData(1, 'b');
    tree.AssignData(2, 'c');
    tree.AssignData(3, 'd');
    tree.AssignData(4, 'e');
    tree.AssignData(5, 'f');
    tree.AssignData(6, 'g');
    tree.AssignData(7, 'h');
    tree.AssignData(8, 'i');

    tree.AddChild(0, 2);
    tree.AddChild(0, 1);
    tree.AddChild(1, 3);
    tree.AddChild(2, 5);
    tree.AddChild(2, 4);
    tree.AddChild(3, 8);
    tree.AddChild(3, 7);
    tree.AddChild(3, 6);

    tree.Print();
    return 0;
}
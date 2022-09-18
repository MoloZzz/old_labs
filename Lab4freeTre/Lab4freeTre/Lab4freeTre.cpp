#include <iostream>


struct treeNode {
    int data;
    treeNode* childs[5];
};

void add(int data,int a, treeNode*& tree) {
    if (tree == nullptr) {
        tree->data = data;

        return;
    }
    treeNode* tempTree = tree;
    treeNode *tempNode = new treeNode;
    tempNode->data = data;

    tree->childs[a] = tempTree;
 
}

void print(treeNode *tree,int a) {
    std::cout << tree->data << std::endl;
 
    if (tree->childs[a] != nullptr) {
        std::cout << tree->childs[a+1]->data << std::endl;
    }
}


int main()
{

    treeNode* tree = new treeNode{1}; //завжди задаю так вказівники,для виділення памяті
    add(111, 1, tree);
    add(27, 2, tree);
    add(2, 4, tree);
    add(25, 3, tree);
    print(tree,1);


}

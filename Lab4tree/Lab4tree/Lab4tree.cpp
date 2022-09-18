#include<iostream>
#include<conio.h>


struct node
{
    int data;                           
    node* left, * right;                        
};

                  


void push(int data, node** tree) //не придумав як зробить без подвійного вказівника
{
    if ((*tree) == NULL)                   
    {
        (*tree) = new node;                
        (*tree)->data = data;                
        (*tree)->left = (*tree)->right = NULL;
        return;                        
    }
   
    if (data > (*tree)->data) push(data, &(*tree)->right);
    else push(data, &(*tree)->left);
}


void print(node* tree, int u)
{
    if (tree == NULL) return;
    print(tree->left, ++u);
    for (int i = 0; i < u; ++i)
    std::cout << "-";
    std::cout << tree->data << std::endl;
    u--;
    print(tree->right, ++u);
}

int main()
{
    int n;               //кількість елементів               
    int first_data;              
    node* tree = NULL; 
    std::cout << "enter number of elements  ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "enter data  ";
        std::cin >> first_data;

        push(first_data, &tree);
    }
    std::cout << "your tree:" << std::endl;
    print(tree, 0);
    std::cin.ignore().get();
}
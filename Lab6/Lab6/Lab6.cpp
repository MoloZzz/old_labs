#include <iostream>
#include<string>


    struct Node {
        std::string data;
        Node* next;
    };
    
  

    void add(Node *&head,std::string sdata) {
        if (head->data.length() == 0) {
            head->data = sdata;
            head->next = nullptr;
            return;
        }

        Node* newNode = new Node;
        newNode->data = sdata;
        newNode->next = nullptr;


        Node* temp = head;

        if (sdata.length() >= head->data.length()) {
            newNode->next = head;
            head = newNode;
            return;
        }

        int current_pos = 1;
        while (temp->next != nullptr ){

            if (sdata.length() >= temp->data.length()) {
                int position = current_pos;
                current_pos = 1;
                temp = head;
                while (current_pos < position - 1) {
                    temp = temp->next;
                    current_pos++;
                }

                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }

            temp = temp->next;
            current_pos++;

        }

            temp->next = newNode;
            return;
        


        
    }
 
    void print(Node* first) {
        if (first->data.length() == 0) {
            std::cout << "list is empty" << std::endl;
        }
        else {
            Node* tempN = first;
            std::cout << tempN->data << std::endl;
            while (tempN->next != nullptr) {
                tempN = tempN->next;
                std::cout << tempN->data << std::endl;
            }
        }
    }

    void add_massive(Node *&head_massive,std::string sdata,int massive_lenth){
        Node *temp = head_massive;
        int current_pos = 1;
        if (head_massive == nullptr) {
            add(head_massive, sdata);
        }
        while (temp->next != nullptr) {
            temp = temp->next;
            current_pos++;
        }
        if (current_pos == massive_lenth) {
            std::cout << "list is full" << std::endl;
        }
        else {
            add(head_massive, sdata);
        }
    }

    struct node
    {
        std::string data;
        node* left, * right;
    };




    void push(std::string data, node** tree) //не придумав як зробить без подвійного вказівника
    {
        if ((*tree) == NULL)
        {
            (*tree) = new node;
            (*tree)->data = data;
            (*tree)->left = (*tree)->right = NULL;
            return;
        }

        if (data.length() < (*tree)->data.length()) push(data, &(*tree)->right);
        else push(data, &(*tree)->left);
    }


    void print_binary(node* tree, int u)
    {
        if (tree == NULL) return;
        print_binary(tree->left, ++u);

 
        std::cout << tree->data << std::endl;
        u--;
        print_binary(tree->right, ++u);
    }

    void check(Node*& head,Node *&secondLine) {
        Node* temp = head;
        Node* tempAdress = new Node;

        while (temp->next != nullptr) {
            if ((temp->next)->data.length() >= secondLine->data.length()) {
                temp = temp->next;
            }else {

                tempAdress = temp->next;
                temp->next = *&secondLine;
                secondLine = tempAdress;

            }
            
        }
       
    }
    Node* component_list(Node* head1, Node* head2) {
        Node* head = new Node;
      
        if (head1->data.length() >= head2->data.length()) {
            head = head1;
            check(head, head2);
        }
        else{
            head = head2;
            check(head, head1);
        }
        return head;

    }

int main()
{
    Node* head1 = new Node;
    head1->next = nullptr;
    Node* head2 = new Node;
    head2->next = nullptr;


      add(head1, "11");
      add(head1, "11111");
      add(head1, "11111111111111111111111111");
  //  add(head1, "1");
  //  add(head1, "1321");
  //  add(head1, "113213211");
  //  add(head1, "2323");
  //  add(head1, "21312321");
  //  add(head1, "b");
  //  add(head1, "11322");
  //  add(head1, "11fdggfdd322");


//  add(head2, "23");
    add(head2, "fds");
//  add(head2, "1gh");
//  add(head2, "113dfsd213211");
    add(head2, "2323");
    add(head2, "fdsd25");
    add(head2, "fdsd21e");
    add(head2, "bcxzxttyyz");
//  add(head2, "11322xczxcz"); 
//  add(head2, "11fdggfdd32czxzx2");
    
    print(component_list(head1, head2));

    
 /* Node masssive[5];
    add_massive(head, "fdsd", 5);
    add_massive(head, "fd", 5);
    add_massive(head, "fsd", 5);
    add_massive(head, "f", 5);
    add_massive(head, "dsgfhd", 5);
    add_massive(head, "fd6757sd", 5);
    add_massive(head, "fds567565d", 5);
    print(head);
    */
            
/*    node* tree = NULL;
    push("jenga", &tree);
    push("1", &tree);
    push("september", &tree);
    push("hi", &tree);
    push("hahshh", &tree);
    print_binary(tree,5);
    */



}

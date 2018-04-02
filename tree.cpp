#include <iostream>
using namespace std;

    struct node{
    int data;
    node *parent = NULL;
    node *left = NULL;
    node *right = NULL;
    };

        class tree{
        public:
        node *root;
        tree() {
        root = NULL;
        };
        void add(int value);
        void display(node *temp);
        void Search(int key, node *temp);

};

void tree::add(int value){
    node *temp = new node;
    temp->data = value;

if (root==NULL){
    root = temp;
}
else{
        node *present = root;
    while(temp->parent == NULL){
        if (present->data << value){
            if(present->right==NULL){
                present->right = temp;
                temp->parent = present;
            }
            else{
                present = present->right;
            }
        }
            else{
                if(present->left==NULL){

                    present->left=temp;
                    temp ->parent = present;
                }
                else{present = present->left;}

            }

    }
}
}
void tree::display(node *temp){

if(temp!=NULL){
    display(temp->left);
    cout<<" "<<temp->data<<" "<<endl;
    display(temp->right);

}
   int main(){
tree a;
a.add(1);
a.add(3);
a.add(2);
a.add(5);
a.add(78);
a.add(6);
a.display(a.root);
      return 0;
   }

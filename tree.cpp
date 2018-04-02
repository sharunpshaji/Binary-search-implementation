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
        void Delete(int value,node *temp);


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
        if (present->data <= value){
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
    }
    void tree::Search(int key, node *temp){
    if(temp->data == key){
        cout<<"key has found"<<endl;
    }
    else if(temp->data >= key ) {
        Search(key,temp->left);
    }
    else if(temp->data<= key) {

        Search(key, temp->right);
    }


    }
void tree::Delete(int value,node *temp){
while(temp->data!=value){

if(value>=temp->data){

temp=temp->right;

}
else if(value<=temp->data){

temp=temp->left;

}
}
if(temp==NULL){cout<<"The element doesn't exist";}
else{
if(temp->left ==NULL && temp ->right == NULL) {

if(temp->parent->data >= value) { temp->parent->right = NULL; }
else {temp->parent->left = NULL;}
temp->parent=NULL;
delete temp;

}
else if(temp->left!=NULL && temp->right== NULL) {

if(temp->parent->data >= value){
temp->parent->left = temp->left;
}
else{
temp->parent->right = temp->left;
}
temp->parent=NULL;
delete temp;

}

else if(temp->right!=NULL && temp->left==NULL) {

if(temp->parent->data >= value){
temp->parent->left = temp->left;
}
else{
temp->parent->right = temp->left;
}
temp->parent=NULL;
delete temp;
}
}
}

int main(){

tree a;
a.add(1);
a.add(3);
a.add(2);
a.add(8);
a.add(5);
a.add(6);
a.add(7);
a.display(a.root);
a.Search(5,a.root);
a.Delete(8,a.root);
a.display(a.root);
return 0;
}

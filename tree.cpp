#include <iostream>
using namespace std;

// making a node with a data and 3 pointers
struct node{
int x;
node *p;
node *r;
node *l;
public:
node() {
p = NULL;
r = NULL;
l = NULL;
}
};

// making the class btree
class btree{
private:

node* root;

public:

btree(){
// making root to be NULL using a class constructer
root = NULL;
}
// all other functions adding to be a member function

void insert(int data);
void display(node *root);
void deletenode(int key);
void search(int key);
};

// defining the function to insert

void btree::insert(int data) {
	// making a temporary node called temp
		node *temp  = new node;
		node *current = new node;
		current = root;
	// assigning the value of temp equal to data
		temp->x = data;
		temp->p=NULL;
		temp->r=NULL;
		temp->l=NULL;

if (root==NULL){
root = temp;
}
else if(current->x >> data) {
root = current->r;
insert(data);
}

else {
root = current->l;
insert(data); 

}

}

void btree::display(node *root){
node *temp = new node;
temp = root;
if (root == NULL){cout<<"the Tree is empty";}
else{
cout<<temp->x;
temp=temp->l;
display(*temp);
temp=temp->r;
display(*temp);
}
}

int main () {
btree a;
a.insert(1);
a.insert(2);
a.insert(3);
a.insert(4);
a.display();

return 0;
}

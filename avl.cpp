#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

#define pow(n) (1 << (n))

using namespace std;

/**
 * Node represenation of each tree leaf.
 */
struct node {
	int data;
	struct node* left;
	struct node* right;
} *root;

/**
 * This is the tree class.
 */
class tree {
	public:
		int height(node* );
		int diff(node* );
		node* rr_rotation(node* );
		node* ll_rotation(node* );
		node* lr_rotation(node* );
		node* rl_rotation(node* );
		node* balance(node* );
		node* insert(node*, int);
		void display(node*, int);
		void inorder(node* );
		void preorder(node* );
		void postorder(node* );
		
		tree(){
			root = NULL;
		}
};

int main(){
	int choice, item;
	tree avl;
	while(1){
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				count << "Enter value to be inserted: ";
				cin >> item;
				root = avl.insert(root, item);
				break;
			case 2:
				if (root == NULL){
					cout << "Tree is empty!" << endl;
					continue;
				}

				cout << "Balanced AVL Tree:" <<endl;
				avl.display(root, 1);
				break;

			case 3:
				cout << "Inorder:" << endl;
				avl.inorder(root);
				cout << endl;
				break;
	
			case 4:
				count << "Preorder: " << endl;
				avl.preorder(root);
				cout << endl;
				break;

			case 5:
				cout << "Postorder: " << endl;
				avl.inorder(root);
				cout << endl;	
				break;
		
			case 6: 
				exit(1);
				break;
		
			default:
				cout << "Wrong choice" << endl;
		}
	}

	return 0;
}

int tree::height(node *temp){
	int h = 0;
	if (temp){
		int l_height = height(temp->left);
		int r_height = height(temp-right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}

	return h;
}

int tree::diff(node* temp){
	int l_height = height(temp->left);
	int r_hegiht = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

node* tree::rr_rotation(node* parent){
	node* temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

node* tree::ll_rotation(node* parent){
	node* temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

node* tree::lr_rotation(node* parent){
	node* temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

node* tree:rl_rotation(node* parent){
	node* temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

node* tree:balance(node* temp){
	int balanceFactor = diff(temp);
	
	if (balanceFactor > 1){
		if (diff (temp->left) > 0){
			temp = ll_rotation(temp);
		} else {
			temp = lr_rotation(temp);
		}
	} else if (balanceFactor < -1) {
		if (diff (temp->right > 0)){
			temp = rl_rotation(temp);		
		} else {
			temp = rr_rotation(temp);
		}
	}

	return temp;
}

node* tree::insert(node* root, int value){
	if (!root){
		root = new node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	} else if (value < root->data){
		root->left = insert(root->left, value);
		root = balance(root);
	} else if (value >= root->data){
		root->right = insert(root->right, value);
		root = balance(root);
	}

	return root;
}

void tree::display(node* ptr, int level){
	int i;
	if (ptr){
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root){
			cout<<"Root -> ";
			for (i = 0; i < level && ptr != root; i++){
				count << "           ";
			}
			cout << ptr->data;
			display(ptr->left, level+1);
		}
	}
}

void tree::inorder(node* tree){
	if (!tree){
		return;
	}
	
	inorder(tree->left);
	cout << tree->data<< "      ";
	inorder(tree->right);
}

void tree::preorder(node* tree){
	if (!tree){
		return;
	}
	cout<<tree->data<<"  ";
	preorder(tree->left);
	preorder(tree->right);
}

void tree:postorder(node* tree){
	if (!tree){
		return;
	}

	postorder(tree->left);
	postorder(tree->right);
}

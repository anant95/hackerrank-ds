#include<iostream>
using namespace std;
class binaryTreeNode{
	public:
	int data;
	binaryTreeNode* left;
       	binaryTreeNode* right;
	binaryTreeNode(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};
class binaryTree{
public:
	binaryTreeNode* insert(int data, binaryTreeNode* root){
		binaryTreeNode* node = new binaryTreeNode(data);
		if(!root)
			return node;
		binaryTreeNode* point = root;
		binaryTreeNode* prev = NULL;
		while(point){
			prev = point;
			if(point->data >= data)
				point = point->left;
			else
				point = point->right;
		}
		if(prev->data >= data)
			prev->left = node;
		else
			prev->right = node;
		return root;
	}
	void printPreOrder(binaryTreeNode* root){
		binaryTreeNode* point = root;
		if(!point)
			return;
			printf("%d", point->data);
			printPreOrder(point->left);
			printPreOrder(point->right);
		}
	void printInOrder(binaryTreeNode* root){
		binaryTreeNode* point = root;
		if(!point)
			return;
			printInOrder(point->left);
			printf("%d", point->data);
			printInOrder(point->right);
		}
	void printPostOrder(binaryTreeNode* root){
		binaryTreeNode* point = root;
		if(!point)
			return;
			printPostOrder(point->left);
			printPostOrder(point->right);
			printf("%d", point->data);
		}
	int treeHeight(binaryTreeNode* root){
		if(!root)
			return 0;
		int hl = treeHeight(root->left);
	       int hr = treeHeight( root->right);
	       int h =  hl > hr ? hl : hr;
	       return h+1;
	}
};
int main(){
	int n,data;
	scanf("%d", &n);
	binaryTree bt;
	binaryTreeNode* root = NULL;
	while(n--){
		scanf("%d",&data);
		root = bt.insert(data, root);
	}
	bt.printPreOrder(root);
	printf("%d\n",bt.treeHeight(root)-1);
}

#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newnode(int data){
	struct node* NODE = (struct node*)malloc(sizeof(struct node));
	NODE->data = data;
	NODE->left = NULL;
	NODE->right = NULL;
	return NODE;
}
struct node* findLCA(struct node* head, int data1, int data2){
	if(head==NULL) return head;
	if(head->data==data1 | head->data==data2) return head;
	struct node* left = findLCA(head->left,data1,data2);
	struct node* right = findLCA(head->right,data1,data2);
	if(left!=NULL && right!=NULL) return head;
	if(left!=NULL) return left;
	return right;
}
bool findNode(struct node* head,int data){
	if(head==NULL) return false;
	if(head->data==data) return true;
	return findNode(head->left,data) | findNode(head->right,data);
}
int main(){
	struct node* head = newnode(1);
	head->left = newnode(2);
	head->right = newnode(3);
	head->left->left = newnode(4);
	head->left->right = newnode(5);
	head->right->left = newnode(6);
	head->right->right = newnode(7);
	struct node* LCA = findLCA(head,1,2);
	if(LCA&&findNode(head,1)&&findNode(head,2)) printf("%d",LCA->data);
	else printf("NULL");
}

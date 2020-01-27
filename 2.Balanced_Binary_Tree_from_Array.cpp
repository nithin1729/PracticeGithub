#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
void heapify(int A[], int size, int index){
	int largest = index;
	int left = 2*index + 1;
	int right = left + 1;
	if(left<size&&A[left]>A[largest]) largest = left;
	if(right<size&&A[right]>A[largest]) largest = right;
	if(largest!=index){
		A[index] = A[index] ^ A[largest];
		A[largest] = A[index] ^ A[largest];
		A[index] = A[index] ^ A[largest];
		heapify(A,size,largest);
	}
}
void heapsort(int A[], int size){
	int i;
	for(i=size/2-1;i>=0;i--) heapify(A,size,i);
	for(i=size-1;i>0;i--){
		A[i] = A[i] ^ A[0];
		A[0] = A[i] ^ A[0];
		A[i] = A[i] ^ A[0];
		heapify(A,i,0);
	}
}
struct node* newnode(int data){
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->data = data;
	head->left = NULL;
	head->right = NULL;
	return head;
}
struct node* createBalancedBT(int A[], int left, int right){
	if(left>right) return NULL;
	int mid = (left+right)/2;
	struct node* head = newnode(A[mid]);
	head->left = createBalancedBT(A,left,mid-1);
	head->right = createBalancedBT(A,mid+1,right);
	return head;
}
void preorder(struct node* head){
	if(head==NULL) return;
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
}
void inorder(struct node* root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(struct node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
int main(){
	int size;
	scanf("%d",&size);
	int inp[size],i;
	for(i=0;i<size;i++) scanf("%d",&inp[i]);
	heapsort(inp,size);
	//for(i=0;i<size;i++) printf("%d ",inp[i]);
	struct node* root = createBalancedBT(inp,0,size-1);
	printf("Preorder : ");
	preorder(root);
	printf("\n");
	printf("Inorder : ");
	inorder(root);
	printf("\n");
	printf("Postorder : ");
	postorder(root);
}

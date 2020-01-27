#include<stdio.h>
int findPeak(int A[], int left, int right){
	if(left==right) return A[left];
	if(right==left+1){
		if(A[left]>A[right]) return A[left];
		return A[right];
	}
	int mid = (left+right)/2;
	if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]) return A[mid];
	if(A[mid]>A[mid-1]) return findPeak(A,mid,right);
	return findPeak(A,left,mid-1);
}
int main(){
	int size;
	scanf("%d",&size);
	int A[size],i;
	for(i=0;i<size;i++) scanf("%d",&A[i]);
	printf("%d",findPeak(A,0,size-1));
}

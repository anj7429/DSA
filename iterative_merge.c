// iterative merge sort

#include<stdio.h>
void mergesort(int a[],int n){
	int temp[20];
	int i,j,k,l1,l2,u1,u2,size;
	size=1;
	while(size<n){
		l1=0;
		k=0;
		while(l1+size<n){
			l2=l1+size;
			u1=l2-1;
			u2=(l2+size-1<n)?l2+size-1:n-1;
			printf("l1 : %d u1 : %d l2 : %d u2 : %d ",l1,u1,l2,u2);
	        printf("size : %d ",size);
	        printf("\n");
			for(i=l1,j=l2;i<=u1 && j<=u2;){
				if(a[i]<a[j]){
					temp[k]=a[i];
					i++;
					k++;
				}
				else{
					temp[k]=a[j];
					j++;
					k++;
				}
			}
			while(i<=u1){
				temp[k++]=a[i++];
			}
			while(j<=u2){
				temp[k++]=a[j++];
			}
			l1=u2+1;
		}
		i=l1;
		while(i<n){
			temp[k++]=a[i++];
		}
		for(i=0;i<n;i++){
		a[i]=temp[i];
	    }
//	    printf("\n");
//	    for(int i=0;i<n;i++){
//	    	printf("%d ",a[i]);
//		}
//		printf("\n");
	    size=size*2;
		}
}
void display(int a[],int n){
	printf("Sorted array look like: \n");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("\nEnter array elements: ");
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergesort(a,n);
	display(a,n);
	return 0;
}

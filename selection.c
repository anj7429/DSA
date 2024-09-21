// selection sort
#include<stdio.h>
void selection(int a[],int n);
void bubblesort(int a[],int n);
void insertion(int a[],int n);
void display(int a[],int n);
int main(){
	int n;
	int i;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	selection(a,n);
    bubblesort(a,n);
    insertion(a,n);
	return 0;	
}
void selection(int a[],int n){
	printf("Array after applying selection sort: \n");
	int min,j;
	for(int i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(min!=i){
			int temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
		
	}
	display(a,n);
}

void bubblesort(int a[],int n){
	printf("Array after applying bubble sort: \n");
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			else{
				continue;
			}
		}
	}
	display(a,n);
	
}
void insertion(int a[],int n){
	printf("Array after insertion sort: \n");
	int j;
	for(int i=1;i<n-1;i++){
		int temp=a[i];
		for(j=i;j>0;j--){
			if(a[j]<a[j-1]){
				a[j]=a[j-1];
			}
			else{
				break;
			}
		}
		a[j]=temp;
	}
	display(a,n);
}
void display(int a[],int n){
	int i;
	for( i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

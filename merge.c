#include<stdio.h>
void merge(int a[],int lb1,int ub1,int lb2,int ub2){
    int i=lb1;
    int j=lb2;
    int k=0;
    int temp[ub2-lb1+1];
    while(i<=ub1 && j<=ub2){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=ub1){
        temp[k++]=a[i++];
    }
    while(j<=ub2){
        temp[k++]=a[j++];
    }
    for(i=lb1,k=0;i<=ub2;i++,k++){
        a[i]=temp[k];
    }
}
void mergesort(int a[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,mid+1,ub);
    }
}
void display(int a[],int n){
    printf("Sorted array is \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    display(a,n);
    return 0;
}
#include<stdio.h>
int binary(int a[],int start,int end,int el){
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==el){
            return mid;
        }
        else if(a[mid]<el){
            return binary(a,mid+1,end,el);
        }
        else{
            return binary(a,start,mid-1,el);
        }
    }
    return -1;
}
int main(){
    int n,el;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&el);
    int z=binary(a,0,n-1,el);
    if(z==-1){
        printf("Element not found");
    }
    else{
        printf("Element found at index %d ",z);
    }
    return 0;
}
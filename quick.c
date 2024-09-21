#include<stdio.h>
void partition(int a[],int lb,int ub,int *pj){
    int i=lb;
    int j=ub;
    int temp;
    int x=a[lb];
    while(i<j){

        while(i<ub && a[i]<=x){
            i++;
        }

        while(x<a[j]){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[lb]=a[j];
    a[j]=x;
    *pj=j;
}
void quick(int a[],int lb,int ub){
    int j;
    if(lb<ub){
        partition(a,lb,ub, &j);
        quick(a,lb,j);
        quick(a,j+1,ub);

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
    quick(a,0,n-1);
    display(a,n);
    return 0;
}
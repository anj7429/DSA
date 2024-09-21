#include<stdio.h>
void shell(int a[],int n){
    // for(int gap=n/2;gap>0;gap=gap/2){
    for(int gap=4;gap>0;gap--){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i=i-gap){
                if(a[i+gap]>=a[i]){
                    break;
                }
                else{
                    // swap(a[i-gap],a[i]);
                    int temp=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    shell(a,n);
    return 0;
}
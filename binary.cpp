#include<iostream>
using namespace std;
int binary(int a[],int start,int end,int el){
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==el){
            return mid;
        }
        else if(a[mid]<el){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;

}
int main(){
    int n,el;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be searched : ";
    cin>>el;
    int z=binary(a,0,n-1,el);
    if(z==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index "<<z<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
int linear(int a[],int n,int el){
    for(int i=0;i<n;i++){
        if(a[i]==el){
            return i;
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
    int z=linear(a,n,el);
    if(z==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at index "<<z<<endl;
    }
    return 0;
}
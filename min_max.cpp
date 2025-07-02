// time complexity is 3n/2 (optimised)
#include<iostream>
using namespace std;
void min_max(int a[],int n){
    int min=a[0];
    int max=a[0];
    // int flag=0;
    int p=0,q=0;
    for(int i=1;i<=n-2;i+=2){
        if(a[i]<a[i+1]){
            if(min>a[i]){
                min=a[i];
                p=i;
            }
            if(max<a[i+1]){
                max=a[i+1];
                q=i+1;
            }
        }
        else{
            if(a[i]>max){
                max=a[i];
                q=i;
            }
            if(a[i+1]<min){
                min=a[i+1];
                p=i+1;
            }
        }
    }
    if(a[0] < min){
        min = a[0];
        p = 0;
    }
    if(a[0] > max){
        max = a[0];
        q = 0;
    }
    // for even 
    if(n%2==0){
        if(a[n-1]<min){
            min=a[n-1];
            p=n-1;
        }
        if(a[n-1]>max){
            max=a[n-1];
            q=n-1;
        }
    }
    cout<<"index: "<<p<<" Minimum: "<<min<<endl;
    cout<<"index: "<<q<<" Maximum: "<<max<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    min_max(a,n);
    return 0;
}
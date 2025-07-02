#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void insertion(int a[],int n){
    for(int j=1;j<n;j++){
        int temp=a[j];
        int i=j-1;
        while(i>=0 && a[i]>temp){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=temp;
    }
}
void display(int a[],int n){
    cout<<endl<<endl<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    srand(time(0));
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
        cout<<a[i]<<" ";
    }
    clock_t start=clock();
    insertion(a,n);
    display(a,n);
    clock_t end=clock();
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Start time : "<<start<<endl<<" End time: "<<end<<endl;
    cout<<"Time taken by an algorithm is "<<time<<endl;
    return 0;
}
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void display(int a[],int n){
    cout<<endl<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void max_heapify(int a[],int n,int i){
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        max_heapify(a,n,largest);
    }
}
void heapsort(int a[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        max_heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        max_heapify(a,i,0);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    srand(time(0));
    int a[n];
    cout<<"Array elements: ";
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
        cout<<a[i]<<" ";
    }
    clock_t start=clock();
    heapsort(a,n);
    display(a,n);
    clock_t end=clock();
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Start time : "<<start<<endl<<"End time: "<<end<<endl;
    cout<<"Time taken by an algorithm is "<<time<<endl;
    return 0;
}
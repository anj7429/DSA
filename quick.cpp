#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int partition(int a[],int lb,int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(a[start],a[end]);
        }
    }
    swap(a[lb],a[end]);
    return end;
}
void quicksort(int a[],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
void display(int a[],int n){
    cout<<endl<<"Sorted array look like: ";
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
    quicksort(a,0,n-1);
    display(a,n);
    clock_t end=clock();
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Start time : "<<start<<endl<<"End time: "<<end<<endl;
    cout<<"Time taken by an algorithm is "<<time<<endl;
    return 0;
}
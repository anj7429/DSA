#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void selection(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(a[i],a[min]);
        }
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
    selection(a,n);
    display(a,n);
    clock_t end=clock();
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Start time : "<<start<<endl<<" End time: "<<end<<endl;
    cout<<"Time taken by an algorithm is "<<time<<endl;
    return 0;
}
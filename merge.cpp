#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void merge(int a[],int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    int l[n1];
    int ri[n2];
    for(int i=0;i<n1;i++){
        l[i]=a[p+i];
    }
    for(int j=0;j<n2;j++){
        ri[j]=a[q+1+j];
    }
    int i=0,j=0,k=p;
    while (i < n1 && j < n2) {
        if (l[i] <= ri[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = ri[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = ri[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int p,int r){
    int q;
    if(p<r){
        q = p+(r - p)/2; 
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
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
    mergesort(a,0,n-1);
    display(a,n);
    clock_t end=clock();
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Start time : "<<start<<endl<<" End time: "<<end<<endl;
    cout<<"Time taken by an algorithm is "<<time<<endl;
    return 0;
}
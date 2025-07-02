#include<iostream>
#include<cmath>
using namespace std;
int knapsack(int p[],int w[],int W,int n){
    int i,wt;
    int k[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int wt=0;wt<=W;wt++){
            if(i==0 || wt==0){
                k[i][wt]=0;
            }
            else if(w[i-1]<=wt){
                k[i][wt]=max((p[i-1]+k[i-1][wt-w[i-1]]),k[i-1][wt]);
            }
            else{
                k[i][wt]=k[i-1][wt];
            }
        }
    }
    return k[n][W];
}
int main(){
    int n,W;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Enter the weight of knapsack: ";
    cin>>W;
    int p[n],w[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the profit , weight of item"<<i+1;
        cin>>p[i];
        cin>>w[i];
    }
    cout<<knapsack(p,w,W,n);
    return 0;
}
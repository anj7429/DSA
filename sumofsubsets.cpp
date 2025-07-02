#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>sumofsubsets(vector<int>&nums,int tar){
    vector<vector<int>>ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        vector<int>temp;
        for(int j=i;j<n;j++){
            temp.push_back(nums[j]);
            sum+=nums[j];
            if(sum==tar){
                ans.push_back(temp);
            }
        }
    }
    return ans;
}
int main(){
    int n,tar,val;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter target: ";
    cin>>tar;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>val;
        nums.push_back(val);
    }
    vector<vector<int>>a=sumofsubsets(nums,tar);
    if(a.empty()){
        cout<<"No subsets found!";
    }
    else{
    for(const vector<int>&subset:a){
        for(const int i:subset){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}

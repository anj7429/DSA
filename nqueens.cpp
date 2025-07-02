#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool issafe(vector<string>&board,int row, int col,int n){
	// horizontally safe
	for(int j=0;j<n;j++){
		if(board[row][j] =='Q'){
			return false;
		}
	}
	// vertically safe
	for(int i=0;i<n;i++){
		if(board[i][col]=='Q'){
			return false;
		}
	}
	// upper left diagonal
	for(int i=row,j=col;i>=0 && j>=0; i--,j--){
		if(board[i][j]=='Q'){
			return false;
		}
	}
	// upper right diagonal
	for(int i=row,j=col;i>=0 && j<n; i--,j++){
		if(board[i][j]=='Q'){
			return false;
		}
	}
	return true;	
}
void nqueens(vector<string>&board,int n,int row,vector<vector<string> >&ans){
    if(row==n){
        ans.push_back(board);
        return;
    }
	for(int j=0;j<n;j++){
		if(issafe(board,row,j,n)){
			 board[row][j]='Q';
			 nqueens(board,n,row+1,ans);
			 board[row][j]='.';
		}
	}
}
vector<vector<string> >queen_placement(int n){
	vector<string>board(n,string(n,'.'));
	vector<vector<string> >ans;
	nqueens(board,n,0,ans);
	return ans;
}
int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	vector<vector<string> >a=queen_placement(n);
	for(const vector<string>&board:a){
	    for(const string &row:board){
	        cout<<row<<endl;
	    }
	    cout<<endl;
	}
	cout<<endl;
	return 0;
}

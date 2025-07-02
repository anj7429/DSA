#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int v;
    vector<vector<int>>adj;
    public:
    Graph(int ver){
        v=ver;
        adj.resize(ver);
    }
    void add_edge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfsrec(vector<bool>&visited,int src){
        visited[src]=true;
        cout<<src<<" ";
        for(int i:adj[src]){
            if(visited[i]==false){
                dfsrec(visited,i);
            }
        }  
    }
    void dfs(int src){
        vector<bool>visited(v,false);
        dfsrec(visited,src);
    }
};
int main(){
    int v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    Graph g(v);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(5,6);
    g.dfs(5);
    return 0;
}
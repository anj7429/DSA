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
    void bfs(int src){
        vector<bool>visited(v,false);
        visited[src]=true;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int curr=q.front();
            cout<<curr<<" ";
            q.pop();
            for(int i:adj[curr]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
};
int main(){
    int v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    Graph g(v);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,5);
    g.add_edge(2,6);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.bfs(1);
    return 0;
}
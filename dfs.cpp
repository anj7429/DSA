#include<iostream>
#include<stack>
#include<vector>
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
    void dfsrec(vector<bool>&visited,int s){
        visited[s]=true;
        cout<<s<<" ";
        for(int i:adj[s]){
            if(visited[i]==false){
                dfsrec(visited,i);
            }
        }
    }
    void dfs(int s){
        vector<bool>visited(v,false);
        dfsrec(visited,s);
    }
};
int main(){
    Graph g(7);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,5);
    g.add_edge(2,6);
    g.add_edge(1,3);
    g.add_edge(1,4);
    cout<<"DFS traversal: "<<endl;
    g.dfs(1);
    return 0;
}

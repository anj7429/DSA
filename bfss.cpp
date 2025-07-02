#include<iostream>
#include<queue>
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
    void bfs(int src){
        vector<bool>visited(v,false);
        queue<int>q;
        visited[src]=true;
        q.push(src);
        while(!q.empty()){
            int curr=q.front();
            cout<<curr<<" ";
            q.pop();
            for(int n:adj[curr]){
                if(!visited[n]){
                    visited[n]=true;
                    q.push(n);
                }
            }
        }
    }
};
int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph g(vertices);

    cout << "Enter each edge (u v):" << endl;
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;
    
    cout << "BFS traversal starting from node " << start << ": ";
    g.bfs(start);
    cout << endl;

    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source,dest,weight;
};
bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}
// int findparent(int v,int *parent){
//     if(parent[v]==v){
//         return v;
//     }
//     return findparent(parent[v],parent);
// }
int findparent(int v, int *parent){
    if(parent[v] != v)
        parent[v] = findparent(parent[v], parent); // Path compression
    return parent[v];
}
void kruskal(Edge *input,int n,int E){
    if(E < n - 1){
        cout << "MST not possible: not enough edges." << endl;
        return;
    }    
    sort(input,input+E,compare);
    Edge *output=new Edge[n-1];
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count=0;    // how many times we have added in mst
    int i=0;        // tells us about the current edge
    while(count!=n-1){
        Edge current_edge=input[i];
        // check if we can add the currentedge in mst or not
        int sourceparent=findparent(current_edge.source,parent);
        int destparent=findparent(current_edge.dest,parent);
        if(sourceparent!=destparent){
            output[count]=current_edge;
            count++;
            parent[sourceparent]=destparent;
        }
        i++;
    }
    int weigh=0;
    cout<<"MINIMUM SPANNING TREE USING KRUSKALS ALGORITHM: ";
    for(int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest)
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        else
        cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        weigh+=output[i].weight;
    }
    cout<<"Total weight of mst is "<<weigh<<endl;
    delete[] output;
    delete[] parent;
}
int main(){
    int n,E;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>E;
    Edge *input=new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskal(input,n,E);
    delete[] input;
    return 0;
}
#include "../headers/main.h"

int main(){
    Graph G = createGraph();
    vector<Vertex> endList;
    vector<int> scc;

    endList = AlgoMethod::DfsEndList(G);
    Graph Gt = G.T();
    scc = AlgoMethod::DfsStrongComponent(Gt, endList);
    cout << G;
    cout << Gt;
}

Graph createGraph(){
    int n;
    int m;

    cin >> n;
    cin >> m;

    Graph G(n);


    for(int i = 0 ; i < m ; i++){
        int u;
        int v;

        cin >> u >> v;
        G.AddEdge(u - 1, v - 1);
    }

    return G;
}

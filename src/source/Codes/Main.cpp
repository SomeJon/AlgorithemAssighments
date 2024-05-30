#include "../headers/main.h"

int main(){
    Graph G = createGraph();


    cout << G;
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
        G.AddEdge(u, v);
    }

    return G;
}


void Visit(Vertex u, vector<)
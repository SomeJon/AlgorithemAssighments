#include "main.h"

int main(){
    try{
    Graph G = createGraph();
    Graph GSuper = AlgoMethod::GetSuperGraph(G);

    cout << GSuper;
    }
    catch(runtime_error& e){
        cout << e.what();
        std::exit(1);
    }
}

Graph createGraph(){
    int n;
    int m;

    cin >> n;
    cin >> m;

    Graph G = Graph::MakeEmptyGraph(n);


    for(int i = 0 ; i < m ; i++){
        int u;
        int v;

        cin >> u >> v;
        G.AddEdge(u - 1, v - 1);
    }

    return G;
}

#include "main.h"

//At any point, if an int is asked for a point, its value should be -1 after receiving the value,
// program only works with points starting at 0, if a point is being print, it is printed with a +1
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

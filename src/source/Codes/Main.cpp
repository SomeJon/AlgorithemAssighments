#include "../headers/main.h"

int main(){
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

    cout << G;
}
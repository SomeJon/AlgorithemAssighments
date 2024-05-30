#include "../headers/AlgoMethod.h"

vector<Vertex> AlgoMethod::DfsEndList(Graph G) {
    vector<eColor> Color;
    vector<Vertex> d;
    vector<Vertex> V = G.getVertexes();
    int n = V.size();

    for(int i = 0 ; i < n ; i++){
        Color.push_back(White);
    }

    for(int i = 0 ; i < n ; i++) {
        Vertex u = V.at(i);
        if (Color[vertex(u)] == White) { //Visit
            Color[vertex(u)] = Gray;
            list<Edge<Vertex>> adjacent = u.getAdjacent();
            for(auto & edge : adjacent){
                Vertex v = edge.getRight();

            }
        }
    }
}
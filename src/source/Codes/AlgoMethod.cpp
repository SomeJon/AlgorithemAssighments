#include "../headers/AlgoMethod.h"

vector<Vertex> AlgoMethod::DfsEndList(Graph& G) {
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
            AlgoMethod::VisitEndList(u, Color, d);
        }
    }

    return d;
}

void AlgoMethod::VisitEndList(Vertex& u, vector<AlgoMethod::eColor>& Color, vector<Vertex>& d) {
    list<Edge<Vertex>> adjacent = u.getAdjacent();
    for(auto & edge : adjacent){
        Vertex v = edge.getRight();
        if(Color[vertex(v)] == White){
            Color[vertex(v)] = Gray;
            VisitEndList(v, Color, d);
        }
    }
    Color[vertex(u)] = Black;
    d.push_back(u);
}

vector<int> AlgoMethod::DfsStrongComponent(Graph& GT, vector<Vertex>& endList) {
    vector<eColor> Color;
    vector<int> stronglyConnectedComponent;
    vector<Vertex> V = endList;
    int id = 0;
    int n = V.size();

    for(int i = 0 ; i < n ; i++){
        Color.push_back(White);
    }

    for (int i = 0  ; i < n ;  i++) {
        stronglyConnectedComponent.push_back(0);
    }

    for(int i = 0 ; i < n ; i++) {
        Vertex u = V.at(i);
        if (Color[vertex(u)] == White) { //Visit
            Color[vertex(u)] = Gray;
            AlgoMethod::VisitStrongComponent(u, Color, stronglyConnectedComponent, id);
            id++;
        }
    }

    return stronglyConnectedComponent;
}

void AlgoMethod::VisitStrongComponent
            (Vertex &u, vector<eColor> &Color, vector<int> &idArray, int id) {
    list<Edge<Vertex>> adjacent = u.getAdjacent();
    for(auto & edge : adjacent){
        Vertex v = edge.getRight();
        if(Color[vertex(v)] == White){
            Color[vertex(v)] = Gray;
            VisitStrongComponent(v, Color, idArray, id);
        }
    }
    Color[vertex(u)] = Black;
    idArray.at(vertex(u)) = id;
}
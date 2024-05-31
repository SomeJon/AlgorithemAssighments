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
        Vertex& u = V.at(i);
        if (Color[vertex(u)] == White) { //Visit
            Color[vertex(u)] = Gray;
            AlgoMethod::VisitEndList(u, Color, d);
        }
    }

    return d;
}

void AlgoMethod::VisitEndList(Vertex& u, vector<AlgoMethod::eColor>& Color, vector<Vertex>& d) {
    list<Adjacent<Vertex>> adjacent = u.getAdjacent();
    for(Adjacent<Vertex> & adj : adjacent){
        Vertex v = adj.getAdj();
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
    list<Adjacent<Vertex>> adjacent = u.getAdjacent();
    for(Adjacent<Vertex> & adj : adjacent){
        Vertex v = adj.getAdj();
        if(Color[vertex(v)] == White){
            Color[vertex(v)] = Gray;
            VisitStrongComponent(v, Color, idArray, id);
        }
    }
    Color[vertex(u)] = Black;
    idArray.at(vertex(u)) = id;
}

Graph AlgoMethod::GetSuperGraph(Graph &G) {
    Graph Gt = G.T();
    vector<Vertex> endList = DfsEndList(G);
    vector<int> IdComp = DfsStrongComponent(Gt, endList);
    vector<Vertex> V = G.getVertexes();
    int numOfComponent = *std::max_element
            (IdComp.begin(), IdComp.end()) + 1;
    vector<list<Vertex>> components = createComponentArray
            (IdComp, V, numOfComponent);


    Graph GSuper = Graph::MakeEmptyGraph(numOfComponent);
    vector<int> lastVisit(numOfComponent);
    for(int i = 0 ; i < numOfComponent ; i++)
        lastVisit[i] = i;

    int currId = 0;
    for(list<Vertex>& comp : components){
        for(Vertex& u : comp){
            list<Adjacent<Vertex>> adjacent = u.getAdjacent();
            for(Adjacent<Vertex> & adj : adjacent){
                Vertex v = adj.getAdj();
                int adjId = IdComp[vertex(v)];
                if(adjId != currId && lastVisit[adjId] != currId){
                    GSuper.AddEdge(currId, adjId);
                    lastVisit[adjId] = currId;
                    //This trick uses the fact that the components are returned
                    //in a topological order, meaning, after finishing a comp, no other
                    //strong comp would have an edge to the finished comp
                }
            }
        }
        currId++;
    }

    return GSuper;
}

vector<list<Vertex>> AlgoMethod::createComponentArray(vector<int> id, vector<Vertex> V, int size) {
    vector<list<Vertex>> Components(size);

    for(Vertex& u : V){
        Components[id[vertex(u)]].push_back(u);
    }

    return Components;
}
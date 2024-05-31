

#ifndef ALGORITHEMASSIGHMENTS_ALGOMETHOD_H
#define ALGORITHEMASSIGHMENTS_ALGOMETHOD_H
#include "Vertex.h"
#include "Graph.h"
#include "Base.h"

class AlgoMethod{
private:
    enum eColor{
        White,
        Gray,
        Black
    };
public:
    static vector<Vertex> DfsEndList(Graph& G);
    static vector<int> DfsStrongComponent(Graph& GT, vector<Vertex>& d);
    static Graph GetSuperGraph(Graph& G);

private:
    static void VisitEndList(Vertex& v, vector<eColor>& Color, vector<Vertex>& endList);
    static void VisitStrongComponent(Vertex& v, vector<eColor>& Color, vector<int>& idArray, int id);
    static int vertex(const Vertex& u)     {return u.getPoint();}
    static vector<list<Vertex>> createComponentArray(vector<int> id, vector<Vertex> V, int size);

};

#endif //ALGORITHEMASSIGHMENTS_ALGOMETHOD_H



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

private:
    static void VisitEndList(Vertex& v, vector<eColor>& Color, vector<Vertex>& endList);
    static void VisitStrongComponent(Vertex& v, vector<eColor>& Color, vector<int>& idArray, int id);
    static int vertex(const Vertex& u)     {return u.getPoint();}

};

#endif //ALGORITHEMASSIGHMENTS_ALGOMETHOD_H

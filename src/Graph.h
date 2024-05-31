#ifndef __GRAPH_H
#define __GRAPH_H

#include "Base.h"
#include "Vertex.h"
#include "Edge.h"


class Graph {
private:
	vector<Vertex> V;
	list<Edge<Vertex>> E;

public:
	vector<Vertex> getVertexes() { return V; }
	list<Edge<Vertex>> getEdges() { return E; }

	explicit Graph(int n) {
		for (int i = 0  ; i < n ;  i++) {
			Vertex add = Vertex(i);
			V.push_back(add);
		}
	}

	static Graph MakeEmptyGraph(int n) {
		return Graph(n);
	}

	bool isAdjacent(int u, int v) {
		bool ret = false;

		try {
			list<Adjacent<Vertex>> listToSearch = V.at(u - 1).getAdjacent();
			ret = (find(listToSearch.begin(), listToSearch.end(),
                        Vertex(v)) != listToSearch.end());
		}
		catch (...) {
            throw runtime_error("invalid input");
		}

		return ret;
	}

	list<Adjacent<Vertex>> GetAdjList(int u) {
        list<Adjacent<Vertex>> ret;
		
		try {
			ret = V.at(u - 1).getAdjacent();
		}
		catch (...) {
            throw runtime_error("invalid input");
		}

		return ret;
	}

	void AddEdge(int u, int v) {
		try {
            if(u == v){
                throw runtime_error("invalid input");
            }

            Vertex& thisU = V.at(u);
            Vertex& thisV = V.at(v);
			thisU.addEdge(thisV);
            Edge<Vertex> toAdd(thisU, thisV);
            E.push_back(toAdd);
		}
		catch (...) {
            throw runtime_error("invalid input");
		}
	}

	void RemoveEdge(int u, int v) {
		try {
			V.at(u - 1).removeEdge(Vertex(v));
            for(Edge<Vertex> edge : E){
                if(edge.getLeft().getPoint() == u && edge.getRight().getPoint() == v){
                    E.remove(edge);
                    break;
                }
            }
		}
		catch (...) {
            throw runtime_error("invalid input");
		}
	}

    Graph T(){
        Graph reversed = Graph::MakeEmptyGraph((int)V.size());
        for(auto & edge : E){
            Vertex u = edge.getLeft();
            Vertex v = edge.getRight();
            reversed.AddEdge(v.getPoint(), u.getPoint());
        }

        return reversed;
    }

	virtual ~Graph() = default;

    friend std::ostream& operator<<(std::ostream& os, const Graph& g)
    {
        int n = g.V.size();
        int m = g.E.size();

        os << n  << " " << m;
//        for(int i = 0 ; i < n ; i++)
//            os << g.V.at(i) << " ";
//        os << "\n";
//
//        _List_const_iterator<Edge<Vertex>> curr = g.E.begin();
//        for(int i = 0 ; i < m ; i++) {
//            os << *curr;
//            curr++;
//        }

        return os;
    }
};


#endif
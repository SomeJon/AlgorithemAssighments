#ifndef __GRAPH_H
#define __GRAPH_H

#pragma once
#include "Base.h"
#include "Vertex.h"
#include "Edge.h"


class Graph {
private:
	std::vector<Vertex&> V;
	std::list<Edge&> E;

public:
	std::vector<Vertex&> getVertexes() { return V; }
	std::list<Edge&> getEdges() { return E; }

	Graph(int n) {
		for (int i; i < n; i++) {
			Vertex& add = *(new Vertex(i));
			V.push_back(add);
		}
	}

	Graph MakeEmptyGraph(int n) {
		return Graph(n);
	}

	bool IsAdjecnt(int u, int v) {
		bool ret = false;

		try {
			std::list<Edge> listToSearch = V.at(u - 1).getAdjList();
			ret = (std::find(listToSearch.begin(), listToSearch.end(), v) != listToSearch.end());
		}
		catch (...) {
			throw "Invalid Input!";
		}

		return ret;
	}

	std::list<Edge> GetAdjList(int u) {
		std::list<Edge> ret;
		
		try {
			ret = V.at(u - 1).getAdjList();
		}
		catch (...) {
			throw "Invalid Input!";
		}

		return ret;
	}

	void AddEdge(int u, int v) {
		Vertex thisU;
		Vertex thisV;

		try {
			thisU = V.at(u - 1);
			thisV = V.at(v - 1);
			thisU.addEdge(thisV);
		}
		catch (...) {
			throw "Invalid Input!";
		}
	}

	void RemoveEdge(int u, int v) {
		try {
			std::list<Edge> listToSearch = V.at(u - 1).getAdjList();
			listToSearch.erase(std::find(listToSearch.begin(), listToSearch.end(), v));
		}
		catch (...) {
			throw "Invalid Input!";
		}
	}

	virtual ~Graph() = default;
};


#endif
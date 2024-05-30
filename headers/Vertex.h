#ifndef __VERTEX_H
#define __VERTEX_H

#include "Base.h"
#include "Edge.h"

class Vertex {
private:
	int m_Point;
	std::list<Edge> m_Adjacent;

public:
	int getPoint()									{ return m_Point;		}
	void setPoint(int i_PointId)					{ m_Point = i_PointId;	}
	std::list<Edge> getAdjList()			{ return m_Adjacent;	}
	void setAdjList(std::list<Edge> i_List) { m_Adjacent = i_List;	}
	Edge addEdge(Vertex i_Adjacent) {
		Edge toAdd(*this, i_Adjacent);
		m_Adjacent.push_back(toAdd);
		return toAdd;
	}

	Vertex() = default;

	Vertex(int i_PointId) {
		setPoint(i_PointId);
		m_Adjacent = std::list<Edge>();
	}

	bool operator==(Vertex i_Other) {
		return i_Other.m_Point == m_Point;
	}

	bool operator!=(Vertex i_Other) {
		return i_Other.m_Point != m_Point;
	}

	bool operator==(int i_Other) {
		return i_Other == m_Point;
	}

	bool operator!=(int i_Other) {
		return i_Other != m_Point;
	}
};

#endif
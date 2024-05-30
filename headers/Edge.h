#ifndef __EDGE_H
#define __EDGE_H

#include "Base.h"
#include "Vertex.h"

class Edge {
private:
	Vertex m_Left;
	Vertex m_Right;

public:
	Vertex& getLeft()				{ return m_Left;	}
	void setLeft(Vertex& i_Left)	{ m_Left = i_Left;	}
	Vertex& getRight()				{ return m_Right;	}
	void setRight(Vertex& i_Right)	{ m_Right = i_Right; }

	Edge(Vertex& i_Left, Vertex& i_Right){
		setLeft(i_Left);
		setRight(i_Right);
	}

	bool operator==(int i_Other) {
		return i_Other == m_Right.getPoint();
	}

	bool operator!=(int i_Other) {
		return i_Other != m_Right.getPoint();
	}
};

#endif
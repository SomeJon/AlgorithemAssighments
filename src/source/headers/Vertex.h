#ifndef __VERTEX_H
#define __VERTEX_H

#include "Base.h"
#include "Edge.h"

class Vertex {
private:
	const int m_Point;
	list<Edge<Vertex>> m_Adjacent;

public:
    [[nodiscard]] int getPoint() const {
        return m_Point;
    }

    [[nodiscard]] list<Edge<Vertex>> getAdjacent() const {
        return m_Adjacent;
    }

    explicit Vertex(int i_point) : m_Point(i_point) {}

    Edge<Vertex> addEdge(Vertex& i_Adjacent) {
		Edge<Vertex> toAdd(*this, i_Adjacent);
		m_Adjacent.push_back(toAdd);
		return toAdd;
	}

	bool operator==(const Vertex& i_Other) const {
		return i_Other.m_Point == m_Point;
	}

	bool operator!=(const Vertex& i_Other) const {
		return i_Other.m_Point != m_Point;
	}

	bool operator==(int i_Other) const {
		return i_Other == m_Point;
	}

	bool operator!=(int i_Other) const {
		return i_Other != m_Point;
	}

    friend std::ostream& operator<<(std::ostream& os, const Vertex& v)
    {
        os << (v.m_Point + 1);

        return os;
    }
};

#endif
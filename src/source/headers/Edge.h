#ifndef __EDGE_H
#define __EDGE_H

#include "Base.h"

template<class T>
class Edge{
private:
    T& m_Left;
	T& m_Right;

public:
    [[nodiscard]] const T &getLeft() const {
        return m_Left;
    }

    void setLeft(const T &i_left) {
        m_Left = i_left;
    }

    [[nodiscard]] const T &getRight() const {
        return m_Right;
    }

    void setRight(const T &i_right) {
        m_Right = i_right;
    }


    Edge(T& i_Left, T& i_Right): m_Left(i_Left), m_Right(i_Right){
	}

	bool operator==(int i_Other) {
		return static_cast<bool>(i_Other == m_Right.getPoint());
	}

	bool operator!=(int i_Other) {
        return static_cast<bool>(i_Other != m_Right.getPoint());
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << e.m_Left << " " << e.m_Right << "\n";

        return os;
    }
};

#endif
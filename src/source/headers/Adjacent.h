#ifndef ALGORITHEMASSIGHMENTS_ADJACENT_H
#define ALGORITHEMASSIGHMENTS_ADJACENT_H

template<class T>
class Adjacent{
private:
    T& m_Adj;
public:
    explicit Adjacent(T &i_adj) : m_Adj(i_adj) {}

    T &getAdj() const {
        return m_Adj;
    }

    bool operator==(const Adjacent& i_Other) const {
        return i_Other.m_Adj == m_Adj;
    }

    bool operator!=(const Adjacent& i_Other) const {
        return i_Other.m_Adj != m_Adj;
    }

    bool operator==(const T& i_Other) const {
        return i_Other == m_Adj;
    }

    bool operator!=(const T& i_Other) const {
        return i_Other != m_Adj;
    }
};
#endif //ALGORITHEMASSIGHMENTS_ADJACENT_H

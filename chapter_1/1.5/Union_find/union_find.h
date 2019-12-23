#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

#include <iostream>

using namespace std;

class Union_find
{
public:
    Union_find(int N)               //以整数标识（0到N-1）初始化N个触点
    : _count(N)
    , _id(new int[N])
    , _N(N)
    {
        for (int i = 0; i < N; ++i) _id[i] = i; //此时的id索引数组表示N个连通分量，每个触点表示一个连通分量 
    }

    void set_union(int p, int q)        //在p和q之间添加一条连接
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;

        _id[pRoot] = qRoot;
        _count--;
    }

    int find(int p)             //得出触点p所在的分量的标识符
    {
        int ID = _id[p];
        while (ID != p)
            ID = _id[ID];
        return ID;
    }

    bool connected(int p, int q)           //如果p，q属于同一个分量，则p，q是连接的
    {
        return find(p) == find(q);
    }

    int count(void) {   return _count;  }           //返回连通分量的数量

private:
    int * _id;          
    int _count;
    int _N;
};












#endif
#ifndef __Graph_h__
#define __Graph_h__
#include "authority.h"

#define UndeterminedVertex 65535        /* ∞设为双字节无符号整数的最大值65535*/
#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,顶点存储为整型，没有什么意义 */
typedef double WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef class EdgeNode *Edge;
class EdgeNode{
public:
    Vertex origin, destinction;      /* 边连接的两个顶点 */
    WeightType Weight;  /* 边权重 */
};

/* 用邻接矩阵定义的图 */
class GraphRect{
public:
    int vertexNum;  /* 顶点数 */
    int edgeNum;  /* 边数   */
    vector<vector<Vertex>> Rect; /* 邻接矩阵 */
    vector<DataType>Data;      /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */

    //初始化一个图,默认100个顶点
    GraphRect(){
        this->vertexNum=MaxVertexNum;
        this->edgeNum=0;
        vector<Vertex>temp;
        temp.resize(vertexNum,UndeterminedVertex);
        this->Rect.resize(vertexNum,temp);
    }

    //指定顶点个数初始化一个图
    GraphRect(Vertex x){
        this->vertexNum=x;
        this->edgeNum=0;
        vector<Vertex>temp;
        temp.resize(vertexNum,UndeterminedVertex);
        this->Rect.resize(vertexNum,temp);
    }

    //插入一条有序边
    void InsertOrderedEdge( Edge E )
    {
        /* 插入边 <vertex1, vertex2> */
        this->Rect[E->origin][E->destinction] = E->Weight;
    }

    //插入一条无序边
    void InsertUnorderedEdge( Edge E )
    {
        this->Rect[E->origin][E->destinction] = E->Weight;
        this->Rect[E->destinction][E->origin] = E->Weight;
    }
};

/* 不作链表头的邻接点结点的定义 */
class GraphCommonNode{
public:
    Vertex index=-1;        /* 这个邻接点的下标 */
    GraphCommonNode* Next=NULL;    /* 指向下一个邻接点的指针 */
    WeightType Weight=-1;  /* 两个点之间的边的权重 */
    GraphCommonNode(){
        this->index=-1;
        this->Next=NULL;
        this->Weight=-1;
    }
};

/* 作链表头的顶点结点的定义 */
//多一个存储顶点的数据
class GraphHeadNode{
public:
    GraphCommonNode* FirstNode;/* 边表头指针 */
    DataType Data;            /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
    GraphHeadNode(){
        this->FirstNode=NULL;
    }
};

/* 用邻接表定义的图 */
class GraphList{
public:
    int vertexNum;     /* 顶点数 */
    int edgeNum;     /* 边数   */
    vector<GraphHeadNode> GraphHeadNodeVector;  /* 邻接表 */

    //创建一个没有边的图,默认100个顶点
    GraphList(){
        this->vertexNum=MaxVertexNum;
        this->edgeNum=0;
        for(int i=0;i<vertexNum;i++){
            GraphHeadNodeVector[i].FirstNode=NULL;
        }
    }

    //创建一个没有边的图,指定顶点个数
    GraphList(int x){
        this->vertexNum=x;
        this->edgeNum=0;
        for(int i=0;i<vertexNum;i++){
            GraphHeadNodeVector[i].FirstNode=NULL;
        }
    }

    //插入一条有序边
    void InsertOrderedEdge(Edge E){
        GraphCommonNode * NewNode;
        NewNode->index=E->destinction;
        NewNode->Weight=E->Weight;
        NewNode->Next=this->GraphHeadNodeVector[E->origin].FirstNode;
        this->GraphHeadNodeVector[E->origin].FirstNode=NewNode;
    };

    //插入一条无序边
    void InsertUnorderedEdge(Edge E){
        GraphCommonNode * NewNode1;
        NewNode1->index=E->destinction;
        NewNode1->Weight=E->Weight;
        NewNode1->Next=this->GraphHeadNodeVector[E->origin].FirstNode;
        this->GraphHeadNodeVector[E->origin].FirstNode=NewNode1;

        GraphCommonNode * NewNode2;
        NewNode2->index=E->origin;
        NewNode2->Weight=E->Weight;
        NewNode2->Next=this->GraphHeadNodeVector[E->destinction].FirstNode;
        this->GraphHeadNodeVector[E->destinction].FirstNode=NewNode2;
    };
};















#endif
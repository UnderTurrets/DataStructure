#ifndef __Graph_h__
#define __Graph_h__
#include "authority.h"
#include "SetType.h"
#include "Heap.h"

#define UndeterminedWeight 77777        /* ∞设为双字节无符号整数的最大值77777*/
#define UndeterminedVertex -1        /* ∞设为双字节无符号整数的最大值77777*/
#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,顶点存储为整型，没有什么意义 */
typedef double WeightType;        /* 边的权值设为整型 */
typedef string VertexDataType;        /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef class EdgeNode* Edge;
class EdgeNode{
public:
    Vertex source, destination;      /* 边连接的两个顶点 */
    WeightType Weight;  /* 边权重 */

    //构造函数
    EdgeNode():source(UndeterminedVertex),destination(UndeterminedVertex),Weight(UndeterminedWeight){}
    EdgeNode(Vertex x,Vertex y,WeightType value):source(x),destination(y),Weight(value){}

    //重载运算符，基于权重进行比较
    bool operator> (EdgeNode that);
    bool operator>= (EdgeNode that);
    bool operator< (EdgeNode that);
    bool operator<= (EdgeNode that);

};

/* 不作链表头的邻接点结点的定义 */
class GraphCommonNode{
public:
    Vertex index=UndeterminedVertex;        /* 这个邻接点的下标 */
    GraphCommonNode* Next=NULL;    /* 指向下一个邻接点的指针 */
    WeightType Weight=UndeterminedWeight;  /* 从链表头顶点到这个点之间的边的权重 */

    //构造函数
    GraphCommonNode():index(UndeterminedVertex),Next(NULL),Weight(UndeterminedWeight){}
};

/* 作链表头的顶点结点的定义 */
//多一个存储顶点的数据
class GraphHeadNode{
public:
    GraphCommonNode* FirstNode;/* 边表头指针 */
    VertexDataType Data;            /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */

    //构造函数
    GraphHeadNode():FirstNode(NULL){}
};

/* 用邻接表定义的图 */
class GraphList{
public:
    int vertexNum;     /* 顶点数 */
    int edgeNum;     /* 边数   */
    MinHeap<EdgeNode>EdgeHeap; /*边构成的最小堆*/
    vector<GraphHeadNode> GraphHeadNodeVector;  /* 邻接表 */
    vector<bool>Isvisited;   /*判断顶点是否被访问过*/
    vector<vector<WeightType>> dist; /*dist[index1][index2]表示index1到index2的最短距离，不考虑权重为负数*/
    vector<vector<Vertex>> path;  /*path[index1][index2]表示index1到index2经过的某顶点，不考虑权重为负数*/
    WeightType TotalWeight;   /*最小生成树的权重和*/

private:
    //Edge的初始化方法
    void EdgeHeap_initialize();

    //GraphHeadNodeVector的初始化方法
    void GraphHeadNodeVector_initialize();

    //Isvisited的初始化方法
    void Isvisited_initialize();

    //dist的初始化方法
    void dist_initialize();

    //path的初始化方法
    void path_initialize();

    //TotalWeight的初始化方法
    void TotalWeight_initialize();

public:
    //创建一个没有边的图,默认100个顶点
    GraphList();

    //创建一个没有边的图,指定顶点个数
    GraphList(int n);

    //拷贝构造
    GraphList(GraphList & that):vertexNum(that.vertexNum),edgeNum(that.edgeNum),GraphHeadNodeVector(that.GraphHeadNodeVector),\
                                Isvisited(that.Isvisited),dist(that.dist),path(that.path),TotalWeight(that.TotalWeight){}

    //重载运算符进行赋值
    GraphList operator= (GraphList that);

    //插入一条有序边
    void InsertOrderedEdge(Edge E);
    void InsertOrderedEdge(Vertex source,Vertex destination,WeightType weight);

    //插入一条无序边
    void InsertUnorderedEdge(Edge E);

private:
    //给定一个顶点，DFS遍历其连通分量
    //核心函数
    void DFS_ConnectedComponent_helper(Vertex squence);
public:
    //外部接口
    void DFS_ConnectedComponent(Vertex squence);

public:
    //DFS遍历这个图，无论是否连通
    void DFS();

private:
    //给定一个顶点，BFS遍历其连通分量
    //核心函数
    void BFS_ConnectedComponent_helper(Vertex squence);

public:
    //外部接口
    void BFS_ConnectedComponent(Vertex squence);

public:
    //BFS遍历这个图，无论是否连通
    void BFS();

private:
    // 返回this->dist[source]中未被收录的顶点且weight最小者
    Vertex FindMinVertex(Vertex source);

    //计算单源最短路径unsigned的核心函数
    bool FindSingleMinWeight_helper (Vertex source);

public:
    //计算单源最短路径unsigned的外部接口
    bool FindSingleMinWeight(Vertex source);

    //计算多源最短路径unsigned的外部接口
    void FinAllMinWeight();

    //Kruskal算法：将最小生成树保存为邻接表存储的图并返回其指针，若不存在最小生成树则返回NULL
    GraphList* Kruskal();

    /* 邻接表存储 - 拓扑排序算法 */
    bool TopSort(vector<Vertex> TopOrder );/* 对GraphList进行拓扑排序,  TopOrder顺序存储排序后的顶点下标 */

};

/* 用邻接矩阵定义的图 */
class GraphRect{
public:
    int vertexNum;  /* 顶点数 */
    int edgeNum;  /* 边数   */
    vector<vector<WeightType>> EdgeWeightRect; /* 邻接矩阵 */
    vector<VertexDataType>Data;      /* 存顶点的数据 */
    vector<bool>Isvisited;   /*判断顶点是否被访问过*/
    /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
    vector<vector<WeightType>> dist; /*dist[index1][index2]表示index1到index2的最短距离，不考虑权重为负数*/
    vector<vector<Vertex>> path;  /*path[index1][index2]表示index1到index2经过的某顶点，不考虑权重为负数*/
    WeightType TotalWeight;   /*最小生成树的权重和*/

private:
    //EdgeWeightRect的初始化方法
    void EdgeWeightRect_initialize();

    //Isvisited的初始化方法
    void Isvisited_initialize();

    //dist的初始化方法
    void dist_initialize();

    //path的初始化方法
    void path_initialize();

    //TotalWeight的初始化方法
    void TotalWeight_initialize();

public:
    //初始化一个图,默认100个顶点
    GraphRect();

    //指定顶点个数初始化一个图
    GraphRect(Vertex n);

    //拷贝构造
    GraphRect(GraphRect & that):vertexNum(that.vertexNum),edgeNum(that.edgeNum),EdgeWeightRect(that.EdgeWeightRect),Data(that.Data),\
                                Isvisited(that.Isvisited),dist(that.dist),path(that.path),TotalWeight(that.TotalWeight){}

    //重载运算符进行赋值
    GraphRect operator= (GraphRect that);

    //插入一条有序边
    void InsertOrderedEdge( Edge E );
    void InsertOrderedEdge( Vertex source,Vertex destinaiton,WeightType weight );

    //插入一条无序边
    void InsertUnorderedEdge( Edge E );

    //给定一个顶点，DFS遍历其连通分量
private:
    //核心函数
    void DFS_ConnectedComponent_helper(Vertex squence);
public:
    //外部接口
    void DFS_ConnectedComponent(Vertex squence);

public:
    //DFS遍历这个图，无论是否连通
    void DFS();

    //给定一个顶点，BFS遍历其连通分量
private:
    //核心函数
    void BFS_ConnectedComponent_helper(Vertex squence);

public:
    //外部接口
    void BFS_ConnectedComponent(Vertex squence);

public:
    //BFS遍历这个图，无论是否连通
    void BFS();

private:
    // 返回this->dist[source]中未被收录的顶点且weight最小者
    Vertex FindMinVertex(Vertex source);

    //计算单源最短路径unsigned的核心函数
    bool FindSingleMinWeight_helper (Vertex source);

public:
    //计算单源最短路径unsigned的外部接口
    bool FindSingleMinWeight(Vertex source);

    //计算多源最短路径unsigned的外部接口
    void FinAllMinWeight();

    // prim算法：将最小生成树保存为邻接矩阵存储的图并返回其指针，若不存在最小生成树则返回NULL
    GraphRect* PrimToGraphRect();
};
#endif
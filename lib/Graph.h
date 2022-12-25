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
    Vertex origin, destination;      /* 边连接的两个顶点 */
    WeightType Weight;  /* 边权重 */
    EdgeNode(){}
    EdgeNode(Vertex x,Vertex y,WeightType value):origin(x),destination(y),Weight(value){}
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
    void InsertOrderedEdge( Edge E ){
        if(E->origin>this->vertexNum||E->destination>this->vertexNum){
            cout<<"This graph doesn't have enough vertexs!"<<endl;
            return;
        }
        /* 插入边 <vertex1, vertex2> */
        this->Rect[E->origin][E->destination] = E->Weight;
    }

    //插入一条无序边
    void InsertUnorderedEdge( Edge E ){
        if(E->origin>this->vertexNum||E->destination>this->vertexNum){
            cout<<"This graph doesn't have enough vertexs!"<<endl;
            return;
        }
        this->Rect[E->origin][E->destination] = E->Weight;
        this->Rect[E->destination][E->origin] = E->Weight;
    }


};

/* 不作链表头的邻接点结点的定义 */
class GraphCommonNode{
public:
    Vertex index=-1;        /* 这个邻接点的下标 */
    GraphCommonNode* Next=NULL;    /* 指向下一个邻接点的指针 */
    WeightType Weight=-1;  /* 从链表头顶点到这个点之间的边的权重 */
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
        GraphHeadNodeVector.resize(vertexNum);
        for(int i=0;i<vertexNum;i++){
            if(GraphHeadNodeVector[i].FirstNode) {
                GraphHeadNodeVector[i].FirstNode = NULL;
            }
        }
    }

    //创建一个没有边的图,指定顶点个数
    GraphList(int x){
        this->vertexNum=x;
        this->edgeNum=0;
        GraphHeadNodeVector.resize(vertexNum);
        for(int i=0;i<vertexNum;i++){
            if(GraphHeadNodeVector[i].FirstNode) {
                GraphHeadNodeVector[i].FirstNode = NULL;
            }
        }
    }

    //插入一条有序边
    void InsertOrderedEdge(Edge E){
        GraphCommonNode * NewNode;
        NewNode->index=E->destination;
        NewNode->Weight=E->Weight;
        if(!this->GraphHeadNodeVector[E->origin].FirstNode) {
            this->GraphHeadNodeVector[E->origin].FirstNode = NewNode;
        }else if(this->GraphHeadNodeVector[E->origin].FirstNode){
            GraphCommonNode* temp=this->GraphHeadNodeVector[E->origin].FirstNode;
            while (temp->Next){
                temp=temp->Next;
            }
            temp->Next=NewNode;
        }
    };
    void InsertOrderedEdge(Vertex origin,Vertex destination,WeightType weight){
        if(origin>this->vertexNum || destination>this->vertexNum){
            cout<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        GraphCommonNode * NewNode=new GraphCommonNode;
        NewNode->index=destination;
        NewNode->Weight=weight;
        if(!this->GraphHeadNodeVector[origin].FirstNode) {
            this->GraphHeadNodeVector[origin].FirstNode = NewNode;
        }else if(this->GraphHeadNodeVector[origin].FirstNode){
            GraphCommonNode* temp=this->GraphHeadNodeVector[origin].FirstNode;
            while (temp->Next){
                temp=temp->Next;
            }
            temp->Next=NewNode;
        }
    };

    //插入一条无序边
    void InsertUnorderedEdge(Edge E){
        GraphCommonNode * NewNode1=new GraphCommonNode;
        NewNode1->index=E->destination;
        NewNode1->Weight=E->Weight;
        if(!this->GraphHeadNodeVector[E->origin].FirstNode) {
            this->GraphHeadNodeVector[E->origin].FirstNode = NewNode1;
        }else if(this->GraphHeadNodeVector[E->origin].FirstNode){
            GraphCommonNode* temp=this->GraphHeadNodeVector[E->origin].FirstNode;
            while (temp->Next){
                temp=temp->Next;
            }
            temp->Next=NewNode1;
        }

        GraphCommonNode * NewNode2=new GraphCommonNode;
        NewNode2->index=E->origin;
        NewNode2->Weight=E->Weight;
        if(!this->GraphHeadNodeVector[E->destination].FirstNode) {
            this->GraphHeadNodeVector[E->destination].FirstNode = NewNode2;
        }else if(this->GraphHeadNodeVector[E->destination].FirstNode){
            GraphCommonNode* temp=this->GraphHeadNodeVector[E->destination].FirstNode;
            while (temp->Next){
                temp=temp->Next;
            }
            temp->Next=NewNode2;
        }
    };

    //给定一个顶点，DFS遍历其连通分量
    void DFS_ConnectedComponent(Vertex x){
        if(x>vertexNum){
            cout<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        //在此可以进行对顶点数据的操作
        cout<<"This is in Vertex "<<x<<"."<<endl;



        //在此以上可以进行对顶点数据的操作
        for(GraphCommonNode* temp=this->GraphHeadNodeVector[x].FirstNode;temp;temp=temp->Next){
            //在此可以进行对边的权重的操作
            cout<<"Vertex "<<x<<" to "<<"Vertex "<<temp->index<<":weight="<<temp->Weight<<endl;
            //在此以上可以进行对边的权重的操作
            DFS_ConnectedComponent(temp->index);
        }
    }

    //DFS遍历这个图，无论是否连通
    void DFS(){
        for(Vertex x=0;x<this->vertexNum;x++){
            DFS_ConnectedComponent(x);
        }
    }

    //给定一个顶点，BFS遍历其连通分量
    void BFS_ConnectedComponent(Vertex x){
        if(x>vertexNum){
            cout<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        queue<Vertex>Q;
        Q.push(x);
        while (!Q.empty()){
            Vertex temp=Q.front();
            Q.pop();
            //在此可以进行对顶点数据的操作
            cout<<"This is in Vertex "<<temp<<"."<<endl;
            //在此以上可以进行对顶点数据的操作
            if(this->GraphHeadNodeVector[temp].FirstNode) {
                for (GraphCommonNode *NewNode = this->GraphHeadNodeVector[temp].FirstNode;NewNode;NewNode=NewNode->Next){
                    Q.push(NewNode->index);
                    //在此可以进行对边的权重的操作
                    cout<<"Vertex "<<temp<<" to "<<"Vertex "<<NewNode->index<<":weight="<<NewNode->Weight<<endl;
                    //在此以上可以进行对边的权重的操作
                }
            }
        }
    }

    //BFS遍历这个图，无论是否连通
    void BFS(){
        for(Vertex x=0;x<this->vertexNum;x++){
            BFS_ConnectedComponent(x);
        }
    }

};















#endif
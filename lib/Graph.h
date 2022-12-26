#ifndef __Graph_h__
#define __Graph_h__
#include "authority.h"

#define UndeterminedWeight 77777        /* ∞设为双字节无符号整数的最大值77777*/
#define UndeterminedVertex -1        /* ∞设为双字节无符号整数的最大值77777*/
#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,顶点存储为整型，没有什么意义 */
typedef double WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef class EdgeNode *Edge;
class EdgeNode{
public:
    Vertex source, destination;      /* 边连接的两个顶点 */
    WeightType Weight;  /* 边权重 */
    EdgeNode():source(UndeterminedVertex),destination(UndeterminedVertex),Weight(UndeterminedWeight){}
    EdgeNode(Vertex x,Vertex y,WeightType value):source(x),destination(y),Weight(value){}
};

/* 用邻接矩阵定义的图 */
class GraphRect{
public:
    int vertexNum;  /* 顶点数 */
    int edgeNum;  /* 边数   */
    vector<vector<WeightType>> WeightRect; /* 邻接矩阵 */
    vector<DataType>Data;      /* 存顶点的数据 */
    vector<bool>Isvisited;   /*判断顶点是否被访问过*/
    /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
    vector<vector<WeightType>> dist; /*dist[index1][index2]表示index1到index2的最短距离，不考虑权重为负数*/
    vector<vector<Vertex>> path;  /*path[index1][index2]表示index1到index2经过的某顶点，不考虑权重为负数*/

    //初始化一个图,默认100个顶点
    GraphRect(){
        this->vertexNum=MaxVertexNum;
        this->edgeNum=0;
        vector<WeightType>temp;
        temp.resize(vertexNum,UndeterminedWeight);
        this->WeightRect.resize(vertexNum,temp);
        this->Isvisited.resize(this->vertexNum, false);
        vector<WeightType>temp_dist;temp_dist.resize(vertexNum,UndeterminedWeight);
        vector<Vertex>temp_path;temp_path.resize(vertexNum,UndeterminedVertex);
        this->dist.resize(vertexNum,temp_dist);this->path.resize(vertexNum,temp_path);
        for(Vertex i=0;i<vertexNum;i++){
            this->dist[i][i]=0;
            this->path[i][i]=i;
            this->WeightRect[i][i]=0;
        }
    }

    //指定顶点个数初始化一个图
    GraphRect(Vertex n){
        this->vertexNum=n;
        this->edgeNum=0;
        vector<WeightType>temp;
        temp.resize(vertexNum,UndeterminedWeight);
        this->WeightRect.resize(vertexNum,temp);
        this->Isvisited.resize(this->vertexNum, false);
        vector<WeightType>temp_dist;temp_dist.resize(vertexNum,UndeterminedWeight);
        vector<Vertex>temp_path;temp_path.resize(vertexNum,UndeterminedVertex);
        this->dist.resize(vertexNum,temp_dist);this->path.resize(vertexNum,temp_path);
        for(Vertex i=0;i<vertexNum;i++){
            this->dist[i][i]=0;
            this->path[i][i]=i;
            this->WeightRect[i][i]=0;
        }
    }

    //插入一条有序边
    void InsertOrderedEdge( Edge E ){
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        /* 插入边 <vertex1, vertex2> */
        this->WeightRect[E->source][E->destination] = E->Weight;
    }
    void InsertOrderedEdge( Vertex source,Vertex destinaiton,WeightType weight ){
        if(source >= this->vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(destinaiton >= this->vertexNum){
            cout<<"Vertex "<<destinaiton<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        /* 插入边 <vertex1, vertex2> */
        this->WeightRect[source][destinaiton] = weight;
    }

    //插入一条无序边
    void InsertUnorderedEdge( Edge E ){
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        this->WeightRect[E->source][E->destination] = E->Weight;
        this->WeightRect[E->destination][E->source] = E->Weight;
    }

    //给定一个顶点，DFS遍历其连通分量
private:
    void DFS_ConnectedComponent_helper(Vertex squence){
        if(squence>=vertexNum){
            cout<<"Vertex "<<squence<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        this->Isvisited[squence]=true;
        //在此可以进行对顶点数据的操作
        cout<<"This is in Vertex "<<squence<<"."<<endl;



        //在此以上可以进行对顶点数据的操作
        for(int i=0;i<this->WeightRect[squence].size();i++){
            if(this->WeightRect[squence][i]!=UndeterminedWeight){
                //在此可以进行对边的权重的操作
                cout<<"Vertex "<<squence<<" to "<<"Vertex "<<i<<":weight="<<this->WeightRect[squence][i]<<endl;
                //在此以上可以进行对边的权重的操作
                if(!this->Isvisited[i])DFS_ConnectedComponent_helper(i);
            }
        }
    }
public:
    void DFS_ConnectedComponent(Vertex squence){
        this->Isvisited.resize(this->vertexNum, false);
        DFS_ConnectedComponent_helper(squence);
        this->Isvisited.resize(this->vertexNum, false);
    }

public:
    //DFS遍历这个图，无论是否连通
    void DFS(){
        this->Isvisited.resize(this->vertexNum, false);
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x])DFS_ConnectedComponent_helper(x);
        }
        this->Isvisited.resize(this->vertexNum, false);
    }

    //给定一个顶点，BFS遍历其连通分量
private:
    void BFS_ConnectedComponent_helper(Vertex squence){
        if(squence>=vertexNum){
            cout<<"Vertex "<<squence<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        queue<Vertex>Q;
        Q.push(squence);
        while(!Q.empty()){
            Vertex temp;
            temp=Q.front();
            Q.pop();
            this->Isvisited[temp]= true;
            //在此可以进行对顶点数据的操作
            cout<<"This is in Vertex "<<temp<<"."<<endl;



            //在此以上可以进行对顶点数据的操作
            for(int i =0;i<this->WeightRect[temp].size();i++){
                if(this->WeightRect[temp][i]!=UndeterminedWeight  ) {
                    if(!this->Isvisited[i])Q.push(i);
                    //在此可以进行对边的权重的操作
                    cout << "Vertex " << temp << " to " << "Vertex " << i << ":weight=" << this->WeightRect[temp][i] << endl;
                    //在此以上可以进行对边的权重的操作
                }
            }
        }
    }

public:
    void BFS_ConnectedComponent(Vertex squence){
        this->Isvisited.resize(this->vertexNum, false);
        BFS_ConnectedComponent_helper(squence);
        this->Isvisited.resize(this->vertexNum, false);
    }

public:
    //BFS遍历这个图，无论是否连通
    void BFS(){
        this->Isvisited.resize(this->vertexNum, false);
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x])BFS_ConnectedComponent_helper(x);
        }
        this->Isvisited.resize(this->vertexNum, false);
    }

private:
    // 返回this->dist[source]中未被收录的顶点且weight最小者
    Vertex FindMinVertex(Vertex source){
        Vertex minVertex,temp;WeightType minWeight=UndeterminedWeight;
        for ( temp=0; temp<this->vertexNum; temp++) {
            if ( !this->Isvisited[temp] && this->dist[source][temp]<minWeight) {
                /* 若V未被收录，且dist[V]更小 */
                minWeight = this->dist[source][temp]; /* 更新最小距离 */
                minVertex = temp; /* 更新对应顶点 */
            }
        }
        if (minWeight != UndeterminedWeight) /* 若找到最小dist */
            return minVertex; /* 返回对应的顶点下标 */
        else return UndeterminedVertex;  /* 若这样的顶点不存在，返回错误标记 */
    }

    //单源最短路径unsigned
    bool FindSingleMinWeight_helper (Vertex source){
        if(source>=vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return false;
        }
        for(Vertex temp=0;temp<this->vertexNum;temp++){
            this->dist[source][temp]=this->WeightRect[source][temp];
            if(this->dist[source][temp]!=UndeterminedWeight) {
                this->path[source][temp] = source;
            }else{
                this->path[source][temp]= UndeterminedVertex;
            }
        }
        this->Isvisited[source]= true;
        while (1){
            Vertex V=this->FindMinVertex(source);
            if(V==UndeterminedVertex){
                break;
            }
            this->Isvisited[V]= true;
            for(Vertex temp=0;temp<this->vertexNum;temp++){
                if(!this->Isvisited[temp] && this->WeightRect[V][temp]!=UndeterminedWeight){
                    if(this->WeightRect[V][temp]<0){
                        return false;
                    }
                    if(this->dist[source][V]+this->WeightRect[V][temp] < this->dist[source][temp]){
                        this->dist[source][temp]=this->dist[source][V]+this->WeightRect[V][temp];
                        this->path[source][temp]=V;
                    }
                }
            }
        }
        return true;
    }

public:
    bool FindSingleMinWeight(Vertex source){
        this->Isvisited.resize(this->vertexNum, false);
        bool ret=this->FindSingleMinWeight_helper(source);
        this->Isvisited.resize(this->vertexNum, false);
        return ret;
    }

    //多源最短路径unsigned
    void FinAllMinWeight(){
        this->Isvisited.resize(this->vertexNum, false);
        for(Vertex V=0;V< this->vertexNum;V++){
            this->FindSingleMinWeight_helper(V);
        }
        this->Isvisited.resize(this->vertexNum, false);
    }
};

/* 不作链表头的邻接点结点的定义 */
class GraphCommonNode{
public:
    Vertex index=UndeterminedVertex;        /* 这个邻接点的下标 */
    GraphCommonNode* Next=NULL;    /* 指向下一个邻接点的指针 */
    WeightType Weight=UndeterminedWeight;  /* 从链表头顶点到这个点之间的边的权重 */
    GraphCommonNode(){
        this->index=UndeterminedVertex;
        this->Next=NULL;
        this->Weight=UndeterminedWeight;
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
    vector<bool>Isvisited;   /*判断顶点是否被访问过*/
    vector<vector<WeightType>> dist; /*dist[index1][index2]表示index1到index2的最短距离，不考虑权重为负数*/
    vector<vector<Vertex>> path;  /*path[index1][index2]表示index1到index2经过的某顶点，不考虑权重为负数*/


    //创建一个没有边的图,默认100个顶点
    GraphList(){
        this->vertexNum=MaxVertexNum;
        this->edgeNum=0;
        this->Isvisited.resize(this->vertexNum, false);
        GraphHeadNodeVector.resize(vertexNum);
        vector<WeightType>temp_dist;temp_dist.resize(vertexNum,UndeterminedWeight);
        vector<Vertex>temp_path;temp_path.resize(vertexNum,UndeterminedVertex);
        this->dist.resize(vertexNum,temp_dist);this->path.resize(vertexNum,temp_path);
        for(Vertex i=0;i<vertexNum;i++){
            if(GraphHeadNodeVector[i].FirstNode) {
                GraphHeadNodeVector[i].FirstNode = NULL;
            }
            this->dist[i][i]=0;
            this->path[i][i]=i;
        }
    }

    //创建一个没有边的图,指定顶点个数
    GraphList(int n){
        this->vertexNum=n;
        this->edgeNum=0;
        this->Isvisited.resize(this->vertexNum, false);
        GraphHeadNodeVector.resize(vertexNum);
        vector<WeightType>temp_dist;temp_dist.resize(vertexNum,UndeterminedWeight);
        vector<Vertex>temp_path;temp_path.resize(vertexNum,UndeterminedVertex);
        this->dist.resize(vertexNum,temp_dist);this->path.resize(vertexNum,temp_path);
        for(Vertex i=0;i<vertexNum;i++){
            if(GraphHeadNodeVector[i].FirstNode) {
                GraphHeadNodeVector[i].FirstNode = NULL;
            }
            this->dist[i][i]=0;
            this->path[i][i]=i;
        }
    }

    //插入一条有序边
    void InsertOrderedEdge(Edge E){
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        GraphCommonNode * NewNode;
        NewNode->index=E->destination;
        NewNode->Weight=E->Weight;
        if(!this->GraphHeadNodeVector[E->source].FirstNode) {
            this->GraphHeadNodeVector[E->source].FirstNode = NewNode;
        }else if(this->GraphHeadNodeVector[E->source].FirstNode){
            GraphCommonNode* temp=this->GraphHeadNodeVector[E->source].FirstNode;
            while (temp->Next){
                temp=temp->Next;
            }
            temp->Next=NewNode;
        }
    };
    void InsertOrderedEdge(Vertex source,Vertex destination,WeightType weight){
        if(source >= this->vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(destination >= this->vertexNum){
            cout<<"Vertex "<<destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        GraphCommonNode * NewNode=new GraphCommonNode;
        NewNode->index=destination;
        NewNode->Weight=weight;
        if(!this->GraphHeadNodeVector[source].FirstNode) {
            this->GraphHeadNodeVector[source].FirstNode = NewNode;
        }else if(this->GraphHeadNodeVector[source].FirstNode){
            GraphCommonNode* temp=this->GraphHeadNodeVector[source].FirstNode;
            while (temp->Next){
                temp=temp->Next;
            }
            temp->Next=NewNode;
        }
    };

    //插入一条无序边
    void InsertUnorderedEdge(Edge E){
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        GraphCommonNode * NewNode1=new GraphCommonNode;
        NewNode1->index=E->destination;
        NewNode1->Weight=E->Weight;
        if(!this->GraphHeadNodeVector[E->source].FirstNode) {
            this->GraphHeadNodeVector[E->source].FirstNode = NewNode1;
        }else if(this->GraphHeadNodeVector[E->source].FirstNode){
            GraphCommonNode* temp=this->GraphHeadNodeVector[E->source].FirstNode;
            while (temp->Next){
                temp=temp->Next;
            }
            temp->Next=NewNode1;
        }

        GraphCommonNode * NewNode2=new GraphCommonNode;
        NewNode2->index=E->source;
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
private:
    void DFS_ConnectedComponent_helper(Vertex squence){
        if(squence>=vertexNum){
            cout<<"Vertex "<<squence<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        this->Isvisited[squence]= true;
        //在此可以进行对顶点数据的操作
        cout<<"This is in Vertex "<<squence<<"."<<endl;



        //在此以上可以进行对顶点数据的操作
        for(GraphCommonNode* temp=this->GraphHeadNodeVector[squence].FirstNode;temp;temp=temp->Next){
            //在此可以进行对边的权重的操作
            cout<<"Vertex "<<squence<<" to "<<"Vertex "<<temp->index<<":weight="<<temp->Weight<<endl;
            //在此以上可以进行对边的权重的操作
            if(!this->Isvisited[temp->index])DFS_ConnectedComponent_helper(temp->index);
        }
    }
public:
    void DFS_ConnectedComponent(Vertex squence){
        this->Isvisited.resize(this->vertexNum, false);
        DFS_ConnectedComponent_helper(squence);
        this->Isvisited.resize(this->vertexNum, false);
    }

public:
    //DFS遍历这个图，无论是否连通
    void DFS(){
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x]){
                DFS_ConnectedComponent_helper(x);
            }
        }
    }

    //给定一个顶点，BFS遍历其连通分量
private:
    void BFS_ConnectedComponent_helper(Vertex squence){
        if(squence>=vertexNum){
            cout<<"Vertex "<<squence<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        queue<Vertex>Q;
        Q.push(squence);
        while (!Q.empty()){
            Vertex temp=Q.front();
            Q.pop();
            this->Isvisited[temp]= true;
            //在此可以进行对顶点数据的操作
            cout<<"This is in Vertex "<<temp<<"."<<endl;
            //在此以上可以进行对顶点数据的操作
            if(this->GraphHeadNodeVector[temp].FirstNode) {
                for (GraphCommonNode *NewNode = this->GraphHeadNodeVector[temp].FirstNode;NewNode;NewNode=NewNode->Next){
                    if(!this->Isvisited[NewNode->index]){
                        Q.push(NewNode->index);
                    }
                    //在此可以进行对边的权重的操作
                    cout<<"Vertex "<<temp<<" to "<<"Vertex "<<NewNode->index<<":weight="<<NewNode->Weight<<endl;
                    //在此以上可以进行对边的权重的操作
                }
            }
        }
    }
public:
    void BFS_ConnectedComponent(Vertex squence){
        this->Isvisited.resize(this->vertexNum, false);
        BFS_ConnectedComponent_helper(squence);
        this->Isvisited.resize(this->vertexNum, false);
    }

public:
    //BFS遍历这个图，无论是否连通
    void BFS(){
        this->Isvisited.resize(this->vertexNum, false);
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x]){
                BFS_ConnectedComponent_helper(x);
            }
        }
        this->Isvisited.resize(this->vertexNum, false);
    }

private:
    // 返回this->dist[source]中未被收录的顶点且weight最小者
    Vertex FindMinVertex(Vertex source){
        if(source>=vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return UndeterminedVertex;
        }
        Vertex minVertex,temp;WeightType minWeight=UndeterminedWeight;
        for(temp=0; temp<this->vertexNum;temp++){
            if(!this->Isvisited[temp] && this->dist[source][temp]<minWeight){
                minWeight=this->dist[source][temp];
                minVertex=temp;
            }
        }
        if(minWeight!=UndeterminedWeight)
            return minVertex;
        else{
            return UndeterminedVertex;
        }
    }

    //单源最短路径unsigned
    bool FindSingleMinWeight_helper (Vertex source){
        if(source>=vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return false;
        }
        for(GraphCommonNode* temp=this->GraphHeadNodeVector[source].FirstNode;temp;temp=temp->Next){
            this->dist[source][temp->index]=temp->Weight;
            this->path[source][temp->index]=source;
        }
        this->Isvisited[source]= true;
        while (1){
            Vertex V=this->FindMinVertex(source);
            if(V==UndeterminedVertex){
                break;
            }
            this->Isvisited[V]= true;
            for(Vertex temp=0;temp<this->vertexNum;temp++){
                GraphCommonNode* NewNode=this->GraphHeadNodeVector[V].FirstNode;
                while (NewNode && NewNode->index!=temp){
                    NewNode=NewNode->Next;
                }
                if(!this->Isvisited[temp] && NewNode){
                    if(NewNode->Weight<0){
                        return false;
                    }
                    if(this->dist[source][V]+NewNode->Weight < this->dist[source][NewNode->index]){
                        this->dist[source][NewNode->index]=this->dist[source][V]+NewNode->Weight;
                        this->path[source][NewNode->index]=V;
                    }
                }
            }
        }
        return true;
    }

public:
    bool FindSingleMinWeight(Vertex source){
        this->Isvisited.resize(this->vertexNum, false);
        bool ret=this->FindSingleMinWeight_helper(source);
        this->Isvisited.resize(this->vertexNum, false);
        return ret;
    }

    //多源最短路径unsigned
    void FinAllMinWeight(){
        this->Isvisited.resize(this->vertexNum, false);
        for(Vertex V=0;V< this->vertexNum;V++){
            this->FindSingleMinWeight_helper(V);
        }
        this->Isvisited.resize(this->vertexNum, false);
    }

};















#endif
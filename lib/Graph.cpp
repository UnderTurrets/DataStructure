#include "Graph.h"

//边
bool EdgeNode::operator> (EdgeNode that){
    return this->Weight>that.Weight;
}
bool EdgeNode::operator>= (EdgeNode that){
    return this->Weight>=that.Weight;
}
bool EdgeNode::operator< (EdgeNode that){
    return this->Weight<that.Weight;
}
bool EdgeNode::operator<= (EdgeNode that){
    return this->Weight<=that.Weight;
}

/* 用邻接表定义的图 */
    //EdgeHeap的初始化方法
    void GraphList::EdgeHeap_initialize(){
        Vertex V;
        GraphCommonNode* W;
        EdgeNode temp;
        for ( V=0; V<this->vertexNum; V++ )
            for ( W=this->GraphHeadNodeVector[V].FirstNode; W; W=W->Next )
                if ( V < W->index ) { /* 避免重复录入无向图的边，只收V1<V2的边 */
                    temp.source = V;
                    temp.destination = W->index;
                    temp.Weight = W->Weight;
                    this->EdgeHeap.insert(temp);
                }
        this->EdgeHeap.LimitData=EdgeNode(UndeterminedVertex,UndeterminedVertex,UndeterminedWeight);
    }

    //GraphHeadNodeVector的初始化方法
    void GraphList::GraphHeadNodeVector_initialize(){
        GraphHeadNodeVector.resize(vertexNum);
        for(Vertex i=0;i<vertexNum;i++){
            if(GraphHeadNodeVector[i].FirstNode) {
                GraphHeadNodeVector[i].FirstNode = NULL;
            }
        }
        return;
    }

    //Isvisited的初始化方法
    void GraphList::Isvisited_initialize(){
        this->Isvisited.resize(this->vertexNum, false);
        return;
    }

    //dist的初始化方法
    void GraphList::dist_initialize(){
        vector<WeightType>temp_dist;
        temp_dist.resize(vertexNum,UndeterminedWeight);
        this->dist.resize(vertexNum,temp_dist);
        for(Vertex i=0;i<vertexNum;i++){
            this->dist[i][i]=0;
        }
        return;
    }

    //path的初始化方法
    void GraphList::path_initialize(){
        vector<Vertex>temp_path;
        temp_path.resize(vertexNum,UndeterminedVertex);
        this->path.resize(vertexNum,temp_path);
        for(Vertex i=0;i<vertexNum;i++){
            this->path[i][i]=UndeterminedVertex;
        }
        return;
    }

    //TotalWeight的初始化方法
    void GraphList::TotalWeight_initialize(){
        this->TotalWeight=UndeterminedWeight;
        return;
    }

    GraphList GraphList::operator= (GraphList that){
        this->vertexNum=that.vertexNum;
        this->edgeNum=that.edgeNum;
        this->GraphHeadNodeVector=that.GraphHeadNodeVector;
        this->Isvisited=that.Isvisited;
        this->dist=that.dist;
        this->path=that.path;
        this->TotalWeight=that.TotalWeight;
        return *this;
    }

    //创建一个没有边的图,默认100个顶点
    GraphList::GraphList(){
        this->vertexNum=MaxVertexNum;
        this->edgeNum=0;
        this->dist_initialize();
        this->path_initialize();
        this->GraphHeadNodeVector_initialize();
        this->Isvisited_initialize();
        this->TotalWeight_initialize();
        this->EdgeHeap_initialize();
    }

    //创建一个没有边的图,指定顶点个数
    GraphList::GraphList(int n){
        this->vertexNum=n;
        this->edgeNum=0;
        this->dist_initialize();
        this->path_initialize();
        this->GraphHeadNodeVector_initialize();
        this->Isvisited_initialize();
        this->TotalWeight_initialize();
        this->EdgeHeap_initialize();
    }

    //插入一条有序边
    void GraphList::InsertOrderedEdge(Edge E){
        //插入失败的情况
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }

        //插入后发生变化的，重新初始化
        this->edgeNum++;
        this->dist_initialize();
        this->path_initialize();
        this->TotalWeight_initialize();
        this->EdgeHeap.insert(*E);

        //开始插入操作
        GraphCommonNode * NewNode = new GraphCommonNode;
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
    void GraphList::InsertOrderedEdge(Vertex source,Vertex destination,WeightType weight){
        //插入失败的情况
        if(source >= this->vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(destination >= this->vertexNum){
            cout<<"Vertex "<<destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }

        //插入后发生变化的，重新初始化
        this->edgeNum++;
        this->dist_initialize();
        this->path_initialize();
        this->TotalWeight_initialize();
        this->EdgeHeap.insert(EdgeNode(source,destination,weight));

        //开始插入操作
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
    void GraphList::InsertUnorderedEdge(Edge E){
        //插入失败的情况
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }

        //插入后发生变化的，重新初始化
        this->edgeNum++;
        this->dist_initialize();
        this->path_initialize();
        this->TotalWeight_initialize();
        this->EdgeHeap.insert(EdgeNode(E->source,E->destination,E->Weight));
        this->EdgeHeap.insert(EdgeNode(E->destination,E->source,E->Weight));

        //开始插入操作
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
    void GraphList::DFS_ConnectedComponent_helper(Vertex squence){
        //遍历失败的情况
        if(squence>=vertexNum){
            cout<<"Vertex "<<squence<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }

        //在此可以进行对顶点数据的操作
        cout<<"This is in Vertex "<<squence<<"."<<endl;
        //在此以上可以进行对顶点数据的操作
        this->Isvisited[squence]= true;
        for(GraphCommonNode* temp=this->GraphHeadNodeVector[squence].FirstNode;temp;temp=temp->Next){
            //在此可以进行对边的权重的操作
            cout<<"Vertex "<<squence<<" to "<<"Vertex "<<temp->index<<":weight="<<temp->Weight<<endl;
            //在此以上可以进行对边的权重的操作
            if(!this->Isvisited[temp->index])DFS_ConnectedComponent_helper(temp->index);
        }
    }

    void GraphList::DFS_ConnectedComponent(Vertex squence){
        this->Isvisited_initialize();
        DFS_ConnectedComponent_helper(squence);
        this->Isvisited_initialize();
    }

    //DFS遍历这个图，无论是否连通
    void GraphList::DFS(){
        this->Isvisited_initialize();
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x]){
                DFS_ConnectedComponent_helper(x);
            }
        }
        this->Isvisited_initialize();
    }

    //给定一个顶点，BFS遍历其连通分量
    void GraphList::BFS_ConnectedComponent_helper(Vertex squence){
        //遍历失败的情况
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

    void GraphList::BFS_ConnectedComponent(Vertex squence){
        this->Isvisited_initialize();
        BFS_ConnectedComponent_helper(squence);
        this->Isvisited_initialize();
    }

    //BFS遍历这个图，无论是否连通
    void GraphList::BFS(){
        this->Isvisited_initialize();
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x]){
                BFS_ConnectedComponent_helper(x);
            }
        }
        this->Isvisited_initialize();
    }

    // 返回this->dist[source]中未被收录的顶点且weight最小者
    Vertex GraphList::FindMinVertex(Vertex source){
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
    bool GraphList::FindSingleMinWeight_helper (Vertex source){
        if(source>=vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return false;
        }
        for(GraphCommonNode* temp=this->GraphHeadNodeVector[source].FirstNode;temp;temp=temp->Next){
            this->dist[source][temp->index]=temp->Weight;
            this->path[source][temp->index]=UndeterminedVertex;
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

    bool GraphList::FindSingleMinWeight(Vertex source){
        this->Isvisited_initialize();
        bool ret=this->FindSingleMinWeight_helper(source);
        this->Isvisited_initialize();
        return ret;
    }

    //多源最短路径unsigned
    void GraphList::FinAllMinWeight(){
        this->Isvisited_initialize();
        for(Vertex V=0;V< this->vertexNum;V++){
            this->FindSingleMinWeight_helper(V);
        }
        this->Isvisited_initialize();
    }

    //Kruskal算法：将最小生成树保存为邻接表存储的图并返回其指针，若不存在最小生成树则返回NULL
    GraphList* GraphList::Kruskal(){
        int ECount;
        SetType<Vertex> VSet(this->vertexNum); /* 顶点数组并初始化 */
        for(Vertex V=0;V<this->vertexNum;V++){
            VSet.collection[V].val=V;
        }
        EdgeNode NextEdge;
        VSet.Initialize(); /* 初始化顶点并查集 */

        /* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
        GraphList* ret=new GraphList(this->vertexNum);
        WeightType temp_TotalWeight = 0;; /* 初始化权重和     */
        ECount = 0;      /* 初始化收录的边数 */

        while ( ECount < this->vertexNum-1 ) {  /* 当收集的边不足以构成树时 */
            NextEdge = this->EdgeHeap.deleteMin(); /* 从边集中得到最小边的位置 */
            if (NextEdge.source==UndeterminedVertex) /* 边集已空 */
                break;
            /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
            if ( !VSet.Check(VSet.GetIndex(NextEdge.source),VSet.GetIndex(NextEdge.destination) ) ) {
                VSet.Union(NextEdge.source,NextEdge.destination);

                /* 将该边插入ret */
                ret->InsertOrderedEdge(&NextEdge);
                temp_TotalWeight += NextEdge.Weight; /* 累计权重 */
                ECount++; /* 生成树中边数加1 */
            }
        }
        if ( ECount < this->vertexNum-1 ) {
            this->TotalWeight_initialize();/* 设置错误标记，表示生成树不存在 */
            delete ret;
            return NULL;
        } else {
            this->TotalWeight=temp_TotalWeight;
            ret->TotalWeight=temp_TotalWeight;
            return ret;
        }
    }


/* 用邻接矩阵定义的图 */
    //EdgeWeightRect的初始化方法
    void GraphRect::EdgeWeightRect_initialize(){
        vector<WeightType>temp;
        temp.resize(vertexNum,UndeterminedWeight);
        this->EdgeWeightRect.resize(vertexNum,temp);
        for(Vertex i=0;i<vertexNum;i++){
            this->EdgeWeightRect[i][i]=0;
        }
    }

    //Isvisited的初始化方法
    void GraphRect::Isvisited_initialize(){
        this->Isvisited.resize(this->vertexNum, false);
        return;
    }

    //dist的初始化方法
    void GraphRect::dist_initialize(){
        vector<WeightType>temp_dist;
        temp_dist.resize(vertexNum,UndeterminedWeight);
        this->dist.resize(vertexNum,temp_dist);
        for(Vertex i=0;i<vertexNum;i++){
            this->dist[i][i]=0;
        }
        return;
    }

    //path的初始化方法
    void GraphRect::path_initialize(){
        vector<Vertex>temp_path;
        temp_path.resize(vertexNum,UndeterminedVertex);
        this->path.resize(vertexNum,temp_path);
        for(Vertex i=0;i<vertexNum;i++){
            this->path[i][i]=UndeterminedVertex;
        }
        return;
    }

    //TotalWeight的初始化方法
    void GraphRect::TotalWeight_initialize(){
        this->TotalWeight=UndeterminedWeight;
        return;
    }

    GraphRect GraphRect::operator= (GraphRect that){
        this->vertexNum=that.vertexNum;
        this->edgeNum=that.edgeNum;
        this->EdgeWeightRect=that.EdgeWeightRect;
        this->Data=that.Data;
        this->Isvisited=that.Isvisited;
        this->dist=that.dist;
        this->path=that.path;
        this->TotalWeight=that.TotalWeight;
        return *this;
}

    //初始化一个图,默认100个顶点
    GraphRect::GraphRect(){
        this->vertexNum=MaxVertexNum;
        this->edgeNum=0;
        this->dist_initialize();
        this->path_initialize();
        this->EdgeWeightRect_initialize();
        this->Isvisited_initialize();
        this->TotalWeight_initialize();
    }

    //指定顶点个数初始化一个图
    GraphRect::GraphRect(Vertex n){
        this->vertexNum=n;
        this->edgeNum=0;
        this->dist_initialize();
        this->path_initialize();
        this->EdgeWeightRect_initialize();
        this->Isvisited_initialize();
        this->TotalWeight_initialize();
    }

    //插入一条有序边
    void GraphRect::InsertOrderedEdge( Edge E ){
        //插入失败的情况
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        //插入后发生变化的，重新初始化
        this->edgeNum++;
        this->dist_initialize();
        this->path_initialize();
        this->TotalWeight_initialize();

        //开始插入操作
        this->EdgeWeightRect[E->source][E->destination] = E->Weight;
    }
    void GraphRect::InsertOrderedEdge( Vertex source,Vertex destinaiton,WeightType weight ){
        //插入失败的情况
        if(source >= this->vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(destinaiton >= this->vertexNum){
            cout<<"Vertex "<<destinaiton<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        //插入后发生变化的，重新初始化
        this->edgeNum++;
        this->dist_initialize();
        this->path_initialize();
        this->TotalWeight_initialize();

        //开始插入操作
        this->EdgeWeightRect[source][destinaiton] = weight;
    }

    //插入一条无序边
    void GraphRect::InsertUnorderedEdge( Edge E ){
        //插入失败的情况
        if(E->source >= this->vertexNum){
            cout<<"Vertex "<<E->source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }
        if(E->destination >= this->vertexNum){
            cout<<"Vertex "<<E->destination<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }

        //插入后发生变化的，重新初始化
        this->edgeNum++;
        this->dist_initialize();
        this->path_initialize();
        this->TotalWeight_initialize();

        //开始插入操作
        this->EdgeWeightRect[E->source][E->destination] = E->Weight;
        this->EdgeWeightRect[E->destination][E->source] = E->Weight;
    }

    //给定一个顶点，DFS遍历其连通分量
    void GraphRect::DFS_ConnectedComponent_helper(Vertex squence){
        //遍历失败的情况
        if(squence>=vertexNum){
            cout<<"Vertex "<<squence<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return;
        }

        //在此可以进行对顶点数据的操作
        cout<<"This is in Vertex "<<squence<<"."<<endl;



        //在此以上可以进行对顶点数据的操作
        this->Isvisited[squence]=true;
        for(int i=0;i<this->EdgeWeightRect[squence].size();i++){
            if(this->EdgeWeightRect[squence][i]!=UndeterminedWeight){
                //在此可以进行对边的权重的操作
                cout<<"Vertex "<<squence<<" to "<<"Vertex "<<i<<":weight="<<this->EdgeWeightRect[squence][i]<<endl;
                //在此以上可以进行对边的权重的操作
                if(!this->Isvisited[i])DFS_ConnectedComponent_helper(i);
            }
        }
    }
    void GraphRect::DFS_ConnectedComponent(Vertex squence){
        this->Isvisited_initialize();
        DFS_ConnectedComponent_helper(squence);
        this->Isvisited_initialize();
    }

    //DFS遍历这个图，无论是否连通
    void GraphRect::DFS(){
        this->Isvisited_initialize();
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x])DFS_ConnectedComponent_helper(x);
        }
        this->Isvisited_initialize();
    }

    //给定一个顶点，BFS遍历其连通分量
    void GraphRect::BFS_ConnectedComponent_helper(Vertex squence){
        //遍历失败的情况
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
            for(int i =0;i<this->EdgeWeightRect[temp].size();i++){
                if(this->EdgeWeightRect[temp][i]!=UndeterminedWeight  ) {
                    if(!this->Isvisited[i])Q.push(i);
                    //在此可以进行对边的权重的操作
                    cout << "Vertex " << temp << " to " << "Vertex " << i << ":weight=" << this->EdgeWeightRect[temp][i] << endl;
                    //在此以上可以进行对边的权重的操作
                }
            }
        }
    }

    void GraphRect::BFS_ConnectedComponent(Vertex squence){
        this->Isvisited_initialize();
        BFS_ConnectedComponent_helper(squence);
        this->Isvisited_initialize();
    }

    //BFS遍历这个图，无论是否连通
    void GraphRect::BFS(){
        this->Isvisited_initialize();
        for(Vertex x=0;x<this->vertexNum;x++){
            if(!this->Isvisited[x])BFS_ConnectedComponent_helper(x);
        }
        this->Isvisited_initialize();
    }

    // 返回this->dist[source]中未被收录的顶点且weight最小者
    Vertex GraphRect::FindMinVertex(Vertex source){
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
    bool GraphRect::FindSingleMinWeight_helper (Vertex source){
        //寻找失败的情况
        if(source>=vertexNum){
            cout<<"Vertex "<<source<<":"<<"The vertex you has typed in doesn't exist!"<<endl;
            return false;
        }

        for(Vertex temp=0;temp<this->vertexNum;temp++){
            this->dist[source][temp]=this->EdgeWeightRect[source][temp];
            this->path[source][temp]= UndeterminedVertex;
        }
        this->Isvisited[source]= true;
        while (1){
            Vertex V=this->FindMinVertex(source);
            if(V==UndeterminedVertex){
                break;
            }
            this->Isvisited[V]= true;
            for(Vertex temp=0;temp<this->vertexNum;temp++){
                if(!this->Isvisited[temp] && this->EdgeWeightRect[V][temp]!=UndeterminedWeight){
                    if(this->EdgeWeightRect[V][temp]<0){
                        return false;
                    }
                    if(this->dist[source][V]+this->EdgeWeightRect[V][temp] < this->dist[source][temp]){
                        this->dist[source][temp]=this->dist[source][V]+this->EdgeWeightRect[V][temp];
                        this->path[source][temp]=V;
                    }
                }
            }
        }
        return true;
    }

    bool GraphRect::FindSingleMinWeight(Vertex source){
        this->Isvisited_initialize();
        bool ret=this->FindSingleMinWeight_helper(source);
        this->Isvisited_initialize();
        return ret;
    }

    //多源最短路径unsigned
    void GraphRect::FinAllMinWeight(){
        this->Isvisited_initialize();
        for(Vertex V=0;V< this->vertexNum;V++){
            this->FindSingleMinWeight_helper(V);
        }
        this->Isvisited_initialize();
    }

    // prim算法：将最小生成树保存为邻接矩阵存储的图并返回其指针，若不存在最小生成树则返回NULL
    GraphRect* GraphRect::PrimToGraphRect(){
        vector<Vertex>parent;parent.resize(this->vertexNum,0);//parent[index]表示 Vertex index的根,从顶点0开始
        Vertex  V, W;
        int VCount;
        Edge E;

        WeightType temp_TotalWeight = 0; /* 初始化权重和     */
        VCount = 0;      /* 初始化收录的顶点数 */
        /* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
        GraphRect* ret=new GraphRect(this->vertexNum);
        E = (Edge)malloc( sizeof(EdgeNode) ); /* 建立空的边结点 */

        /* 将初始点0收录进ret */
        VCount ++;
        V=0;
        this->Isvisited[0]=true;

        while (1) {
            Vertex source=V;

            /* 初始化。默认初始点下标是0 */
            for (Vertex temp=0; temp<this->vertexNum; temp++) {
                /* 这里假设若V到W没有直接的边，则Graph->G[V][W]定义为INFINITY */
                dist[source][temp] = this->EdgeWeightRect[source][temp];
            }

            V = this->FindMinVertex( source );
            /* V = 未被收录顶点中dist最小者 */
            if ( V==UndeterminedVertex ) /* 若这样的V不存在 */
                break;   /* 算法结束 */
            /* 将V及相应的边<parent[V], V>收录进ret */
            E->source = parent[V];
            E->destination = V;
            E->Weight = dist[source][V];
            ret->InsertOrderedEdge(E);
            temp_TotalWeight += dist[source][V];
            VCount++;
            this->Isvisited[V]=true;
            for( W=0; W<this->vertexNum; W++ ) /* 对图中的每个顶点W */
                if ( !this->Isvisited[W] && this->EdgeWeightRect[V][W]!=UndeterminedWeight ) {
                    /* 若W是V的邻接点并且未被收录 */
                    if ( this->EdgeWeightRect[V][W] < dist[source][W] ) {
                        /* 若收录V使得dist[W]变小 */
                        dist[source][W] = this->EdgeWeightRect[V][W]; /* 更新dist[W] */
                        parent[W] = V; /* 更新树 */
                    }
                }
        } /* while结束*/
        if ( VCount < this->vertexNum ) { /* ret中收的顶点不到|V|个，不存在最小生存树 */
            this->TotalWeight_initialize();
            delete ret;
            return NULL;
        }else {
            this->TotalWeight=temp_TotalWeight;
            ret->TotalWeight=temp_TotalWeight;
            return ret;
        }/* 算法执行完毕，返回 */
    }










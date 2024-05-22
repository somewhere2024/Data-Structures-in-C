#include"MYSTL.h"


// 创建新顶点
Vertex* createVertex(void* data)
{
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex)); // 分配新顶点的内存空间。malloc返回指针类型强制转化为Vertex* 
    if (newVertex == NULL)
    { // 检查内存分配是否成功
        printf("内存分配失败！\n");
        exit(1); // 若失败，则退出程序
    }
    newVertex->data = data; // 将数据存储到新顶点中
    newVertex->visited = false; // 初始化访问标记为false
    return newVertex; // 返回新顶点
}

// 创建新边
Edge* createEdge(int start, int end)
{
    Edge* newEdge = (Edge*)malloc(sizeof(Edge)); // 分配新边的内存空间
    if (newEdge == NULL)
    { // 检查内存分配是否成功
        printf("内存分配失败！\n");
        exit(1); // 若失败，则退出程序
    }
    newEdge->start = start; // 设置边的起始顶点索引
    newEdge->end = end;     // 设置边的终止顶点索引
    return newEdge;         // 返回新边
}

// 创建图
Graph* createGraph()
{
    int i, j;
    Graph* graph = (Graph*)malloc(sizeof(Graph)); // 分配新图的内存空间
    if (graph == NULL)
    { // 检查内存分配是否成功
        printf("内存分配失败！\n");
        exit(1); // 若失败，则退出程序
    }
    graph->numVertices = 0; // 初始化顶点数量为0
    graph->numEdges = 0;    // 初始化边数量为0
    for (i = 0; i < MAX_VERTICES; i++)
    { // 初始化邻接矩阵为0
        for (j = 0; j < MAX_VERTICES; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph; // 返回新图
}

// 添加顶点
void addVertex(Graph* graph, void* data)
{
    if (graph->numVertices < MAX_VERTICES)
    { // 检查顶点数量是否小于最大限制
        Vertex* vertex = createVertex(data); // 创建新顶点
        graph->vertices[graph->numVertices++] = vertex; // 将顶点添加到图的顶点数组中
    }
    else
    {
        printf("顶点数量超过最大限制！\n");
    }
}

// 添加边
void addEdge(Graph* graph, int start, int end)
{
    if (start >= 0 && start < graph->numVertices && end >= 0 && end < graph->numVertices)
    {
        // 检查起始顶点索引和终止顶点索引是否有效
        //假设为无向图 
        graph->adjacencyMatrix[start][end] = 1; // 设置邻接矩阵对应位置为1，表示有边连接
        graph->adjacencyMatrix[end][start] = graph->adjacencyMatrix[start][end];
        Edge* edge = createEdge(start, end);    // 创建新边
        graph->edges[graph->numEdges++] = edge; // 将边添加到图的边数组中
    }
    else
    {
        printf("顶点索引无效！\n");
    }
}

// 深度优先搜索（DFS）
void DFS(Graph* graph, int vertexIndex, void (*print)(void*))
{
    int i;
    if (vertexIndex < 0 || vertexIndex >= graph->numVertices)
    {
        // 检查顶点索引是否有效
        printf("顶点索引无效！\n");
        return;
    }
    graph->vertices[vertexIndex]->visited = true; // 将当前顶点标记为已访问
    print(graph->vertices[vertexIndex]->data);    // 打印当前顶点数据
    printf(" ");
    for (i = 0; i < graph->numVertices; i++)
    {
        // 遍历与当前顶点相邻的顶点
        if (graph->adjacencyMatrix[vertexIndex][i] == 1 && graph->vertices[i]->visited == false)
        {
            // 如果存在连接且未被访问，则递归访问相邻顶点
            DFS(graph, i, print);
        }
    }
}

// 广度优先搜索（BFS）
void BFS(Graph* graph, int start, void (*print)(void*))
{
    int i;
    if (start < 0 || start >= graph->numVertices)
    {
        // 检查起始顶点索引是否有效
        printf("起始顶点索引无效！\n");
        return;
    }

    int queue[MAX_VERTICES]; // 定义队列用于广度优先搜索，先进先出 
    int qian = 0, hou = 0; // 定义队列的前端和后端
    queue[hou++] = start;   // 将起始顶点索引加入队列
    graph->vertices[start]->visited = true; // 标记起始顶点为已访问

    while (qian < hou)
    {
        int current = queue[qian++]; // 取出队列的当前顶点索引
        print(graph->vertices[current]->data); // 打印当前顶点数据
        printf(" ");

        for (i = 0; i < graph->numVertices; i++)
        {
            // 遍历与当前顶点相邻的顶点
            if (graph->adjacencyMatrix[current][i] == 1 && graph->vertices[i]->visited == false)
            {
                // 如果存在连接且未被访问，则将其加入队列并标记为已访问
                queue[hou++] = i;
                graph->vertices[i]->visited = true;
            }
        }
    }
}

// 打印整数
void printInt(void* data)
{
    printf("%d", *(int*)data); // 打印整数数据
}

// 打印浮点数
void printFloat(void* data)
{
    printf("%.2f", *(float*)data); // 打印浮点数数据
}

// 打印字符
void printChar(void* data)
{
    printf("%c", *(char*)data); // 打印字符数据
}

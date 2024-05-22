#include"MYSTL.h"


// �����¶���
Vertex* createVertex(void* data)
{
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex)); // �����¶�����ڴ�ռ䡣malloc����ָ������ǿ��ת��ΪVertex* 
    if (newVertex == NULL)
    { // ����ڴ�����Ƿ�ɹ�
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1); // ��ʧ�ܣ����˳�����
    }
    newVertex->data = data; // �����ݴ洢���¶�����
    newVertex->visited = false; // ��ʼ�����ʱ��Ϊfalse
    return newVertex; // �����¶���
}

// �����±�
Edge* createEdge(int start, int end)
{
    Edge* newEdge = (Edge*)malloc(sizeof(Edge)); // �����±ߵ��ڴ�ռ�
    if (newEdge == NULL)
    { // ����ڴ�����Ƿ�ɹ�
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1); // ��ʧ�ܣ����˳�����
    }
    newEdge->start = start; // ���ñߵ���ʼ��������
    newEdge->end = end;     // ���ñߵ���ֹ��������
    return newEdge;         // �����±�
}

// ����ͼ
Graph* createGraph()
{
    int i, j;
    Graph* graph = (Graph*)malloc(sizeof(Graph)); // ������ͼ���ڴ�ռ�
    if (graph == NULL)
    { // ����ڴ�����Ƿ�ɹ�
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1); // ��ʧ�ܣ����˳�����
    }
    graph->numVertices = 0; // ��ʼ����������Ϊ0
    graph->numEdges = 0;    // ��ʼ��������Ϊ0
    for (i = 0; i < MAX_VERTICES; i++)
    { // ��ʼ���ڽӾ���Ϊ0
        for (j = 0; j < MAX_VERTICES; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph; // ������ͼ
}

// ��Ӷ���
void addVertex(Graph* graph, void* data)
{
    if (graph->numVertices < MAX_VERTICES)
    { // ��鶥�������Ƿ�С���������
        Vertex* vertex = createVertex(data); // �����¶���
        graph->vertices[graph->numVertices++] = vertex; // ��������ӵ�ͼ�Ķ���������
    }
    else
    {
        printf("������������������ƣ�\n");
    }
}

// ��ӱ�
void addEdge(Graph* graph, int start, int end)
{
    if (start >= 0 && start < graph->numVertices && end >= 0 && end < graph->numVertices)
    {
        // �����ʼ������������ֹ���������Ƿ���Ч
        //����Ϊ����ͼ 
        graph->adjacencyMatrix[start][end] = 1; // �����ڽӾ����Ӧλ��Ϊ1����ʾ�б�����
        graph->adjacencyMatrix[end][start] = graph->adjacencyMatrix[start][end];
        Edge* edge = createEdge(start, end);    // �����±�
        graph->edges[graph->numEdges++] = edge; // ������ӵ�ͼ�ı�������
    }
    else
    {
        printf("����������Ч��\n");
    }
}

// �������������DFS��
void DFS(Graph* graph, int vertexIndex, void (*print)(void*))
{
    int i;
    if (vertexIndex < 0 || vertexIndex >= graph->numVertices)
    {
        // ��鶥�������Ƿ���Ч
        printf("����������Ч��\n");
        return;
    }
    graph->vertices[vertexIndex]->visited = true; // ����ǰ������Ϊ�ѷ���
    print(graph->vertices[vertexIndex]->data);    // ��ӡ��ǰ��������
    printf(" ");
    for (i = 0; i < graph->numVertices; i++)
    {
        // �����뵱ǰ�������ڵĶ���
        if (graph->adjacencyMatrix[vertexIndex][i] == 1 && graph->vertices[i]->visited == false)
        {
            // �������������δ�����ʣ���ݹ�������ڶ���
            DFS(graph, i, print);
        }
    }
}

// �������������BFS��
void BFS(Graph* graph, int start, void (*print)(void*))
{
    int i;
    if (start < 0 || start >= graph->numVertices)
    {
        // �����ʼ���������Ƿ���Ч
        printf("��ʼ����������Ч��\n");
        return;
    }

    int queue[MAX_VERTICES]; // ����������ڹ�������������Ƚ��ȳ� 
    int qian = 0, hou = 0; // ������е�ǰ�˺ͺ��
    queue[hou++] = start;   // ����ʼ���������������
    graph->vertices[start]->visited = true; // �����ʼ����Ϊ�ѷ���

    while (qian < hou)
    {
        int current = queue[qian++]; // ȡ�����еĵ�ǰ��������
        print(graph->vertices[current]->data); // ��ӡ��ǰ��������
        printf(" ");

        for (i = 0; i < graph->numVertices; i++)
        {
            // �����뵱ǰ�������ڵĶ���
            if (graph->adjacencyMatrix[current][i] == 1 && graph->vertices[i]->visited == false)
            {
                // �������������δ�����ʣ����������в����Ϊ�ѷ���
                queue[hou++] = i;
                graph->vertices[i]->visited = true;
            }
        }
    }
}

// ��ӡ����
void printInt(void* data)
{
    printf("%d", *(int*)data); // ��ӡ��������
}

// ��ӡ������
void printFloat(void* data)
{
    printf("%.2f", *(float*)data); // ��ӡ����������
}

// ��ӡ�ַ�
void printChar(void* data)
{
    printf("%c", *(char*)data); // ��ӡ�ַ�����
}

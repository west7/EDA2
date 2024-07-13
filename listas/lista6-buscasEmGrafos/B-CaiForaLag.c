#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    int size;
    Node *head;
    Node *tail;
} Queue;

Queue QueueInit()
{
    return (Queue){.head = NULL, .tail = NULL, .size = 0};
}

int front(Queue *q)
{
    int front;
    if (q->size > 0)
        front = q->head->data;
    return front;
}

int back(Queue *q)
{
    int back;
    if (q->size > 0)
        back = q->tail->data;
    return back;
}

void push(Queue *q, int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    if (q->size == 0)
    {
        q->head = n;
        q->tail = n;
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
    }
    q->size++;
}

int pop(Queue *q)
{
    int value = front(q);

    if (q->size > 0)
    {
        Node *removed = q->head;
        q->head = q->head->next;
        if (!q->head)
        {
            q->tail = NULL;
        }
        free(removed);
        q->size--;
    }
    return value;
}

void clear(Queue *q)
{
    while (q->size > 0)
        pop(q);
}

typedef struct Edge
{
    int v, w;
    int weight;
} Edge;

typedef struct Graph
{
    int numVertex, numEdges;
    int **edges;
} Graph;

#define NULL_EDGE 2147483647
#define sum(a, b) (a + b)
#define less(a, b) (a < b)

Graph GraphInit(int numVertex)
{
    Graph g = {.numVertex = numVertex, .numEdges = 0};
    g.edges = malloc(sizeof(int *) * g.numVertex);
    for (unsigned i = 0; i < g.numVertex; i++)
    {
        g.edges[i] = malloc(sizeof(int) * g.numVertex);
        for (unsigned j = 0; j < g.numVertex; j++)
        {
            g.edges[i][j] = NULL_EDGE;
        }
    }
    return g;
}

void GraphFree(Graph g)
{
    for (unsigned i = 0; i < g.numVertex; i++)
        free(g.edges[i]);
    free(g.edges);
}

void GraphInsert(Graph *g, Edge e)
{
    if (e.v > g->numVertex || e.w > g->numVertex)
        return;

    g->numEdges += (g->edges[e.v][e.w] == NULL_EDGE);
    g->edges[e.v][e.w] = e.weight;
}

void GraphConnections(Graph g, int start, int connections[])
{
    if (connections[start] < 0)
        connections[start] = start;
    for (unsigned i = 0; i < g.numVertex; i++)
        if (g.edges[start][i] != NULL_EDGE && connections[i] < 0)
        {
            int mn = ((int)i < connections[start] ? (int)i : connections[start]);
            connections[start] = mn;
            connections[i] = mn;
            GraphConnections(g, i, connections);
        }
}

void FloydWarshall(Graph g, int transitive[][2001])
{
    for (unsigned i = 0; i < g.numVertex; i++)
    {
        for (unsigned j = 0; j < g.numVertex; j++)
            transitive[i][j] = g.edges[i][j] != NULL_EDGE;
        transitive[i][i] = 1;
    }

    for (unsigned i = 0; i < g.numVertex; i++)
        for (unsigned j = 0; j < g.numVertex; j++)
            if (transitive[j][i] == 1)
                for (unsigned k = 0; k < g.numVertex; k++)
                    if (transitive[i][k] == 1)
                        transitive[j][k] = 1;
}

short bellmanford(Graph g, int start, int *dist)
{
    short *onQueue = malloc(sizeof(short) * g.numVertex);
    for (unsigned i = 0; i < g.numVertex; i++)
        dist[i] = NULL_EDGE, onQueue[i] = 0;
    dist[start] = 0;

    Queue q = QueueInit();
    push(&q, start);
    onQueue[start] = 1;

    const int sentinel = g.numVertex;
    unsigned k = 0;
    push(&q, sentinel);

    while (!q.size == 0)
    {
        int v = pop(&q);
        if (v < sentinel)
        {
            for (unsigned i = 0; i < g.numVertex; i++)
            {
                if (g.edges[v][i] == NULL_EDGE)
                    continue;

                if (less(sum(dist[v], g.edges[v][i]), dist[i]))
                {
                    dist[i] = k == g.numVertex ? NULL_EDGE : sum(dist[v], g.edges[v][i]);
                    if (!onQueue[i])
                    {
                        push(&q, i);
                        onQueue[i] = 1;
                    }
                }
            }
        }
        else
        {
            if (q.size == 0)
                return 1;
            if (++k >= g.numVertex + 1)
                return 0;
            push(&q, v);
            for (unsigned i = 0; i < g.numVertex; i++)
                onQueue[i] = 0;
        }
    }

    clear(&q);
    free(onQueue);
    return 1;
}

int distX[2001][2001], distS[2001][2001], tc[2001][2001], negative_cycles[2001];

int main()
{
    int v;
    scanf(" %d", &v);

    Graph gX = GraphInit(v), gS = GraphInit(v);
    for (int f, t, c, d; scanf(" %d %d %d %d", &f, &t, &c, &d) == 4 && (f | t | c | d);)
    {
        GraphInsert(&gS, (Edge){.v = f, .w = t, .weight = c});
        if (d == 0)
            GraphInsert(&gS, (Edge){.v = t, .w = f, .weight = c});

        if (d == 1)
            continue;

        GraphInsert(&gX, (Edge){.v = f, .w = t, .weight = c});
        GraphInsert(&gX, (Edge){.v = t, .w = f, .weight = c});
    }

    for (int i = 0; i < gS.numVertex; i++)
    {
        if (!bellmanford(gS, i, distS[i]))
            negative_cycles[i] = 1;
        bellmanford(gX, i, distX[i]);
    }

    FloydWarshall(gS, tc);

    GraphFree(gX);
    GraphFree(gS);

    for (int t, x; scanf(" %d %d", &t, &x) == 2;)
    {
        int ans = distS[t][x] != NULL_EDGE && distX[t][x] != NULL_EDGE;
        if (negative_cycles[t])
        {
            for (int i = 0; i < v && ans; i++)
                if (distS[t][i] == NULL_EDGE && (tc[i][t] || tc[i][x]))
                    ans = 0;
        }

        if (ans)
            printf("%d %d\n", distX[t][x], distS[t][x]);
        else
            printf("Impossibru\n");
    }

    return 0;
}
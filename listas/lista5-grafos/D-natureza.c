#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Edge
{
    int v, w;
} Edge;

typedef struct Graph
{
    int numVertex, numEdges;
    Edge **edges;
} Graph;

#define NULL_EDGE ((Edge){-1, -1});

Graph GraphInit(int v)
{
    Graph g;
    g.numVertex = v;
    g.numEdges = 0;
    g.edges = malloc(sizeof(Edge *) * v);
    for (int i = 0; i < v; i++)
    {
        g.edges[i] = malloc(sizeof(Edge) * v);
        for (int j = 0; j < g.numVertex; j++)
            g.edges[i][j] = NULL_EDGE;
    }
    return g;
}

void GraphFree(Graph g)
{
    for (int i = 0; i < g.numVertex; i++)
        free(g.edges[i]);
    free(g.edges);
}

void GraphInsert(Graph *g, Edge e)
{
    if (e.v > g->numVertex || e.w > g->numVertex)
        return;

    g->edges[e.v][e.w] = e;
    g->numEdges++;
}

void GraphConnections(Graph g, int start, int connections[])
{
    if (connections[start] < 0)
        connections[start] = start;

    for (int i = 0; i < g.numVertex; i++)
    {
        Edge e = g.edges[start][i];
        if (e.v != -1 && connections[i] < 0)
        {
            int min = ((int)i < connections[start] ? (int)i : connections[start]);
            connections[start] = min;
            connections[i] = min;
            GraphConnections(g, i, connections);
        }
    }
}

int connections[5001], freq[5001];
char animals[5001][32];

int main()
{

    while (1)
    {
        int v, c;
        scanf(" %d %d", &v, &c);
        if (!v && !c)
            break;

        for (int i = 0; i < v; i++)
            connections[i] = -1, freq[i] = 0;

        for (int i = 0; i < v; i++)
            scanf(" %s", animals[i]);

        Graph g = GraphInit(v);

        for (int i = 0; i < c; i++)
        {
            char a[32], b[32];
            scanf(" %s %s", a, b);
            int ai = -1, bi = -1;
            for (int j = 0; j < v && (ai == -1 || bi == -1); j++)
            {
                if (ai == -1 && strcmp(animals[j], a) == 0)
                    ai = j;
                else if (bi == -1 && strcmp(animals[j], b) == 0)
                    bi = j;
            }
            GraphInsert(&g, (Edge){.v = bi, .w = ai});
            GraphInsert(&g, (Edge){.v = ai, .w = bi});
        }

        for (int i = 0; i < v; i++)
            GraphConnections(g, i, connections);
        GraphFree(g);

        int ans = 0;
        for (int i = 0; i < v; i++)
            if (++freq[connections[i]] > ans)
                ans = freq[connections[i]];

        printf("%d\n", ans);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NULL_EDGE -1

typedef struct Edge
{
    int v, w;
} Edge;

typedef struct Graph
{
    int numVertex, numEdges;
    int **edges;
} Graph;

Graph GraphInit(int v)
{
    Graph g = {.numVertex = v, .numEdges = 0};
    g.edges = malloc(sizeof(int *) * g.numVertex);
    for (unsigned i = 0; i < g.numVertex; i++)
    {
        g.edges[i] = malloc(sizeof(int) * g.numVertex);
        for (unsigned j = 0; j < g.numVertex; j++)
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

    g->numEdges += (g->edges[e.v][e.w] == NULL_EDGE);
    g->edges[e.v][e.w] = 1;
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

int t[2001][2001];

int main()
{
    int n, m;
    while (scanf(" %d", &n))
    {
        if (!n)
            break;

        scanf(" %d", &m);
        Graph g = GraphInit(n);
        for (int i = 0, v, w, p; i < m; i++)
        {
            scanf(" %d %d %d", &v, &w, &p);
            v--, w--;
            GraphInsert(&g, (Edge){.v = v, .w = w});
            if (p == 2)
                GraphInsert(&g, (Edge){.v = w, .w = v});
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                t[i][j] = 0;

        FloydWarshall(g, t);
        GraphFree(g);

        int cont = 1;
        for (int i = 0; i < n && cont; i++)
            for (int j = 0; j < n && cont; j++)
                if (!t[i][j])
                    cont = 0;

        printf("%d\n", cont);
    }

    return 0;
}

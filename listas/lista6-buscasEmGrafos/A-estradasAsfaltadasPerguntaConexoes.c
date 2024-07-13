#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Edge
{
    int v, w;
} Edge;

typedef struct Graph
{
    int numVertex, numEdges;
    int **edges;
} Graph;

#define NULL_EDGE -1

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

int tr[2001][2001];

int main(void)
{
    int V;
    scanf(" %d", &V);

    Graph g = GraphInit(V);

    int v, w, d;
    for (; scanf(" %d %d %d", &v, &w, &d) == 3 && d;)
    {
        GraphInsert(&g, (Edge){.v = v, .w = w});
        if(d == 2)
            GraphInsert(&g, (Edge){.v = w, .w = v});
    }

    FloydWarshall(g, tr);
    GraphFree(g);

    for(int t, x; scanf(" %d %d", &t, &x) == 2;)
        printf("%s\n", (tr[t][x] && tr[x][t] ? "Ida e volta" : (tr[t][x] ? "Apenas Ida" : (tr[x][t] ? "Apenas Volta" : "Impossibru"))));

    return 0;
}
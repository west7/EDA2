#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int v, w;
    int weight;
} Edge;

typedef struct Graph
{
    int numVertex, numEdges;
    int **edges;
    int **weights;
    int *grau;
} Graph;


Graph GraphInit(int numVertex)
{
    Graph g = {.numVertex = numVertex, .numEdges = 0};
    g.grau = calloc(g.numVertex, sizeof(int));

    g.edges = malloc(numVertex * sizeof(int *));
    for (int i = 0; i < numVertex; i++)
        g.edges[i] = malloc(numVertex * sizeof(int));

    g.weights = malloc(numVertex * sizeof(int *));
    for (int i = 0; i < numVertex; i++)
        g.weights[i] = malloc(numVertex * sizeof(int));
    return g;
}

void GraphFree(Graph g)
{
    for (unsigned i = 0; i < g.numVertex; i++)
    {

        free(g.edges[i]);
        free(g.weights[i]);
    }
    free(g.edges);
    free(g.weights);
}

void GraphInsert(Graph *g, Edge e)
{
    if (e.v > g->numVertex || e.w > g->numVertex || e.v >= g->numVertex || e.w >= g->numVertex)
        return;

    g->edges[e.v][g->grau[e.v]] = e.w;
    g->weights[e.v][g->grau[e.v]] = e.weight;
    g->grau[e.v]++;

    g->edges[e.w][g->grau[e.w]] = e.v;
    g->weights[e.w][g->grau[e.w]] = e.weight;
    g->grau[e.w]++;
}

int shortPath(int *dist, int *visited, int numVertex)
{
    int smallest = -1, first = 1;

    for (unsigned i = 0; i < numVertex; i++)
    {
        if (dist[i] >= 0 && visited[i] == 0)
        {
            if (first)
            {
                smallest = i;
                first = 0;
            }
            else
            {
                if (dist[smallest] > dist[i])
                    smallest = i;
            }
        }
    }
    return smallest;
}

void Dijkstra(Graph *g, int start, int *ant, int *dist, int *visited)
{
    int cont, index, u;
    cont = g->numVertex;

    for (unsigned i = 0; i < g->numVertex; i++)
    {
        ant[i] = -1;
        dist[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    while (cont--)
    {
        u = shortPath(dist, visited, g->numVertex);
        visited[u] = 1;
        for (unsigned i = 0; i < g->grau[u]; i++)
        {
            index = g->edges[u][i];
            if (dist[index] < 0)
                dist[index] = dist[u] + g->weights[u][i];
            else if (dist[index] > 0 && dist[index] > dist[u] + g->weights[u][i])
            {
                dist[index] = dist[u] + g->weights[u][i];
                ant[index] = u;
            }
        }
    }
}

int main()
{
    int N, M, S, T, B;
    scanf(" %d %d", &N, &M);

    Graph g = GraphInit(N + 2);

    for (unsigned i = 0; i < M; i++)
    {
        scanf(" %d %d %d", &S, &T, &B);
        GraphInsert(&g, (Edge){.v = S, .w = T, .weight = B});
    }

    int *dist = malloc(g.numVertex * sizeof(int));
    int *ant = malloc(g.numVertex * sizeof(int));
    int *visited = malloc(g.numVertex * sizeof(int));

    Dijkstra(&g, 0, ant, dist, visited);
    printf("%d\n", dist[g.numVertex - 1]);

    GraphFree(g);
    free(dist);
    free(ant);
    free(visited);

    return 0;
}
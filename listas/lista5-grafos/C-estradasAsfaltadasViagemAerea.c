#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int v, w;
}Edge;

typedef struct Graph{
    int numVertex, numEdges;
    Edge **edges;
}Graph;

#define NULL_EDGE ((Edge){-1, -1});

Graph GraphInit(int v){
    Graph g;
    g.numVertex = v;
    g.numEdges = 0;
    g.edges = malloc(sizeof(Edge *) * v);
    for(int i = 0; i < v; i++){
        g.edges[i] = malloc(sizeof(Edge) * v);
        for(int j = 0; j < g.numVertex; j++)
            g.edges[i][j] = NULL_EDGE;    
    }
    return g;
}

void GraphFree(Graph g){
    for(int i = 0; i < g.numVertex; i++)
        free(g.edges[i]);
    free(g.edges);
}

void GraphInsert(Graph *g, Edge e){
    if(e.v > g->numVertex || e.w > g->numVertex)
        return; 

    g->edges[e.v][e.w] = e;
    g->numEdges++;
}

void GraphConnections(Graph g, int start ,int components[]){
    if (components[start] < 0)
        components[start] = start;

    for(int i = 0; i < g.numVertex; i++){
        Edge e = g.edges[start][i];
        if(e.v != -1 && components[i] < 0){
            int min = ((int)i < components[start] ? (int)i : components[start]);
            components[start] = min;
            components[i] = min;
            GraphConnections(g, i, components);
        }
    }
}

int components[5001];

int main(){
    int V, J;
    scanf(" %d %d", &V, &J);

    Graph g = GraphInit(V);

    for(int v ,w; scanf(" %d %d", &v, &w) == 2;){   
        GraphInsert(&g, (Edge){.v = v, .w = w});
        GraphInsert(&g, (Edge){.v = w, .w = v});
    }

    for(int i = 0; i < V; i++)
        components[i] = -1;

    for(int i = 0; i < V; i++)
        GraphConnections(g, i, components);  
   
    GraphFree(g);

    int *max = malloc(sizeof(int) * V);
    for(int i = 0; i < V; i++)
        max[i] = 0;

    int cont = V - 1;
    for(int i = V - 1; i >= 0; i--)
    {
        if(++max[components[i]] > max[cont] || (max[components[i]] == max[cont] && cont != components[J] && components[i] < cont))
            cont = components[i];
    }

    free(max);

    if(cont == components[J] && g.numEdges == 0)
        printf("Fique em casa\n");
    else if(cont == components[J])
        printf("Bora pra estrada\n");
   else
        printf("Vamos para %d\n", cont);

    return 0;
}
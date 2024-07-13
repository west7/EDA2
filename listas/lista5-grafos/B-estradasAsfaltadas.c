#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Edge{
    int v, w;
}Edge;

typedef struct Graph{
    int numVertex;
    Edge **edges;
}Graph;

#define NULL_EDGE ((Edge){-1, -1});

Graph GraphInit(int v){
    Graph g;
    g.numVertex = v;
    g.edges = malloc(sizeof(Edge *) * v);
    for(int i = 0; i < v; i++){
        g.edges[i] = malloc(sizeof(Edge) * v);
        for(int j = 0; j < v; j++)
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
}

void dfs(Graph g, int start, bool visited[]){
    visited[start] = true;
    for(int i = 0; i < g.numVertex; i++){
        Edge e = g.edges[start][i];
        if(e.v != -1 && !visited[i])
            dfs(g, i, visited);
    }
}


bool visited[5001];

int main(){
    int V;
    scanf(" %d", &V);

    Graph g = GraphInit(V);

    
    for(int v ,w; scanf(" %d %d", &v, &w) == 2;){   
        GraphInsert(&g, (Edge){.v = v, .w = w});
        GraphInsert(&g, (Edge){.v = w, .w = v});
    }
        
    int cont = 0;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(g, i, visited);
            cont++;
        }
    }

    printf("%d\n", cont);
    GraphFree(g);

    return 0;
}
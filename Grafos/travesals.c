
#include "graphs.h"

int color[MAX];


void df_visit(GraphL g, int s)
{
    int vis[MAX];
    int i;
    for (i = 0; i < MAX; i++) vis[i] = 0;
    return df_visit_R (g,s,vis);
    
}

void df_visit_R (GraphL g, int s, int vis[]){
    struct edge *aux;
    vis[s] = 1;
    for (aux = g[s]; aux; aux = aux -> next){
        if(vis[aux->dest] == 0) df_visit_R(g,aux->dest,vis);
    }
}

void dfs (GraphL g, int n)
{
    i
    
}





void bf_visit(GraphL g, int s)
{
    for (int i= 0; i < s; i++) g[i] = 0;
    
}


void bfs (GraphL g, int n)
{
    bfs_sol(g, n);
    
}


void dists (GraphL g, int s, int dist[]) 
{
    dists_sol (g, s, dist); 
}


void shortestPath (GraphL g, int s, int  d) 
{
    shortestPath_sol (g, s, d);
}



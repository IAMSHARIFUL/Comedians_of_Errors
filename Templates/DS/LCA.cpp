int lca(int u,int v)
{   if(depth[v]>depth[u])
        v=pth_ancestor(v,depth[v]-depth[u]);
    if(depth[u]>depth[v])
        u=pth_ancestor(u,depth[u]-depth[v]);
    if(u==v)
        return u;
    for(int i=log2(n-1);i>=0;i--){
        if(bparent[u][i]!=bparent[v][i]){
            u=bparent[u][i];
            v=bparent[v][i];
        }}
    return bparent[u][0];}

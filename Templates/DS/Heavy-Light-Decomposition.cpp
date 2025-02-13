namespace HLD{
  struct Node{
    int mn=INT_MAX,unp=INT_MAX;
    Node(){}
    Node(int mn,int unp): mn(mn),unp(unp){}};
  inline Node combine(Node a,Node b){
    return {min(a.mn,b.mn),INT_MAX};}
  inline Node propagate(Node to,Node from,int len){
    if(from.unp==INT_MAX)
      return to;
    to.mn=min(to.mn,from.unp);
    to.unp=min(to.unp,from.unp);
    return to;}
  #define MAX_SIZE 100001
  vector<vector<int> >G;
  vector<int> parent,depth, heavy,head,pos;
  vector<int> node_val;
  vector<int> node_val_order;
  SegTree<Node> sgt( MAX_SIZE,combine,propagate);
  int cur_pos;
  int dfs(int node){
    int sz=1;
    int max_c_size=0;
    for(auto c:G[node]){
      if(c!=parent[node]){
        parent[c]=node;
        depth[c]=depth[node]+1;
        int c_size=dfs(c);
        sz+=c_size;
        if(c_size>max_c_size){
          max_c_size=c_size;
          heavy[node]=c; }}}
    return sz;}
  void decompose(int node,int h){
    pos[node]=cur_pos++;
    head[node]=h;
    if(heavy[node]!=-1)
      decompose(heavy[node],h);
    for(int c:G[node]){
      if(c!=parent[node]&& c!=heavy[node])
        decompose(c,c);}
    return;}
  //for query on path the node_val of a node is the cost of the edge to parent
  //exclude=true for query on path,it excludes the value stored in lca(a,b)
  int query(int a,int b,int n,bool exclude=false){//n number of node in the tree
    Node res;//not really generalized,for min max update accordingly
    while(head[a]!=head[b]){
      if(depth[head[a]]> depth[head[b]])swap(a,b);
      res=combine(res, sgt.query(pos[head[b]],pos[b]));
      b=parent[head[b]];}
    if(depth[a]>depth[b])swap(a,b);
    res=combine(res,exclude? sgt.query(pos[a]+1,pos[b]) :sgt.query(pos[a],pos[b]));
    return res.mn;}
//  void update(int node,int val)
//  {
//    sgt.update(pos[node],val);
//  }
  void update(int a,int b,int val){
    while(head[a]!=head[b]){
      if(depth[head[a]]> depth[head[b]])
        swap(a,b);
      //res=combine(res,sgt.query(pos[head[b]],pos[b]));
      sgt.update(pos[head[b]], pos[b],{0,val});
      b=parent[head[b]];
    }
    if(depth[a]>depth[b])swap(a,b);
    //res=combine(res,exclude? sgt.query(pos[a]+1, pos[b]): sgt.query(pos[a],pos[b]));
    sgt.update(pos[a],pos[b],{0,val});
    //return res.mn;}
  void init(int n){
    parent.resize(n);
    depth.resize(n);
    heavy.assign(n,-1);
    head.resize(n);
    pos.resize(n);
    parent[0]=0;//might change later
    dfs(0);
    cur_pos=0;
    decompose(0,0);
    node_val_order.resize(n);
    for(int i=0;i<n;++i){
      node_val_order[pos[i]]= node_val[i];}
    sgt.n=n;
    sgt.build(node_val_order, 1,0,n-1); }}

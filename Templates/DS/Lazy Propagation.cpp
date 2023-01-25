struct node{
    int sum, prop;
    node(){
        sum=0, prop=0;}
} st[500000];
void propagate(int p, int c, int len){   
    st[c].prop+=st[p].prop;
    st[c].sum+=len*st[p].prop;}
void combine(int v, int l, int r){
    st[v].prop=0;
    st[v].sum=st[l].sum+st[r].sum;}
void update(int v, int vl, int vr, int l, int r, int u){
    if(l>r) return;
    if(vl==l and vr==r){
        st[v].sum+=(vr-vl+1)*u;
        st[v].prop+=u;
        return;}
    int mid=(vl+vr)/2;
    propagate(v, 2*v, mid-vl+1);
    propagate(v, 2*v+1, vr-mid);
    if(r<=mid) update(2*v, vl, mid, l, r, u);
    else if(l>mid) update(2*v+1, mid+1, vr, l, r, u);
    else {
        update(2*v, vl, mid, l, mid, u);
        update(2*v+1, mid+1, vr, mid+1, r, u);}
    combine(v, 2*v, 2*v+1);}
int query(int v, int vl, int vr, int l, int r){
    if(l>r) return 0;
    if(vl==l and vr==r) return st[v].sum;
    int mid=(vl+vr)/2;
    propagate(v, 2*v, mid-vl+1);
    propagate(v, 2*v+1, vr-mid);
    int qres;
    if(r<=mid) qres=query(2*v, vl, mid, l, r);
    else if(l>mid) qres=query(2*v+1, mid+1, vr, l, r);
    else qres=query(2*v, vl, mid, l, mid)+query(2*v+1, mid+1, vr, mid+1, r);
    combine(v, 2*v, 2*v+1);
    return qres;}

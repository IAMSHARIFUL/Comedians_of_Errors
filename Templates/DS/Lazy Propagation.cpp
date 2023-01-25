#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mt make_tuple
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int ,int , int > tiii;
const int INF=INT_MAX;
const ll mod=1000000007;
struct node
{
    int sum, prop;
    node(){
        sum=0, prop=0;
    }
} st[500000];

void propagate(int p, int c, int len)
{
    //propagate unpropagated data to childs
    st[c].prop+=st[p].prop;
    st[c].sum+=len*st[p].prop;
}
void combine(int v, int l, int r)
{
    //nullify unpropagated data of parent
    //assign the combination of childs to parent
    st[v].prop=0;
    st[v].sum=st[l].sum+st[r].sum;
}
void update(int v, int vl, int vr, int l, int r, int u)
{
    if(l>r) return;
    if(vl==l and vr==r){
        //range update
        st[v].sum+=(vr-vl+1)*u;
        st[v].prop+=u;
        return;
    }
    int mid=(vl+vr)/2;

    propagate(v, 2*v, mid-vl+1);
    propagate(v, 2*v+1, vr-mid);

    if(r<=mid) update(2*v, vl, mid, l, r, u);
    else if(l>mid) update(2*v+1, mid+1, vr, l, r, u);
    else {
        update(2*v, vl, mid, l, mid, u);
        update(2*v+1, mid+1, vr, mid+1, r, u);
    }

    combine(v, 2*v, 2*v+1);
}
int query(int v, int vl, int vr, int l, int r)
{
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
    return qres;
}

/*Fully Generalized implementation for Monotone slope,Arbitrary query
runtime insert() O(1) query() O(logn) */
class MonotoneCHT{
    deque<Line> Q;
    int type;
    void insertBack(Line nl){
        //handle parallel line insertion
        if(!Q.empty()&&Q.back().parallel(nl)){
            if(type<2){
                if(Q.back().c>nl.c)
                    Q.pop_back();
                else
                    return;}
            else{
                if(Q.back().c<nl.c)
                    Q.pop_back();
                else
                    return;}}
        while(Q.size()>1&&Q.back().intersect(nl)<Q[Q.size()-2].intersect(nl))
            Q.pop_back();
        Q.push_back(nl);}
    void insertFront(Line nl){
        if(!Q.empty()&&Q[0].parallel(nl)){
            if(type<2){
                if(Q[0].c>nl.c)
                    Q.pop_front();
                else
                    return;}
            else{
                if(Q[0].c<nl.c)
                    Q.pop_front();
                else
                    return;}}
        while(Q.size()>1&&Q[0].intersect(nl)>Q[1].intersect(nl))
            Q.pop_front();
        Q.push_front(nl);}
    pii bSearch(ll x){
        if(Q.size()==1||Q[0].intersect(Q[1]).first>=x)
            return {0,0};
        int l=1,r=(int)Q.size()-1;
        while(r>l+1){
            int mid=(l+r)/2;
            if(Q[mid].intersect(Q[mid-1]).first<x)
                l=mid;
            else
                r=mid;}
        return {l,r};}
public:
    //slope increasing or decreasing(not query point
    //query point is arbitrary),querying for maximum or minimum
    MonotoneCHT(bool increasing,bool maximum){
        type=increasing;
        if(maximum)
            type|=2;}
    void insert(Line nl){
        if(type==3||type==0)
            insertBack(nl);
        else
            insertFront(nl);}
    ll fastQuery(ll x)//if monotone query satisfied //not tested,although it should be ok
    {
        #ifdef INCREASING_QUERY
        while(Q.size()>1&&Q[0].intersect(Q[1]).first<x)
            Q.pop_front();
        return Q[0](x);
        #else
        while(Q.size()>1&&Q.back().intersect(Q[(int)Q.size()-2]).first>x)
            Q.pop_back();
        return Q.back()(x);
        #endif}
    ll query(ll x){
        pii indx=bSearch(x);
        if(type<2)
            return min(Q[indx.first](x),Q[indx.second](x));
        return max(Q[indx.first](x),Q[indx.second](x));}
    void clear()
    {Q.clear();}};

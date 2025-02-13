#define MAX 100000
int prime[MAX+1],Phi[MAX+1];
vector<int> pr;
void sieve(){
    for (int i=2; i <= N; ++i) {
        if (prime[i] == 0) {
            prime[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j < (int)pr.size() && pr[j] <= prime[i] && i*pr[j] <= N; ++j) {
            prime[i * pr[j]] = pr[j];
        }
    }
}
void PhiWithSieve(){
    int i;
    for(i=2; i<=MAX; i++){
        if(prime[i]==i){
            Phi[i]=i-1;
        }
        else if((i/prime[i])%prime[i]==0){
            Phi[i]=Phi[i/prime[i]]*prime[i];
        }
        else{
            Phi[i]=Phi[i/prime[i]]*(prime[i]-1);
        }
    }
}
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}
int PrimitiveRoot(int p){
    vector<int>fact;
    int phi=Phi[p];
    int n=phi;
    while(n>1){
        if(prime[n]==n){
            fact.push_back(n);
            n=1;
        }
        else{
            int f=prime[n];
            while(n%f==0){
                n=n/f;
            }
            fact.push_back(f);
        }
    }
    int res;
    for(res=p-1; res>1; --res){
        for(n=0; n<fact.size(); n++){
            if(powmod(res,phi/fact[n],p)==1){
                break;
            }
        }
        if(n>=fact.size()) return res;
    }
    return -1;
}
ll DiscreteLog(ll a,ll b,ll mod){
    ll n,p,q;
    n=(ll)sqrt((double)mod)+1ll;
    ll an=powmod(a,n,mod);
    map<ll,ll> map_;
    ll cur=an;
    for(p=1;p<=n;p++){
        if(map_.find(cur)==map_.end()){
            map_.insert({cur,p});
        }
        cur=(cur*an)%mod;
    }
    cur=b;
    ll mn=LLONG_MAX;
    for(q=0;q<=n;q++){
        if(map_.find(cur)!=map_.end()){
            mn=min((n*map_[cur])-q,mn);
        }
        cur=(cur*a)%mod;
    }
    if(mn==LLONG_MAX)return -1;
    else return mn;
}
vector<int> DiscreteRoot(int n,int a,int k){
    int g = PrimitiveRoot(n);
    vector<int> ans;
    int any_ans = DiscreteLog(powmod(g,k,n),a,n);
    if (any_ans == -1){
        return ans;
    }
    int delta = (n-1) / gcd(k, n-1);
    for (int cur = any_ans % delta; cur < n-1; cur += delta)
        ans.push_back(powmod(g, cur, n));
    sort(ans.begin(), ans.end());
    return ans;
}

//zeta transform or sos dp
void zeta(vll& d,int m){
  int n=1<<m;
  for(int len=2;len<=n;len*=2){
    for(int i=0;i<n;i+=len){
      int l2=len>>1;
      for(int j=i;j<i+l2;++j){
        d[j+l2]+= d[j];}}}}
//zeta_inverse or mobius transform
void zinv(vll &d,int m){
  int n=1<<m;
  for(int len=2;len<=n;len*=2){
    for(int i=0;i<n;i+=len){
      int l2=len>>1;
      for(int j=i;j<i+l2;++j){
        d[j+l2]-=d[j];}}}}
//subset sum convolution
//not fully tested,got some error if used with mod
#define MAX_SIZE 1<<20
ll f[MAX_SIZE];
ll g[MAX_SIZE];
ll res[MAX_SIZE];
ll fhat[20][MAX_SIZE];
ll ghat[20][MAX_SIZE];
ll h[20][MAX_SIZE];
void subsetConvolution(int m){
  int n=1<<m;
  memset(fhat,0,sizeof(fhat));
  memset(ghat,0,sizeof(ghat));
  memset(res,0,sizeof(res));
  memset(h,0,sizeof(h));
  for(int i=0;i<n;++i){
    fhat[__builtin_popcount(i)][i]=f[i];
    ghat[__builtin_popcount(i)][i]=g[i];}
  for (int i=0; i<=m; i++) {
    zeta(fhat[i],m);
    zeta(ghat[i],m);
    for (int j=0; j<=i; j++){
      for (int mask = 0; mask < n; mask++){
        h[i][mask] += fhat[j][mask]*ghat[i-j][mask];}}
    zinv(h[i],m);}
  for(int  i=0;i<n;++i)
    res[i]=h[__builtin_popcount(i)][i];}

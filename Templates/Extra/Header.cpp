#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double ftype;
typedef pair<ftype,ftype> pff;
#define all(a) a.begin(), a.end()
#define some(a,l,r) a.begin()+l,a.begin()+(r+1)
#define csort(a) sort(all(a))
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#ifdef COMEDIANS
#define infile ;
#define outfile ;
#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge{c b, e;};
Gene c> rge<c> range(c i, c j){ return {i, j};}
struct printer{
    ~printer(){cerr<<endl;}
    Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
    Rics(string x){cerr<<x;return *this;}
    Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
    Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
    Gene c >Rics(rge<c> x){
        *this,"["; for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it; return *this,"]";}
};
#define stop getchar()
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) debug(), "[",#x,": ",(x),"] "
#define test_handle(T) cin>>T
#else
#define dbg(x) ;
#define infile ;
#define outfile ;
#define test_handle(T) T = 1
#endif
//Use -DCOMEDIANS in compiler flag in others tab, or remove ifdef
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ftype EPS = 1e-10;
const ftype PI = acos(-1);
const int MAX = 3e5+5;
const int BMAX = 18;
const int MOD = 1e9+7;
using namespace __gnu_pbds;
/*
find_by_order(k) --> returns iterator to the kth largest element counting from 0
order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt")
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;          ///Random
    x=(x^(x>>30))*0xbf58476d1ce4e5b9; ///Random
    x=(x^(x>>27))*0x94d049bb133111eb; ///Random
    return x^(x>>31);
    }
  const uint64_t FIXED_RANDOM = chrono::
    steady_clock::now().time_since_epoch().count();
  size_t operator()(uint64_t x) const {
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<int, int> x) const {
    return splitmix64((uint64_t(x.first)<<32) +
           x.second + FIXED_RANDOM);
  }
};
gp_hash_table<pair<int,int>,int,custom_hash> ht;
namespace my_gcc_ints {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
    using int128 = __int128;
#pragma GCC diagnostic pop
}
# stresstester GENERATOR SOL1 SOL2 ITERATIONS
for i in $(seq 1 "$4") ; do
    echo -en "\rAttempt $i/$4"
    $1 > in.txt
    $2 < in.txt > out1.txt
    $3 < in.txt > out2.txt
    diff -y out1.txt out2.txt > diff.txt
    if [ $? -ne 0 ] ; then
        echo -e "\nTestcase Found:"; cat in.txt
        echo -e "\nOutputs:"; cat diff.txt
        exit
    fi
done

//Put it in header File
void err(istream_iterator<string> it) {cout<<endl;} 
 template<typename T, typename... Args> 
 void err(istream_iterator<string> it, T a, Args... args){ 
  cout << *it << " = " << a << " ";err(++it, args...); 
 } 
 template<class T1, class T2>  
 ostream &operator <<(ostream &os, pair<T1,T2>&p) { 
  os<<"{"<<p.first<<", "<<p.second<<"} "; 
  return os; 
 } 
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
//In code File
#ifdef COMEDIANS
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
#define ALL(x) x.begin(),x.end()

/*
 く__,.ヘヽ.　　　　/　,ー､ 〉
　　　　　＼ ', !-─‐-i　/　/´
　　　 　 ／｀ｰ'　　　 L/／｀ヽ､
　　 　 /　 ／,　 /|　 ,　 ,　　　 ',
　　　ｲ 　/ /-‐/　ｉ　L_ ﾊ ヽ!　 i
　　　 ﾚ ﾍ 7ｲ｀ﾄ　 ﾚ'ｧ-ﾄ､!ハ|　 |
　　　　 !,/7 '0'　　 ´0iソ| 　      |　　　
　　　　 |.从"　　_　　 ,,,, / |./ 　 |
　　　　 ﾚ'| i＞.､,,__　_,.イ / 　.i 　|
　　　　　 ﾚ'| | / k_７_/ﾚ'ヽ,　ﾊ.　|
　　　　　　 | |/i 〈|/　 i　,.ﾍ |　i　|
　　　　　　.|/ /　ｉ： 　 ﾍ!　　＼　|
　　　 　 　 kヽ>､ﾊ 　 _,.ﾍ､ 　 /､!
　　　　　　 !'〈//｀Ｔ´', ＼ ｀'7'ｰr'
　　　　　　 ﾚ'ヽL__|___i,___,ンﾚ|ノ
　　　　　 　　　ﾄ-,/　|___./
　　　　　 　　　'ｰ'　　!_,.:
              Author: Solirous
*/ 
#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
#define fr(i,start,end) for(int i=start;i<end;i++)
#define fre(x,arr) for(auto x : arr)
int n,q;
//pre is the number of elements with indices in [a,b] which is greater or equal to c
int bsgaming(vector<int>&a,int l,int r,int c){
  while(l<=r){
    int mid=(l+r)>>1;  
    if(a[mid]>=c){
      r=mid-1;
    }else{
      l=mid+1;
    }
    //debug(mid,l,r);
  }
  return l;
}
int main(){
  cin.tie(0)->sync_with_stdio(0);
  freopen("GIVEAWAY.inp","r",stdin);
  freopen("GIVEAWAY.out","w",stdout);
  cin>>n;
  int sz=sqrt(n);
  vector<int> arr(n,0);
  fr(i,0,n) cin>>arr[i];
  vector<vector<int>>  blocks((n%sz==0?n/sz:(n/sz)+1));
  for(int i=0;i<n;i++){
    blocks[i/sz].emplace_back(arr[i]);
  }
  cin>>q;
  int t,a,b,c;
  for(int i=0;i*sz<n;i++){
    sort(blocks[i].begin(),blocks[i].end());
  }
  //debug(blocks);
  while(q--){
    cin>>t;
    if(t==0){
      cin>>a>>b>>c;
      --a,--b;
      int ans=0;
      for(int i=a;i<=b;){
        if(i%sz==0&&i+sz-1<=b){
          int idx=bsgaming(blocks[i/sz],0,blocks[i/sz].size()-1,c);//minimum pos that's actually greater or equal than c
          ans+=((int)blocks[i/sz].size()-idx);
        //  debug(ans);
          i+=sz;
        }else{
          if(arr[i]>=c){
            ++ans;
          }
          ++i;
        }
      }
      cout<<ans<<"\n";
    }else{
      cin>>a>>b;
      --a;
      int prev=arr[a];
      //debug(prev);
      bool addb=false;
      int cnt=0;
      vector<int> tmp;
      for(int i=0;i<blocks[a/sz].size();i++){
        if(blocks[a/sz][i]<b){
          if(blocks[a/sz][i]==prev){
            ++cnt;
            if(cnt==1){
            cnt=INT_MIN;
              continue;
            }else{
              tmp.emplace_back(blocks[a/sz][i]);
            }
          }else{
            tmp.emplace_back(blocks[a/sz][i]);
          }
        }else{
          if(!addb){
            tmp.emplace_back(b);
            addb=true;
            continue;
          }
          if(blocks[a/sz][i]==prev){
            ++cnt;
            if(cnt==1){
                cnt=INT_MIN;
              continue;
            }
          }

          tmp.emplace_back(blocks[a/sz][i]);
        }
      }
      if(!addb){
        tmp.emplace_back(b);
      }
      swap(blocks[a/sz],tmp);
    }
  }
}



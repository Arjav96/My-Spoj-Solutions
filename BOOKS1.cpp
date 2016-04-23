#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 500;
const int inf = 0x7fffffff;
 
ll p[MAXN];
int n, k;
 
bool ok(ll s) {
  ll t = 0;
  int cnt = 1;
  for(int i = 0;i < n;i++) {
    if(p[i] > s) { cnt = inf; break; }
    if(t + p[i] > s) {
      cnt++;
      t = 0;
    }
    t += p[i];
  }
  return cnt <= k;
}
 
void print(int idx,ll s,int tk) {
  ll t = 0;
  int i;
  for(i = idx;i >= 0;i--) {
    if(t + p[i] > s || i+1 == tk-1) {
      print(i,s,tk-1);
      break;
    }
    t += p[i];
  }
  if(i >= 0) printf("/ ");
  for(i++;i <= idx;i++) {
    printf("%lld",p[i]);
    if(i != n-1) printf(" ");
  }
}
 
int main() {
  int tcase;
  scanf("%d",&tcase);
  while(tcase--) {
    scanf("%d%d",&n,&k);
    ll s = 0;
    for(int i = 0;i < n;i++) {
      scanf("%lld",p+i);
      s += p[i];
    }
    ll l = 0, r = s;
    ll m;
    while(l < r) {
      m = (l+r)/2LL;
      if(ok(m)) r = m;
      else l = m+1;
    }
    //printf("%lld\n",r);
    print(n-1,r,k);
    puts("");
  }
  return 0;
} 

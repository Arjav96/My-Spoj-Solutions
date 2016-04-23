/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * Created By : Arjav Jain
 * CSE, MNNIT-ALLAHABAD 
 * vampire18
 _._._._._._._._._._._._._._._._._._._._._.*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define MP make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define PER(i,a,b) for(int i=b;i>=a;--i)
#define X first
#define Y second
#define all(c) c.begin(),c.end() //eg sort(all(v));
 
#define tr(c, itr) for(itr = (c).begin(); itr != (c).end(); itr++)
#define present(container, element) (container.find(element) != container.end()) //for set,map,etc
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vectors
 
typedef long long ll;
typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef pair<int,int > pii; 
typedef pair<string,int> psi;
 
#define sz(a) int((a).size())
#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))
 
//i/o
#define sc(n) scanf("%d",&n)
#define sc2(n,m) scanf("%d%d",&n,&m)
#define scs(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define scc(n) scanf("%c",&n)
 
#define scll(n) scanf("%lld",&n)
#define scll2(n,m) scanf("%lld%lld",&n,&m)
#define outll(n) printf("%lld\n",n)
#define outll2(n,m) printf("%lld %lld\n",n,m)
 
//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 10001
#define INF 1000000000
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
vector< pair< int,pii > > V;
int par[MAX];
int size[MAX];
 
int root(int i){
    while(i != par[i]){
        par[i] = par[par[i]];
        i = par[i];
    }
    return i;
}
 
int uni(int a,int b){
    int p = root(a);
    int q = root(b);
    if(size[p] < size[q]){
        par[p] = par[q];
        size[q] += size[p];
    }
    else{
        par[q] = par[p];
        size[p] += size[q];
    }
}
 
int kruskal(vector< pair< int,pii > > V){
	int x,y;
	int cost;
	int mincost=0;
	for(int i=0;i<sz(V);++i){
		x = V[i].second.first;
		y = V[i].second.second;
		cost = V[i].first;
		if(root(x) != root(y)){
			uni(x, y);
			mincost += cost;
		}
	}
	return mincost;
}
 
int main(){
	int t,n,e,cost,a,b;
	char city[15];
	sc(t);
	while(t--){
		sc(n);
		REP(i,1,n){
		    par[i] = i;
            size[i] = 1;
			scs(city);sc(e);
			REP(j,1,e){
				sc2(a,cost);
				if(a > i) V.pb(MP(cost,MP(i,a)));
			}
		}
		sort(V.begin(),V.end());
		out(kruskal(V));
		V.clear();
	}
}

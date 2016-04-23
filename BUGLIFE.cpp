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
typedef pair< int,int > ii; 
 
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
#define MAX 6105
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
vector<int> V[2005];
//vector<vector<int> > dis(103, vector<int> (103,INT_MAX));
vector<int> vis(2005);
int n,m,a,b;
bool flag = false;
void dfs(int n){
	vector<int>::iterator it;
	//vis[n] = true;
	it = V[n].begin();
	while(it != V[n].end()){
		if(!vis[*it]) {
			vis[*it] = vis[n] == 1 ? -1 : 1;
			dfs(*it);
		}
		else if(vis[*it] == vis[n]){
			//printf("Suspicious bugs found!\n");
			flag = true;
			return;
		}
		it++;
	}
}
 
int main(){
	int t;
	sc(t);
	rep(j,t){
		flag = false;
		sc2(n,m);
		REP(i,1,n){
			V[i].clear();
			vis[i] = 0;
		}
		rep(i,m){
			sc2(a,b);
			V[a].pb(b);
			V[b].pb(a);
		}
		printf("Scenario #%d:\n",j+1);
		REP(i,1,n){
			if(!vis[i]){
				vis[i] = 1;
				dfs(i);
			}
			if(flag) break;
		}
		if(!flag) printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");
	}
} 

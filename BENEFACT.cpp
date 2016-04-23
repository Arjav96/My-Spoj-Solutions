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
#define MAX 50001
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
vector< pii > V[MAX];
vector< pii >:: iterator it;
vector<bool> vis(MAX);
vector<int> dist(MAX);
int n;
int bfs(int tmp){
	queue<int> q;
	int mx,idx;
	REP(i,1,n){
		dist[i] = 0;
		vis[i] = false;
	}
	q.push(tmp);
	vis[tmp] = true;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		it = V[tmp].begin();
		while(it != V[tmp].end()){
			if(!vis[it->X]){
				vis[it->X] = true;
				dist[it->X] = dist[tmp] + it->Y;
				q.push(it->X);
			}
			it++;
		}
	}
	mx = dist[1];idx = 1;
	REP(i,2,n){
		if(mx < dist[i]){
			mx = dist[i];
			idx = i;
		}
	}
	return idx;
}
 
int main(){
	int t,a,b,d,start,ans;
	sc(t);
	while(t--){
		sc(n);
		REP(i,1,n){
		    V[i].clear();
		}
		REP(i,1,n-1){
			sc(a);sc2(b,d);
			V[a].pb(MP(b, d));
			V[b].pb(MP(a, d));
		}
		start = bfs(1);
		ans = bfs(start);
		out(dist[ans]);
	}
} 

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
#define MAX 10005
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
vector<int> V[MAX];
bool vis[MAX];
int pathdis[MAX]; 
 
void bfs(int n){
	queue<pair<int,int> > q;
	q.push(MP(n,0));
	int root,dis;
	while(!q.empty()){
		root = q.front().first;
		dis =q.front().second;
		vis[root] = true;
		vector<int>::iterator it;
		it = V[root].begin();
		while(it != V[root].end()){
			if(!vis[*it])
				q.push(MP(*it,dis+1));
			it++;
		}
		pathdis[root] = dis;
		q.pop();
	}
}
 
int main(){
	int n,m,a,b,t,mxroot;
	sc(n);
	rep(i,n-1){
		sc2(a,b);
		V[a].pb(b);
		V[b].pb(a);
	}
	bfs(1);
	mxroot = 0;
	REP(i,1,n){
		mxroot = (pathdis[mxroot] < pathdis[i]) ? i : mxroot;
	}
	clr(vis);
	clr(pathdis);
	bfs(mxroot);
	mxroot = 0;
	REP(i,1,n){
		mxroot = max(pathdis[i], mxroot);
	}
	printf("%d\n",mxroot);
} 

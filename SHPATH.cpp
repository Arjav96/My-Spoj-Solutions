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
#define MAX 10003
#define INF 1000000000
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
map<string,int> M;
map<string,int>::iterator it;
vector< pii > V[MAX];
int dis[MAX];
vector<bool> vis(MAX);
 
int main(){
	int t,n,e,start,end,cost,a,q,b,c;
	char city[20];
	sc(t);
	while(t--){
		sc(n);
		REP(i,1,n){
			scs(city);sc(e);
			M.insert(MP(city,i));
			REP(j,1,e){
				sc2(a,cost);
				V[i].pb(MP(a,cost));
			}
		}
		sc(q);
		rep(i,q){
		    scs(city);
			it=M.find(city);
			start=it->Y;
			scs(city);
			it=M.find(city);
			end=it->Y;
			priority_queue< pii, vector< pii >, greater< pii > > Q;
			Q.push(MP(0, start));
			REP(j,1,n){
				dis[j]=INF;
				vis[j]=false;
			}
			dis[start]=0;
			while(!Q.empty()){
				a=Q.top().Y;
				cost=Q.top().X;
				Q.pop();
				if(vis[a]) continue;
				vector< pii >::iterator itv=V[a].begin();
				while(itv != V[a].end()){
					b=itv->X;
					c=itv->Y;
					if(!vis[b] && (dis[a] + c) < dis[b]){
						dis[b] = dis[a] + c;
						Q.push(MP(dis[b],b));
					}
					itv++;
				}
				vis[a] = true;
				if(a==end) break;
			}
			out(dis[end]);
		}
		REP(i,1,n){
			V[i].clear();
		}
		M.clear();
	}
}
 

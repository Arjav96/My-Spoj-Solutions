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
#define MAX 1001
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
vector<int> V[MAX];
vector<int>::iterator it;
vector<bool> vis(MAX),inclu(MAX);
int cnt,v;
stack<int> S;
void dfs(int n){
	S.push(n);
	cnt = 0;v = 0;
	while(!S.empty()){
		n = S.top();
		S.pop();
		v++;
		vis[n] = true;
		it = V[n].begin();
		while(it != V[n].end()){
			if(!vis[*it]){
				if(!inclu[*it]) S.push(*it);
                inclu[*it] = true;
				cnt++;
			}
			it++;
		}
	}
}
 
inline void f(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
 
 
inline void write(int x){
         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) putchar_unlocked(buffor[i--]);
            putchar_unlocked('\n');
}
 
int main(){
	int n,m,r,e,a,b;
	int ans=0,highway=0,stadium=0;
	while(sc(n)!=EOF){
		f(&m);f(&r);f(&e);
		ans=0;highway=0;stadium=0;
		REP(i,1,n){
			V[i].clear();
			vis[i] = false;
			inclu[i] = false;
		}
		rep(i,m){
			f(&a);f(&b);
			V[a].pb(b);
			V[b].pb(a);
		}
		REP(i,1,n){
			if(!vis[i]){
				dfs(i);
				highway = (((v*(v-1))/2 - cnt)*r);
				stadium = (v*e);
				ans += ((highway <= stadium) ? highway : stadium);
			}
		}
		write(ans);
	}
} 

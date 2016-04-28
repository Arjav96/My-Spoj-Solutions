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
#define F first
#define S second
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
#define MAX 101
#define MAX2 1000001
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
vector<int> v[MAX];
vector<int> rev[MAX];
vector<bool> vis(MAX,false);
int cnt,n;
stack<int> S;
 
void dfs_stack(int node){
    vis[node] = true;
    vector<int>::iterator it = v[node].begin();
    while(it != v[node].end()){
        if(!vis[*it]) dfs_stack(*it);
        it++;
    }
    S.push(node);
}
 
void dfs(int node){
    vis[node] = true;
    vector<int>::iterator it = rev[node].begin();
    while(it != rev[node].end()){
        if(!vis[*it]) dfs(*it);
        it++;
    }
}
 
void kosaraju(){
    REP(i,1,n){
        if(!vis[i]) dfs_stack(i);
    }
    REP(i,1,n){
        vis[i] = false;
    }
    while(!S.empty()){
        int tmp = S.top();
        S.pop();
        if(!vis[tmp]){
            cnt++;
            dfs(tmp);
        }
    }
} 
int main(){
    int t;
    char str[MAX];
    sc(t);
    while(t--){
        cnt = 0;
        sc(n);
        REP(i,1,n){
            scs(str);
            rep(j,n){
                if(str[j] == 'Y'){
                    v[i].pb(j+1);
                    rev[j+1].pb(i);
                }
            }
        }
        kosaraju();
        out(cnt);
        REP(i,1,n){
            v[i].clear();
            rev[i].clear();
            vis[i] = false;
        }
    }
}
 

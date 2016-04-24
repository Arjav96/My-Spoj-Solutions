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
#define MAX 100001
#define MAX2 1000001
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
int par[MAX];
int size[MAX];
multiset<int> M;
void init(){
    REP(i,1,MAX){
        par[i] = i;
        size[i] = 1; 
    }
}
 
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
        M.erase(M.find(size[p]));
        M.erase(M.find(size[q]));
        size[q] += size[p];
        M.insert(size[q]); 
    }
    else{
        par[q] = par[p];
        M.erase(M.find(size[p]));
        M.erase(M.find(size[q]));
        size[p] += size[q];
        M.insert(size[p]);
    }
}
 
int main(){
	int n,q,a,b,ans=0;
	sc2(n,q);
	if(n == 1){printf("0\n"); return 0;}
	init();
	rep(i,n){
	    M.insert(1);
	}
	while(q--){
		sc2(a,b);
		if(root(a) != root(b)){
			uni(a,b);
			ans = *M.rbegin() - *M.begin();
			out(ans);
		}
		else{
			out(ans);
		}
	}
} 

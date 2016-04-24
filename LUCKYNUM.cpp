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
 
 
int main(){
	int t,n,flag,num,cntdig8,cntdig6;
	sc(t);
	while(t--){
		sc(n);
		flag = 0,cntdig8 = 0,cntdig6 = 0;
		queue<pair<int, pair<int,int> > > q;
		q.push(MP(6, MP(0, 1)));
		q.push(MP(8, MP(1, 0)));
		while(!q.empty()){
			num = q.front().first;
			cntdig8 = q.front().second.first;
			cntdig6 = q.front().second.second;
			if(cntdig8 + cntdig6 > 200){
				flag = 0; printf("-1\n"); break;
			}
			if(num % n == 0){
				flag = 1;
				rep(i,cntdig8) printf("8");
				rep(i,cntdig6) printf("6");
				printf("\n");
				break;
			}
			if(cntdig6){
				q.push(MP(num % n * 10 + 6, MP(cntdig8,cntdig6 + 1)));
			}
			else{
				q.push(MP(num % n * 10 + 6, MP(cntdig8,cntdig6 + 1)));
				q.push(MP(num % n * 10 + 8, MP(cntdig8 + 1, cntdig6)));
			}
			q.pop();
		}
	}
} 

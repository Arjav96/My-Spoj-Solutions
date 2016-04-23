/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * Created By : Arjav Jain
 * CSE, MNNIT-ALLAHABAD 
 * vampire18
 _._._._._._._._._._._._._._._._._._._._._.*/
 
#include<iostream>
#include<cstdio>
#include<cstring>
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
//typedef vector<int> vi; 
//typedef vector< vi > vvi; 
//typedef pair< int,int > ii; 
 
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
 
 
//vector< vector<int> > LPS(MAX, vector<int> (MAX,0) );
int LPS[MAX][MAX] = {0};
int _LPS_(char s[],int n){
	int j;
	rep(i,n){
		LPS[i][i] = 1;
	}
	REP(k,2,n){
		rep(i,n - k + 1){
			j = i + k -1;
			if(s[i] == s[j] && k == 2){
				LPS[i][j] = 2;
			}
			else if(s[i] == s[j]){
				LPS[i][j] = LPS[i+1][j-1] + 2;
			}
			else{
				LPS[i][j] = max(LPS[i][j-1], LPS[i+1][j]);
			}
		}
	}
	return LPS[0][n-1];
}
 
 
int main(){
	int t,len;
	char str[MAX];
	sc(t);
	while(t--){
		scs(str);
		len = strlen(str);
		printf("%d\n",(len - _LPS_(str,len)));
	}
} 

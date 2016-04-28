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
#define MAX 100009
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
int cost[10003];
vector<bool> vis(10003,false); 
vector<bool> check(10003,false);
void pre(){
	for(int i=3;i<100;i+=2){
		if(!check[i]){
			for(int j=i*i;j<10001;j+=2*i){
				check[j] = true;
			}
		}
	}
}
 
void dig(int arr[],int num){
	int len=3;
	while(num){
		arr[len--] = num % 10;
		num /= 10;
	}
}
 
int dignum(int arr[]){
	int num=0,d=0;
	while(d < 4){
		num = num*10 + arr[d++];
	}
	return num;
}
 
int main(){
	pre();
	int t,n,m,u,v,digit[4],tmp;
	sc(t);
	while(t--){
		ini(cost);
		sc2(n,m);
		queue<int> q;
		q.push(n);
		cost[n] = 0;
		while(!q.empty()){
			int no = q.front();
			q.pop();
			PER(i,0,3){
				dig(digit,no);
				REP(j,0,9){
					digit[i] = j;
					tmp = dignum(digit);
					if(tmp&1 && !check[tmp] && cost[tmp] == -1 && tmp >= 1000){
						cost[tmp] = cost[no] + 1;
						q.push(tmp);
					}
				}
			}
		}
		if(cost[m] == -1) printf("Impossible\n");
		else printf("%d\n",cost[m]);
	}
} 

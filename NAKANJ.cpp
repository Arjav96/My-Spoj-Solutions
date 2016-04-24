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
#define MAX 1000
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
bool vis[9][9] = {false};
int moves[9][9];
void bfs(string start,string end){
	queue<pair<int,int> > q;
	q.push(MP(start[0] - 'a',start[1] - '0'));
	//cout<<"#"<<start[0] - 'a'<<start[1] - '0'<<"#";
	vis[start[0] - 'a'][start[1] - '0'] = true;
	moves[start[0] - 'a'][start[1] - '0'] = 0;
	int col, row; 
	while(!q.empty()){
		col = q.front().first;
		row = q.front().second;
		//cout<<"#"<<col<<row<<"#";
		q.pop();
		if((col == (end[0] - 'a'))&&(row == (end[1] - '0'))){
			//cout<<"#\n";
			printf("%d\n",moves[col][row]);
			break;
		}
		if(((col + 1) <= 7)&&((row + 2) <= 8)){
			//cout<<"1\n";
			if(moves[col + 1][row + 2] > (moves[col][row] + 1)) moves[col + 1][row + 2] = moves[col][row] + 1;
			if(!vis[col + 1][row + 2]){
				//cout<<"1\n";
				q.push(MP(col + 1, row + 2));
				vis[col + 1][row + 2] = true;
			}
		}
		if(((col + 2) <= 7)&&((row + 1) <= 8)){
			//cout<<"2\n";
			if(moves[col + 2][row + 1] > (moves[col][row] + 1)) moves[col + 2][row + 1] = moves[col][row] + 1;
			if(!vis[col + 2][row + 1]){
				//cout<<"2\n";
				q.push(MP(col + 2, row + 1));
				vis[col + 2][row + 1] = true;
			}
		}
		if(((col - 1) >= 0)&&((row + 2) <= 8)){
			//cout<<"3\n";
			if(moves[col - 1][row + 2] > (moves[col][row] + 1)) moves[col - 1][row + 2] = moves[col][row] + 1;
			if(!vis[col - 1][row + 2]){
				//cout<<"3\n";
				q.push(MP(col - 1, row + 2));
				vis[col - 1][row + 2] = true;
			}
		}
		if(((col - 2) >= 0)&&((row + 1) <= 8)){
			//cout<<"4\n";
			if(moves[col - 2][row + 1] > (moves[col][row] + 1)) moves[col - 2][row + 1] = moves[col][row] + 1;
			if(!vis[col - 2][row + 1]){
				//cout<<"4\n";
				q.push(MP(col - 2, row + 1));
				vis[col - 2][row + 1];
			}
		}
		if(((col - 1) >= 0)&&((row - 2) >= 1)){
			//cout<<"5\n";
			if(moves[col - 1][row - 2] > (moves[col][row] + 1)) moves[col - 1][row - 2] = moves[col][row] + 1;
			if(!vis[col - 1][row - 2]){
				//cout<<"5\n";
				q.push(MP(col - 1, row - 2));
				vis[col - 1][row - 2];
			}
		}
		if(((col + 1) <= 7)&&((row - 2) >= 1)){
			//cout<<"6\n";
			if(moves[col + 1][row - 2] > (moves[col][row] + 1)) moves[col + 1][row - 2] = moves[col][row] + 1;
			if(!vis[col + 1][row - 2]){
				//cout<<"6\n";
				q.push(MP(col + 1, row - 2));
				vis[col + 1][row - 2];
			}
		}
		if(((col - 2) >= 0)&&((row - 1) >= 1)){
			//cout<<"7\n";
			if(moves[col - 2][row - 1] > (moves[col][row] + 1)) moves[col - 2][row - 1] = moves[col][row] + 1;
			if(!vis[col - 2][row - 1]){
				//cout<<"7\n";
				q.push(MP(col - 2, row - 1));
				vis[col - 2][row - 1];
			}
		}
		if(((col + 2) <= 7)&&((row - 1) >= 1)){
			//cout<<"8\n";
			if(moves[col + 2][row - 1] > (moves[col][row] + 1)) moves[col + 2][row - 1] = moves[col][row] + 1;
			if(!vis[col + 2][row - 1]){
				//cout<<"8\n";
				q.push(MP(col + 2, row - 1));
				vis[col + 2][row - 1];
			}
		}
	}
}
 
int main(){
	int t;
	sc(t);
	string start,end;
	while(t--){
		cin>>start>>end;
		//cout<<start<<end;
		memset(vis,0,sizeof(vis));
		rep(i,9){
			rep(j,9){
				moves[i][j] = 1000; 
				//cout<<moves[i][j]<<"\n";
			}
		}
		//while(!q.empty()){
		//	q.pop();
		//}
		bfs(start,end);
		
	}
} 

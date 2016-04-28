#include <cstdio>
using namespace std;
typedef long long ll;
#define MAX 100000
int sq_div[MAX+10], cnt[1400], range[750];
ll ans[MAX+10];
 
int total_div(int n) { 
	int div = 1, i, c;
	for(i=2; i*i<=n; ++i) {
		if(n % i == 0) {
			c = 0;
			while(n % i == 0) {
				n /= i;
				c++;
			}
			div *= (2*c+1);
		}
	}
	if(n>1) div *= 3;
	return div;
}
 
void pre() {
	int n, k, i;
	for(n=2; n<100000; ++n) {
		sq_div[n] = total_div(n);
		cnt[sq_div[n]]++;
	}
	for(k=1, i=0; k<=1323; k+=2) {		//tot_div for max perfect sq not exceeds 1323.
		range[(k-1)>>1] = i;
		if(!cnt[k]) continue;
		for(n=2; n<100000; ++n)
			if(sq_div[n]==k)
				ans[i++] = (ll)n*(ll)n;
	}
	range[(k-1)>>1] = i;
}
 
int lower(int k, ll n) {
	int low, high, mid;
	if(!cnt[k] || ans[range[(k-1)>>1]] >= n) return 0;
	low = range[(k-1)>>1]; high = range[((k-1)>>1) + 1];
	while(low < high-1) {
		mid = low + (high - low)/2;
		if(ans[mid] >= n) high = mid;
		else low = mid;
	}
	return low - range[(k-1)>>1] + 1;
}
 
int upper(int k, ll n) {
	int low, high, mid;
	if(!cnt[k] || ans[range[(k-1)>>1]] > n) return 0;
	low = range[(k-1)>>1]; high = range[((k-1)>>1) + 1];
	while(low < high - 1) {
		mid = low + (high - low)/2;
		if(ans[mid] > n) high = mid;
		else low = mid;
	}
	return low - range[(k-1)>>1] + 1;
}
 
int main() {
	int t, k;
	ll l, h;
	pre();
	scanf("%d", &t);
	while(t--) {
		scanf("%d%lld%lld", &k, &l, &h);
		if( k > 1323 || !cnt[k]) {
			printf("0\n");
			continue;
		}
		printf("%d\n", upper(k, h) - lower(k, l));
	}
	return 0;
} 

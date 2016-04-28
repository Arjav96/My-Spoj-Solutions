#include <bits/stdc++.h>
using namespace std;
int main() {
int t, n;
string s;
cin >> t;
while(t--) {
int ans = 0, state[26] = {0};
cin >> n >> s;
for(int i = 0; i < n-1; i++) {
char k = s[2 * i], d = s[2 * i + 1];
state[k - 'a']++;
if (state[d - 'A'])
state[d - 'A']--;
else
ans++;
}
cout << ans << endl;
}
return 0;
} 

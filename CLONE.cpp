//CLONE:::Use of map
 
#include <iostream>
#include <map>
using namespace std;
int main(){
int n,m,i;
string s;
cin>>n>>m;
while(n!=0){
map<string,int> m1;
for(i=0;i<n;i++){
cin>>s;
m1[s]++;
}
map<string,int>::iterator iter;
map<int,int> m2;
for (iter = m1.begin(); iter != m1.end(); ++iter) {
m2[iter->second]++;
}
for(i=1;i<=n;i++){
cout<<m2[i]<<endl;
}
cin>>n>>m;
}
} 

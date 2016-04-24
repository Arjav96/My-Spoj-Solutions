#include <iostream>
using namespace std;
int main(){
unsigned int i,j,k,n,c1,c2;
int t;
cin>>t;
while(t--){
cin>>n;
if(n%2!=0){
cout<<n<<endl;
continue;
}
k=1<<31;
j=31;
while((n&k)==0){
k=k>>1;
j--;
}
k=j;
//cout<<k<<endl;
i=0;
while(k>i){
c1=n&(1<<i);
c2=n&(1<<k);
j=~c1;
n&=j;
j=~c2;
n&=j;
c1=c1<<(k-i);
c2=c2>>(k-i);
n=n|c1|c2;
k--;
i++;
}
cout<<n<<endl;
}
} 

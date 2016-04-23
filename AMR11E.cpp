// find nth num which has 3 or more distinct prime factors.
 
#include<iostream>
#include<vector>
using namespace std;
int main(){
int T,n;
int num[3000],lucky[3000];
 
for(int i=0;i<3000;i++) 
num[i]=0;
 
for(int i=2;i<3000;i++){
	if(num[i]==0){
		for(int j=2*i;j<3000;j+=i){
			num[j]+=1;
		}
	}
}
vector<long long> arr;
for(int i=2;i<3000;i++){
	if(num[i]>=3){
		arr.push_back(i);
	}
}
 
cin>>T;
for(int i=0;i<T;i++){
cin>>n;
cout<<arr[n-1]<<endl;;
}
 
return 0;
} 

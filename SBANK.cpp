 
//This spoj problem may seem difficult in the beginning, but all that is required is a good knowledge of STL in C++. It simply required obtaining the account number from the user and storing it in a map. After this, just iterate through the map and print the values.
 
#include<iostream>
using namespace std;
#include<set>
#include<map>
#include<string>
#include<cstdio>
 
int main(){
int t;
for( scanf("%d", &t); t; t--){
int count;
char dummy;
map<string, int> table;
map<string, int>::iterator it;
char str[40];
for( scanf("%d\n", &count); count; count--){
gets(str);
table[(string)str]++;
}
for( it = table.begin(); it != table.end(); it++){
printf("%s %d\n", it->first.c_str(), it->second);
}
printf("\n");
}
}
   

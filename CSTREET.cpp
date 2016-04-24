#include <bits/stdc++.h>
using namespace std;
vector < pair<int,pair<int,int> > > graph;
 
int root(int *parent,int i)
{
    while(parent[i] != i)         
    {
    	parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}
 
int uni(int *parent,int *size,int A ,int B)
{
    int root_A = root(parent, A);       
    int root_B = root(parent, B);
    if(size[root_A] < size[root_B])
    {
        parent[root_A] = parent[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        parent[root_B] = parent[root_A];
        size[root_A] += size[root_B];
    }
}
 
int main() {
	int t,n,m,i,s,d;
	int price,l;
	scanf("%d",&t);
	while(t--)
	{
		graph.clear();
		scanf("%d",&price);
		scanf("%d%d",&n,&m);	
		int parent[n+5];
		int size[n+5];
		for(i=0;i<n+5;i++)
		{
			parent[i]=i;
			size[i]=1;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&s,&d,&l);
			graph.push_back(make_pair(l, make_pair(s,d)));
		}
		sort(graph.begin(),graph.end());
		int idx=0,u,v,pr;
		long long ans=0;
		while(idx != m-1)
		{
			pr=graph[idx].first;
			u=graph[idx].second.first;
			v=graph[idx].second.second;
			if(root(parent,u)!=root(parent,v))
			{	uni(parent,size,u,v);
			    ans += pr;
			}
			idx++;
		}
		printf("%lld\n",ans*price);
	}
	return 0;
}  

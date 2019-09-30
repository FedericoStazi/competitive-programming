#define INF 1000000
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <map>
using namespace std;
 
//ifstream in("input.txt");
//ofstream out("output.txt");
 
typedef long long ll;
int N,M,x,y;
int A[300005],pos[300005],foe[300005];
ll ans;
 
int main()
{
	
	cin>>N>>M;
	for(int i=1;i<N+1;i++)
	{
		//cin>>A[i];
		scanf("%d",&A[i]);
		pos[A[i]]=i;
		
	}
	for(int i=0;i<M;i++)
	{
		
		//cin>>x>>y;
		scanf("%d %d",&x,&y);
		
		if(foe[pos[x]]<pos[y] and pos[x]>pos[y])
			foe[pos[x]]=pos[y];
		
		if(foe[pos[y]]<pos[x] and pos[y]>pos[x])
			foe[pos[y]]=pos[x];
		
	}
	
	int L=1;
	int R=1;
	for(;R<N+1;R++)
	{
		
		L=max(L,foe[R]+1);
		
		ans+=(R-L)+1;
		
	}
	
	cout<<ans;
	
}
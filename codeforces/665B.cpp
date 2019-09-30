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
 
int pos[101];
int N,M,K,x;
int ans;
 
int main()
{
	
	cin>>N>>M>>K;
	for(int i=0;i<K;i++)
	{
		
		cin>>x;
		pos[x]=i+1;
		
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			
			cin>>x;
			ans+=pos[x];
			for(int k=1;k<K+1;k++)
				if(pos[k]<pos[x])
					pos[k]++;
			pos[x]=1;	
		}
	
	cout<<ans;
	
}
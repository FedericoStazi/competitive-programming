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
 
int A[300005];
int ans,N,K,L,R,O;
int maxL,maxR;
 
int main()
{
	
	cin>>N>>K;	
	for(int i=0;i<N;i++)
		cin>>A[i];
		
	while(R<N)
	{
		
		if(A[R]==0)
			O++;
		if(O>K)
		{
			
			while(A[L]==1)
				L++;
			L++;
			O--;
			
		}
		
		if(ans<R-L+1)	
		{
			
			ans=R-L+1;
			maxL=L;
			maxR=R;
			
		}
			
		R++;
		
	}
	
	cout<<ans<<"\n";
	
	for(int i=0;i<N;i++)
		if(i>=maxL and i<=maxR and ans!=0)
			cout<<1<<" ";
		else
			cout<<A[i]<<" ";
	
}
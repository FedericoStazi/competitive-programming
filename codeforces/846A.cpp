#define INF 1000000007
#include <bits/stdc++.h>
 
using namespace std;
 
ifstream in("input.txt");
ofstream out("output.txt");
 
int A[105];
int S0,D1,ans,N;
 
int main()
{
 
	ios::sync_with_stdio(false);
 
	cin>>N;	
	for(int i=0;i<N;i++)
		cin>>A[i];
 
	for(int i=0;i<N;i++)
		if(A[i])
			D1++;
		
	for(int i=0;i<N+1;i++)
	{
		
		ans=max(ans,S0+D1);
		if(A[i])
			D1--;
		else
			S0++;
		
	}
	
	cout<<ans;
 
}
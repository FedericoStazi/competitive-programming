#include<bits/stdc++.h>
using namespace std;
 
int N;
int A[1005],B[1005];
int x,ans;
 
int main()
{
	
	cin>>N;/*
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N;i++)
		cin>>B[i];	*/
	
	for(int i=0;i<N;i++)
		cin>>B[i]>>A[i];
	
	for(int i=0;i<N;i++)
	{
		x+=A[i];
		x-=B[i];
		ans=max(ans,x);
	}
	
	cout<<ans;
	
}
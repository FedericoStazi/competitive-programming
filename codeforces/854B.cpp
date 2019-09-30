#define INF 1000000007
#include <bits/stdc++.h>
 
using namespace std;
int N,K;
 
 
 
int main()
{
	
	cin>>N>>K;
	
	if(K==N or K==0)
		cout<<0;
	else
		cout<<1;
	cout<<" ";
	if(K<=N/3)
		cout<<2*K;
	else
		cout<<N-K;
	
}
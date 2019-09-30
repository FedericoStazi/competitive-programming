#define INF 1000000007
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
ll N,K;
ll C[300005];
ll A[600005];
priority_queue<pair<ll,ll> > PQ;
 
int main()
{
	
	cin>>N>>K;
	for(ll i=0;i<N;i++)
		cin>>C[i];
	
	for(ll i=0;i<N+K;i++)
	{
		
		if(i<N)
			PQ.push(make_pair(C[i],i));
		if(i>=K)
		{
			
			A[PQ.top().second]=i;
			PQ.pop();
			
		}
		
	}
	
	ll ans=0;
	
	for(ll i=0;i<N;i++)
		ans+=(A[i]-i)*C[i];
 
	cout<<ans<<endl;
	
	for(ll i=0;i<N;i++)
		cout<<A[i]+1<<" ";
	
}
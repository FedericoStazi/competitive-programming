#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
 
#ifndef ONLINE_JUDGE
#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
#endif
 
ll N,K;
ll P[100005];
ll C[100005];
ll sol[100005];
pii A[100005];
priority_queue<ll> PQ;
ll S;
 
int main()
{
 
	cin>>N>>K;
	for(ll i=0;i<N;i++)
		cin>>P[i];
	for(ll i=0;i<N;i++)
		cin>>C[i];
 
	for(ll i=0;i<N;i++)
		A[i]=make_pair(P[i],i);
	sort(A,A+N);
 
	for(ll i=0;i<N;i++)
	{
		sol[A[i].second]=S;
		PQ.push(-C[A[i].second]);
		S+=C[A[i].second];
		if(PQ.size()>K)
		{
			S+=PQ.top();
			PQ.pop();
		}
	}
 
	for(ll i=0;i<N;i++)
		cout<<sol[i]+C[i]<<" ";
	
	cerr<<"Tempo di esecuzione: "<<(1.0*clock() / CLOCKS_PER_SEC)<<"\n";
 
}
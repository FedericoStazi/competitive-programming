#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
 
ll N;
ll A[100005];
ll B[100005];
pair<ll,ll> V[100005];
ll ans;
 
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i]>>B[i];
		V[i]={B[i]-A[i],i};
	}
 
	sort(V,V+N);
	for(ll i=0;i<N;i++){
		int x=V[i].second;
		ans+=A[x]*i+B[x]*(N-i-1);
	}
 
	cout<<ans;
 
}
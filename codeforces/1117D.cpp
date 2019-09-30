#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
 
ll md=1e9+7;
ll N,M;
 
vector<ll> mult(vector<ll> A, pii a, vector<ll> B, pii b){
	
	assert(a.second==b.first);
 
	vector<ll> V(a.first*b.second);
 
	for(ll i=0;i<a.first;i++)
		for(ll k=0;k<a.second;k++)
			for(ll j=0;j<b.second;j++)
				V[b.second*i+j]=(V[b.second*i+j]+A[a.second*i+k]*B[b.second*k+j])%md;
 
	return V;
}
 
vector<ll> pot(vector<ll> A, pii a, ll k){
 
	if(k==1)
		return A;
 
	vector<ll> V;
	V=pot(A, a, k/2);
 
	V=mult(V, a, V, a);
 
	if(k%2)
		return mult(V, a, A, a);
	else
		return V;
}
 
int main(){
 
	cin>>N>>M;
 
	vector<ll> A(M,1);
	vector<ll> V(M*M);
	for(ll i=0;i<M-1;i++)
		V[i+1+M*i]=1;
	V[M*(M-1)]=V[M*M-1]=1;
 
	cout<<mult(pot(V,{M,M},N),{M,M},A,{M,1})[0];
 
	//this is another test
 
}
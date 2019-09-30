#include <iostream>
using namespace std;
typedef long long int ll;
 
ll N,Q;
ll INF=1e18;
ll A[100005],K[100005],V[100005],S[100005],G[100005];
ll R_sum[400005],R_min[400005],R_max[400005];
ll LP[400005];
char c;
ll x,y,z;
 
void prop(ll k, ll l, ll r){
 
	if(LP[k]==INF)
		return;
 
	if(l!=r){
 
		LP[2*k]=LP[k];
		LP[2*k+1]=LP[k];
	}
 
	R_sum[k]=(r-l+1)*LP[k];
	R_min[k]=LP[k];
	R_max[k]=LP[k];
	LP[k]=INF;
}
 
void upd(ll k, ll l, ll r, ll a, ll b, ll x){
 
	prop(k,l,r);
 
	if(r<a or b<l)
		return;
	else if(a<=l and r<=b){
		if(R_max[k]<x){
			LP[k]=x;
			prop(k,l,r);
			return;
		}
		else if(R_min[k]>=x)
			return;
	}
 
	ll m=(l+r)/2;
	upd(2*k,l,m,a,b,x);
	upd(2*k+1,m+1,r,a,b,x);
 
	R_sum[k]=R_sum[2*k]+R_sum[2*k+1];
	R_min[k]=R_min[2*k];
	R_max[k]=R_max[2*k+1];
 
}
 
ll que(ll k, ll l, ll r, ll a, ll b){
 
	prop(k,l,r);
 
	if(b<l or r<a)
		return 0;
	else if(a<=l and r<=b)
		return R_sum[k];
	else{
		ll m=(l+r)/2;
		return que(2*k,l,m,a,b)+que(2*k+1,m+1,r,a,b);
	}
 
}
 
void bui(ll k, ll l, ll r){
 
	LP[k]=INF;
 
	if(l==r){
		R_sum[k]=V[l];
		R_min[k]=V[l];
		R_max[k]=V[l];
	}
	else{
		ll m=(l+r)/2;
		bui(2*k,l,m);
		bui(2*k+1,m+1,r);
 
		R_sum[k]=R_sum[2*k]+R_sum[2*k+1];
		R_min[k]=R_min[2*k];
		R_max[k]=R_max[2*k+1];
	}
}
 
void pri(ll k, ll l, ll r){
	cout<<k<<" ("<<l<<","<<r<<") "<<R_sum[k]<<"/"<<R_min[k]<<"/"<<R_max[k]<<" "<<LP[k]<<endl;
	if(l!=r){
		ll m=(l+r)/2;
		pri(2*k,l,m);
		pri(2*k+1,m+1,r);
	}
	if(k==1)
		cout<<"----\n";
}
 
int main(){
 
	cin>>N;
	for(ll i=1;i<N+1;i++)
		cin>>A[i];
 
	for(ll i=1;i<N;i++)
		cin>>K[i];
 
	for(ll i=N;i>0;i--)
		S[i]=S[i+1]+K[i];
 
	for(ll i=N;i>0;i--)
		G[i]=G[i+1]+S[i];
 
	for(ll i=1;i<N+1;i++)
		V[i]=A[i]+S[i];
 
	bui(1,1,N);
 
	//for(int i=1;i<N+1;i++)cout<<i<<" "<<A[i]<<" "<<V[i]<<" "<<S[i]<<" "<<G[i]<<endl;
 
	cin>>Q;
	while(Q--){
		//pri(1,1,N);
		cin>>c>>x>>y;
		if(c=='+'){
			z=que(1,1,N,x,x)+y;
			upd(1,1,N,x,N,z);
		}
		else{
			z=que(1,1,N,x,y)-G[x]+G[y+1];
			cout<<z<<"\n";
		}
	}
 
}
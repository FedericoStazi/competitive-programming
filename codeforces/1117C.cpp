#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
 
ll K;
ll p,q,a,b;
ll X[100005],Y[100005];
ll vx[1005],vy[1005];
string S;
 
ll check(ll n){
	ll x=X[K]*(n/K)+X[n%K];
	ll y=Y[K]*(n/K)+Y[n%K];
	//cout<<x<<" "<<y<<endl;
	return abs(x-a)+abs(y-b)-n;
}
 
int main(){
 
	cin>>p>>q;
	cin>>a>>b;
	cin>>K;
	cin>>S;
 
	a-=p;
	b-=q;
 
	vx['R']=1;
	vx['L']=-1;
	vy['U']=1;
	vy['D']=-1;
 
	for(int i=0;i<K;i++){
		X[i+1]=X[i]+vx[S[i]];
		Y[i+1]=Y[i]+vy[S[i]];
	}
 
/*	for(int i=0;i<20;i++)
		cout<<i<<" "<<check(i)<<endl;
*/
	ll l=0,r=2e18,m;
	while(l<r){
		m=(l+r)/2;
		if(check(m)<=0)
			r=m;
		else
			l=m+1;
	}	
 
	if(l==2e18)
		l=-1;
 
	cout<<l;
 
}
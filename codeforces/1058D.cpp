#include <bits/stdc++.h>
using namespace std;
 
int n,m,k,a,b,k1,k2;
int ans1,ans2;
 
int main(){
	
	cin>>n>>m>>k;
 
	k1=__gcd(n,k);
	k/=k1;
 
	k2=__gcd(m,k);
	k/=k2;
 
	a=n/k1;
	b=m/k2;
 
	if(k>2){
		cout<<"NO";
		return 0;
	}
	else if(k==2){
		ans1=a;
		ans2=b;
	}
	else{
		ans1=a;
		ans2=b;
		if(k1!=1)
			ans1*=2;
		else
			ans2*=2;
	}
 
	cout<<"YES\n0 0\n"<<ans1<<" 0\n0 "<<ans2;
 
}
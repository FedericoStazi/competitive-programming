#include <iostream>
using namespace std;
typedef pair<int,pair<int,int> > piii;
 
int N,M;
int sol[10000000];
int aperte[10000000];
int chiuse[10000000];
string S;
int p,q;
 
piii query(int k, int l, int r, int a, int b){
 
	if(b < l or r  < a) return {0,{0,0}};
	else if(a <= l and r <= b) return {sol[k],{aperte[k],chiuse[k]}};
	else{
		int m=(l+r)/2;
		piii res,x,y;
		x=query(2*k,l,m,a,b);
		y=query(2*k+1,m+1,r,a,b);
 
		res.first=x.first+y.first+2*min(x.second.first-x.first/2,y.second.second-y.first/2);
		res.second={x.second.first+y.second.first,x.second.second+y.second.second};
 
		return res;
	}
 
}
 
void costruisci(int k, int l, int r){
 
	if(l==r){
		if(S[l]=='(')
			aperte[k]=1;
		else
			chiuse[k]=1;
	}
	else{
		int m=(l+r)/2;
		costruisci(2*k,l,m);
		costruisci(2*k+1,m+1,r);
 
		aperte[k]=aperte[2*k]+aperte[2*k+1];
		chiuse[k]=chiuse[2*k]+chiuse[2*k+1];
		sol[k]=sol[2*k]+sol[2*k+1]+2*min(aperte[2*k]-sol[2*k]/2,chiuse[2*k+1]-sol[2*k+1]/2);
	}
}
 
 
int main(){
 
	cin>>S;
	N=S.size();
	costruisci(1,0,N-1);
 
	cin>>M;
	while(M--){
		cin>>p>>q;
		p--,q--;
		cout<<query(1,0,N-1,p,q).first<<endl;
	}
 
}
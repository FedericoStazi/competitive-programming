#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
 
int G=2000006;
int N,L;
int x,y;
int X[300005],Y[300005];
vector<pii> V;
int R[20000006];
int LP[20000006];
int ans;
 
void prop(int k, int l, int r){
	if(l!=r){
		LP[2*k]+=LP[k];
		LP[2*k+1]+=LP[k];
	}
	R[k]+=LP[k];
	LP[k]=0;
}
 
void upd(int a, int b, int x, int k=1, int l=0, int r=2*G){
	prop(k,l,r);
	if(r<a or b<l)
		return;
	else if(a<=l and r<=b){
		LP[k]+=x;
		prop(k,l,r);
	}
	else{
		int m=(l+r)/2;
		upd(a,b,x,2*k,l,m);
		upd(a,b,x,2*k+1,m+1,r);
		R[k]=max(R[2*k],R[2*k+1]);
	}
}
 
int que(){
	return R[1];
}
 
int main(){
 
	cin>>N>>L;
	L*=2;
	for(int i=1;i<N+1;i++){
		cin>>x>>y;
		X[i]=x+y;
		Y[i]=y-x;
		V.push_back({X[i],i});
		V.push_back({X[i]+L+1,-i});
	}
 
	sort(V.begin(),V.end());
	//for(pii p:V)cout<<p.second<<" ("<<p.first<<") "<<X[abs(p.second)]<<" "<<Y[abs(p.second)]<<endl;
 
	for(pii p:V){
		if(p.second>0)
			upd(Y[p.second]+G,Y[p.second]+L+G,+1);
		else
			upd(Y[-p.second]+G,Y[-p.second]+L+G,-1);
		ans=max(ans,que());
	}
 
	cout<<ans;
 
}
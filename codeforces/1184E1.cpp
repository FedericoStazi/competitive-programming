#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
 
int N,M;
int a,b,x;
pair<int,pii> E[1000006];
int P[100005];
int S[100005];
 
int fi(int a){
	int b=a;
	while(b!=P[b])
		b=P[b];
 
	P[a]=b;
	return b;
}
 
void un(int a, int b){
 
	a=fi(a);
	b=fi(b);
 
	if(S[a]<S[b])
		swap(a,b);
 
	P[b]=a;
	S[a]=S[a]+S[b];
}
 
bool check(int w){
	
	for(int i=1;i<N+1;i++)
		P[i]=i,S[i]=1;
 
	for(int i=0;i<M;i++){
 
		if(E[i].first>=w){
			if(fi(a)!=fi(b))
				return true;
			else
				return false;
		}
 
		if(fi(E[i].second.first)!=fi(E[i].second.second))
			un(E[i].second.first,E[i].second.second);
 
	}
	if(fi(a)==fi(b))
		return false;
	else
		return true;
}
 
int main(){
 
	cin>>N>>M;
	M--;
	cin>>a>>b>>x;
	for(int i=0;i<M;i++)
		cin>>E[i].second.first>>E[i].second.second>>E[i].first;
	sort(E,E+M);
 
	int l=0,r=1e9+1,m;
	while(l<r){
		m=(l+r)/2;
		if(check(m))
			l=m+1;
		else
			r=m;
	}
 
	cout<<l-1;
 
}
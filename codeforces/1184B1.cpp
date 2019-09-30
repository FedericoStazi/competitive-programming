#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
 
int INF=1e5;
int B,S;
int x,y;
vector<pii> V;
int ans[200005];
int R;
 
int main(){
 
	cin>>S>>B;
	for(int i=0;i<S;i++){
		cin>>x;
		V.push_back({x,INF+i});
	}
	for(int i=0;i<B;i++){
		cin>>x>>y;
		V.push_back({x,y});
	}
	sort(V.begin(),V.end());
 
	for(pii p:V){
		if(p.second<INF)
			R+=p.second;
		else
			ans[p.second-INF]=R;
	}
 
	for(int i=0;i<S;i++)
		cout<<ans[i]<<" ";
 
}
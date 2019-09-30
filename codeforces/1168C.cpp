#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
 
int N,Q;
int K=21;
int A[300005];
int P[300005];
int R[25][300005];
int x,y;
 
vector<pii> V;
 
int main(){
 
	cin>>N>>Q;
	for(int i=0;i<N;i++)
		cin>>A[i];
	A[N]=(1<<25)-1;
 
	for(int j=0;j<K;j++)
		for(int i=0;i<N+1;i++)
			R[j][i]=N;
	
	for(int j=0;j<K;j++){
		x=-1;
		for(int i=0;i<N;i++)
			if(A[i]&(1<<j)){
				if(x!=-1)
					R[j][x]=i;
				x=i;
			}
	}
 
	for(int i=N-1;i>=0;i--){
 
		V.clear();
		for(int j=0;j<K;j++)
			V.push_back({R[j][i],j});
		sort(V.begin(),V.end());
 
		for(int a=0;a<V.size();a++)
			for(int b=a+1;b<V.size();b++)
				R[V[b].second][i]=min(R[V[b].second][i],R[V[b].second][R[V[a].second][i]]);
 
	}
 
	while(Q--){
 
		cin>>x>>y;
		x--,y--;
		bool flag=false;
 
		for(int j=0;j<K;j++)
			if(A[y]&(1<<j) and R[j][x]<=y)
				flag=true;
 
		if(flag)
			cout<<"Shi\n";
		else
			cout<<"Fou\n";
 
	}
 
}
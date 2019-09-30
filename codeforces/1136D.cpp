#include <iostream>
#include <vector>
using namespace std;
 
int N,M;
int P[1000006];
int C[1000006];
vector<int> grafo[1000006];
int x,y,ans;
 
int main(){
 
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>P[i];
	for(int i=0;i<M;i++){
		cin>>x>>y;
		grafo[y].push_back(x);
	}
	
	for(int i=N-1;i>=0;i--)
		if(C[P[i]]==N-1-i-ans and i!=N-1)
			ans++;
		else
			for(int f:grafo[P[i]])
				C[f]++;
 
	cout<<ans;
}
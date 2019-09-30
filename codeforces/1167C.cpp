#include <iostream>
#include <vector>
using namespace std;
 
int N,M;
int x,y;
vector<int> grafo[1000005];
bool V[1000005];
int A[1000005];
 
void DFS1(int k){
 
	if(V[k])
		return;
	V[k]=true;
 
	if(k<N)
		x++;
 
	for(int f:grafo[k])
		DFS1(f);
 
}
 
void DFS2(int k){
 
	if(A[k])
		return;
	A[k]=x;
 
	for(int f:grafo[k])
		DFS2(f);
 
}
 
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>x;
		while(x--){
			cin>>y;
			y--;
			grafo[N+i].push_back(y);
			grafo[y].push_back(N+i);
		}
	}
 
	for(int i=0;i<N;i++)
		if(!V[i]){
			x=0;
			DFS1(i);
			DFS2(i);
		}
		
	for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
 
}
#include <iostream>
using namespace std;
 
int N,D,M;
int x,y;
 
int main(){
 
	cin>>N>>D>>M;
	while(M--){
 
		cin>>x>>y;
 
		if(x+y<D){
			cout<<"NO\n";
			continue;
		}
 
		x=N-x;
		if(x+y<N-D){
			cout<<"NO\n";
			continue;
		}
 
		y=N-y;
		if(x+y<D){
			cout<<"NO\n";
			continue;
		}
 
		x=N-x;
		if(x+y<N-D){
			cout<<"NO\n";
			continue;
		}
 
		cout<<"YES\n";
 
	}
 
}
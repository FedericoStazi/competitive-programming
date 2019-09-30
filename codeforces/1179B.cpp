#include <iostream>
using namespace std;
 
int N,M;
 
void m(int x, int y){
	cout<<x+1<<" "<<y+1<<"\n";
}
 
int main(){
	cin>>N>>M;
	for(int i=0;i<N/2;i++){
		for(int j=0;j<M;j++){
			m(i,j);
			m(N-1-i,M-1-j);
		}
	}
	
	if(N%2){
		for(int i=0;i<M/2;i++){
			m(N/2,i);
			m(N/2,M-1-i);
		}
		if(M%2)
			m(N/2,M/2);
	}
}
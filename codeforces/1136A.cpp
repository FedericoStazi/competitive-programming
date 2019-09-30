#include <iostream>
using namespace std;
 
int N,K;
int L[1005];
int R[1005];
int ans;
 
int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>L[i]>>R[i];
	cin>>K;
	for(int i=0;i<N;i++)
		if(R[i]<K)
			ans++;
	cout<<N-ans;
}
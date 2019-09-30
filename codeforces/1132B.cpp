#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
 
ll N,M,S,x;
ll A[300005];
 
int main(){
	cin>>N;
	for(ll i=0;i<N;i++)
		cin>>A[i];
	sort(A,A+N);
	for(ll i=0;i<N;i++)
		S+=A[i];
	cin>>M;
	for(ll i=0;i<M;i++){
		cin>>x;
		cout<<S-A[N-x]<<"\n";
	}
 
}
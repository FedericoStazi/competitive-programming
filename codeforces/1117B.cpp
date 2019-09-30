#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
 
ll N,M,K;
ll A,B;
ll V[200005];
 
int main(){
 
	cin>>N>>M>>K;
	for(int i=0;i<N;i++)
		cin>>V[i];
 
	sort(V,V+N);
	A=V[N-1];
	B=V[N-2];
 
	cout<<((M/(K+1))*(K*A+B)+(M%(K+1))*A);
 
}
#include <iostream>
using namespace std;
typedef long long int ll;
 
ll N,M;
ll x,y;
 
int main(){
 
	cin>>N>>M;
 
	if(M==0){
		cout<<N<<" "<<N;
		return 0;
	}
 
	for(ll i=1,j=1;;j++,i+=j)
		if(M<=i){
			y=N-(j+1);
			break;
		}
 
	if(N%2==0)
		x=max(0LL,(N/2-M)*2);
	else
		x=max(0LL,((N+1)/2-M)*2-1);
	
	cout<<x<<" "<<y;
 
}
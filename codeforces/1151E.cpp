#include <iostream>
using namespace std;
typedef long long int ll;
 
ll N,x,y;
ll k,ans;
 
int main(){
 
	cin>>N;
 
	for(int i=0;i<N;i++){
		cin>>x;
		k=(max(x,y)-min(x,y)+1);
		ans+=(k-1)*(N-max(x,y)+min(x,y)+1);
		y=x;
	}
 
	y=0;
	k=(max(x,y)-min(x,y)+1);
	ans+=(k-1)*(N-max(x,y)+min(x,y)+1);
 
	cout<<ans/2;
 
}
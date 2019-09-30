#include <iostream>
using namespace std;
typedef long long int ll;
 
ll R;
 
int main(){
	cin>>R;
	for(ll x=1;x<1e6+5;x++){
		if(R-x*x-x-1>0 and (R-x*x-x-1)%(2*x)==0){
			cout<<x<<" "<<(R-x*x-x-1)/(2*x);
			return 0;
		}
	}
	cout<<"NO";
}
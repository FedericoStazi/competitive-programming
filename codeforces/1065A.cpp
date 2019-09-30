#include <iostream>
using namespace std;
typedef long long int ll;
 
int T;
ll A,B,S,C;
 
int main(){
	cin>>T;
	while(T--){
		cin>>S>>A>>B>>C;
		cout<<(S/C)+((S/C)/A)*B<<"\n";
	}
}
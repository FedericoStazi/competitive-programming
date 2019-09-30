#include <iostream>
using namespace std;
 
int N,K,M,T;
int x,y;
 
int main(){
	cin>>N>>K>>M>>T;
	while(T--){
		cin>>x>>y;
		if(x){
			if(K>=y)
				K++;
			N++;
		}
		else{
			if(K<=y)
				N=y;
			else{
				N-=y;
				K-=y;
			}
		}
		cout<<N<<" "<<K<<endl;
	}
}
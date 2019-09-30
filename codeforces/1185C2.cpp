#include <iostream>
using namespace std;
 
int N,M;
int x,S,ans;
int R[200005];
 
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
 
		cin>>x;
		S=ans=0;
 
		for(int j=0;j<101;j++)
			if(S+R[j]*j<=M-x){
				S+=R[j]*j;
				ans+=R[j];
			}
			else{
				ans+=(M-x-S)/j;
				break;
			}
 
		cout<<i-ans<<" ";
		R[x]++;
	}
}
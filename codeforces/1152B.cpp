#include <iostream>
#include <assert.h>
using namespace std;
 
int M[100];
int N;
int ans;
 
void pr(){
	cout<<ans<<"\n";
	for(int i=0;i<(ans+1)/2;i++)
		cout<<M[i]<<" ";
}
 
int main(){
	cin>>N;
	if(__builtin_popcount(N+1)==1){
		pr();
		return 0;
	}
	for(int s=20;s>0;s--){
		if((1<<s)>2*N)
			continue;
		M[ans/2]=s;
		ans++;
		N=N^((1<<s)-1);
		if(__builtin_popcount(N+1)==1){
			pr();
			return 0;
		}
		N++;
		ans++;
		if(__builtin_popcount(N+1)==1){
			pr();
			return 0;
		}
	}
	assert(false);
}
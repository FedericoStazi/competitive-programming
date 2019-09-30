#include <iostream>
using namespace std;
 
int res,ans,sol;
int N;
int A[100005];
 
int main(){
 
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
 
	for(int i=0;i<N;i++)
		res=max(res,A[i]);
	
	for(int i=0;i<N;i++){
		if(i and A[i]==res and A[i-1]==res)
			ans++;
		else
			ans=0;
		sol=max(sol,ans);
	}
 
	sol=max(sol,ans);
 
	cout<<sol+1;
 
}
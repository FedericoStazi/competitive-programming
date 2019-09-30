#include <iostream>
using namespace std;
 
int N,M;
int A[300005];
int B[300005];
 
bool check(int k){
 
	if(A[0]+k>=M)
		B[0]=0;
	else
		B[0]=A[0];
 
	for(int i=1;i<N;i++){
		if(A[i]+k>=M and (A[i]+k)%M>=B[i-1])
			B[i]=B[i-1];
		else if(A[i]+k>=B[i-1])
			B[i]=max(B[i-1],A[i]);
		else
			return false;
	}
	return true;
}
 
int main(){
 
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>A[i];
 
	int l=0,r=M,m;
	while(l<r){
		m=(l+r)/2;
		if(check(m))
			r=m;
		else
			l=m+1;
	}
	cout<<l;
}
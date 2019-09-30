#include <iostream>
using namespace std;
 
int N;
int A[1005];
int C[1000006];
int ans;
 
int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
 
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			C[A[i]+A[j]]++;
 
	for(int i=0;i<3e5;i++)
		if(C[ans]<C[i])
			ans=i;
 
	cout<<C[ans];
 
}
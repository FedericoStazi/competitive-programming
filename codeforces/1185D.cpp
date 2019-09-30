#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 
int N,m,p=-1;
bool flag;
int A[200005];
map<int,int> M;
 
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
		M[A[i]]=i+1;
	}
 
	sort(A,A+N);
 
	for(int i=1;i<N;i++)
		m=max(m,A[i]-A[i-1]);
 
	flag=true;
	for(int i=2;i<N;i++)
		if(A[i]-A[i-1]!=A[2]-A[1])
			flag=false;
	if(flag){
		cout<<M[A[0]];
		return 0;
	}
 
	flag=true;
	for(int i=1;i<N-1;i++)
		if(A[i]-A[i-1]!=A[1]-A[0])
			flag=false;
	if(flag){
		cout<<M[A[N-1]];
		return 0;
	}
 
	for(int i=1;i<N;i++)
		if(A[i]-A[i-1]!=m){
			if(A[i+1]-A[i-1]==m and p==-1)
				p=i++;
			else{
				cout<<-1;
				return 0;
			}
		}
 
	cout<<M[A[p]];
 
}
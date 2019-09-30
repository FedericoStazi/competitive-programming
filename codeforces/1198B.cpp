#include <iostream>
using namespace std;
 
int N,Q;
int t,x,y;
int A[200005];
int T[200005];
int P[200005];
 
int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	cin>>Q;
 
	for(int i=1;i<Q+1;i++){
		cin>>t;
		if(t==1){
			cin>>x>>y;
			x--;
			A[x]=y;
			T[x]=i;
		}
		else{
			cin>>x;
			P[i]=x;
		}
	}
 
	//for(int i=0;i<Q+1;i++)cout<<P[i]<<" ";cout<<endl;
 
	for(int i=Q+1;i>=0;i--)
		P[i]=max(P[i],P[i+1]);
 
	for(int i=0;i<N;i++)
		cout<<max(A[i],P[T[i]])<<" ";
 
}
#include <iostream>
using namespace std;
 
int N,M,Q;
int x,y,z;
int R[5000006];
int A[1000006];
int B[1000006];
int LP[5000006];
 
void prop(int k, int l, int r){
	if(l!=r){
		LP[2*k]+=LP[k];
		LP[2*k+1]+=LP[k];	
	}
	R[k]+=LP[k];
	LP[k]=0;
}
 
void upd(int b, int v, int k=1, int l=0, int r=1e6+1){
 
	prop(k,l,r);
 
	if(b<l)
		return;
	else if(r<=b){
		LP[k]+=v;
		prop(k,l,r);
	}
	else{
		int m=(l+r)/2;
		upd(b,v,2*k,l,m);
		upd(b,v,2*k+1,m+1,r);
		R[k]=min(R[2*k],R[2*k+1]);
	}
 
}
 
int que(int k=1, int l=0, int r=1000000+1){
 
	prop(k,l,r);
 
	if(R[k]>=0)
		return -1;
 
	if(l==r)
		return l;
 
	int m=(l+r)/2;
 
	prop(2*k+1,m+1,r);
 
	if(R[2*k+1]<0)
		return que(2*k+1,m+1,r);
	else
		return que(2*k,l,m);
 
}
 
int main(){
 
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>A[i];
		upd(A[i],-1);
	}
 
	for(int i=0;i<M;i++){
		cin>>B[i];
		upd(B[i],+1);
	}
 
	cin>>Q;
	while(Q--){
		cin>>x;
		if(x==1){
			cin>>y>>z;
			y--;
			upd(A[y],+1);
			A[y]=z;
			upd(A[y],-1);
		}
		else{
			cin>>y>>z;
			y--;
			upd(B[y],-1);
			B[y]=z;
			upd(B[y],+1);	
		}
		cout<<que()<<"\n";
	}
 
}
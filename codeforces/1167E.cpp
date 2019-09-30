#include <iostream>
using namespace std;
typedef long long int ll;
 
int N,X;
int A[1000006];
int frst[1000006],lst[1000006];
int P,Q;
int x;
ll ans;
 
int main(){
	cin>>N>>X;
	for(int i=0;i<N;i++){
		cin>>A[i];
		if(!frst[A[i]])
			frst[A[i]]=i+1;
		lst[A[i]]=i+1;
	}
 
	frst[X+1]=N+1;
	lst[X+1]=N+1;
 
	P=1;
	x=0;
	for(;P<X+1;P++)
		if(frst[P]){
			if(frst[P]<lst[x])
				break;
			x=P;
		}
 
	Q=X;
	x=X+1;
	for(;Q>0;Q--)
		if(frst[Q]){
		if(lst[Q]>frst[x])
			break;
		x=Q;
	}
 
/*	for(int i=0;i<X+2;i++)
		cout<<i<<") "<<frst[i]<<" "<<lst[i]<<endl;
*/
	for(int i=1;i<X+1;i++)
		if(!lst[i])
			lst[i]=lst[i-1];
 
	for(int i=X;i>0;i--)
		if(!frst[i])
			frst[i]=frst[i+1];
 
/*	for(int i=0;i<X+2;i++)
		cout<<i<<") "<<frst[i]<<" "<<lst[i]<<endl;
*/
	for(int l=1,r=Q;l<P+1;l++){
		while((lst[l-1]>=frst[r+1] or r<l) and r<X+1)
			r++;
		//cout<<l<<" "<<r<<endl;
		ans+=(ll)(X+1-r);
	}
 
	cout<<ans;
 
}
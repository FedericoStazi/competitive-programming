#include <iostream>
#include <assert.h>
using namespace std;
 
int N,x,q;
int a1,a2,b1,b2;
 
bool flag;
 
int query(int a, int b, int c, int d, bool chck=false){
	if(chck){
		assert(1<=a and a<=N);
		assert(1<=b and b<=N);
		assert(1<=c and c<=N);
		assert(1<=d and d<=N);
	}
	int r;
	cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	cin>>r;
	return r;
}
 
int main(){
 
	cin>>N;
 
	for(int i=1;i<N+1;i++){
		q=query(1,1,i,N);
		if((q%2) and !(x%2))
			a1=i;
		if(!(q%2) and (x%2))
			a2=i;
		x=q;
	}
 
	x=0;
	for(int i=1;i<N+1;i++){
		q=query(1,1,N,i);
		if((q%2) and !(x%2))
			b1=i;
		if(!(q%2) and (x%2))
			b2=i;
		x=q;
	}
 
	assert(a1+a2+b1+b2>1);
 
	if(!b1 and !b2){
		int l=1,r=N+1,m;
		while(l<r){
			m=(l+r)/2;
			q=query(a1,1,a1,m);
			if(q%2)
				r=m;
			else
				l=m+1;
		}
		b1=b2=l;
	}
	else if(!a1 and !a2){
		int l=1,r=N+1,m;
		while(l<r){
			m=(l+r)/2;
			q=query(1,b1,m,b1);
			if(q%2)
				r=m;
			else
				l=m+1;
		}
		a1=a2=l;
	}
	else if(!(query(a1,b1,a1,b1)%2))
		swap(b1,b2);
	cout<<"! "<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
 
}
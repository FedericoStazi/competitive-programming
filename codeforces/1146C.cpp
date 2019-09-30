#include <iostream>
#include <assert.h>
using namespace std;
 
int T;
int N;
int x,y;
 
int query(int a, int b){
	int res;
	cout<<1<<" "<<(b-a+1)<<" "<<1;
	for(int i=a;i<b+1;i++)
		cout<<" "<<i;
	cout<<endl;
	cin>>res;
	assert(res!=-1);
	return res;
}
 
int main(){
	cin>>T;
	while(T--){
 
		cin>>N;
 
		x=query(2,N);
		assert(x!=-1);
 
		int l=2,r=N+1,m;
		while(l<r){
			m=(l+r)/2;
			if(query(l,m)==x)
				r=m;
			else
				l=m+1;
		}
 
		cout<<1<<" "<<N-1<<" "<<l;
		for(int i=1;i<N+1;i++)
			if(i!=l)
				cout<<" "<<i;
		cout<<endl;
		cin>>x;
 
		cout<<"-1 "<<x<<endl;
 
	}
}
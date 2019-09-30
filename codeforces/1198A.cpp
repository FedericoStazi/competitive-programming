#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int ll;
 
ll N,I;
ll A[400005];
int M[400005];
int B[400005];
ll L,R=-1;
ll K;
ll ans;
 
ll lg(ll x){
	if(x==1)
		return 0;
	else
		return 32-__builtin_clz(x-1);
}
 
int main(){
 
	cin>>N>>I;
	for(ll i=0;i<N;i++)
		cin>>A[i];
	A[N]=-1;
 
	sort(A,A+N);
 
	int p=0;
	for(int i=0;i<N+1;i++)
		if(!i or A[i]!=A[i-1])
			M[i]=p++;
		else
			M[i]=p;
 
	while(L<N){
 
		while(true){
 
			R++;
			if(!B[M[R]])
				K++;
			B[M[R]]++;
 
			if(N*lg(K)>I*8 or R==N){
				B[M[R]]--;
				if(!B[M[R]])
					K--;
				R--;
				break;
			}
 
		}
 
		ans=max(ans,R-L+1);
 
		B[M[L]]--;
		if(!B[M[L]])
			K--;
		L++;
	}
 
	cout<<N-ans;
 
}
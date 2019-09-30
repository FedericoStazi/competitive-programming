#include <iostream>
#include <deque>
using namespace std;
typedef long long int ll;
 
ll N,M;
ll x,y;
deque<ll> Q;
pair<ll,ll> P[300005];
 
int main(){
 
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>x;
		Q.push_back(x);
	}
 
	for(int i=0;i<N-1;i++){
 
		x=Q.front();
		Q.pop_front();
		y=Q.front();
		Q.pop_front();
 
		P[i]={x,y};
 
		Q.push_back(min(x,y));
		Q.push_front(max(x,y));
	}
 
	for(int i=0;i<M;i++){
		cin>>x;
		if(x<N)
			cout<<P[x-1].first<<" "<<P[x-1].second<<"\n";
		else
			cout<<Q[0]<<" "<<Q[(x-1)%(N-1)+1]<<"\n";
	}
 
}
 
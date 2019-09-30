#include <iostream>
using namespace std;
typedef long long int ll;
 
ll md=1e9+7;
ll N;
ll DP[1005][1005];
 
ll F(int a, int b, bool c){
 
	if(c)
		return (F(a+1,b,false)+F(a,b+1,false))%md;
 
	if(DP[a][b])
		return DP[a][b];
 
	if(a>N or b>a or (a==N and b==N))
		return 0;
 
	if(b<a)
		DP[a][b]=(F(a+1,b,false)+F(a,b+1,true)+1)%md;
	else if(a<N)
		DP[a][b]=(F(a+1,b,true)+F(a,b+1,false)+1)%md;
 
	return DP[a][b];
}
 
int main(){
	cin>>N;
	cout<<F(0,0,false);
}
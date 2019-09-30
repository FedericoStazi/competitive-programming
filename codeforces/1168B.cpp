#include <iostream>
using namespace std;
typedef long long int ll;
 
ll N;
string S;
ll ans;
 
int main(){
	cin>>S;
	N=S.size();
	for(int l=0;l<N;l++)
		for(int r=l;r<l+9 and r<N+1;r++){
			bool flag=false;
			for(int i=l;i<r;i++)
				for(int j=1;i+2*j<r;j++)
					if(S[i]==S[i+j] and S[i]==S[i+2*j])
						flag=true;
			if(flag)
				ans++;
		}
	for(ll i=0;i<N;i++)
		ans+=max(0ll,N-(i+8));
	cout<<ans;
}
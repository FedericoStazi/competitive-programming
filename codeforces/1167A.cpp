#include <iostream>
using namespace std;
 
int T;
int N;
string S;
 
int main(){
	cin>>T;
	while(T--){
		bool flag=false;
		cin>>N>>S;
		for(int i=0;i<N-10;i++)
			if(S[i]=='8')
				flag=true;
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
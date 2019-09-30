#include <iostream>
using namespace std;
 
int N;
string P,S;
int DP[1005][1005];
 
int main(){
 
	cin>>N;
	cin>>P;
 
	for(int i=0;i<N;i++)
		if(!i or P[i]!=P[i-1])
			S.push_back(P[i]);
 
	N=S.size();
 
	for(int a=N-1;a>=0;a--)
		for(int b=a+1;b<=N;b++){
			if(b==a+1)
				DP[a][b]=1;
			else{
				DP[a][b]=DP[a+1][b]+1;
				int x=0;
				for(int c=a+1;c<b;c++)
					if(S[c]==S[a])
						DP[a][b]=min(DP[a][b],DP[a+1][c]+DP[c][b]);
			}
		}
 
	cout<<DP[0][N];
 
}
#include<bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define pb push_back
#define mp make_pair
#define Fx first
#define Sx second
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
#endif
 
int DP[3005][4];
int N;
int S[30005],C[30005];
int INF=1e9;
int ans=INF;
 
int main()
{
 
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>S[i];
	for(int i=0;i<N;i++)
		cin>>C[i];
 
	for(int i=0;i<N;i++)
		DP[i][0]=0;
	for(int i=0;i<N;i++)
		DP[i][1]=C[i];
 
	for(int i=0;i<N;i++)
		DP[i][2]=DP[i][3]=INF;
 
	for(int k=2;k<4;k++)
		for(int i=0;i<N;i++)
			for(int j=i-1;j>=0;j--)
				if(S[j]<S[i])
					DP[i][k]=min(DP[i][k],DP[j][k-1]+C[i]);
 
	for(int i=0;i<N;i++)
		ans=min(ans,DP[i][3]);
/*
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<4;j++)
			cout<<DP[i][j]<<" ";
		cout<<endl;
	}
*/
	if(ans==INF)
		ans=-1;
 
	cout<<ans;
 
	#ifndef ONLINE_JUDGE
	printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
	#endif
}
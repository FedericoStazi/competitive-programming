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
 
int N,M,K,S;
int A[100005];
vector<int> grafo[100005];
queue<int> Q;
int D[100005][100];
int INF=1e9;
int x,y;
int nodo;
bool V[100005];
int ans;
 
int main()
{
 
	cin>>N>>M>>K>>S;
 
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		A[i]--;
	}
 
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}
 
	for(int i=0;i<N;i++)
		for(int j=0;j<K;j++)
			D[i][j]=INF;
 
	for(int P=0;P<K;P++)
	{
 
		memset(V,false,sizeof(V));
 
		for(int i=0;i<N;i++)
			if(A[i]==P)
			{
				D[i][P]=0;
				Q.push(i);
				V[i]=true;
			}
 
		while(!Q.empty())
		{
			nodo=Q.front();
			Q.pop();
			for(int f:grafo[nodo])
				if(!V[f] and D[f][P]>D[nodo][P]+1)
				{
					V[f]=true;
					D[f][P]=D[nodo][P]+1;
					Q.push(f);
				}		
		}
 
	}
 
	for(int i=0;i<N;i++)
	{
		ans=0;
		sort(D[i],D[i]+K);
		for(int j=0;j<S;j++)
			ans+=D[i][j];
		cout<<ans<<" ";
	}
 
	#ifndef ONLINE_JUDGE
	printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
	#endif
}
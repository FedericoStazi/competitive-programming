#include<bits/stdc++.h>
using namespace std;
 
 
#ifndef ONLINE_JUDGE
#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
#endif
 
int N,A,B;
bool flag=true;
bool M[1005][1005];
 
int main()
{
 
	cin>>N>>A>>B;
 
	if(A!=1 and B!=1)
	{
		cout<<"NO";
		return 0;
	} 
 
	if(A==1 and B==1)
	{
		for(int i=0;i<N-1;i++)
			M[i][i+1]=M[i+1][i]=true;
		M[N][0]=M[0][N]=true;		
 
		if(N==2 or N==3)
		{
			cout<<"NO";
			return 0;
		}
		cout<<"YES\n";
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<M[i][j];
			cout<<"\n";
		}
 
		return 0;
	}
	
	if(B==1)
	{
		swap(A,B);
		flag=false;
	}
 
	for(int i=B-1;i<N;i++)
		for(int j=B-1;j<N;j++)
			if(i!=j)
				M[i][j]=true;
 
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(i!=j)
				M[i][j]=(M[i][j]^flag);
 
	cout<<"YES\n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<M[i][j];
		cout<<"\n";
	}
 
	#ifndef ONLINE_JUDGE
	printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
	#endif
 
}
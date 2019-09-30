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
 
int N;
int A[1000005];
bool V[1000005];
int k;
int ans;
 
int main()
{
 
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		A[i]--;
	}
 
	for(int i=0;i<N;i++)
		if(!V[i])
		{
			V[i]=true;
			k=i;
			do
			{
				k=A[k];
				V[k]=true;
				ans++;
			}while(k!=i);
			ans--;
		}
 
	if((ans%2)==(N%2))
		cout<<"Petr";	
	else
		cout<<"Um_nik";
 
	#ifndef ONLINE_JUDGE
	printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
	#endif
 
}
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
 
long double k;
long double x,y;
 
int main()
{
 
	cin>>x>>y;
 
	if((x==y) or (x==2 and y==4) or (x==4 and y==2))
		cout<<"=";
	else
	{
		k=y/x;
		if(pow(x,k-1)>k)
			cout<<">";
		else
			cout<<"<";
 
	}
 
	#ifndef ONLINE_JUDGE
	printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
	#endif
 
}
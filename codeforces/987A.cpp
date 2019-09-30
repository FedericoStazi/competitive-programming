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
map<string,int> colore;
map<int,string> nome;
int K[6];
string str;
 
int main()
{
 
	cin>>N;
 
	colore["purple"]=0;
	colore["green"]=1;
	colore["blue"]=2;
	colore["orange"]=3;
	colore["red"]=4;
	colore["yellow"]=5;
 
	nome[0]="Power";
	nome[1]="Time";
	nome[2]="Space";
	nome[3]="Soul";
	nome[4]="Reality";
	nome[5]="Mind";
 
	fori(0,N)
	{
		cin>>str;
		K[colore[str]]++;
	}
 
	cout<<6-N<<endl;
	fori(0,6)
		if(K[i]==0)
			cout<<nome[i]<<endl;
 
	#ifndef ONLINE_JUDGE
	printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
	#endif
}
#include <bits/stdc++.h>
#define fori(x,n) for(int i=x;i<n;i++)
#define forv(d,x,n) for(int d=x;d<n;d++)
#define mp make_pair
#define pb push_back
#define Fx first
#define Sx second
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
//#define cin in
//#define cout out
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int N;
int A[1000006];
char x,p='0';
int inizio;
string S;
 
int main()
{
 
    cin>>N;
    fori(0,N)
        cin>>A[i];
    cin>>S;
 
    fori(0,N-1)
    {
        x=S[i];
        if(x=='0')
        {
            if(p=='1')
            {
                sort(A+inizio,A+i+1);
            }
        }
        else
        {
            if(p=='0')
                inizio=i;
        }
        p=x;
    }
    if(p=='1')
    {
        sort(A+inizio,A+N);
    }
 
    bool flag=false;
    fori(0,N-1)
        //cout<<A[i]<<" ";
        if(A[i]>A[i+1])
            flag=true;
    if(flag)
        cout<<"NO";
    else
        cout<<"YES";
 
}
 
/*
#define tt pair<pii,int>
 
queue<tt> V,Q;
int N,T,x,y;
int currT,A[1005];
 
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>N;
		fori(0,N)
		{
			cin>>x>>y;
			V.push(mp(mp(x,y),i));
		}
		while(!V.empty() or !Q.empty())
        {
 
        }
	}
 
}*/
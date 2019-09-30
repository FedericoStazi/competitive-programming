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

vector<int> grafo[100005];
int N,Q,x,y;
int H[100005];

void DFS(int k, int p)
{
    H[k]=H[p]+1;
    for(int f:grafo[k])
        if(f!=p)
            DFS(f,k);
}

int main()
{

    cin>>N;
    fori(0,N-1)
    {
        cin>>x>>y;
        grafo[x].pb(y);
        grafo[y].pb(x);
    }

    DFS(1,0);

    cin>>Q;

    while(Q--)
    {
        cin>>x>>y;
        if((H[x]+H[y])%2==0)
            cout<<"Even\n";
        else
            cout<<"Odd\n";
    }

}

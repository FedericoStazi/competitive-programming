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
//ifstream in("savein.txt");
//ofstream out("saveout.txt");

int T,W;
string S;
map<string,int> M;
int A[7];

int main()
{

    cin>>T;
    M["mon"]=0;
    M["tues"]=1;
    M["wed"]=2;
    M["thurs"]=3;
    M["fri"]=4;
    M["sat"]=5;
    M["sun"]=6;
    while(T--)
    {
        cin>>W>>S;
        fori(0,7)
            A[i]=W/7;
        fori(28,W)
            A[(M[S]+i)%7]++;
        fori(0,7)
            cout<<A[i]<<" ";
        cout<<endl;
    }

}

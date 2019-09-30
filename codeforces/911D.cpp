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
 
int N,A[1500];
int M,x,y;
bool flag=true;
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    cin>>N;
 
    fori(0,N)
        cin>>A[i];
 
    fori(0,N)
        forv(j,0,i)
            if(A[i]<A[j])
                flag=!flag;
 
    cin>>M;
 
    fori(0,M)
    {
        cin>>x>>y;
        if((y-x)%4==1 or (y-x)%4==2)
            flag=!flag;
 
        if(flag)
            cout<<"even\n";
        else
            cout<<"odd\n";
    }
 
}
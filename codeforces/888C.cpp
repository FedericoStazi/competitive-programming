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
 
vector<int> A[26];
int ans=1e9,res;
string S;
 
int main()
{
 
    cin>>S;
 
    for(char c='a';c<='z';c++)
        A[c-'a'].pb(-1);
    fori(0,S.size())
        A[S[i]-'a'].pb(i);
    for(char c='a';c<='z';c++)
        A[c-'a'].pb(S.size());
 
    for(char c='a';c<='z';c++)
        {
            res=0;
            for(int i=0;i<A[c-'a'].size()-1;i++)
                res=max(res,A[c-'a'][i+1]-A[c-'a'][i]);
            ans=min(ans,res);
        }
 
    cout<<ans;
 
}
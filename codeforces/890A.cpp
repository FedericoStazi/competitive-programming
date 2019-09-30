#include <bits/stdc++.h>
#define fori(x,n) for(int i=x;i<n;i++)
#define forv(d,x,n) for(int d=x;d<n;d++)
#define mp make_pair
#define pb push_back
#define Fx first
#define Sx second
#define pii pair<int,int>
#define ll long long
 
using namespace std;
 
int A[6];
int K,X,Y;
 
int main()
{
 
    ios::sync_with_stdio(false);
 
    fori(0,6)
        cin>>A[i];
 
    fori(0,64)
    {
        K=X=Y=0;
        forv(j,0,6)
            if(i&(1<<j))
                K++;
        if(K==3)
            forv(j,0,6)
                if(i&(1<<j))
                    X+=A[j];
                else
                    Y+=A[j];
 
        if(X==Y and K==3)
        {
            cout<<"YES";
            return 0;
        }
    }
 
    cout<<"NO";
 
}
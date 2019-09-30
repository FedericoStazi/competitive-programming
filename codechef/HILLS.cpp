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

int T;
int N,U,D;
int x,p;

int main()
{

    cin>>T;
    while(T--)
    {
        cin>>N>>U>>D;

        int flag=-1;
        int G=1;

        cin>>p;
        for(int i=1;i<N;i++)
        {
            cin>>x;
            if(x>=p and x-p<=U)
                p=x;
            else if(x<=p and p-x<=D)
                p=x;
            else if(G and x<=p)
            {
                G--;
                p=x;
            }
            else if(flag==-1)
                flag=i-1;
        }

        if(flag==-1)
            flag=N-1;

        cout<<flag+1<<endl;

    }

}
/*
3
5 3 2
2 5 2 6 3
5 2 3
4 4 4 4 4
5 2 7
1 4 3 2 1
*/

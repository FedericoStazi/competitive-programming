#pragma GCC optimize("Ofast")
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
#define ld long double
//#define cin in
//#define cout out

using namespace std;

int T;
int N;
int A[100005],B[100005];
int p,ans;
bool flag,f2;
vector<pii> V;
int L[100005],R[100005];
priority_queue<pii> PQA,PQB;
int RT[200005];

void s()
{
    cout<<"L: ";
    fori(0,N)
        cout<<L[i]<<" ";
    cout<<"\nR: ";
    fori(0,N)
        cout<<R[i]<<" ";
    cout<<"\n";
}

void iniz()
{
    fori(0,N)
        RT[i]=A[i];
}

void upd(int x, int y, int k)
{
    fori(x,y+1)
        RT[i]=k;
}

int que(int k)
{
    return RT[k];
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;
        fori(0,N)
            cin>>A[i];
        fori(0,N)
            cin>>B[i];

        iniz();

        f2=true;
        fori(0,N)
            if(B[i]>A[i])
                f2=false;

        if(!f2)
            cout<<"-1\n";
        else
        {

            V.clear();
            fori(0,N)
                V.pb(mp(-B[i],i));
            sort(V.begin(),V.end());

            ans=0;
            fori(0,N)
            {
                L[i]=-1;
                R[i]=-1;
            }

            ///DESTRA

            fori(0,N)
            {
                PQA.push(mp(B[i],i));
                PQB.push(mp(-B[i],i));

                while(!PQA.empty() and PQA.top().Fx>A[i])
                {
                    if(R[PQA.top().Sx]==-1)
                        R[PQA.top().Sx]=i-1;
                    PQA.pop();
                }

                while(!PQB.empty() and -PQB.top().Fx<B[i])
                {
                    if(R[PQB.top().Sx]==-1)
                        R[PQB.top().Sx]=i-1;
                    PQB.pop();
                }

            }

            while(!PQA.empty())
            {
                if(R[PQA.top().Sx]==-1)
                    R[PQA.top().Sx]=N-1;
                PQA.pop();
            }

            while(!PQB.empty())
            {
                if(R[PQB.top().Sx]==-1)
                    R[PQB.top().Sx]=N-1;
                PQB.pop();
            }

            assert(PQA.empty() and PQB.empty());

            ///SINISTRA

            for(int i=N-1;i>=0;i--)
            {
                PQA.push(mp(B[i],i));
                PQB.push(mp(-B[i],i));

                while(!PQA.empty() and PQA.top().Fx>A[i])
                {
                    if(L[PQA.top().Sx]==-1)
                        L[PQA.top().Sx]=i+1;
                    PQA.pop();
                }

                while(!PQB.empty() and -PQB.top().Fx<B[i])
                {
                    if(L[PQB.top().Sx]==-1)
                        L[PQB.top().Sx]=i+1;
                    PQB.pop();
                }

            }

            while(!PQA.empty())
            {
                if(L[PQA.top().Sx]==-1)
                    L[PQA.top().Sx]=0;
                PQA.pop();
            }

            while(!PQB.empty())
            {
                if(L[PQB.top().Sx]==-1)
                    L[PQB.top().Sx]=0;
                PQB.pop();
            }

            assert(PQA.empty() and PQB.empty());

            ///SOLUZIONE

            forv(j,0,N)
            {

                p=V[j].Sx;

                //cout<<"x "<<que(p)<<" "<<B[p]<<endl;
                if(que(p)!=B[p])
                {
                    ans++;
                    upd(L[p],R[p],B[p]);

                }

            }

            cout<<ans<<'\n';
        }
    }
}

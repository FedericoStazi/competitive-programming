#include<bits/stdc++.h>
#define fori(x,y) for(int i=x;i<y;i++)
#define forv(x,y,z) for(int x=y;x<z;x++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pait<ll,ll>

using namespace std;

int T;
int N,Q;
int q;
int l,r,m;
int p;
int cmin,cmag;
bool flag;
int A[100005],B[100005];
map<int,int> minori,maggiori;
map<int,int> pos;
int smin,smag;

int main()
{

    ios::sync_with_stdio(false);

    cin>>T;

    while(T--)
    {

        cin>>N>>Q;

        maggiori.clear();
        minori.clear();
        pos.clear();

        fori(0,N)
            cin>>A[i+1];

        fori(0,N)
            B[i+1]=A[i+1];

        fori(0,N)
            pos[A[i+1]]=i+1;

        sort(B+1,B+N+1);

        fori(0,N)
        {
            minori[B[i+1]]=i;
            maggiori[B[i+1]]=N-1-i;
        }

        while(Q--)
        {
            cin>>q;
            l=1;
            r=N;
            cmin=0;
            cmag=0;
            smin=0;
            smag=0;
            p=pos[q];
            flag=true;

            while(l<=r and flag)
            {
                m=(l+r)/2;

                if(m==p)
                {
                    flag=false;
                }
                else if(m<p)
                {
                    if(A[m]>q)
                    {
                        cmin++;
                        smin++;
                        //cout<<"1a\n";
                    }
                    else
                    {
                        cmin++;
                        //cout<<"1b\n";
                    }
                    l=m+1;
                }
                else if(m>p)
                {
                    if(A[m]<q)
                    {
                        cmag++;
                        smag++;
                        //cout<<"2a\n";
                    }
                    else
                    {
                        cmag++;
                        //cout<<"2b\n";
                    }
                    r=m-1;
                }

            }
            //cout<<"x "<<cmin<<" "<<smin<<" "<<cmag<<" "<<smag<<endl;


            if(cmin>minori[q] or cmag>maggiori[q])
                cout<<-1<<endl;
            else
                cout<<max(smin,smag)<<endl;

        }

    }

}

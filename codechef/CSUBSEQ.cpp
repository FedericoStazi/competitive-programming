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
//#define cin in #define cout out

using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");


struct B
{

    int i;
    int a;
    int b;
    int c;
    int d;

    void R()
    {
        i=0;
        a=0;
        b=0;
        c=0;
        d=0;
    }


}l,p;

int T,N,K,ans;
string S;
deque < pair<B,int> > Q;
int dist;
bool V[260][34][34][34][34];

bool F(B h)
{

    bool j=V[h.i][h.a][h.b][h.c][h.d];
    V[h.i][h.a][h.b][h.c][h.d]=true;
    return j;

}

int main()
{

    cin>>T;

    while(T--)
    {
        Q.clear();

        cin>>N>>K;
        cin>>S;

        l.R();
        Q.push_front(mp(l,0));

        while(true)
        {

            if(Q.empty())
            {
                cout<<"-1\n";
                break;
            }

            l=Q.front().Fx;
            dist=Q.front().Sx;
            Q.pop_front();

            if(l.i==N and l.d==K)
            {
                cout<<dist<<endl;
                break;
            }

            if(l.i==N)
                continue;

            if(S[l.i]=='c')
            {
                p=l;
                p.a=min(p.a+1,K+1);
                p.i++;
                if(!F(p))
                    Q.push_front(mp(p,dist));
            }

            if(S[l.i]=='h')
            {
                p=l;
                p.b=min(p.b+p.a,K+1);
                p.i++;
                if(!F(p))
                    Q.push_front(mp(p,dist));
            }

            if(S[l.i]=='e')
            {
                p=l;
                p.c=min(p.c+p.b,K+1);
                p.i++;
                if(!F(p))
                    Q.push_front(mp(p,dist));
            }

            if(S[l.i]=='f')
            {
                p=l;
                p.d=min(p.d+p.c,K+1);
                p.i++;
                if(!F(p))
                    Q.push_front(mp(p,dist));
            }

            p=l;
            p.i++;
            if(!F(p))
                Q.push_back(mp(p,dist+1));

        }

        if(T)
        {
            memset(V,false,sizeof(V));
        }

    }

}

/*
        fori(1,N+1)
        {
            forv(a,0,2*K+3)
                forv(b,0,2*K+3)
                    forv(c,0,2*K+3)
                        forv(d,0,2*K+3)
                            if(true)///TODO
                            {
                                if(S[i-1]=='c' and a-1 >= 0)
                                    DP[i][a][b][c][d]=min(DP[i][a][b][c][d],DP[i
                                        -1][a-1][b][c][d]);
                                if(S[i-1]=='h' and b-a >= 0)
                                    DP[i][a][b][c][d]=min(DP[i][a][b][c][d],DP[i
                                        -1][a][b-a][c][d]);
                                if(S[i-1]=='e' and c-b >= 0)
                                    DP[i][a][b][c][d]=min(DP[i][a][b][c][d],DP[i
                                        -1][a][b][c-b][d]);
                                if(S[i-1]=='f' and d-c >= 0)
                                    DP[i][a][b][c][d]=min(DP[i][a][b][c][d],DP[i
                                        -1][a][b][c][d-c]);

                                DP[i][a][b][c][d]=min(DP[i][a][b][c][d],DP[i
                                    -1][a][b][c][d]+1);

                                if(d==K and i==N)
                                    ans=min(ans,DP[i][a][b][c][d]);

                                cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "
                                    <<DP[i][a][b][c][d]<<endl;
                            }
        }


*/
/*
5
7 3
chehefc
8 4
chehefch
19 24
ccccchhhhheeeeeffff
20 5
echhhfhfcecfhechfcch
99 27
ffhffhffcfechchccccfhhhfhhhhhhehhhehhhhheeeeefeeeeeeheeheeeeffcfffffffffffhffffc
    hffeffcefefhhfcehfe
*/

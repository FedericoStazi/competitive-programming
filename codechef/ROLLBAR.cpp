#include <iostream>
#include <queue>
using namespace std;
typedef pair<pair<int,int>,int> ppi;

int T;
int N,M,x,y;
int D[1005][1005][5];
bool V[1005][1005][5];
char A[1005][1005];
queue<ppi> Q;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>M>>x>>y;
        for(int i=0;i<N+2;i++)
            for(int j=0;j<M+2;j++)
                A[i][j]='0';
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cin>>A[i+1][j+1];

        for(int i=0;i<N+2;i++)
            for(int j=0;j<M+2;j++)
                for(int k=0;k<5;k++)
                    D[i][j][k]=1e9,V[i][j][k]=false;

        D[x][y][0]=0;
        Q.push({{x,y},0});

        while(!Q.empty()){

            ppi p,q;
            p=Q.front();
            Q.pop();

            //cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;

            if(p.first.first<1 or p.first.first>N or p.first.second<1 or p.first
                .second>M)
                continue;
            if(p.second==1 and (p.first.first-1<1 or A[p.first.first-1][p.first
                .second]=='0'))
                continue;
            if(p.second==2 and (p.first.second+1>M or A[p.first.first][p.first
                .second+1]=='0'))
                continue;
            if(p.second==3 and (p.first.first+1>N or A[p.first.first+1][p.first
                .second]=='0'))
                continue;
            if(p.second==4 and (p.first.second-1<1 or A[p.first.first][p.first
                .second-1]=='0'))
                continue;
            if(V[p.first.first][p.first.second][p.second] or A[p.first.first][p
                .first.second]=='0')
                continue;
            V[p.first.first][p.first.second][p.second]=true;

            if(p.second==0){
                q={{p.first.first-1,p.first.second},1};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second+1},2};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first+1,p.first.second},3};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second-1},4};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);
            }

            if(p.second==1){
                q={{p.first.first-2,p.first.second},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second+1},1};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first+1,p.first.second},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second-1},1};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);
            }

            if(p.second==2){
                q={{p.first.first-1,p.first.second},2};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second+2},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first+1,p.first.second},2};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second-1},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);
            }

            if(p.second==3){
                q={{p.first.first-1,p.first.second},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second+1},3};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first+2,p.first.second},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second-1},3};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);
            }

            if(p.second==4){
                q={{p.first.first-1,p.first.second},4};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second+1},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first+1,p.first.second},4};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);

                q={{p.first.first,p.first.second-2},0};
                Q.push(q);if(!(q.first.first<1 or q.first.first>N) and !(q.first
                    .second<1 or q.first.second>M) and A[q.first.first][q.first
                    .second]!='0')
                D[q.first.first][q.first.second][q.second]=min(D[q.first
                    .first][q.first.second][q.second],D[p.first.first][p.first
                    .second][p.second]+1);
            }

        }

        for(int i=1;i<N+1;i++){
            for(int j=1;j<M+1;j++)
                if(D[i][j][0]==1e9 or A[i][j]=='0')
                    cout<<"-1 ";
                else
                    cout<<D[i][j][0]<<" ";
            cout<<endl;
        }

    }

}
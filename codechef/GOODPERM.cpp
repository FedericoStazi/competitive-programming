#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

#ifndef ONLINE_JUDGE
#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
#endif

int T,N,K;
vector<int> V;
int A[10];
int res,ans;
bool flag;

int main()
{

    cin>>T;

    while(T--)
    {

        ans=0;

        cin>>N>>K;
        for(int i=0;i<N;i++)
            cin>>A[i];

        V.clear();
        for(int i=0;i<N;i++)
            V.push_back(i+1);

        do{

            res=0;
            flag=true;

            for(int i=0;i<N;i++)
                if(A[i]!=V[i] and A[i]!=0)
                    flag=false;

            if(flag)
            {

                for(int i=0;i<N-1;i++)
                        if(V[i+1]>V[i])
                            res++;

                if(res==K)
                    ans++;
                
            }

        }while(next_permutation(V.begin(),V.end()));

        cout<<ans<<endl;
    }

    #ifndef ONLINE_JUDGE
    printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
    #endif

}
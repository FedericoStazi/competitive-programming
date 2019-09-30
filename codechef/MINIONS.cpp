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
 
int T,N;
ll A[400005];
ll B[400005];
vector<pii> V;
priority_queue<pll> migliori,riserve;
ll x,S;
 
int main()
{
 
    cin>>T;
 
    while(T--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>A[i]>>B[i];
            V.push_back(make_pair(A[i],i));
        }
        
        sort(V.begin(),V.end(),greater<pii>());

        for(pii p:V)
        {

            int i=p.second;

            if(!migliori.empty() and migliori.top().first>B[i])
            {
                x=migliori.top().second;
                S-=B[x];
                S+=B[i];
                migliori.pop();
                migliori.push(make_pair(B[i],i));
                riserve.push(make_pair(-B[x],x));
            }
            else
                riserve.push(make_pair(-B[i],i));

            while(!riserve.empty() and ((ll)migliori.size()+1)*A[i]>=(S-riserve
                .top().first))
            {
                x=riserve.top().second;
                riserve.pop();
                S+=B[x];
                migliori.push(make_pair(B[x],x));
            }

        }
 
        cout<<migliori.size()<<endl;
 
        while(!migliori.empty())
            migliori.pop();
        while(!riserve.empty())
            riserve.pop();
        V.clear();
        S=0;
 
    }
 
 
    #ifndef ONLINE_JUDGE
    printf("Tempo di esecuzione: %.6f",1.0*clock() / CLOCKS_PER_SEC);
    #endif
 
} 
#include <iostream>
#include <set>
#include <algorithm>
#include <bitset>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long int ll;
typedef bitset<14> bs;

ll N,M;
string S[2],P[2][15];
set<ll> Q[2][15];
vector<ll> V[2];
vector<ll> res[2];
ll ans;
ll foll[2][15][100005];

vector<int> z_function(string s) {
    int n=s.size();
    vector<int> Z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r)
            Z[i]=min(r-i+1,Z[i-l]);
        while(i+Z[i]<n and s[Z[i]]==s[i+Z[i]])
            Z[i]++;
        if(i+Z[i]-1>r)
            l=i,r=i+Z[i]-1;
    }
    return Z;
}

int main(){

    cin>>N>>M;

    cin>>S[0];
    S[1]=S[0];
    reverse(S[1].begin(),S[1].end());

    for(ll k=0;k<M;k++){
        cin>>P[0][k];
        P[1][k]=P[0][k];
        reverse(P[1][k].begin(),P[1][k].end());
    }

    for(ll t=0;t<2;t++)
        for(ll k=0;k<M;k++){
            vector<int> v=z_function(P[t][k]+"$"+S[t]);
            foll[t][k][N]=N+1;
            for(int i=v.size()-1;i>=P[t][k].size()+1;i--)
                if(v[i]==P[t][k].size())
                    foll[t][k][i-P[t][k].size()-1]=i-P[t][k].size()-1;
                else
                    foll[t][k][i-P[t][k].size()-1]=foll[t][k][i-P[t][k].size()];
        }

    for(int b=0;b<(1<<M);b++){

        if(__builtin_popcount(b)!=M/2)
            continue;

        V[0].clear();
        V[1].clear();
        res[0].clear();
        res[1].clear();

        for(ll k=0;k<M;k++)
            V[(b>>k)&1].push_back(k);

        for(ll t=0;t<2;t++){

            assert(V[t].size()<8);

            do{
                ll q=0;
                for(ll p=0;p<V[t].size() and q<N+1;p++)
                    q=foll[t][V[t][p]][q]+P[t][V[t][p]].size();
                if(t==0)
                    res[t].push_back(q-1);
                else
                    res[t].push_back(N-q);

            }while(next_permutation(V[t].begin(),V[t].end()));
        }

        sort(res[0].begin(),res[0].end());
        sort(res[1].begin(),res[1].end());

        ll x=0,y=0;

        while(x<res[0].size() and y<res[1].size()){
            while(res[1][y]<=res[0][x] and y<res[1].size())
                y++;
            if(x<res[0].size() and y<res[1].size())
                ans+=((ll)res[1].size()-y);
            x++;
        }

    }

    cout<<ans;

}
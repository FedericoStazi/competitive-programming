#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
#include <set>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

ll N,M;
string S[10005];
char P[1000006];
vector<int> V;
priority_queue<pii> PQ[10005];
int C[10005];
multiset<int> R;
int d,f;
bool flag;

ll H(){
    return (*R.begin()+*R.rbegin())/2;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>S[i];
        M+=S[i].size();
    }

    for(int i=0;i<N;i++)
        for(char l:S[i])
            if(l<'2')
                f++;

    for(int i=0;i<N;i++){
        PQ[S[i][0]].push({0,i});
        R.insert(0);
    }

    if(f<500000){
        P[0]='0';
        for(int i=1;i<M;i++){
            if(P[i-1]=='9')
                P[i]='8';
            else if(P[i-1]=='0')
                P[i]='1';
            else if(P[i-2]<P[i-1])
                P[i]=P[i-1]+1;
            else
                P[i]=P[i-1]-1;
        }
    }
    else{
        P[0]='0';
        for(int i=1;i<M;i++){
            if(P[i-1]=='9')
                P[i]='8';
            else if(P[i-1]=='0'){
                for(int j=0;j<3 and i<M;j++,i++)
                    P[i]='0'+1-(j%2);
                i--;
            }
            else if(P[i-2]<P[i-1])
                P[i]=P[i-1]+1;
            else
                P[i]=P[i-1]-1;
        }   
    }

    while(V.size()<M){

        char c=P[d++];
        flag=false;

        while(!PQ[c].empty() and C[PQ[c].top().second]<=H() or !flag){

            flag=true;
            if(PQ[c].empty())
                break;
            int i=PQ[c].top().second;

            V.push_back(i);
            C[i]++;

            R.erase(C[i]-1);
            R.insert(C[i]);
            PQ[c].pop();
            if(C[i]<S[i].size())
                PQ[S[i][C[i]]].push({-C[i],i});
        }
            
    }

    for(ll x:V)cout<<x+1<<" ";

}   
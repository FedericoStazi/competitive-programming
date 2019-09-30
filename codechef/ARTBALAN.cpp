#include <iostream>
#include <algorithm>
using namespace std;

int T;
string S;
int V[1005];
int ans,res;

int main(){
    cin>>T;
    while(T--){

        cin>>S;
        ans=1e9;
        for(int c='A';c<'Z'+1;c++)
            V[c]=0;

        for(char c:S)
            V[c]++;
        sort(V+'A',V+'Z'+1,greater<int>());

        for(int k=1;k<'Z'-'A'+2;k++){
            if(S.size()%k)
                continue;
            res=0;
            for(int i='A';i<'A'+k;i++)
                if(V[i]>S.size()/k)
                    res+=V[i]-(S.size()/k);
            for(int i='A'+k;i<'Z'+1;i++)
                res+=V[i];
            ans=min(ans,res);
        }

        cout<<ans<<endl;
    }
}
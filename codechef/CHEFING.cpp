#include <iostream>
using namespace std;

int T;
int N;
string S[1005];
bool B[1005][1005];
bool flag;
int ans;

int main(){
    cin>>T;
    while(T--){

        cin>>N;
        for(int i=0;i<N;i++)
            cin>>S[i];

        for(int i=0;i<N;i++)
            for(int c='a';c<'z'+1;c++)
                B[c][i]=false;
        ans=0;

        for(int i=0;i<N;i++)
            for(char c:S[i])
                B[c][i]=true;

        for(int c='a';c<'z'+1;c++){
            flag=true;
            for(int i=0;i<N;i++)
                flag&=B[c][i];
            if(flag)
                ans++;
        }

        cout<<ans<<endl;
    }
}
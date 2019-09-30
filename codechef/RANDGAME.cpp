#include <iostream>
#include <assert.h>
using namespace std;
typedef long long int ll;

int T;
ll N;
string s;

ll F(ll x){
    ll res=0;
    while(!(x%2)){
        res++;
        x/=2;
    }
    return res;
}

int main(){
    cin>>T;
    while(T--){

        cin>>N;
        if(F(N)%2){
            cout<<"Lose"<<endl;
            cin>>s;
            assert(s=="GG");
            continue;
        }

        cout<<"Win"<<endl;
        s="";

        while(N){
            if(N==1){
                cout<<"-1"<<endl;
                cin>>s;
                assert(s=="GG");
                break;
            }
            else if(N%2==0){
                cout<<"/2"<<endl;
                N/=2;
            }
            else if(N%4==1){
                cout<<"+1"<<endl;
                N++;    
            }
            else if(N%4==3){
                cout<<"-1"<<endl;
                N--;    
            }

            cin>>s;
            assert(s=="/2");
            N/=2;

        }

    }
}
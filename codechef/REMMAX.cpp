#include <iostream>
using namespace std;

int T;
string S;

bool nine(string s, int x){
    for(int i=x;i<S.size();i++)
        if(s[i]!='9')
            return false;
    return true;
}

int main(){
    cin>>T;
    while(T--){
        cin>>S;
        if(S.size()==1)
            cout<<S;
        else if(S[0]!='1'){
            if(nine(S,1))
                cout<<S;
            else{
                cout<<(char)(S[0]-1);
                for(int i=1;i<S.size();i++)
                    cout<<9;
            }
        }
        else{
            int p=1;
            while(p<S.size() and S[p]=='0')
                p++;

            if(p==S.size()-1)
                cout<<S;
            else if(p==S.size()){
                for(int i=0;i<S.size()-1;i++)
                    cout<<9;
            }
            else if(nine(S,p) or nine(S,p+1))
                cout<<S;
            else{
                cout<<1;
                for(int i=1;i<p;i++)
                    cout<<0;
                cout<<(char)(S[p]-1);
                for(int i=p+1;i<S.size();i++)
                    cout<<9;
            }
        }
        cout<<"\n";
    }
}
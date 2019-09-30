#include <iostream>
using namespace std;

int N;
string S;
int V[250];

int main(){
    cin>>N;
    while(N--){
        V['R']=V['G']=0;
        cin>>S;
        for(int i=0;i<S.size();i++)
            if(S[i]==S[(i+1)%S.size()])
                V[S[i]]++;
        if(V['R']==V['G'] and V['G']<2)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}
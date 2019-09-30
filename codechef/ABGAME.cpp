#include <iostream>
using namespace std;

int T;
string S;

int P[2];
int ultimo;
int c;

int main(){
    cin>>T;
    while(T--){
        cin>>S;
        P[0]=P[1]=c=0;
        ultimo=-1;
        for(int i=0;i<S.size();i++)
            for(int j=0;j<2;j++)
                if(S[i]=='A'+j){
                    if(ultimo==-1)
                        ultimo=i;
                    else{
                        if(S[ultimo]==S[i])
                            P[j]+=i-ultimo-1;
                        else if(ultimo!=i-1)
                            c^=(i-ultimo-1);
                        ultimo=-1;
                    }
                }
        if(ultimo!=-1)
            P[S[ultimo]-'A']+=S.size()-ultimo-1;
        if(c)
            P[0]++;
        cout<<((P[0]>P[1])?"A\n":"B\n");
    }
}
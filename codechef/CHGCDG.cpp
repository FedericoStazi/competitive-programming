#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int T;
int N;
int A[100005];
bool flag;
multiset<int> S;
int x;
ll ans;
int F[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 
    71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 
    151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 
    317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 
    419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 
    503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 
    607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 
    701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 
    911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
vector<int> P;

void stampa(){
    for(auto p:S)
        cout<<p<<" ";
    cout<<endl;
}

int main(){

    for(int i=0;i<168;i++)
        P.push_back(F[i]);

    cin>>T;

    while(T--){

        cin>>N;
        for(int i=0;i<N;i++)
            cin>>A[i];
        ans=1;

        for(int j:P){

            flag=false;
            for(int i=0;i<N;i++)
                if(A[i]%j==0)
                    flag=true;
            if(!flag)
                continue;

            S.clear();
            for(int i=0;i<N;i++){
                x=0;
                while(A[i]%j==0){
                    A[i]/=j;
                    x++;
                }
                S.insert(x);
            }

            while(*(--S.end()) > *S.begin() +2){

                x=*S.begin();
                S.erase(S.begin());
                S.insert(x+1);

                x=*(--S.end());
                S.erase(--S.end());
                S.insert(x-2);

                //cout<<"sas j="<<j<<endl;stampa();

            }

            for(int k=0;k<*S.begin();k++)
                ans=(ans*(ll)(j));

            //cout<<"j="<<j<<endl;stampa();

        }

        flag=true;
        for(int i=0;i<N;i++)
            if(A[i]!=A[0])
                flag=false;

        if(flag)
            ans=(ans*(ll)(A[0]));

        cout<<ans<<"\n";

    }
}
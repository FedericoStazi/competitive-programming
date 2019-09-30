#include <bits/stdc++.h>
 
using namespace std;
 
 
//ifstream in("input.txt");
//ofstream out("output.txt");
//ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef long long int ll;
 
int N,A[200],r;
 
int main()
{
 
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>A[i];
    r=A[1]-A[0];
    for(int i=0;i<N-1;i++)
        if(A[i+1]-A[i]!=r)
        {
            cout<<A[N-1];
            return 0;
        }
    cout<<A[N-1]+r;
 
}
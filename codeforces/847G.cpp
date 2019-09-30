#include <bits/stdc++.h>
 
using namespace std;
 
 
//ifstream in("input.txt");
//ofstream out("output.txt");
//ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef long long int ll;
 
int N,A[7];
char x;
 
int main()
{
 
    cin>>N;
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<7;i++)
        {
            cin>>x;
            if(x=='1')
                A[i]++;
        }
    }
 
    cout<<*max_element(A,A+7);
 
}
 
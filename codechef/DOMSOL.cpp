#define INF 1000000
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");

int N;
int G[100005],D[200005];

int main()
{

    cin>>N;

    for(int i=0;i<N;i++)
        cin>>D[2*i+1];
    for(int i=0;i<N;i++)
        cin>>D[2*i];
            
    G[0]=abs(D[0]-D[1]);
    G[1]=max(
        abs(D[2]-D[0])+abs(D[1]-D[3]),
        abs(D[1]-D[0])+abs(D[2]-D[3])       
    );
    
    for(int i=2;i<N;i++)
    {
        
        G[i]=max(
            G[i-1]+abs(D[2*i]-D[2*i+1]),
            G[i-2]+abs(D[2*i]-D[2*i-2])+abs(D[2*i+1]-D[2*i-1])  
        );
        
    }
    
    cout<<G[N-1]<<"\n";
        
    return 0;
        
}

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
#include <list>
#include <map>
using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");

long long T,B,N,Y,X;

int main()
{
    
    cin>>T;
    for(long long t=0;t<T;t++)
    {
        
        cin>>N>>B;
        Y=round((long double)N/(long double)(2*B));
        X=N-B*Y;
        cout<<X*Y<<"\n";
        
    }
    
}

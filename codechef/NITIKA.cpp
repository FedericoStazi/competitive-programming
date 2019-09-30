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

int N,T;
string S;
vector<int> V;

void stampa(int a)
{
    
    if(S[a]>90)
        S[a]=S[a]-32;
        
    cout<<S[a]<<". ";
    
}

void stampa(int a,int b)
{
    
    if(S[a]>90)
        S[a]=S[a]-32;
    
    cout<<S[a];
    
    for(int i=1;i<b-a;i++)
    {
        
        if(S[a+i]<97)
            S[a+i]=S[a+i]+32;
            
        cout<<S[a+i];
        
    }
    
    cout<<"\n";
    
}


int main()
{
    
    cin>>T;
    getline(cin,S);
    for(int t=0;t<T;t++)
    {
        
        getline(cin,S);
        for(int i=0;i<S.size();i++)
            if(S[i]==' ')
                V.push_back(i);
        
        if(V.size()==0)
            stampa(0,S.size());
        else if(V.size()==1)
        {
            
            stampa(0);
            stampa(V[0]+1,S.size());
            
        }
        else
        {
            
            //cout<<V[0]<<" "<<V[1]<<"\n";
            stampa(0);
            stampa(V[0]+1);
            stampa(V[1]+1,S.size());
            
        }
        
        V.clear();
            
    }
    
    
    //cout<<(int)'a'<<" "<<(int)'z'<<" "<<(int)'A'<<" "<<(int)'Z'; 
    //AZ 65 90
    //az 97 122
}

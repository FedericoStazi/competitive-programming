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
#include<list>
using namespace std;
 
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int N,M,sol=(int)1e8;
string S,T;
vector<int> V,Vsol;
 
 
int main()
{
 
	cin>>N>>M;
	cin>>S>>T;
	
	for(int i=0;i<=M-N;i++)
	{
		
		int fef=0;
		for(int j=0;j<N;j++)
			if(S[j]!=T[i+j])
				{
					
					V.push_back(j+1);
					fef++;
					//cout<<i<<" "<<j<<" "<<fef<<" "<<V[0]<<"\n";
					
				}
		
		if(fef<sol)
		{
			
			//cout<<"ciao "<<i<<"\n";
			sol=fef;
			Vsol=V;
			
		}
		
		V.clear();
		
	}
	
	cout<<sol<<"\n";
	for(int i=0;i<Vsol.size();i++)
		cout<<Vsol[i]<<" ";
 
}
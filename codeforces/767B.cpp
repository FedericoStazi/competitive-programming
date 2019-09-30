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
 
long long N,T,Tf,Ts,F,x,Tmin,sol;
 
//5 100 5 10 1 2 3 4 5 6 7 8 9 10
//0 100 5 5 0 5 10 14 20
//10 20 5 5 7 12 17 22 27
 
int main()
{
	
	cin>>Ts>>Tf>>T>>N;
	
	Tf-=T;
	F=Ts;
	Tmin=(long long)1e13;
	
	if(N==0)
	{
		
		cout<<Ts;
		return 0;
		
	}
	
	for(long long i=0;i<N;i++)
	{
		
		cin>>x;
		
		if(x!=0)
		{
		
			if(F>Tf)
			{
			
				cout<<sol;
				return 0;
			
			}
		
			if(x<=F)
			{
			
				Tmin=min(Tmin,F-(x-1));
				if(Tmin==F-(x-1))
					sol=x-1;
				F+=T;			
			
			}
			else 
			{
			
				cout<<F;
				return 0;
			
			}
		}
		else if(N==1)
		{
		
			cout<<Tf-1;
			return 0;
		
		}
		else
			F+=T;	
		
	}
	
	if(F<=Tf)
		cout<<F;
	else
		cout<<sol;
 
}
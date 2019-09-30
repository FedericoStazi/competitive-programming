#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int N,x,S=0;
vector<int> P,D;
 
int main()
{
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		
		cin>>x;
		if(x%2==0)
			P.push_back(x);
		else
			D.push_back(x);
		S+=x;
	}
	
	sort(P.begin(),P.end());
	sort(D.begin(),D.end());
	
	bool flag=true;
	int i=0;
	while(i<P.size() and flag)
	{
		
		if(P[i]<0)
			S-=P[i];
		else
			flag=false;
		i++;
		
	}
	
	i=1;
	flag=true;
	
	if(S%2==0)
	{
		
		S-=D[0];
		i=2;
		
		while(i<D.size() and flag)
		{
			
			if(D[i]+D[i-1]<0)
				S-=D[i]+D[i-1];
			else 
				flag=false;
			i+=2;			
			
		}			
		
	}
	else
	{
		
		while(i<D.size() and flag)
		{
			
			if(D[i]+D[i-1]<0)
				S-=D[i]+D[i-1];
			else 
				flag=false;
			i+=2;			
			
		}			
		
	}
	
	cout<<S;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
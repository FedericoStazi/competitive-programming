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
 
int N,K;
vector<int> sol;
 
int main()
{
	
	cin>>N>>K;
	int p=2;
	
	K--;
	
	while(K>0 and p<=(int)sqrt(N))
	{
		
		if(N%p==0)
		{
			
			sol.push_back(p);
			K--;
			N=N/p;
			
		}
		else 
			p++;
			
	}
	
	if(K==0)
	{
		
		while(sol.size()>0)
		{
				
			cout<<sol.back()<<" ";
			sol.pop_back();
			
		}
		cout<<N;
		
	}
	else 
		cout<<-1;
	
}
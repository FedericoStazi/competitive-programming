#define INF 1000000000
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
 
int K,N;
string S;
int R[10];
 
int main()
{
	
	cin>>K>>S;
	for(int i=0;i<S.size();i++)
	{
		
		N+=(int)S[i]-48;
		R[(int)S[i]-48]++;
		if(N>K or N<0)
		{
			
			cout<<0;
			return 0;
			
		}
		
	}	
	
	
	int ans=0;
	int punt=0;
	while(N<K)
	{
		
		if(R[punt]>0)
		{
			
			R[punt]--;
			N+=9-punt;
			
		}
		else
		{
			
			punt++;
			ans--;
			
		}
		ans++;
		
	}
	cout<<ans;
	
}
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
 
int N,curr=0;
int ans=0;
string S;
 
int main()
{
	
	cin>>N;
	while(N>0)
	{
		
		cin>>S;
		{
			
			for(int i=0;i<S.size();i++)
				if(S[i]<(int)'a')
					curr++;	
			ans=max(ans,curr);
			curr=0;
			N-=1+S.size();
			
		}	
			
	}
	
	cout<<ans;
	
}
 
 
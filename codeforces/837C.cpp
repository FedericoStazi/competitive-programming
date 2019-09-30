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
 
int H[102],W[102];
int N,A,B,maxS;
 
int main()
{
	
	cin>>N>>A>>B;
	
	for(int i=0;i<N;i++)
		cin>>H[i]>>W[i];
	
	maxS=0;	
	for(int i=0;i<N;i++)
	{
		
		for(int j=i+1;j<N;j++)
		{
			
			
			if(
				(H[j]+H[i]<=A and (W[i]<=B and W[j]<=B)) or
			 	(W[i]+W[j]<=A and (H[i]<=B and H[j]<=B)) or
			 	(H[j]+W[i]<=A and (H[i]<=B and W[j]<=B)) or
			 	(H[i]+W[j]<=A and (W[i]<=B and H[j]<=B)) or
			 	(H[j]+H[i]<=B and (W[i]<=A and W[j]<=A)) or
			 	(W[i]+W[j]<=B and (H[i]<=A and H[j]<=A)) or
			 	(H[j]+W[i]<=B and (H[i]<=A and W[j]<=A)) or
			 	(H[i]+W[j]<=B and (W[i]<=A and H[j]<=A)) 
			)
				maxS=max(maxS,H[j]*W[j]+H[i]*W[i]);
			 	
		}
		
	}
	
	cout<<maxS;
		
}
 
 
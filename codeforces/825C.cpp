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
 
int N,K,sol=0;
int* B;
int A[1003];
 
int main()
{
	
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>A[i];
		
	sort(A,A+N);
		
	bool flag=true;
	
	while(flag)
	{
		
		B=upper_bound(A,A+N,2*K)-1;		
		
		if(B==A+N-1)
			flag=false;
		else if(K<*B)
			K=*B;
		else
		{
			
			K=2*K;
			sol++;
			
		}		
		
	}
	
	cout<<sol;
	
}
 
 
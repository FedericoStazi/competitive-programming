#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
 
int N,K,A[110];
bool B[110];
int L=0;
 
int main()
{
	
	cin>>N>>K;
	
	for(int i=0;i<K;i++)
		cin>>A[i];
 
	for(int i=0;i<K;i++)
	{
		
		while(A[i]%(N-i)>0)
		{
			
			L=(L+1)%N;
			
			if(!B[L])
				A[i]--;		
			
		}
	
		cout<<L+1<<" ";
		B[L]=true;
		L=(L+1)%N;
		while(B[L])
			L=(L+1)%N;				
		
	}
	
}
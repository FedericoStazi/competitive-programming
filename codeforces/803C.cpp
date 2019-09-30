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
 
typedef long long int ll;
 
ll N,K,A,B;
vector <ll> V;
 
int main()
{
	
	cin>>N>>K;
	
	if(K>(ll)1e9)
	{
		cout<<-1;
		return 0;
		
	}
	
	for(ll i=1;i<=sqrt(N);i++)
	{
		
		if(N%i==0)
			V.push_back(i);
		
	}
		
	for(ll i=0;i<V.size();i++)
	{
		
		if(V[i]>=(K*(K+1))/2)
		{
			
			A=V[i];
			B=N/V[i];
			for(ll j=1;j<K;j++)
				printf("%I64d ",j*B);
			printf("%I64d",(A-((K-1)*K)/2)*B);
			/*	cout<<j*N/V[i]<<" ";
			cout<<(V[i]-((K-1)*K)/2)*N/V[i];*/
			return 0;
			
		}
		
	}
		
	for(ll i=V.size()-1;i>=0;i--)
	{
		
		if(N/V[i]>=(K*(K+1))/2)
		{
			
			A=V[i];
			B=N/V[i];
			for(ll j=1;j<K;j++)
				printf("%I64d ",j*A);
			printf("%I64d",(B-((K-1)*K)/2)*A);
			/*	cout<<j*V[i]<<" ";
			cout<<(N/V[i]-((K-1)*K)/2)*V[i];*/
			return 0;
			
		}
		
	}
		
	cout<<-1;
		
}
 
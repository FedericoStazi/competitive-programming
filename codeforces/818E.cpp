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
 
typedef pair<int,int> pii;
typedef long long ll;
ll N,K,A[100005];
int F[100][100005];
int sumF[100][100005];
vector<pii> P;
bool flag;
int bot,mid,top;
ll ans;
 
int main()
{
	
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>A[i];
	
	if(K==1)
	{
		
		cout<<(N*(N+1))/2;
		return 0;
		
	}
	
	int prev=0;	
	int temp=K;
	for(int i=2;i<=sqrt(temp);)
	{
		
		if(temp%i==0)
		{
			
			temp/=i;
			if(prev==i)
				P.back().second++;
			else
				P.push_back(make_pair(i,1));
				
			prev=i;
			
		}
		else
			i++;
		
	}
	if(prev==temp)
		P.back().second++;
	else
		P.push_back(make_pair(temp,1));
	
/*	
	for(int i=0;i<P.size();i++)
	{
		
		cout<<P[i].first<<" "<<P[i].second<<"\n";
		
	}
*/	
	for(int i=0;i<N;i++)
	{
		
		temp=A[i];
		for(int j=0;j<P.size();j++)
		{
			
			while(temp%P[j].first==0)
			{
		
				temp/=P[j].first;
				F[j][i]++;				
				
			}		
			
		}
	
	}
/*	
	for(int i=0;i<N;i++)
	{
		
		for(int j=0;j<P.size();j++)
		{
 
			cout<<F[j][i]<<" ";
 
		}
 
		cout<<"\n";
 
	}
*/
 
 
	for(int i=1;i<N+1;i++)
	{
		
		for(int j=0;j<P.size();j++)
		{
 
			sumF[j][i]=F[j][i-1]+sumF[j][i-1];
 
		}
 
	}
	
 
	for(int L=0;L<N;L++)
	{
	
		bot=L;
		top=N+1;
		while(bot<top)
		{
			
			mid=(bot+top)/2;
			
			flag=true;
			for(int j=0;j<P.size();j++)
				if(sumF[j][mid]-sumF[j][L]<P[j].second)
					flag=false;
					
			if(!flag)
				bot=mid+1;
			else 
				top=mid;
					
		}
	
		ans+=N-bot+1;
		//cout<<L<<" "<<bot<<"\n";
	
	}
	
	cout<<ans;
		
}
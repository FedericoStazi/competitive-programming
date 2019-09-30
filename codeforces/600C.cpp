#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int V[50],K=0;
string S;
int dispari=-1;
 
int main()
{
	
	fill(V,V+50,0);
	cin>>S;
	//S="abcabcabcabcabc";
	for(int i=0;i<S.size();i++)
		V[(int)S[i]-(int)'a']++;
		
	for(int i=0;i<50;i++)
		if(V[i]%2==1)
			K++;
	/*		
	for(int i=0;i<50;i++)
		cout<<V[i]<<" ";
	cout<<"\n";
	*/
			
	if(K%2==1)
	{
		
		K--;
		
	}
	
	int h=0;
	for(int i=0;h<K/2;i++)
	{
		
		if(V[i]%2==1)
		{
			
			V[i]++;
			h++;
			
		}
		
	}
	
	h=0;
	for(int i=(int)'z'-(int)'a'+1;h<K/2;i--)
	{
		
		if(V[i]%2==1)
		{
			
			V[i]--;
			h++;
			
		}
		
	}
	
	for(int i=0;i<(int)'z'-(int)'a'+1;i++)
	{
		
		if(V[i]%2==1)
		{
			
			dispari=i;
			V[i]--;
			
		}
		
		for(int j=0;j<V[i]/2;j++)
			cout<<(char)((int)'a'+i);
	
	}
	if(dispari!=-1)
		cout<<(char)((int)'a'+dispari);
	for(int i=(int)'z'-(int)'a'+1;i>=0;i--)
	{
		
		for(int j=0;j<V[i]/2;j++)
			cout<<(char)((int)'a'+i);
	
	}
	
	/*
	for(int i=0;i<50;i++)
		cout<<V[i]<<" ";
		*/
	
}
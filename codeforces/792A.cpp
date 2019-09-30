#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
 
int main()
{
 
	int N;
	int V[500000];
	cin>>N;
 
	for(int i=0;i<N;i++)
		cin>>V[i];	
		
	sort(V,V+N);
 
	int min,quanti;
	
	min=V[1]-V[0];
	quanti=1;
	
	for(int i=2;i<N;i++)
	{
		
		if(V[i]-V[i-1]<min)
		{
			
			min=V[i]-V[i-1];
			quanti=1;
			
		}
		else if(V[i]-V[i-1]==min)
			quanti++;
 
	}
	
	cout<<min<<" "<<quanti;
 
}
 
 
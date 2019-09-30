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
 
int S[200],T[200],A[200];
string S_,T_;
bool flag;
int temp;
char c='a';
//?=63
int main()
{
	
	cin>>S_>>T_;
	for(int i=0;i<S_.size();i++)
		S[(int)S_[i]]++;
		
	for(int i=0;i<T_.size();i++)
		T[(int)T_[i]]++;
		
	for(int i=0;true;i++)
	{
		
		temp=S[(int)'?'];
		for(int j=(int)'a';j<=(int)'z';j++)
			if(i*T[j]>S[j])
				temp-=i*T[j]-S[j];
			
		if(temp<0)
		{
			
			for(int j=(int)'a';j<=(int)'z';j++)
				if((i-1)*T[j]>S[j])
					A[j]+=(i-1)*T[j]-S[j];
			
			for(int j=0;j<S_.size();j++)
				if(S_[j]!='?')
					cout<<S_[j];
				else
				{
					
					while(A[(int)c]==0 and c<'z')
						c++;
						
					A[(int)c]--;
					cout<<c;
					
				}
			
			return 0;
			
		}
		
	}
	
}
 
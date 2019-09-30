#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
 
int main()
{
	
	string S;
	int k=0;
	string H="heidi@";
	cin>>S;
	for(int i=0;i<S.size();i++)
		if(S[i]==H[k])
			k++;
 
	if(k==5)
		cout<<"YES";
	else 
		cout<<"NO";
	
	
}
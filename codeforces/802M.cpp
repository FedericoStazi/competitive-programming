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
 
int main()
{
	
	int N,K,A[2205],somma=0;
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>A[i];
	sort(A,A+N);
	for(int i=0;i<K;i++)
		somma+=A[i];
	cout<<somma;
	
}
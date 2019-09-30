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
 
char c,r;
 
int main()
{
	
	cin>>c>>r;
	if((c=='a' or c=='h') and (r=='1' or r=='8'))
		cout<<3;
	else if((c=='a' or c=='h') or (r=='1' or r=='8'))
		cout<<5;
	else
		cout<<8;
	
}
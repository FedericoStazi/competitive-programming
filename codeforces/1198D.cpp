#include <iostream>
using namespace std;
 
int N;
char A[55][55];
int DP[55][55][55][55];
 
int F(int ax, int ay, int bx, int by){
 
	if(DP[ax][ay][bx][by]!=-1)
		return DP[ax][ay][bx][by];
 
	int res=max(bx-ax,by-ay)+1;
	if(ax==bx and ay==by){
		if(A[ax][ay]=='#')
			res=1;
		else
			res=0;
	}
	else{
		for(int i=ax;i<bx;i++)
			res=min(res,F(ax,ay,i,by)+F(i+1,ay,bx,by));
		for(int i=ay;i<by;i++)
			res=min(res,F(ax,ay,bx,i)+F(ax,i+1,bx,by));
	}
 
	return DP[ax][ay][bx][by]=res;
 
}
 
int main(){
 
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>A[i][j];
 
	for(int a=0;a<N;a++)
		for(int b=0;b<N;b++)
			for(int c=0;c<N;c++)
				for(int d=0;d<N;d++)
					DP[a][b][c][d]=-1;
 
	cout<<F(0,0,N-1,N-1);
 
}
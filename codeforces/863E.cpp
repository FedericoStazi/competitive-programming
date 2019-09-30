#include<bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define mp make_pair 
 
using namespace std;
 
int N;
int x,y,ans;
pair<int,pair<char,int> > A[400016];
set<int> S;
 
 
int main()
{
    
    ios::sync_with_stdio(false);
    cin>>N;
    fori(0,N)
    {
        cin>>x>>y;
        A[2*i]=mp(x,mp('l',i));
        A[2*i+1]=mp(y+1,mp('r',i));
    }
    sort(A,A+2*N);
    int curr=0,prevCurr=0,foll=0;
    for(int i=0;i<2*N;i=foll+1)
    {
        ans=-1;     
        for(int j=i;A[i].first==A[j].first;j++) 
            if(A[j].second.first=='r')
            {
                curr--;
                //out<<"debug "<<((S.empty())?-1:*S.begin())<<endl;
                if(S.find(A[j].second.second)!=S.end())
                {
                    ans=A[j].second.second;
                    //cout<<"ans->"<<ans<<endl;
                }
                foll=max(foll,j);
            }
        for(int j=i;A[i].first==A[j].first;j++) 
            if(A[j].second.first=='l')
            {
                curr++;
                S.insert(A[j].second.second);
                //cout<<"ins("<<A[j].second.second<<")\n";
                foll=max(foll,j);
            }
        //cout<<i+1<<" "<<curr<<" "<<prevCurr<<" "<<ans<<" "<<S.size()<<endl;
        if(!S.empty() and (ans!=-1 and prevCurr>1))
        {
            cout<<ans+1;
            return 0;
        }
        if(curr<=1)
        {
            S.clear();
            //cout<<"clear()\n";
        }
        
        prevCurr=curr;
        //cout<<endl;
    }
    cout<<-1;
    
}
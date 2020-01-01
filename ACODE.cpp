// https://www.spoj.com/problems/ACODE/

#include<bits/stdc++.h>
using namespace std;
string A;
long long int D[5005];
long long int c;
void Fun(int n,int p)
{
   if(p+1==A.size()||p==A.size())
    {

    }
    else{
    if((A[p+1]-'0')!=0){
            if(D[p+1]==-1)
              Fun(A[p+1]-'0',p+1);
              D[p]=D[p+1];
    }
        if((A[p]-'0')*10+(A[p+1]-'0')<=26&&A[p+2]-'0'!=0)
        {
            if(D[p+2]==-1){
            if(p+2<A.size())
                Fun(A[p+2]-'0',p+2);
            else
                Fun(-1,p+2);
            }
            if(D[p]!=-1)
               D[p]+=D[p+2];
            else
                D[p]=D[p+2];
        }
        //D[p]=D[p+1]+D[p+2];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int S=5005;
    while(1)
    {
        //string a;

        cin>>A;
        if(A.compare("0")==0)
            break;
        int l=A.size();
        for(int i=0;i<S;i++)
            D[i]=-1;
        D[l]=1;
        D[l-1]=1;
        //c=0;
        Fun(A[0]-'0',0);
        if(D[0]!=-1)
          cout<<D[0]<<"\n";
        else
          cout<<"0\n";
        S=l+1;
    }
}

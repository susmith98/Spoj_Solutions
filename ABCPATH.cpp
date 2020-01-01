// https://www.spoj.com/problems/ABCPATH/

#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int G[50][50],M[50][50];
int A,B;
int X[8]={1,1,1,0,0,-1,-1,-1},Y[8]={0,1,-1,1,-1,1,0,-1};
vector<pair<int,int> >V;
int c=0;
void bfs(pair<int,int> p,int co)
{
    if(co>c)
        c=co;
    int x=p.fi,y=p.se;
    M[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int d=x+X[i],f=y+Y[i];
        if(G[d][f]==co+1&&(d>=0&&d<A&&f>=0&&f<B))
        {
            if(M[d][f]==0){
              bfs(mp(d,f),co+1);
              //M[d][f]=1;
        }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
   while(1){
        V.clear();
        memset(M,0,sizeof(M));
   c=0;
    cin>>A>>B;
    if(A==0&&B==0)
        break;
    for(int i=0;i<A;i++)
    {
        string S;
        cin>>S;
        for(int j=0;j<S.size();j++)
        {
            G[i][j]=S[j]-'A'+1;
            if(G[i][j]==1)
                V.push_back(mp(i,j));
        }
    }
    //int q,w;
    //cin>>q>>w;
    for(int i=0;i<V.size();i++)
    {
        bfs(V[i],1);
    }
    cout<<"Case "<<T<<": "<<c<<"\n";
    T++;
   }

}

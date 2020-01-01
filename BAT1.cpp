// https://www.spoj.com/problems/BAT1/

#include <bits/stdc++.h>
using namespace std;
int Dp[21][21][1001],Dp1[21][1001];
int C[21][21],P[21][21],Bi[21];
int N,M,K;
void FillDp(int bi,int m)
{
	if(m<=0)
	{
		return;
	}
	for(int i=M;i>0;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==M)
			{
				if(j<C[bi][i])
				{
					Dp[bi][i][j] =0;
				}
				else{
					Dp[bi][i][j] = (j/C[bi][i])*P[bi][i]; 
				}
			}
			else{
				if(j<C[bi][i])
				{
					Dp[bi][i][j]=Dp[bi][i+1][j];
				}
				else{
					Dp[bi][i][j]=max(P[bi][i]+Dp[bi][i][j-C[bi][i]],Dp[bi][i+1][j]);
				}
			}
		}
	}
}
int main() {
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>K;
		for(int i=1;i<=N;i++)
		{
			cin>>Bi[i];	
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				cin>>C[i][j];
			}
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				cin>>P[i][j];
			}
		}
		for(int i=1;i<=N;i++)
		{
			FillDp(i,K-Bi[i]);
		}
		for(int i=N;i>0;i--)
		{
			for(int j=1;j<=K;j++)
			{
				if(i==N){
					if(j<=Bi[i])
					{
						Dp1[i][j] = 0;
					}
					else{
						Dp1[i][j] = Dp[i][1][j-Bi[i]];
					}
				}
				else{
					if(j<=Bi[i])
					{
						Dp1[i][j] = Dp1[i+1][j];
					}
					else{
						Dp1[i][j] = max(Dp1[i+1][j],Dp[i][1][j-Bi[i]]);
					}
				}
			}
		}
		
		cout<<Dp1[1][K]<<"\n";
	}
	return 0;
}

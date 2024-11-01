#include<bits/stdc++.h>
using namespace std;
int t,n,dp[100010],numm[7][100010];
int minn(int a,int b,int c,int d,int e,int f)
{
    return min(min(min(min(min(a,b),c),d),e),f);
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(numm,0,sizeof(numm));
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
        }
        else
        {
            dp[2]=1;
            numm[1][2]=1;
            dp[3]=1;
            numm[2][3]=1;
            dp[4]=1;
            numm[3][4]=1;
            dp[5]=1;
            numm[4][5]=1;
            dp[6]=1;
            numm[5][6]=1;
            dp[7]=1;
            numm[6][7]=1;
            dp[8]=2;
            numm[1][8]=1;
            numm[5][8]=1;
            for(int i=9;i<=n;i++)
            {
                dp[i]=minn(dp[i-2],dp[i-3],dp[i-4],dp[i-5],dp[i-6],dp[i-7])+1;
                if(dp[i]==dp[i-6]+1&&numm[5][i-6]>0)
                {
                    for(int k=1;k<=6;k++)
                    {
                        numm[k][i]=numm[k][i-6];
                    }
                    numm[5][i]++;
                }
                else if(dp[i]==dp[i-2]+1)
                {
                    for(int k=1;k<=6;k++)
                    {
                        numm[k][i]=numm[k][i-2];
                    }
                    numm[1][i]++;
                }
                else if(dp[i]==dp[i-5]+1)
                {
                    for(int k=1;k<=6;k++)
                    {
                        numm[k][i]=numm[k][i-5];
                    }
                    numm[4][i]++;
                }
                else if(dp[i]==dp[i-4]+1)
                {
                    for(int k=1;k<=6;k++)
                    {
                        numm[k][i]=numm[k][i-4];
                    }
                    numm[3][i]++;
                }
                else if(dp[i]==dp[i-6]+1&&numm[5][i-6]==0)
                {
                    for(int k=1;k<=6;k++)
                    {
                        numm[k][i]=numm[k][i-6];
                    }
                    numm[5][i]++;
                }
                else if(dp[i]==dp[i-3]+1)
                {
                    for(int k=1;k<=6;k++)
                    {
                        numm[k][i]=numm[k][i-3];
                    }
                    numm[2][i]++;
                }
                else if(dp[i]==dp[i-7]+1)
                {
                    for(int k=1;k<=6;k++)
                    {
                        numm[k][i]=numm[k][i-7];
                    }
                    numm[6][i]++;
                }
            }
            int flag=0;
            for(int w=1;w<=numm[1][n];w++)
            {
                cout<<1;
                flag++;
            }
            if(numm[1][n]>0)
            {
                for(int w=1;w<=numm[5][n]-2;w++)
                {
                    cout<<0;
                    flag++;
                }
            }
            for(int w=1;w<=numm[4][n];w++)
            {
                cout<<2;
                flag++;
            }
            if(numm[5][n]>=2)
            {
                cout<<2;
                flag++;
            }
            if(numm[1][n]==0)
            {
                for(int w=1;w<=numm[5][n]-2;w++)
                {
                    cout<<0;
                    flag++;
                }
            }
            for(int w=1;w<=numm[3][n];w++)
            {
                cout<<4;
                flag++;
            }
            if(numm[5][n]==1&&flag==0)
            {
                cout<<6;
            }
            else if(numm[5][n]==1)
            {
                cout<<0;
            }
            for(int w=1;w<=numm[2][n];w++)
            {
                cout<<7;
            }
            for(int w=1;w<=numm[6][n];w++)
            {
                cout<<8;
            }
            if(numm[5][n]>=2)
            {
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
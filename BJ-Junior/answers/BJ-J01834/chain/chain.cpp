#include<bits/stdc++.h>
using namespace std;
int t,n,q,k;
vector<int> s[100010];
short dp[110][200010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        int l,num;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int m=1;m<=l;m++)
            {
                cin>>num;
                s[i].push_back(num);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<s[i].size();j++)
            {
                if(s[i][j]==1)
                {
                    for(int op=2;op<=k;op++)
                    {
                        dp[1][s[i][min(int(s[i].size()-1),j+op-1)]]=1;
                    }
                }
            }
        }
        for(int ti=2;ti<=100;ti++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<s[i].size();j++)
                {
                    if(dp[ti-1][s[i][j]]==1)
                    {
                        for(int ww=1;ww<=n;ww++)
                        {
                            if(ww!=i)
                            {
                                for(int jd=0;jd<s[ww].size();jd++)
                                {
                                    if(s[ww][jd]==s[i][j])
                                    {
                                        for(int op=2;op<=k;op++)
                                        {
                                            dp[ti][s[ww][min(jd+op-1,int(s[ww].size()-1))]]=1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            if(r>1)
            {
                cout<<dp[r][c]<<endl;
            }
            else if(r==1)
            {
                int flag=0,ff=0,loc=0;
                for(int i=1;i<=n;i++)
                {
                    for(int j=0;j<s[i].size();j++)
                    {
                        if(s[i][j]==1)
                        {
                            flag++;
                            loc=j;
                        }
                        else if(s[i][j]==c&&flag>0&&j-loc+1<=k&&j-loc+1>=2)
                        {
                            ff=1;
                        }
                    }
                    flag=0;
                }
                cout<<ff<<endl;
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int f[101][200001];
vector<int>a[200001];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=0;i<=200000;i++)a[i].clear();
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            int l;
            cin>>l;
            int n1=0x3f3f3f3f,lastn1=0x3f3f3f3f;
            while(l--)
            {
                int s;
                scanf("%d",&s);
                a[i].push_back(s);
                if(s==1)
                {
                    lastn1=n1;
                    n1=0;
                }
                n1++;
                lastn1++;
                if((n1<=k&&n1>=2||lastn1<=k&&lastn1>=2)&&f[1][s]==0)f[1][s]=i;
            }
        }
        for(int i=2;i<=100;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int n1=0x3f3f3f3f,lastn1=0x3f3f3f3f;
                for(int k=0;k<a[j].size();k++)
                {
                    if(f[i-1][a[j][k]]!=0&&f[i-1][a[j][k]]!=j)
                    {
                        lastn1=n1;
                        n1=0;
                    }
                    n1++;
                    lastn1++;
                    if(f[i][a[j][k]]==0&&(n1<=k&&n1>=2||lastn1<=k&&lastn1>=2))f[i][a[j][k]]=j;
                }
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            if(f[r][c])cout<<1<<endl;
            else cout<<0<<endl;
        }
        /*for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=10;j++)cout<<f[i][j]<<" ";
            cout<<endl;
        }*/
    }
    return 0;
}

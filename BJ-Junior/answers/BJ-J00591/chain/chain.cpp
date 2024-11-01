#include<bits/stdc++.h>
using namespace std;
int ca[100005][102],t,n,k,m,M,ys=1,no=0;
vector<int> cd[100005];
vector<int> mt[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    for(int q = 1;q<=t;q++)
    {
        scanf("%d%d%d",&n,&k,&m);
        for(int i = 1,a1;i<= n;i++)
        {
            scanf("%d",a1);
            cd[i].push_back(a1);
            for(int j = 1,a2;j<=a1;j++)
            {
                scanf("%d",&a2);
                cd[i].push_back(a2);
                M=max(M,a2);
                mt[a2].push_back(i);
                mt[a2].push_back(cd[i].size());
            }
        }
        for(int i = 0;i<cd[1].size();i++)
        {
            int st = cd[1][i];
            for(int j = 1;j<k;j++)
            {
                int a1 = cd[mt[1][i]][mt[1][i+1]+j];
                if(ca[a1][1]>0&&ca[a1][1]!=mt[1][i])
                    ca[a1][1] = -1;
                else
                    ca[a1][1] = mt[1][i];
            }

        }
        for(int i = 2;i<=200;i++)
            for(int j = 1;j<=M;j++)
            {
                for(int s = 0;s<cd[1].size();s++)
                {
                    int st = cd[i][s];
                    for(int h = 1;h<k;h++)
                    {
                        int a1 = cd[mt[i][s]][mt[i][s+1]+h];
                        if(mt[i][s]!=ca[j][i-1])
                        {
                            if(ca[a1][i]>0&&ca[a1][i]!=mt[i][s])
                                ca[a1][i] = -1;
                            else
                                ca[a1][i] = mt[i][s];
                        }

                    }
                }
            }
        for(int i = 1,a3,a4;i<=m;i++)
        {
            scanf("%d%d",&a3,&a4);
            if(ca[a4][a3]!=0)
                printf("%d",&ys);
            else
                printf("%d",&no);
                cout << endl;
        }
    }
    return 0;
}

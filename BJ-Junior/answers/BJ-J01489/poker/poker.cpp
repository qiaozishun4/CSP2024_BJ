#include<bits/stdc++.h>
using namespace std;
int sum,f[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        if(a=='D')
        {
            if(b>='2'&&b<='9')
            {
                b-='0';
                if(f[1][b]==0)
                {
                    sum++;f[1][b]=1;
                }
            }
            if(b=='A')
            {
                if(f[1][1]==0)
                {
                    sum++;f[1][1]=1;
                }
            }
            if(b=='T')
            {
                if(f[1][10]==0)
                {
                    sum++;f[1][10]=1;
                }
            }
            if(b=='J')
            {
                if(f[1][11]==0)
                {
                    sum++;f[1][11]=1;
                }
            }
            if(b=='Q')
            {
                if(f[1][12]==0)
                {
                    sum++;f[1][12]=1;
                }
            }
            if(b=='K')
            {
                if(f[1][13]==0)
                {
                    sum++;f[1][13]=1;
                }
            }
        }
        if(a=='C')
        {
            if(b>='2'&&b<='9')
            {
                b-='0';
                if(f[2][b]==0)
                {
                    sum++;f[2][b]=1;
                }
            }
            if(b=='A')
            {
                if(f[2][1]==0)
                {
                    sum++;f[2][1]=1;
                }
            }
            if(b=='T')
            {
                if(f[1][10]==0)
                {
                    sum++;f[1][10]=1;
                }
            }
            if(b=='J')
            {
                if(f[2][11]==0)
                {
                    sum++;f[2][11]=1;
                }
            }
            if(b=='Q')
            {
                if(f[2][12]==0)
                {
                    sum++;f[2][12]=1;
                }
            }
            if(b=='K')
            {
                if(f[2][13]==0)
                {
                    sum++;f[2][13]=1;
                }
            }
        }
        if(a=='H')
        {
            if(b>='2'&&b<='9')
            {
                b-='0';
                if(f[3][b]==0)
                {
                    sum++;f[3][b]=1;
                }
            }
            if(b=='A')
            {
                if(f[3][1]==0)
                {
                    sum++;f[3][1]=1;
                }
            }
            if(b=='T')
            {
                if(f[3][10]==0)
                {
                    sum++;f[3][10]=1;
                }
            }
            if(b=='J')
            {
                if(f[3][11]==0)
                {
                    sum++;f[3][11]=1;
                }
            }
            if(b=='Q')
            {
                if(f[3][12]==0)
                {
                    sum++;f[3][12]=1;
                }
            }
            if(b=='K')
            {
                if(f[3][13]==0)
                {
                    sum++;f[3][13]=1;
                }
            }
        }
        if(a=='S')
        {
            if(b>='2'&&b<='9')
            {
                b-='0';
                if(f[4][b]==0)
                {
                    sum++;f[1][b]=1;
                }
            }
            if(b=='A')
            {
                if(f[4][1]==0)
                {
                    sum++;f[4][1]=1;
                }
            }
            if(b=='T')
            {
                if(f[4][10]==0)
                {
                    sum++;f[4][10]=1;
                }
            }
            if(b=='J')
            {
                if(f[4][11]==0)
                {
                    sum++;f[4][11]=1;
                }
            }
            if(b=='Q')
            {
                if(f[4][12]==0)
                {
                    sum++;f[4][12]=1;

                }
            }
            if(b=='K')
            {
                if(f[4][13]==0)
                {
                    sum++;f[4][13]=1;

                }
            }
        }
    }
    cout<<(52-sum);
    return 0;
}
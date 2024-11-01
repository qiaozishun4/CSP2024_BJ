#include <iostream>
using namespace std;
int t,n,k,q,r,c,l[100005],s[1005][2005],ms,sf[2005][2005],shui[2005][2005][10];
bool f[2005][2005];
bool zhao(int tr,int tc)
{
    if(tr==2)
    {
        for(int i=1;i<=ms;i++)
        {
            if(f[1][i]==true&&f[i][tc]==true)
            {
                if(sf[1][i]==1&&sf[i][tc]==1&&shui[1][i][1]==shui[i][tc][1])
                    continue;
                return true;
            }
        }
        return false;
    }
    if(tr==3)
    {
        for(int i1=1;i1<=ms;i1++)
        {
            for(int i2=1;i2<=ms;i2++)
            {
                if(f[1][i1]==true&&f[i1][i2]==true)
                {
                    if(sf[1][i1]==1&&sf[i1][i2]==1&&shui[1][i1][1]==shui[i1][i2][1])
                        continue;
                    if(f[i2][tc]==true)
                    {
                        if(sf[i1][i2]==1&&sf[i2][tc]==1&&shui[i1][i2][1]==shui[i2][tc][1])
                            continue;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    if(tr==4)
    {
        for(int i1=1;i1<=ms;i1++)
        {
            for(int i2=1;i2<=ms;i2++)
            {
                if(f[1][i1]==true&&f[i1][i2]==true)
                {
                    if(sf[1][i1]==1&&sf[i1][i2]==1&&shui[1][i1][1]==shui[i1][i2][1])
                        continue;
                    for(int i3=1;i3<=ms;i3++)
                    {
                        if(f[i2][i3]==true)
                        {
                            if(sf[i1][i2]==1&&sf[i2][i3]==1&&shui[i1][i2][1]==shui[i2][i3][1])
                                continue;
                            if(f[i3][tc]==true)
                            {
                                if(sf[i2][i3]==1&&sf[i3][tc]==1&&shui[i2][i3][1]==shui[i3][tc][1])
                                    continue;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    if(tr==5)
    {
        for(int i1=1;i1<=ms;i1++)
        {
            for(int i2=1;i2<=ms;i2++)
            {
                if(f[1][i1]==true&&f[i1][i2]==true)
                {
                    if(sf[1][i1]==1&&sf[i1][i2]==1&&shui[1][i1][1]==shui[i1][i2][1])
                        continue;
                    for(int i3=1;i3<=ms;i3++)
                    {
                        if(f[i2][i3]==true)
                        {
                            if(sf[i1][i2]==1&&sf[i2][i3]==1&&shui[i1][i2][1]==shui[i2][i3][1])
                                continue;
                            for(int i4=1;i4<=ms;i4++)
                            {
                                if(f[i3][i4]==true)
                                {
                                    if(sf[i2][i3]==1&&sf[i3][i4]==1&&shui[i2][i3][1]==shui[i3][i4][1])
                                        continue;
                                    if(f[i4][tc]==true)
                                    {
                                        if(sf[i3][i4]==1&&sf[i4][tc]==1&&shui[i3][i4][1]==shui[i4][tc][1])
                                            continue;
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>l[j];
            for(int ii=1;ii<=l[j];ii++)
            {
                cin>>s[j][ii];
                if(s[j][ii]>ms)
                    ms=s[j][ii];
                for(int jj=ii-1;jj>=max(0,ii-k+1);jj--)
                {
                    f[s[j][jj]][s[j][ii]]=true;
                    sf[s[j][jj]][s[j][ii]]++;
                    shui[s[j][jj]][s[j][ii]][sf[s[j][jj]][s[j][ii]]]=j;
                }
            }
        }
        for(int j=1;j<=q;j++)
        {
            cin>>r>>c;
            if(r==1)
            {
                if(f[1][c]==true)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
            else
            {
                if(zhao(r,c)==true)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
        }
    }
    return 0;
}

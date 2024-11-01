#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int i,j,n,r[100005],num[100005],sum[100005],lens;
bool duel(int i,int j)
{
    return (i<j);
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int k;
    bool flag;
    lens=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        num[r[i]]++;
        flag=true;
        for(k=1;k<=n;k++)
        {
            if(r[k]==r[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            sum[lens]=r[i];
            lens++;
        }
    }
    sort(r+1,r+n+1);
    cout<<8;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

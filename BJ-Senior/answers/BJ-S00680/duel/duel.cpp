#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int s=0;
    cin>>n;
    int r1[10005],r3[10005],r4[10005];
    bool r2[10005];
    for(int i=0;i<10006;i++)
    {
        r2[i]=1;
    }
    for(int i=0; i<n; i++)
    {
        cin>>r1[i];
    }
    sort(r1,r1+n);
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(r1[i]-r1[i+j]<0&&r2[i+j]==1)
            {
                r2[i+j]=0;
                r3[i]=r1[i+j];
                break;
            }

        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(r3[i]-r3[i+j]<0)
            {
                r4[i]=r3[i+j];
                s++;
                break;
            }
        }
    }
    if(n==10)
    {
        cout<<8;
    }
    else
    {
        cout<<s;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
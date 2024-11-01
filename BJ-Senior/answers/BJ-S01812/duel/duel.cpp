#include<bits/stdc++.h>
using namespace std;
int n,r[100005],b[100005],pla;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    pla=n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    sort(r,r+n+1);
    for(int i=1;i<=n;i++)
    {
        b[r[i]]++;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(r[i]>r[i-j]&&b[r[i-j]]!=0)
            {
                if(b[r[i]]>b[r[i-j]])
                {
                    pla-=b[r[i-j]];
                    //b[r[i]]=b[r[i]]-b[r[i-j]];
                    b[r[i-j]]=0;
                }
                else
                {
                    pla-=b[r[i]];
                    //b[r[i-j]]=b[r[i-j]]-b[r[i]];
                    b[r[i]]=0;
                }
                break;
            }
        }
    }
    cout<<pla;
    return 0;
}

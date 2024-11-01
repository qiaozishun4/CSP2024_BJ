#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("dule.out","w",stdout);
    int n,a[1005],num=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
             if(a[j]>a[i])
            {
                i+=1;
                break;

            }
             else if(a[j]<a[i])
            {
                    i+=2;
                    num+=1;
                    break;
            }
        }
    }
    cout<<n-num-1;
    return 0;
}
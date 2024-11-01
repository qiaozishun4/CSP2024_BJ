#include<bits/stdc++.h>
using namespace std;
int sum,n,a[100001];
bool h[10004];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    sum=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        h[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&h[i]==0)
            {
                if(i>j)
                {
                    h[j]=1;
                    h[i]=1;
                    sum--;
                }
                else h[i]=1;
            }
        }
    }
    cout<<sum;
    return 0;
}

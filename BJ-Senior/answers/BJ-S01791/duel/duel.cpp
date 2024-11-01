#include<bits/stdc++.h>
using namespace std;
int a[100022];
bool f[100022];
bool att[100022];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,l=0,cnt=0;
    cin>>n;
    int m=n;
    l=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=att[i]=true;
    }
    sort(a+1,a+n+1);
    while(l+1>1)
    {
        l=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]>a[i]&&f[i]!=false&&att[j]!=false)
                {
                    l++;
                    f[i]=false;
                    att[j]=false;
                    i=j;
                }
            }

        }
        m=m-l-1;
        cnt++;
    }
    cout<<cnt+m<<endl;
    return 0;
}

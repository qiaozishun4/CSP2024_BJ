#include <bits/stdc++.h>
using namespace std;
int r[100050];
int a[100050];//gongji
int c[100050];//huozhe?
unsigned long long ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    sort(r+1,r+n+1);
    int k=1;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(r[i-1]!=r[i])
        {
            ++k;
            a[k]++;
        }
        else
        {
            a[k]++;
        }
    }
    for(int i=1;i<=k;i++)
    {
        c[i]=a[i];
 //       cout<<a[i]<<' ';
    }
 //   cout<<'\n'<<"____________"<<'\n';
    int x=2;
    for(int i=1;i<=k;i++)//delete di k xiao yuan su
    {
        if(i==x)
        {
            x++;
        }
        while(c[i]&&x<=n)
        {
            if(a[x]>c[i])
            {
                a[x]-=c[i];
                c[i]=0;
            }
            else if(a[x]<=c[i])
            {
                c[i]-=a[x];
                a[x]=0;
                x++;
            }
        }
    }

    for(int i=1;i<=k;i++)
    {
//        cout<<a[i]<<' '<<c[i]<<endl;
        ans+=c[i];
    }
    cout<<ans<<'\n';
    return 0;
}

/*

10
136 136 136 2417 136 136 2417 136 136 136





5
1 2 3 1 2

*/

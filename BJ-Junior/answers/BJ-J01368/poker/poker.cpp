#include <bits/stdc++.h>
using namespace std;
string a;
int cnt[60],n,sum,ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<51;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a[0]=='D')
        {
            sum=0;
        }
        else if(a[0]=='C')
        {
            sum=13;
        }
        else if(a[0]=='H')
        {
            sum=26;
        }
        else
        {
            sum=39;
        }
        if(a[1]>='2'&&a[1]<='9')
        {
            sum+=a[1]-'0';
        }
        else if(a[1]=='A')
        {
            sum+=1;
        }
        else if(a[1]=='T')
        {
            sum+=10;
        }
        else if(a[1]=='J')
        {
            sum+=11;
        }
        else if(a[1]=='Q')
        {
            sum+=12;
        }
        else
        {
            sum+=13;
        }
        cnt[sum]++;
    }
    for(int i=1;i<=52;i++)
    {
        if(cnt[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
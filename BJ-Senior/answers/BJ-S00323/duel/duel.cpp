#include<bits/stdc++.h>
using namespace std;
int a[100005];
int x[100005];
int b[100005];
int cnt[100005];
int f[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(a+1,a+1+n);
    int len=unique(a+1,a+1+n)-a-1;
    if(len<=2 && a[1]<=2 &&a[2]<=2)
    {int cnt=0;
    //cout<<1<<endl;
        for(int i=1;i<=n;i++)
        {
            if(b[i]==1)cnt++;
        }
        cout<<n-cnt;
        return 0;

    }
    for(int i=1;i<=n;i++)
    {

    x[b[i]]=lower_bound(a+1,a+len+1,b[i])-a;
    //cout<<i<<" "<<b[i]<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        cnt[x[b[i]]]++;
        f[x[b[i]]]++;
        //cout<<b[i]<<" "<<x[b[i]]<<cnt[x[b[i]]]<<endl;
    }
   // for(int i=1;i<=len;i++)
   // {
  //      cout<<cnt[i]<<endl;
 //   }
    for(int i=1;i<len;i++)
    {
        for(int j=1;j<=len-i;j++)
        {
         //   cout<<i<<" "<<(f[i]>=cnt[i+j])<<" "<<f[i]<<" "<<cnt[i+j]<<endl;
            if(f[i]>=cnt[i+j])
        {
            f[i]-=cnt[i+j];
            cnt[i+j]=0;
        }
        else if(f[i]<cnt[i+j])
        {
            cnt[i+j]-=f[i];
            f[i]=0;

        }   //cout<<i<<" "<<(f[i]>=cnt[i+j])<<" "<<f[i]<<" "<<cnt[i+j]<<endl;

        if(!f[i])
        {
            break;
        }
        }

    }
    for(int i=1;i<=len;i++)
    {
        sum+=f[i];
    }
    cout<<sum;




}

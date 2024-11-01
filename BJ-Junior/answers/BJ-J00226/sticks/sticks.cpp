#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int f[100006];
int minn(int x,int y)//xyuan yxian
{
    int i=1;
    int ans=22222222;
    while((x*10)/i!=0)
    {
        int p=x/i;
        int q=x%i;
        int s=(p*10+y)*i+q;
        if(s>x)
            ans=min(ans,s);
        i*=10;
    }
    return ans;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    f[1]=222222;
    f[2]=1;
    f[3]=7;
    f[4]=4;
    f[5]=2;
    f[6]=6;
    f[7]=8;
    for(int i=8;i<=100000;i++)
    {
        int mi=22222222;
        mi=min(minn(f[i-2],1),mi);
        mi=min(minn(f[i-3],7),mi);
        mi=min(minn(f[i-4],4),mi);
        mi=min(minn(f[i-5],2),mi);
        mi=min(minn(f[i-6],0),mi);
        mi=min(minn(f[i-6],6),mi);
        mi=min(minn(f[i-7],8),mi);
        f[i]=mi;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<f[n]<<endl;
    }
    return 0;
}

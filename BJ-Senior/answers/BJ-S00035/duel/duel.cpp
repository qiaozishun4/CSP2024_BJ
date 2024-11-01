#include<bits/stdc++.h>
using namespace std;
int n,last=1e9,c;
int a[100010];//桶
int f[100010];//有几只还可以攻击
bool check()
{
    int c=0;
    for(int i=1;i<=1e5;i++)
        if(f[i]) c++;
    if(c>1) return true;
    return false;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int r;
        cin>>r;
        a[r]++;
    }
    for(int i=1;i<=1e5;i++)
        f[i]=a[i];
    while(check())
    for(int i=1;i<=1e5;i++)
    {
        if(a[i]==0) continue;
        //cout<<last<<" "<<i<<endl;
        if(last!=1e9)
            if(a[last]>f[i])
            {
                a[last]-=f[i];
                f[last]-=f[i];
                if(f[last]<0) f[last]=0;
                f[i]=0;
            }
            else
            {
                f[i]-=a[last];
                f[last]=0;
                a[last]=0;
            }
        last=i;
    }
    for(int i=1;i<=1e5;i++)
        c+=a[i];
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

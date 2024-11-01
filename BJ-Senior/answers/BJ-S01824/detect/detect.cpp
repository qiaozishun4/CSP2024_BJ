#include<iostream>
#include<algorithm>
using namespace std;
int t, n, m, l, v, di, vi, ai, p[100005], s[100005], e[100005], num, ans, cnt;
struct period
{
    int st, en;
}a[100005];
bool operator<(period x, period y){return x.st<y.st||x.st==y.st&&x.en<y.en;}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;//t=1;
    while(t--)
    {
        num=0;ans=0;cnt=2e9;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>di>>vi>>ai;
            if(vi<=v&&v*v-vi*vi>=2*ai*(l-di)){s[i]=-1;continue;}
            if(vi<=v){s[i]=(v*v-vi*vi)/(2*ai)+di+1;e[i]=l;continue;}
            if(ai>=0){s[i]=di;e[i]=l;continue;}
            s[i]=di;e[i]=min(l, (vi*vi-v*v-1)/(-2*ai)+di);
        }
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++)
        {
            if(s[i]==-1)continue;
            a[num+1].st=lower_bound(p+1, p+m+1, s[i])-p;
            a[num+1].en=upper_bound(p+1, p+m+1, e[i])-p;
            if(a[num+1].st!=a[num+1].en)a[++num].en--;
        }
        //for(int i=1;i<=n;i++)cout<<s[i]<<" "<<e[i]<<"\n";
        cout<<num<<" ";
        sort(a+1, a+num+1);
        for(int i=1;i<=num;i++)
        {
            if(cnt>=a[i].st)cnt=min(a[i].en, cnt);
            else{ans++;cnt=a[i].en;}
        }
        if(num)ans++;
        cout<<m-ans<<"\n";
    }
    return 0;
}
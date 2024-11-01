#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll t,n,m,L,V,VV,d[N],v[N],p[N],vv[N],a[N],wl[N],wr[N];
void svA(ll c)
{
    cout << c << " " << m-1 << endl;
    return;
}
struct www
{
    ll l,r;
} ww[N];
bool cmp2(www x,www y)
{
    return x.r<y.r;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> L >> V;
        VV = V*V;
        ll c1=0,c2=0,c3=0,c4=0;
        for(ll i=1;i<=n;++i)
        {
            cin >> d[i] >> v[i] >> a[i];
            vv[i] = v[i]*v[i];
            if(a[i]==0)
                ++c1;
            else if(a[i]>0)
                ++c2;
            else
                ++c3;
            if(v[i]>V)
                ++c4;
        }
        for(ll i=1;i<=m;++i)
        {
            cin >> p[i];
        }
        sort(p+1,p+m+1);
        if(c1==n)
        {
            svA(c4);
            continue;
        }
        for(ll i=1;i<=n;++i)
        {
            wl[i] = -1;
            wr[i] = -1;
            if(a[i]==0)
            {
                if(v[i]<=V)
                {
                    continue;
                }
                for(int j=1;j<=m;++j)
                {
                    if(p[j]>=d[i])
                    {
                        wl[i] = j;
                        wr[i] = m;
                    }
                }
            }
            else if(a[i]>0)
            {
                /*if(d[i]!=0)
                {
                    v[i] = sqrt(v[i]*v[i]+2*a[i]*d[i]);
                }*/
                for(ll j=1;j<=m;++j)
                {
                    /*cout << "a>0 " << i << " " << j << endl;
                    cout << vv[i]+2*a[i]*(d[i]+p[j]) << endl;
                    cout << VV << endl;*/
                    if(d[i]>p[j])
                        continue;
                    if(vv[i]+2*a[i]*(p[j]-d[i])>VV)
                    {
                        wl[i] = j;
                        wr[i] = m;
                        break;
                    }
                }
            }
            else
            {
                ll u = -1;
                for(int j=1;j<=m;++j)
                {
                    if(d[i]<=p[j])
                    {
                        u = j;
                        break;
                    }
                }
                //cout << 'a' << u << endl;
                if(u==-1)
                    continue;
                if(vv[i]+2*a[i]*(p[u]-d[i])>VV)
                {
                    wl[i] = u;
                    wr[i] = u;
                    for(ll j=2;j<=m;++j)
                    {
                        if(vv[i]+2*a[i]*(p[j]-d[i])<0)
                            break;
                        if(vv[i]+2*a[i]*(p[j]-d[i])<=VV)
                        {
                            wr[i] = j-1;
                            break;
                        }
                    }
                }
            }
        }
        ll cnt = 0,ans = 0;
        for(int i=1;i<=n;++i)
        {
            if(wl[i]!=-1&&wr[i]!=-1)
                ++cnt;
            //cout << wl[i] << " " << wr[i] << endl;
        }
        if(cnt==0)
        {
            cout << 0 << " " << n << endl;
            continue;
        }
        if(c2==n)
        {
            cout << cnt << " " << n-1 << endl;
            continue;
        }
        for(int i=1;i<=n;++i)
            ww[i].l = wl[i],ww[i].r = wr[i];
        sort(ww+1,ww+n+1,cmp2);
        if(c3==n)
        {

        }

        for(int i=1;i<m;++i)
        {
            if(wl[i]==-1||wr[i]==-1)
                continue;
            ll wll,wrr;
            wll = 0;
            wrr = 0;
            for(int j=i+1;j<=m;++j)
            {
                if(wl[j]==-1||wr[j]==-1)
                    continue;
                if(wl[i]<=wl[j])
                {
                    if(wr[i]>=wr[j])
                    {
                        wll = wl[j];
                        wrr = wr[j];
                    }
                    else
                    {
                        wll = wl[j];
                        wrr = wr[i];
                    }
                }
                else
                {
                    if(wr[i]>=wr[j])
                    {
                        if(wl[i]>=wr[j])
                        {
                            wll = wl[i];
                            wrr = wr[j];
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        wll = wl[i];
                        wrr = wr[i];
                    }
                }
            }
            if(wll!=0&&wrr!=0)
            {
                ++ans;
            }
        }
        /*for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
        }*/
        /*for(int i=1;i<=n;++i)
        {
            for(int j=1;j<wl[i];++j)
                cout << 0 << " ";
            for(int j=wl[i];j<=wr[i];++j)
            {
                cout << 1 << " ";
            }
            for(int j=wr[i]+1;j<=m;++j)
                cout << 0 << " ";
            cout << endl;
        }*/
        cout << cnt << " " << m-ans << endl;
    }
    return 0;
}

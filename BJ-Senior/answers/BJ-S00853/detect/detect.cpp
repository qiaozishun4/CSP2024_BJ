#include<bits/stdc++.h>
using namespace std;
struct car
{
    int d;
    int v;
    int a;
    int b;
    int e;
    bool is;
}s[100005];
int p[100005];
int f[100005];
bool mycmp(car x,car y)
{
    if(x.b==y.b)
        return x.e<y.e;
    return x.b<y.b;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T,n,m,V,L;
	cin>>T;
	while(T--)
    {
        int i,j,ans=0;
        cin>>n>>m>>L>>V;
        for(i=1;i<=n;i++)
        {
            s[i].is=0;
            cin>>s[i].d>>s[i].v>>s[i].a;
        }
        for(i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(i=1;i<=n;i++)
        {
            if(s[i].d>p[m])
                continue;
            int w=lower_bound(p+1,p+m+1,s[i].d)-p-1;
            if(s[i].d==p[w+1])
                w++;
            if(s[i].a==0)
            {
                if(s[i].v<=V)
                    continue;
                else
                {
                    //f[w]=1;
                    s[i].b=w;
                    s[i].e=m;
                    s[i].is=1;
                    ans++;
                    continue;
                }
            }
            double S=s[i].d+double(V*V-s[i].v*s[i].v)/2/s[i].a;
            int l=lower_bound(p+1,p+m+1,s[i].d)-p-1;
            if(s[i].d==p[l+1])
                l++;
            int r=lower_bound(p+1,p+m+1,S)-p-1;
            if(S==p[r+1])
                r++;
            if(s[i].a>0&&S<p[m])
            {
                //f[r]=1;
                s[i].b=r;
                s[i].e=m;
                s[i].is=1;
                ans++;
            }
            if(s[i].a<0&&l!=r)
            {
                //f[l]=1;
                s[i].b=l;
                s[i].e=r-1;
                s[i].is=1;
                ans++;
            }
        }
        cout<<ans<<endl;
        sort(s+1,s+n+1,mycmp);
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(i==n)
            {
                ans++;
                break;
            }
            while(s[i].b<s[i+1].b&&s[i].b<s[i].e)
            {
                s[i].b++;
            }
            while(s[i].e>s[i+1].e&&s[i].e>s[i].b)
            {
                s[i].e--;
            }
            while(s[i].b==s[i+1].b&&s[i].e==s[i+1].e)
                i++;
            if(s[i].b==s[i].e)
            {
                j=i+1;
                while(j<=n&&s[j].b==s[i].b)
                {
                    if(s[j].is==0)
                        continue;
                    j++;
                }
                i=j-1;
                ans++;
                continue;
            }
            if(s[i].b==s[i+1].b)
            {
                j=i+1;
                bool flag=0;
                int xiao=1e9;
                while(1)
                {
                    if(j>n)
                        break;
                    while(j<=n&&s[j].b==s[i].b)
                    {
                        if(s[j].is==0)
                            continue;
                        xiao=min(xiao,s[j].e);
                        j++;
                    }
                    if(j>n)
                    {
                        ans++;
                        break;
                    }
                    else
                    {
                        if(s[j].b>xiao)
                        {
                            i=j-1;
                            ans++;
                            flag=1;
                            break;
                        }
                        else
                        {
                            s[i].b=s[j].b;
                            xiao=min(xiao,s[j].e);
                        }
                    }
                }
                if(flag)
                    continue;
                if(j>n)
                    break;
            }
        }
        cout<<m-ans<<endl;
    }
	return 0;
}

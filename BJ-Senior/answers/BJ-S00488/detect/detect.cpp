#include<bits/stdc++.h>
using namespace std;
struct SE
{
    int st,ed;
}se[100005];
bool cmp(SE a,SE b)
{
    return a.ed<b.ed;
}
double car[100005][4],s,V,v[100005][4];
int n,m,t,ans = 0,l,k,h,sxt[100005];
void js(double a,double b,int c)
{
    int l = 1,r = m,z;
    if(a < sxt[m])
    {
        if(b > sxt[1])
        {
             while(l<r)
            {
                z = (r+l+1)/2;
                if(sxt[z]>=b)
                {
                    r = z-1;
                }
                else
                {
                    l = z;
                }
            }
            if(sxt[l]>a&&sxt[l]<b)
            {
                se[k].ed = l;
                ans++;
            }
            l = 1;
            r = m;
            while(l<r)
            {
                z = (r+l)/2;
                if(sxt[z]>a)
                {
                    r = z;
                }
                else
                {
                    l = z+1;
                }
            }
            se[k].st = l;
            k++;
        }
    }

}
void cs(double a,int c)
{
    int l = 1,r = m,z;
    if(a < sxt[m])
    {
        ans++;
        while(l<r)
        {
            z = (r+l)/2;
            if(sxt[z]>=a)
            {
                r = z;
            }
            else
            {
                l = z+1;
            }
        }
        se[k].st = l;
        se[k].ed = m;
        k++;
    }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    for(int i = 1;i<=t;i++)
    {
        k=0;
        scanf("%d%d%d%d",&n,&m,&l,&h);
        ans = 0;
        V=h;
        for(int i = 1,a1,a2,a3;i<=n;i++)
        {
            scanf("%d%d%d",&a1,&a2,&a3);
            v[i][0] = a1;
            v[i][1] = a2;
            v[i][2] = a3;
        }
        for(int i = 1;i<=m;i++)
        {
            scanf("%d",&sxt[i]);
        }
        for(int i = 1;i<=n;i++)
        {
            if(v[i][2]>0)
            {
                s = (V*V-v[i][1]*v[i][1])/(v[i][2]*2);
                cs(max(v[i][0]+s,v[i][0]-0.01),i);
            }
            else if(v[i][2]<0)
            {
                if(v[i][1]>V)
                {
                    s = (V*V-v[i][1]*v[i][1])/(v[i][2]*2);
                    js(v[i][0]-0.01,v[i][0]+s,i);
                }

            }
            else if(v[i][2]==0)
            {
                if(v[i][1]>V)
                {
                    cs(v[i][0]-0.01,i);
                }
            }
        }
        printf("%d",ans);
        cout << ' ';
        ans = 0;
        sort(se,se+k,cmp);
        int h = 0;
        int nu = 0;
        while(nu < k)
        {
            if(se[nu].st>h)
            {
                h = se[nu].ed;
                ans++;
            }
            nu++;
        }
        ans = m-ans;
        printf("%d",ans);
        cout << endl;
    }
    return 0;
}

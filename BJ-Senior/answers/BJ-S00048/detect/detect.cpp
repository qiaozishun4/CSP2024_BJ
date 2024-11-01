#include<bits/stdc++.h>
//#define l[(int)i] c[(int)i].l
using namespace std;
int d[100005],v[100005],a[100005];
struct T
{
    int l,r;
    friend bool operator<(T a,T b)
    {
        if(a.l!=b.l)return a.l<b.l;
        return a.r<b.r;
    }
}c[100005];
int k[100005];
int n,m,len,V;
bool check(int i)
{
    if(c[i].l==0&&c[i].r==0)return 0;
    int l1=0,r1=m+1;
    while(l1<r1)
    {
        int mid=l1+r1;
        mid>>=1;
        if(k[mid]>=c[i].l)r1=mid;
        else l1=mid+1;
    }
    int tmp1=l1;
    l1=0,r1=m+1;
    while(l1<r1)
    {
        int mid=l1+r1+1;
        mid>>=1;
        if(k[mid]<c[i].r)l1=mid;
        else r1=mid-1;
    }
    c[i].l=tmp1;
    c[i].r=r1;
    //c[i]=(T){c[i].l,c[i].r};
    //cout<<i<<" "<<c[i].l<<" "<<c[i].r<<endl;
    if(c[i].l>c[i].r)c[i].l=c[i].r=0;
    if(c[i].l!=0&&c[i].l!=m+1&&c[i].r!=0&&c[i].r!=m+1)return 1;
    return 0;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>len>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>0)
            {
                c[i].r=len+1;
                c[i].l=d[i]+max(0,(V*V-v[i]*v[i]+(2*a[i]-1))/(2*a[i]));
                if((V*V-v[i]*v[i])%(2*a[i])==0)c[i].l++;
                if(v[i]>V)c[i].l=d[i],c[i].r=len+1;
                //c[i].l=min(c[i].l,len);
            }
            if(a[i]==0)
            {
                if(v[i]>V)c[i].l=d[i],c[i].r=len+1;
            }
            if(a[i]<0)
            {
                c[i].l=d[i];
                c[i].r=d[i]+max(0,(V*V-v[i]*v[i]+(2*a[i]-1))/(2*a[i]));
                if((V*V-v[i]*v[i])%(2*a[i])==0)c[i].r--;
                c[i].r=min(c[i].r,len+1);
                //if(v[i]<V)c[i].r=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>k[i];
        }
        int ans1=0;
        k[0]=-1;
        k[m+1]=len+1;
        //cout<<m<<endl;
        //cout<<k[1]<<" "<<k[m]<<endl;
        for(int i=1;i<=n;i++)
        {
            if(check(i))ans1++;//cout<<i<<endl;
        }
        sort(c+1,c+n+1);
        //cout<<1<<' '<<c[1].l<<" "<<c[1].r<<endl;
        for(int i=1;i<n;i++)
        {//cout<<i+1<<" "<<c[i+1].l<<" "<<c[i+1].r<<endl;
            if(c[i].r>=c[i+1].l)
            {
                c[i+1].r=min(c[i+1].r,c[i].r);
                c[i+1].l=max(c[i].l,c[i+1].l);
                c[i].l=c[i].r=0;
            }
            if(c[i].l>c[i].r)c[i].l=c[i].r=0;
        }
        int ans2=m;
        for(int i=1;i<=n;i++)
        {
            if(c[i].l!=0)ans2--;
            //cout<<i<<" "<<c[i].l<<" "<<c[i].r<<endl;
        }
        //if(t==6)cout<<m<<endl;
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}


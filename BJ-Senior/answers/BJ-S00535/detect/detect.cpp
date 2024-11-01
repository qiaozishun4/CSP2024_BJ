#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,l,vmax,ans1,ans2;
struct node
{
    ll d,v,a;
    double s,e;//qidian zhongdian
    bool fs,fe;//shifou baohan duandian
    int iss,ise;//shifou wei fenshu
    ll ks,ke;//shexiangtou
}car[100100];
struct node2
{
    ll s,t;
}a[100100];
bool cmp(node2 a,node2 b)
{
    if(a.t==b.t) return a.s<b.s;
    else return a.t<b.t;
}
ll p[100100];
void check(ll x)
{
    if(car[x].a==0)
    {
        if(car[x].v>vmax)
        {
            car[x].s=car[x].d,car[x].e=l;
            car[x].fs=true,car[x].fe=true;
        }
        else
        {
            car[x].s=car[x].e=-1;
        }
        return;
    }
    if(car[x].a>0)
    {
        if(car[x].v>vmax)
        {
            car[x].s=car[x].d,car[x].e=l;
            car[x].fs=true,car[x].fe=true;
        }
        else
        {
            double over=(vmax*vmax-car[x].v*car[x].v)*1.0/2/car[x].a;
            if((vmax*vmax-car[x].v*car[x].v)%(2*car[x].a)>car[x].a) car[x].iss=1;
            else if((vmax*vmax-car[x].v*car[x].v)%(2*car[x].a)<car[x].a) car[x].iss=2;
            else car[x].iss=0;
            over+=car[x].d;
            if(over>=l) car[x].s=car[x].e=-1;
            else
            {
                car[x].s=over,car[x].e=l;
                car[x].fs=false,car[x].fe=true;
            }
        }
    }
    if(car[x].a<0)
    {
        if(car[x].v<vmax)
        {
            car[x].s=car[x].e=-1;
        }
        else
        {
            double over=(vmax*vmax-car[x].v*car[x].v)*1.0/2/car[x].a;
            if((vmax*vmax-car[x].v*car[x].v)%(2*car[x].a)>car[x].a) car[x].ise=1;
            else if((vmax*vmax-car[x].v*car[x].v)%(2*car[x].a)<car[x].a) car[x].ise=2;
            else car[x].ise=0;
            over+=car[x].d;
    //        cout<<"over"<<over<<endl;
            car[x].s=car[x].d;car[x].e=over;
            car[x].fs=true,car[x].fe=false;
     //       cout<<"e"<< car[x].e<<endl;
            if(car[x].e>l) car[x].e=l,car[x].fe=true;
        }
    }
}
ll cmp1(double s,int f)
{
    ll l=1,r=m,ans=m+1;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(p[mid]<s) l=mid+1;
        else if(p[mid]>s)
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else if(p[mid]==s&&f==0)
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else if(p[mid]==s&&f==1)
        {
          //  l=mid+1;
            ans=min(ans,mid);
            r=mid-1;
        }
        else{
         //   ans=min(ans,mid);
         //   r=mid-1;
            l=mid+1;
        }
    }
    return ans;
}
ll cmp2(double s,int f)
{
    ll l=1,r=m,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(p[mid]>s) r=mid-1;
        else if(p[mid]<s)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else if(p[mid]==s&&f==0)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else if(p[mid]==s&&f==1)
        {
        //    r=mid-1;
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
         //   ans=max(ans,mid);
       //     l=mid+1;
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>vmax;
        ans1=ans2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>car[i].d>>car[i].v>>car[i].a;
            check(i);
        }
    /*    cout<<"*******************";
        for(int i=72907;i<=72907;i++)
        {
            cout<<i<<":"<<car[i].s;
            if(car[i].fs==true) cout<<"<=";
            else cout<<"<";
            cout<<"x";
            if(car[i].fe==true) cout<<"<=";
            else cout<<"<";
            cout<<car[i].e<<endl;
        }//*/
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
/*
        if(t==19)
        {
            cout<<1<<endl;
            cout<<n<<" "<<m<<" "<<l<<" "<<vmax<<endl;
            for(int i=1;i<=n;i++)
            {
                cout<<car[i].d<<" "<<car[i].v<<" "<<car[i].a<<endl;
            }
            for(int i=1;i<=m;i++) cout<<p[i]<<" ";
            return 0;
        }//*/
        for(int i=1;i<=n;i++)
        {
            ll ss=cmp1(car[i].s,car[i].iss);
            if(car[i].fs==false&&car[i].s==double(p[ss])&&car[i].iss==false) ss++;
            ll ee=cmp2(car[i].e,car[i].ise);
            if(car[i].fe==false&&car[i].e==double(p[ee])&&car[i].ise==false) ee--;
        //    cout<<i<<":"<<ss<<" "<<ee<<endl;
            if(ss==m+1||ee==m+1||ss==0||ee==0)
            {
          //      if(i==72907) cout<<"*****************"<<car[i].v<<"<="<<vmax<<endl;
         //       cout<<"NO";
        //        if(i%20==0) cout<<endl;
                continue;
            }

            else if(ss<=ee)
            {
            //    if(i==72907) cout<<"*****************"<<car[i].v<<"<="<<vmax<<endl;
           //     cout<<"YES";
                ans1++;
                a[ans1].s=ss,a[ans1].t=ee;
            }
         //   if(i==72907) cout<<"*****************"<<car[i].v<<"<="<<vmax<<endl;
         //   else cout<<"NO";
         //   if(i%20==0) cout<<endl;
        }
        sort(a+1,a+ans1+1,cmp);
   //     cout<<endl;
    //    for(int i=1;i<=ans1;i++) cout<<a[i].s<<" "<<a[i].t<<endl;
        ll last=0;
        for(int i=1;i<=ans1;i++)
        {
            if(last>=a[i].s) continue;
            else
            {
                last=a[i].t;ans2++;
            }
        }
        cout<<ans1<<" "<<m-ans2<<endl;
    }


    return 0;
}

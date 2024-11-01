#include<bits/stdc++.h>
using namespace std;
#define fio(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

///*
const int N=100005;
int n,m,L,ans1,ans2,fin;
double p[N];
short V,T;
bool ifordered;
int had[N];
struct car
{
    int d;
    short v,a;
}c[N];
struct oh
{
    int c,n;
}cnt[N];
map<pair<int,int>,bool> got;

bool bigger(oh a,oh b){return a.c>b.c;}
//*/

int main()
{
    fio("detect");
    ///*
    cin>>T;
    while(T--)
    {
    cin>>n>>m>>L>>V;
    ans1=fin=0,ans2=1,memset(cnt,0,sizeof(cnt)),memset(had,0,sizeof(had));
    for(int i=1;i<=m;i++) cnt[i].n=i;
    for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
    p[0]=-1;
    ifordered=true;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
        if(p[i]<p[i-1]) ifordered=false;
    }
    if(!ifordered) sort(p+1,p+1+m);
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<ans1<<"\n";
        if(c[i].a==0)
        {
            if(c[i].v<=V)
            {
                //cout<<"\n";
                continue;
            }
            for(int j=lower_bound(p+1,p+1+m,c[i].d)-p;j<=m;j++) got[{i,j}]=true,cnt[j].c++;
            ans1++;
            //cout<<"         "<<lower_bound(p+1,p+1+m,c[i].d)-p<<"\n";
            continue;
        }
        double tgt=c[i].d+(1.0*V*V-1.0*c[i].v*c[i].v)/2.0/c[i].a;
        //cout<<"       "<<tgt;
        if(c[i].a>0)
        {
            int upb=upper_bound(p+1,p+1+m,tgt)-p;
            if(upb>m) continue;
            for(int j=upb;j<=m;j++) got[{i,j}]=true,cnt[j].c++;
            //cout<<" "<<upb<<"\n";
        }
        else
        {
            int upb=lower_bound(p+1,p+1+m,tgt)-p,
                lwb=lower_bound(p+1,p+1+m,c[i].d)-p;
            if(upb<=lwb) continue;
            for(int j=lwb;j<upb;j++) got[{i,j}]=true,cnt[j].c++;
            //cout<<" "<<lwb<<" "<<upb<<"\n";
        }
        ans1++;
        //cout<<ans1<<"\n";
    }
    //cout<<ans1<<" ";
    cout<<ans1<<"\n";
    while(fin<n)
    //for(int e=1;e<=10;e++)
    {
        sort(cnt+ans2,cnt+1+m,bigger);
        for(int i=1;i<=n;i++) if(got[{cnt[ans2].n,i}]&&!had[i])
        {
            cout<<"     "<<i<<" "<<i+1<<"\n";
            fin++;
            had[i]=true;
            for(int j=ans2+1;j<=m;j++) if(got[{cnt[ans2].n,i}]) cnt[j].c--;
        }
        ans2++;
    }
    cout<<ans2<<"\n";
    }
    //*/
    return 0;
}
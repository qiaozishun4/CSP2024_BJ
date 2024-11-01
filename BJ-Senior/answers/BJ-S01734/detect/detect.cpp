#include<bits/stdc++.h>
using namespace std;

#define s first
#define t second
typedef pair<double,double> up;
up a[114514];
double p[114514];
double p1[114514];

int work(){
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(p1,0,sizeof(p1));
    int n,m;
    double l,v;
    cin>>n>>m>>l>>v;
    for(int i=0;i<n;i++){
        double di,vi,ai;
        cin>>di>>vi>>ai;
        if(ai==0)
            if(vi>v)a[i].s=di,a[i].t=l;
            else a[i].s=a[i].t=-1;
        else if(ai>0)
            if((v*v-vi*vi)/(2*ai)+di<l)a[i].s=di+max(0.0,(v*v-vi*vi)/(2*ai))+((int)((v*v-vi*vi)/(2*ai))==((v*v-vi*vi)/(2*ai))?0.1:0.0),a[i].t=l;
            else a[i].s=a[i].t=-1;
        else if(ai<0)
            if(vi<=v)a[i].s=a[i].t=-1;
            else a[i].s=di,a[i].t=min(l,di+(v*v-vi*vi)/(2*ai)-((int)((v*v-vi*vi)/(2*ai))==((v*v-vi*vi)/(2*ai))?0.1:0.0));
        //if(i==302)cout<<(v*v-vi*vi)/(2*ai)+di<<endl;
    }

    for(int i=0;i<m;i++)cin>>p[i];
    for(int i=0;i<m;i++)p1[i]=-p[m-1-i];


    //for(int i=0;i<n;i++)cout<<a[i].s<<' '<<a[i].t<<endl;cout<<endl;

    for(int i=0;i<n;i++)
        if(a[i].s!=-1&&a[i].t!=-1)
            a[i].s=lower_bound(p,p+m,a[i].s)-p,
            a[i].t=m-1-(lower_bound(p1,p1+m,-a[i].t)-p1);

        //for(int i=0;i<n;i++)cout<<a[i].s<<' '<<a[i].t<<endl;cout<<endl;
    //cout<<302<<' '<<a[302].s<<' '<<a[302].t<<endl;

    sort(a,a+n);
    //for(int i=0;i<n;i++)cout<<a[i].s<<' '<<a[i].t<<endl;cout<<endl;

    int last=-1;
    int cnt=-1;
    int allcnt=0;
    for(int i=0;i<n;i++){
        if(a[i].s==-1&&a[i].t==-1)continue;
        if(a[i].s>a[i].t)continue;
        allcnt++;
        if(a[i].s>last)cnt++,last=a[i].t;
        last=min(last,(int)(a[i].t+0.5));
    }
    cout<<allcnt<<' '<<m-cnt-1<<endl;
    return 0;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)work();
    return 0;
}
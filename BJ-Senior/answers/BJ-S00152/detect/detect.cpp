#include<bits/stdc++.h>
using namespace std;
int n,T,m,V,L,ans,cnt,ct;
const int N=100010;
int p[N];
struct node{
    int d,v,a,l,r;
}car[N];
struct node1{
    int l,r;
}t[N];
void calc(int x){
    if(car[x].a==0){
        if(car[x].v<=V) car[x].l=car[x].r=m+1;
        else{
            int loc=lower_bound(p+1,p+m+1,car[x].d)-p;
            if(loc==m+1) car[x].l=car[x].r=m+1;
            else car[x].l=loc,car[x].r=m;
        }
        //cout<<"NO"<<"\n";//shan
    }
    else if(car[x].a>0){
        //car[x].a=-car[x].a;
        if(car[x].v>V){
            int loc=lower_bound(p+1,p+m+1,car[x].d)-p;
            if(loc==m+1) car[x].l=car[x].r=m+1;
            else car[x].l=loc,car[x].r=m;
            //cout<<"NO"<<"\n";//shan
        }
        else{
            bool flag=0;
            //car[x].a=-car[x].a;
            int dis=(V*V-car[x].v*car[x].v)/(car[x].a*2);
            if(dis*car[x].a*2<V*V-car[x].v*car[x].v) flag=1,dis++;
            //dis++;
            int loc=lower_bound(p+1,p+m+1,car[x].d+dis)-p;
            if(flag==0&&p[loc]==car[x].d+dis) loc++;
            if(loc==m+1) car[x].l=car[x].r=m+1;
            else car[x].l=loc,car[x].r=m;
            //cout<<dis<<"\n";//shan
        }
    }
    else{
        car[x].a=-car[x].a;
        if(car[x].v<=V){
            car[x].l=car[x].r=m+1;
            //cout<<"NO"<<"\n";//shan
        }
        else{
            bool flag=0;
            int dis=(car[x].v*car[x].v-V*V)/(car[x].a*2);
            if(dis*car[x].a*2<car[x].v*car[x].v-V*V) flag=1,dis++;
            //dis++;
            int loc1=lower_bound(p+1,p+m+1,car[x].d)-p,loc2=lower_bound(p+1,p+m+1,car[x].d+dis)-p;
            //if(flag==0&&p[loc2]==car[x].d+dis) loc2--;
            if(loc1==m+1) car[x].l=car[x].r=m+1;
            else{
                loc2--;
                if(loc2<loc1) car[x].l=car[x].r=m+1;
                else car[x].l=loc1,car[x].r=loc2;
            }
            //cout<<dis<<"\n";//shan
        }
    }
}
bool cmp(node1 n1,node1 n2){
    return n1.r<n2.r;
    else return n1.l>n2.l;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        ans=cnt=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>car[i].d>>car[i].v>>car[i].a;
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        /*for(int i=1;i<=n;i++){
            cout<<car[i].d<<" "<<car[i].v<<" "<<car[i].a<<"\n";
        }
        for(int i=1;i<=m;i++) cout<<p[i]<<"\n";*/
        for(int i=1;i<=n;i++){
            calc(i);
            if(car[i].l>=1&&car[i].r<=m){
                ans++;
                cnt++;
                t[cnt].l=car[i].l;
                t[cnt].r=car[i].r;
            }
        }
        /*for(int i=1;i<=n;i++){
            cout<<car[i].d<<" "<<car[i].v<<" "<<car[i].a<<" "<<car[i].l<<" "<<car[i].r<<"\n";
        }*/
        //for(int i=1;i<=cnt;i++) cout<<t[i].l<<" "<<t[i].r<<"\n";
        cout<<ans<<" ";
        sort(t+1,t+cnt+1,cmp);
        int x=0;
        for(int i=1;i<=cnt;i++){
            if(x>=t[i].l) continue;
            else x=t[i].r,ct++;
        }
        cout<<m-ct<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e5+5,M=1e5+5;
int t,n,m,l,vs,d[N],v[N],a[N],p[M],qpc[N],ans1,ans2;
pii q[N],qp[N];
bool qk[N],ps[M];

void f(int gc){
    int hd,tl=0;
    for(hd=1;hd<=m;hd++){
        if(p[hd]>=q[gc].first&&p[hd]<=q[gc].second&&tl==0)    tl=hd;
        if(p[hd]>q[gc].second) break;
    }
    qp[gc]={tl,hd-1};
    qpc[gc]=hd-tl;
    if(tl>0)    {ans1++;qk[gc]=0;}
    else    qk[gc]=1;
}
void qf(int i){
    for(int j=1;j<=n;j++){
        if(i>=qp[j].first&&i<=qp[j].second){
            qk[j]=1;
        }
    }
}
int cf(int i){
    int anscf=0;
    for(int j=1;j<=n;j++){
        if(!qk[i]&&i>=qp[j].first&&i<=qp[j].second){
            anscf++;
        }
    }
    return anscf;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n>>m>>l>>vs;
        for(int i=1;i<=n;i++)   cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)   cin>>p[i];
        //
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>vs)    q[i]={d[i],l};
                else    q[i]={-1,-1};
            }
            else{
                int k;
                int vz=vs*vs-v[i]*v[i];
                if(vz%(2*a[i])==0)   k=vz/2/a[i]-1;
                else    k=vz/2/a[i];
                k+=d[i];
                if(a[i]>0){
                    if(k>d[i]){
                        if(k<=l)    q[i]={k,l};
                        else    q[i]={-1,-1};
                    }
                    else    q[i]={d[i],l};
                }
                else{
                    if(k>=d[i]){
                        if(k<=l)    q[i]={d[i],k};
                        else    q[i]={d[i],l};
                    }
                    else    q[i]={-1,-1};
                }
            }
        }
        ans1=0;
        for(int i=1;i<=n;i++)   f(i);
        for(int i=1;i<=m;i++)   ps[i]=0;
        for(int ci=0;ci<n;ci++){
            for(int i=1;i<=n;i++){
                if(!qk[i]&&qpc[i]==ci){
                    int maxj=qp[i].first;
                    for(int j=qp[i].first+1;j<=qp[i].second;j++)
                        if(cf(j)>cf(maxj))  maxj=j;
                    ps[maxj]=1;
                    qf(maxj);
                }
            }
        }
        ans2=0;
        for(int i=1;i<=n;i++)
            if(!ps[i])  ans2++;
        cout<<ans1<<" "<<ans2<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
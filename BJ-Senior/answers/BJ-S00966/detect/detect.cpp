#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{
    int l,r;
};
long long v[3000005],d[30005],a[3005],p[3005],pre[1000005];
node r[3005];
int tt[1000005];
bool cmp(node x1,node x2){
    if(x1.r!=x2.r){
        return x1.r<x2.r;
    }
    else{
        return x1.l<x2.l;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,b,l,s,n,m;
    double dd;
    cin>>T;
    while(T--){
        b=0;
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(tt,0,sizeof(tt));
        memset(pre,0,sizeof(pre));
        cin>>n>>m>>l>>s;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            tt[p[i]]=i;
        }
        for(int i=0;i<=l;i++){
            if(tt[i]){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=pre[i-1];
            }
        }

        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>s){
                    r[++b].l=d[i];
                    r[b].r=l;
                }
            }
            else{
                if(a[i]>0){
                    dd=ceil(   (s*s-v[i]*v[i])*1.0/(2*a[i])   );
                    if(dd*1.0==(s*s-v[i]*v[i])*1.0/(2*a[i])){
                        dd++;
                    }
                    if(dd+d[i]<=l){
                        r[++b].l=d[i]+dd;
                        r[b].r=l;
                    }
                }
                else{
                    if(v[i]>s){
                        dd=floor((s*s-v[i]*v[i])*1.0/(2*a[i]));
                        if(dd*1.0==(s*s-v[i]*v[i])*1.0/(2*a[i])) {
                            dd--;
                        }
                        if(dd+d[i]>=l){
                            r[++b].l=d[i];
                            r[b].r=l;
                        }
                        else{
                            r[++b].l=d[i];
                            r[b].r=d[i]+dd;
                        }
                    }
                }
            }
        }
        int Ans1=0;

        for(int i=1;i<=b;i++){
                if(pre[r[i].r]-pre[r[i].l-1]>0){
                    Ans1++;
                }
                else{
                    r[i].l=l+1;
                    r[i].r=l+1;
                }
        }
        cout<<Ans1<<' ';
        sort(r+1,r+1+b,cmp);
        int k=1,x=1,Ans2=0;

        while(k<=Ans1){
            for(int j=x;j<=m;j++){
                if(p[j]==r[k].r){
                        k++;
                    x=j;
                    Ans2++;#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{
    int l,r;
};
long long v[3000005],d[30005],a[3005],p[3005],pre[1000005];
node r[3005];
int tt[1000005];
bool cmp(node x1,node x2){
    if(x1.r!=x2.r){
        return x1.r<x2.r;
    }
    else{
        return x1.l<x2.l;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,b,l,s,n,m;
    double dd;
    cin>>T;
    while(T--){
        b=0;
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(tt,0,sizeof(tt));
        memset(pre,0,sizeof(pre));
        cin>>n>>m>>l>>s;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            tt[p[i]]=i;
        }
        for(int i=0;i<=l;i++){
            if(tt[i]){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=pre[i-1];
            }
        }

        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>s){
                    r[++b].l=d[i];
                    r[b].r=l;
                }
            }
            else{
                if(a[i]>0){
                    dd=ceil(   (s*s-v[i]*v[i])*1.0/(2*a[i])   );
                    if(dd*1.0==(s*s-v[i]*v[i])*1.0/(2*a[i])){
                        dd++;
                    }
                    if(dd+d[i]<=l){
                        r[++b].l=d[i]+dd;
                        r[b].r=l;
                    }
                }
                else{
                    if(v[i]>s){
                        dd=floor((s*s-v[i]*v[i])*1.0/(2*a[i]));
                        if(dd*1.0==(s*s-v[i]*v[i])*1.0/(2*a[i])) {
                            dd--;
                        }
                        if(dd+d[i]>=l){
                            r[++b].l=d[i];
                            r[b].r=l;
                        }
                        else{
                            r[++b].l=d[i];
                            r[b].r=d[i]+dd;
                        }
                    }
                }
            }
        }
        int Ans1=0;

        for(int i=1;i<=b;i++){
                if(pre[r[i].r]-pre[r[i].l-1]>0){
                    Ans1++;
                }
                else{
                    r[i].l=l+1;
                    r[i].r=l+1;
                }
        }
        cout<<Ans1<<' ';
        sort(r+1,r+1+b,cmp);
        int k=1,x=1,Ans2=0;

        while(k<=Ans1){
            for(int j=x;j<=m;j++){
                if(p[j]==r[k].r){
                        k++;
                    x=j;
                    Ans2++;
                    break;
                }
                if(p[j]>r[k].r){
                    x=j-1;
                k++;
                    Ans2++;
                    break;
                }
            }
            while(p[x]>=r[k].l){
                k++;
            }
        }
        cout<<m-Ans2<<endl;
    }
    return 0;
}

                    break;
                }
                if(p[j]>r[k].r){
                    x=j-1;
                k++;
                    Ans2++;
                    break;
                }
            }
            while(p[x]>=r[k].l){
                k++;
            }
        }
        cout<<m-Ans2<<endl;
    }
    return 0;
}

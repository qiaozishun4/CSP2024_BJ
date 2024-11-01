#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,L,V,ans1,ans2;
struct car{
    int v,d,a;
    double s,t;
};
struct H{
    int nm,I;
};
car r[N];
int p[N];
bool f[N],g[3010][3010],l[N];
//int l[N];
H h[N];
bool cmp2(H x,H y){
    return x.nm<y.nm;
}
bool cmp(car x,car y){
    //return x.s<y.s;
    /*/*/
    if(x.a*y.a<0){
        return x.a>0;
    }else{
        return x.s<y.s;
    }/**/
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        ans1=0;
        ans2=0;
        cin>>n>>m>>L>>V;
        //ans1=n;
        //cout<<"fifif\n";
        for(int i=1;i<=n;i++){
            cin>>r[i].d>>r[i].v>>r[i].a;
            //cout<<'p';
            if(!(r[i].v<=V&&r[i].a<=0)){
                if(r[i].v>V&&r[i].a>=0){
                    r[i].s=r[i].d;
                    continue;
                }
                r[i].t=double(V-r[i].v);
                r[i].t/=double(r[i].a);
                r[i].s=r[i].t*r[i].t;
                r[i].s*=double(r[i].a)*0.5;
                r[i].s+=double(r[i].v)*r[i].t+double(r[i].d);
                //if(r[i].s>double(L)&&r[i].a>0)ans1--;
            }else{
                r[i].s=-1;
                r[i].t=-1;
                //ans1--;
            }
            //cout<<r[i].s<<endl;
        }
        for(int i=1;i<=m;i++)cin>>p[i];

        sort(p+1,p+m+1);
        sort(r+1,r+n+1,cmp);
        int u=1,v=1;
        if(n>20||m>20){
            for(int i=1;i<=m;i++){
                if(r[u].a<0)break;
                for(int j=u;j<=n;j++){
                    if(r[i].s==-1)continue;
                    if(r[j].s<double(p[i])){
                        ans1++;
                        u++;
                    }else break;
                }

            }
            for(int j=u;j<=n;j++){
                if(r[j].s==-1)continue;
                for(int i=v;i<=m;i++){
                    if(double(p[i])>=r[j].d&&double(p[i])<r[j].s){
                        ans1++;
                        v=i;


                        break;

                    }
                    if(double(p[i])>=r[j].s){
                        break;
                    }

                }
            }
            ans2=ans1-1;
        }else{
            memset(g,sizeof(g),0);
            memset(h,sizeof(h),0);
            memset(f,sizeof(f),0);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    g[i][j]=0;
                    f[i]=0;
                    l[i]=0;
                    h[i].nm=0;
                    h[i].I=0;
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        //cout<<r[i].s<<' '<<p[j]<<endl;
                    if(r[i].a>=0){
                        if(r[i].s<double(p[j])){
                            l[i]=1;
                            g[i][j]=1;
                            //l[i]++;
                            h[j].nm++;
                            h[j].I=j;
                            //cout<<f[i]<<endl;
                            if(f[i]==0)ans1++;
                            f[i]=1;
                        }
                    }else{
                        if(r[i].s>double(p[j])&&r[i].d<=p[j]){
                            l[i]=1;
                            g[i][j]=1;
                            //l[i]++;
                            h[j].nm++;
                            h[j].I=j;
                            //cout<<f[i]<<endl;
                            if(f[i]==0)ans1++;
                            f[i]=1;
                        }
                    }
                }
            }
            sort(h+1,h+m+1,cmp2);
            for(int j=1;j<=m;j++){
                bool FF=0;
                for(int i=1;i<=n;i++){
                    if(l[i]==0)continue;
                    bool ff=0;
                    for(int k=1;k<=m;k++){
                        if(g[i][k]&&k!=j){
                            ff=1;
                            break;
                        }
                    }
                    if(ff==0){
                        FF=1;

                    }
                }
                if(FF!=1){
                    ans2++;
                    for(int k=1;k<=n;k++){
                        g[k][j]=0;
                    }
                }
            }
        }

        cout<<ans1<<' '<<ans2<<endl;








    }
}
/*int u=1,v=1;
        while(r[u].a>=0){
            if(r[u].s==-1){
                u++;
                continue;
            }
            if(v>m){
                int _u=u;
                while(r[++u].a>=0);
                ans1-=u-_u;
                break;
            }
            if(r[u].s>=double(p[v])){
                v++;
            }else{
                u++;
            }
        }
        v=m;
        for(int i=n;i>=u;){
            if(r[i].s==-1){
                i--;
                continue;
            }
            if(v<=0){
                ans1-=n-i+1;
                break;
            }
            if(r[i].s<=double(p[v])){
                v--;
            }else if(r[i].d>p[v]){
                ans1--;
                i++;
            }else{
                i++;
            }
        }
        cout<<ans1<<endl;*/

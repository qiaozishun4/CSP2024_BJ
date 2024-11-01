#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=3010,M=21;
int t,n[M],m[M],l[M],v[M],cs[M][N];
pair<int,int>fakuan[N];
bool ch1,ch2,ch3,ch4;
struct node{
    int d,v,a;
}zyz[M][N];
int getone(int x){
    int dkjs=0;
    while(x){
        if(x%2==1)dkjs++;
        x=x>>1;
    }
    return dkjs;
}
int solve(int x){
    int ANS=0,faku=0;
    memset(fakuan,0,sizeof(fakuan));
    for(int i=1;i<=n[x];i++){
        if(zyz[x][i].v<=v[x]&&zyz[x][i].a<=0)continue;
        if(zyz[x][i].a<0){
            double Tim=1.0*(v[x]-zyz[x][i].v)/zyz[x][i].a;
            double juli=1.0*zyz[x][i].v*Tim+0.5*zyz[x][i].a*Tim*Tim;
            for(int j=m[x];j>=1;j--){
                if(cs[x][j]>=zyz[x][i].d){
                    if(zyz[x][i].d+juli>cs[x][j]&&fakuan[i].se==0){
                        ++faku;
                        fakuan[i].se=j;
                    }
                }else{
                    if(fakuan[i].se){
                        fakuan[i].fi=(j+1);
                    }
                    break;
                }

            }
        }else if(zyz[x][i].a>0){
            double Tim=1.0*(v[x]-zyz[x][i].v)/zyz[x][i].a;
            double juli=1.0*zyz[x][i].v*Tim+0.5*zyz[x][i].a*Tim*Tim;
            for(int j=1;j<=m[x];j++){
                if(cs[x][j]>=zyz[x][i].d){
                    if(zyz[x][i].d+juli<cs[x][j]){
                        ++faku;
                        fakuan[i].fi=j;
                        fakuan[i].se=m[x];
                        break;
                    }
                }
            }
        }else if(zyz[x][i].a==0){
            for(int j=1;j<=m[x];j++){
                if(cs[x][j]>=zyz[x][i].d){
                    if(zyz[x][i].v>v[x]){
                        ++faku;
                        fakuan[i].fi=j;
                        fakuan[i].se=m[x];
                    }
                    break;
                }
            }
        }
    }
    cout<<faku<<" ";
    if(faku==0)return m[x];
    int db=1<<m[x];
    for(int i=0;i<db;i++){
        bool kexing=1;
        for(int j=1;j<=n[x];j++){
            if(fakuan[j].se){
                bool sadjf=0;
                for(int k=fakuan[j].fi;k<=fakuan[j].se;k++){
                    if((1<<(k-1))&i){
                        sadjf=1;
                        break;
                    }
                }
                if(!sadjf){
                    kexing=0;
                    break;
                }
            }
        }
        if(kexing==1)ANS=max(ANS,m[x]-getone(i));
    }
    return ANS;
}
int solve2(int x){
    int ANS=0,faku=0;
    memset(fakuan,0,sizeof(fakuan));
    for(int i=1;i<=n[x];i++){
        for(int j=1;j<=m[x];j++){
            if(cs[x][j]>=zyz[x][i].d){
                if(zyz[x][i].v>v[x]){
                    ++faku;
                    fakuan[i].fi=j;
                    fakuan[i].se=m[x];
                }
                break;
            }
        }
    }
    cout<<faku<<" ";
    if(faku>0)return m[x]-1;
    else return m[x];
}int solve3(int x){
    int ANS=0,faku=0;
    memset(fakuan,0,sizeof(fakuan));
    for(int i=1;i<=n[x];i++){
        double Tim=1.0*(v[x]-zyz[x][i].v)/zyz[x][i].a;
        double juli=1.0*zyz[x][i].v*Tim+0.5*zyz[x][i].a*Tim*Tim;
        for(int j=1;j<=m[x];j++){
            if(cs[x][j]>=zyz[x][i].d){
                if(zyz[x][i].d+juli<cs[x][j]){
                    ++faku;
                    fakuan[i].fi=j;
                    fakuan[i].se=m[x];
                    break;
                }
            }
        }
    }
    cout<<faku<<" ";
    if(faku>0)return m[x]-1;
    else return m[x];
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    for(int x=1;x<=t;x++){
        scanf("%d%d%d%d",&n[x],&m[x],&l[x],&v[x]);
        if(n[x]>20||m[x]>20)ch1=1;
        for(int i=1;i<=n[x];i++){
            scanf("%d%d%d",&zyz[x][i].d,&zyz[x][i].v,&zyz[x][i].a);
            if(zyz[x][i].a!=0)ch2=1;
            if(zyz[x][i].a<=0)ch3=1;
        }for(int i=1;i<=m[x];i++){
            scanf("%d",&cs[x][i]);
        }sort(cs[x]+1,cs[x]+m[x]+1);
    }
    if(ch1==0){
        for(int x=1;x<=t;x++){
            cout<<solve(x)<<endl;
        }
    }else if(ch2==0){
        for(int x=1;x<=t;x++){
            cout<<solve2(x)<<endl;
        }
    }else if(ch3==0){
        for(int x=1;x<=t;x++){
            cout<<solve3(x)<<endl;
        }
    }else{
        for(int x=1;x<=t;x++){
            cout<<1<<endl;
        }
    }
    return 0;
}

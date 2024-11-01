#include<bits/stdc++.h>
using namespace std;
int T;
long double n,m,L,V;
int s[100005];
int ans,anss,cntt;
int k,kk;
struct code{
    int w;//1,only x;0 both x,y//or-1==no
    long double x,y;//x:min;y:max//or x=+,y=-
};
code z[100005];
code f[100005];
void solve(int xx,int yy){
    for(int i=1;i<=cntt;i++){
        if(z[i].x<=xx&&yy<=z[i].y){
            z[i].x=xx;
            z[i].y=yy;
            return;
        }else{
            if(xx<=z[i].x&&z[i].y<=yy){
                return;
            }
        }
    }
    cntt++;
    z[cntt].x=xx;
    z[cntt].y=yy;
}
bool cmp(code xx,code yy){
    return xx.x<yy.x;
}
/*bool cm(long double c,long double v0,long double a){
    long double g=2*a*c+v0*v0;
    if(g<V*V){
        return 1;
    }
    return 0;
}*/
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int _=1;_<=T;_++){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            long double d,v,a;
            cin>>d>>v>>a;
            //f[i].v=v;
            //f[i].a=a;
            if(a==0){
                f[i].w=1;
                if(v>V){
                    f[i].x=d;
                }else{
                    f[i].x=-1;
                }
            }
            if(a>0){
                if(v>V){
                    f[i].w=1;
                    f[i].x=d;
                }else{
                    f[i].w=1;
                    f[i].x=d+(V*V-v*v)/(2*a);
                }
            }
            if(a<0){
                f[i].w=0;
                if(v<=V){
                    f[i].x=-1;
                }else{
                    f[i].x=d;
                    f[i].y=d+(V*V-v*v)/(2*a);
                }
            }
            //cout<<f[i].w<<" "<<f[i].x<<" "<<f[i].y<<endl;
        }
        for(int i=1;i<=m;i++){
            int p;
            cin>>p;
            s[p]=1;
            //cout<<p<<" ";
        }
        //cout<<endl;
        for(int i=1;i<=n;i++){
            if(f[i].x==-1){
                continue;
            }
            int cnt=f[i].x;
            if((long double)cnt<f[i].x){
                cnt++;
            }
            if(f[i].w==1){
                for(int j=cnt;j<=L;j++){
                    if(s[j]==1){
                        k=max(k,cnt);
                        ans++;
                        break;
                    }
                }
            }else{
                int cnt2=f[i].y;
                for(int j=cnt;j<=cnt2;j++){
                    if(s[j]==1){
                        ans++;
                        solve(cnt,cnt2);
                        break;
                    }
                }
            }
        }
        sort(z+1,z+1+cntt,cmp);
        for(int i=1;i<=cntt;i++){
            if(z[i].w!=-1){
                for(int j=z[i].y;j>=z[i].x;j--){
                    if(s[j]==1){
                        for(int ii=1;ii<=cntt;ii++){
                            if(z[ii].x<=j){
                                z[ii].w=-1;
                            }else{
                                break;
                            }
                        }
                        if(k<=j){
                            kk=1;
                        }
                        anss++;
                        break;
                    }
                }
            }
        }
        if(kk==0){
            anss++;
        }
        cout<<ans<<" "<<m-anss<<endl;
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        memset(z,0,sizeof(z));
        ans=0;
        cntt=0;
        kk=0;
        anss=0;
        k=0;
    }
    return 0;
}
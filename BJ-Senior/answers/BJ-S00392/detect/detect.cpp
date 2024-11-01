#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define int long long
using namespace std;
struct C{
    int d,v,a;
    long double x=0;
    bool dtd=0;
}c[100005];
struct N{
    long double l,r;
    bool nl=0;
    bool dtd=0;
}sq[100005];
bool cmp(N a,N b){
    if(a.r!=b.r){
        return a.r<b.r;
    }
    return a.l<b.l;
}
int p[100005];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=1e5;i++){
            c[i].d=c[i].v=c[i].a=0;
            //sq[i].l=sq[i].r=sq[i].nl=sq[i].dtd=0;
        }
        memset(p,0,sizeof(p));
        memset(c,0,sizeof(c));
        memset(sq,0,sizeof(sq));
        int n,m,L,V;
        bool fa=1,fb=1,fc=1;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a>0){
                fa=0;
                fc=0;
                //cout<<i<<' '<<(1.0*V*V-1.0*c[i].v*c[i].v)<<endl;
                c[i].x=c[i].d+(1.0*V*V-1.0*c[i].v*c[i].v)/(2.0*c[i].a);
            }else if(c[i].a==0){
                fb=0;
                fc=0;
            }else if(c[i].a<0){
                fa=0;
                fb=0;
                c[i].x=c[i].d+(1.0*c[i].v*c[i].v-1.0*V*V)/(2.0*-1*c[i].a);
            }
            //cout<<c[i].x<<endl;
        }
        //cout<<endl;
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int cnt=0;
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++){
            if(c[i].a>0){
                if(p[n]>c[i].x){
                    c[i].dtd=1;
                    cnt++;
                    sq[cnt].l=c[i].x;
                    sq[cnt].r=2e9;
                    sq[cnt].nl=1;
                }
            }
            if(c[i].a==0){
                if(c[i].d<=p[m]&&V<c[i].v){
                    c[i].dtd=1;
                    cnt++;
                    sq[cnt].l=c[i].d;
                    sq[cnt].r=2e9;
                    sq[cnt].nl=0;
                }
            }
            if(c[i].a<0){
                int l=1,r=m;
                while(l<r){
                    int mid=(l+r+1)>>1;
                    if(p[mid]>=c[i].x){
                        r=mid-1;
                    }else{
                        l=mid;
                    }
                }
                if(p[l]==c[i].x)
                    l--;
                //cout<<l<<' '<<p[l]<<' '<<c[i].x<<endl;
                if(p[l]>=c[i].d&&p[l]<c[i].x){
                    c[i].dtd=1;
                    cnt++;
                    sq[cnt].l=c[i].d;
                    sq[cnt].r=c[i].x;
                    sq[cnt].nl=0;
                }
            }
        }
        cout<<cnt<<' ';
        sort(sq+1,sq+cnt+1,cmp);
        int j=1;
        int mic=0;
        int la=0;
        /*
        cout<<endl;
        for(int i=1;i<=cnt;i++){
            cout<<sq[i].l<<' '<<sq[i].r<<' '<<sq[i].nl<<endl;
        }//*/
        p[m+1]=2e8;
        for(int i=1;i<=cnt;i++){
            //cout<<i<<' '<<j<<' '<<mic<<endl;
            //cout<<sq[i].l<<' '<<sq[i].r<<' '<<sq[i].nl<<"  LA"<<la<<endl;
            while(i<=n&&(sq[i].nl&&la>=sq[i].l)||(!sq[i].nl&&la>sq[i].l))
                i++;
            if(sq[i].r==2e9){
                mic++;
                break;
            }
            if(sq[i].dtd)
                continue;
            while(j<m&&((!sq[i].nl&&p[j+1]<sq[i].r)||(sq[i].nl&&p[j+1]<=sq[i].r)))
                j++;
            //cout<<sq[i].l<<' '<<sq[i].r<<' '<<sq[i].nl<<' '<<p[j]<<endl;
            while(j<=m&&((!sq[i].nl&&sq[i].r>p[j]&&sq[i].r<=p[j+1])||
               (sq[i].nl&&sq[i].r>=p[j]&&sq[i].r<p[j+1]))){
                mic++;
                la=p[j];
                j++;
                sq[i].dtd=1;
                //cout<<"CC"<<i<<endl;
            }
            //cout<<"M"<<mic<<endl;
        }
        cout<<m-mic<<endl;
        //break;
    }
    return 0;
}

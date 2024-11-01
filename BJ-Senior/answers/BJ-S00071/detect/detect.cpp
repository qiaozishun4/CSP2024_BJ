#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int n=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) n=n*10+c-'0';
    return n*f;
}
void read(int &n){
    n=0;
    int f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) n=n*10+c-'0';
    n*=f;
}
void write(int x){
    if(x<0){
        putchar('-');
        write(-x);
        return ;
    }
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
const int N=1e5+5;
int T,n,m,L,V;
struct car{
    int d,v,a;
}cc[N];
int det[N];
pair<int,int>chao[N],c2[N];
int ans1,ans2,cnt;
bool kll[N],ok[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V; ans1=cnt=0;
        memset(kll,0,sizeof(kll));
        memset(ok,0,sizeof(ok));
        for(int i=1;i<=n;i++) cin>>cc[i].d>>cc[i].v>>cc[i].a;
        for(int i=1;i<=m;i++) cin>>det[i];
        det[m+1]=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            int d=cc[i].d,v=cc[i].v,a=cc[i].a;
            int k1=lower_bound(det+1,det+m+2,d)-det;
            if(k1==m+1) continue;
            if(a>0){
                int gg=d+(V*V-v*v)/(2*a);
                if(gg<=L){
                    int k2=upper_bound(det+1,det+m+2,gg)-det;
                    if(k2<=m){
                        chao[++ans1]=make_pair(max(k1,k2),-m);
                        //cout<<i<<endl;
                    }
                }
            }
            else if(a<0){
                int gg=d+(int)ceil(1.0*(V*V-v*v)/(2*a));
                //cout<<"**"<<gg<<endl;
                int k2=lower_bound(det+1,det+m+2,gg)-det-1;
                //cout<<"**"<<k2<<endl;
                if(k2>=k1){
                    chao[++ans1]=make_pair(k1,-k2);
                    //cout<<i<<endl;
                }
            }
            else{
                if(v>V){
                    chao[++ans1]=make_pair(k1,-m);
                    //cout<<i<<endl;
                }
            }
        }
        sort(chao+1,chao+ans1+1);
        int mn=0x3f3f3f3f;
        for(int i=ans1;i;i--){
            if(mn<=-chao[i].second) continue;
            mn=min(-chao[i].second,mn);
            c2[++cnt]=make_pair(chao[i].first,-chao[i].second);
        }
        sort(c2+1,c2+cnt+1);
        pair<int,int>jiao;
        for(int i=1,j=1;i<=cnt;i=j){
            jiao=c2[i]; j++;
            while(j<=cnt&&jiao.second>=c2[j].first&&jiao.first<=c2[j].second) jiao.first=max(jiao.first,c2[j].first),jiao.second=min(jiao.second,c2[j].second),j++;
            ok[jiao.first]=1;
        }
        ans2=m;
        for(int i=1;i<=m;i++) if(ok[i]) ans2--;
        cout<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}


//CSP-S2 T2 rp++;
//rp++ !!!
//rp++ !!!
//rp+= +INF !!!

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int t;
int n,m,l,q;
int p[N];
int f[N*10];

struct node{
    int d,v,a;
}s[N];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        int rp=0;

        cin>>n>>m>>l>>q;

        for(int i=1;i<=n;i++)
            cin>>s[i].d>>s[i].v>>s[i].a;

        for(int i=1;i<=m;i++){
            cin>>p[i];
            f[p[i]]=i;
        }

        int cnt=0;
        bool s1=0;

        for(int i=1;i<=n;i++){

            if(s[i].a==0&&s[i].v>q&&s[i].d<=p[m])
                cnt++;

            if(s[i].a>0&&s[i].d<=p[m]){
                double x=sqrt(s[i].v*s[i].v+2*s[i].a*(p[m]-s[i].d));
                if(x>q*1.0) cnt++;
            }

            if(s[i].a<0){
                s1=1;
                rp++;
                double y=s[i].d+(-1)*s[i].v*s[i].v/2/s[i].a;
                bool flag=0;
                int num=1;
                for(int j=s[i].d;j<=y;j++){
                    if(f[j]>0){
                        num=f[j];
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    double z=sqrt(s[i].v*s[i].v+2*s[i].a*(p[num]-s[i].d));
                    if(z>q*1.0) cnt++;
                }
            }
        }
        cout<<cnt<<" ";

        if(s1==0){
            cout<<m-1<<"\n";
            continue;
        }
        cout<<m-1-rp<<"\n";
    }
    return 0;
}

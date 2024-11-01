#include<bits/stdc++.h>

using namespace std;

const int N=100010;

inline double jsyd(int v,int a,int s){
    return sqrt(pow(v,2)+(2*a*s));
}

int cntm[N];
int cntk[N];
int d[N];
int v[N];
int a[N];
int csy[N];
bool cs[N];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(cntm,0,sizeof(cntm));
        memset(cntk,0,sizeof(cntk));
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(csy,0,sizeof(csy));
        memset(cs,0,sizeof(cs));
        int n,m,l,V;
        //cin>>n>>m>>l>>V;
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&csy[i]);
            for(int j=1;j<=n;j++){
                if(csy[i]<d[j]){
                    continue;
                }
                if(a[j]>=0){
                    if(jsyd(v[j],a[j],(csy[i]-d[j]))>V){
                        cntk[i]++;
                        cs[j]=1;
                    }
                }else{
                    if(jsyd(v[j],a[j],(csy[i]-d[j]))>V){
                        cntm[i]++;
                        cs[j]=1;
                    }
                }
            }
        }
        in
                    }t cntcs=0;
        for(int i=1;i<=n;i++){
            if(cs[i]){
 //                   cerr<<i<<endl;
                cntcs++;
            }
        }
        printf("%d %d\n",cntcs,m-2);
    }
    return 0;
}
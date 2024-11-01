#include<bits/stdc++.h>
using namespace std;
struct str{
    long long l, r;
};
int l[100005];
bool vis[100005];
long long n,m,L,V;
str a[100005];
int i1=1;
bool cmp(str x,str y){
    if(x.r==y.r) return x.l>y.l;
    return x.r<y.r;
}
bool cnp(int n,int m){
    return n>m;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        i1=1;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            long long d,v,m;
            cin>>d>>v>>m;
            if(v>V&&m>=0){
                a[i1].l=d;
                a[i1++].r=L;
                //cout<<d<<" "<<l<<endl;
                continue;
            }if(v<=V&&m<=0){
                //cout<<n<<"-";
                continue;
            }
            double be1=(pow(V,2)-pow(v,2))/(2*m);
            long long be;
            if(be1-int(be1)!=0){
                be=be1+1;
            }else{
                be=be1;
            }
            if(v<=V&&be+d>L) continue;
            else if(v<=V){
                a[i1].l=min(d+be,L);
                a[i1++].r=L;
                //cout<<min(d+be,L)<<" "<<L<<endl;
            }else{
                a[i1].l=d;
                a[i1++].r=min(d+be,L);
                //cout<<d<<" "<<min(d+be,L)<<endl;
            }
        }
        sort(a+1,a+i1,cmp);
        for(int i=1;i<=m;i++){
            cin>>l[i];
        }
        //cout<<i1;
        int num=0;
        for(int i=1;i<i1;i++){
            for(int j=m;j>=1;j--){
                if(a[i].l<=l[j]&&a[i].r>=l[j]){
                    vis[j]=1;
                    num++;
                    //cout<<i;
                    while(i+1<i1&&a[i+1].r>=l[j]&&a[i+1].l<=l[j]){

                        i++;
                        num++;
                        //cout<<i;
                    }
                    break;
                }
            }
        }
        cout<<num<<" ";
        num=0;
        for(int i=1;i<=m;i++){
            if(vis[i]==0) num++;
        }
        cout<<num<<endl;
    }
    return 0;
}

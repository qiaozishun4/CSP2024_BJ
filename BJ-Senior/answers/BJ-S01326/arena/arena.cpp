#include<iostream>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn],c[maxn],t,x[4];
char in[2*maxn];
int logic(int o,int p) {
    return (o|p)-(o&p);
}
int qumici(int op) {
    int k=1;
    while(k<op) k*=2;
    return k;
}
int main() {
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    int k=qumici(n);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>c[i];
    while(k>=1){
        cin>>in;
        k/=2;
    }
    cin>>t;
    while(t--){
        int b[maxn],ans=0;
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for (int i=1;i<=n;i++)
            b[i]=logic(a[i],x[i%4]);
        for (int i=1;i<=m;i++){
            bool fl=false;
            for (int j=1;j<=c[i];j++)
                if (b[j]>0)
                    fl=true;
            if (fl) ans=logic(ans,i);
            else ans=logic(ans,i*(qumici(c[i])-c[i]));
            cout<<ans<<endl;
        }
    }
    return 0;
}
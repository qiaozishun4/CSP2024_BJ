#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=2e4+5;
int l[N],s[N][M],r[N],c[N],n,k,q;
int a[N][M],b[N],lena[N];
void work1(int x){
    int cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=l[i];j++){
            if (s[i][j]==x){
                for (int u=1;u<=lena[i];u++){
                    if ((j-a[i][u])<=k && (j-a[i][u])>=2){
                        cout<<1<<endl;
                        return ;
                    }
                }
            }
        }
    }
    cout<<0<<endl;
}
void MAIN(){
    cin>>n>>k>>q;
    for (int i=1;i<=n;i++){
        cin>>l[i];
        for (int j=1;j<=l[i];j++){
            cin>>s[i][j];
        }
    }
    bool flag=true;
    for (int i=1;i<=q;i++){
        cin>>r[i]>>c[i];
        if (r[i]>1) flag=false;
    }
    if (flag){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=l[i];j++){
                if (s[i][j]==1){
                    a[i][++lena[i]]=j;
                }
            }
        }
        for (int i=1;i<=q;i++){
            work1(c[i]);
        }
    }
    else{
        for (int i=1;i<=q;i++){
            cout<<0;
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--) MAIN();
    return 0;
}

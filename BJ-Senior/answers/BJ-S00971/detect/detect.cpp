#include<bits/stdc++.h>
using namespace std;
struct car{
    int d;
    int v0;
    int a;
};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        car C[10005];
        int n,m,l,v;
        int watch[10005],mn[25][25];
        int ans1=0,ans2=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>C[i].d>>C[i].v0>>C[i].a;
        }
        bool ans[10005];
        for(int i=1;i<=n;i++){
            ans[i]=false;
        }
        for(int i=1;i<=m;i++){
            cin>>watch[i];
            for(int j=1;j<=m;j++){
                if(C[j].d<=watch[i]){
                    if(C[j].v0*C[j].v0+2*C[j].a*(watch[i]-C[j].d)>v*v){
                        if(!ans[j]){
                            ans1++;
                        }
                        ans[j]=true;
                        mn[i][j]=1;
                    }
                }
            }
        }
        bool ansl[10005];
        for(int i=1;i<=m;i++){
            ansl[i]=false;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<i;j++){
                if(i!=j){
                    bool check=true;
                    for(int p=1;p<=n;p++){
                        if(mn[i][p]==1 and mn[j][p]!=1){
                            check=false;
                        }

                    }
                    if(check){
                        ansl[i]=true;
                    }
                    else{
                        bool check=true;
                        for(int p=1;p<=n;p++){
                            if(mn[i][p]!=1 and mn[j][p]==1){
                                check=false;
                            }
                        }
                        if(check){
                            ansl[j]=true;
                        }
                    }
                }
            }

        }
        for(int i=1;i<=m;i++){
            if(ansl[i]){
                ans2++;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
        ans2=0;
    }
    return 0;
}
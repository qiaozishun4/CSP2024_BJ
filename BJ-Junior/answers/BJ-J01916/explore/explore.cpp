#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005,MAXNN=1e6+5;
int t;
int n,m,k;
int x,y,d;
char a[MAXN][MAXN];
int a1[MAXNN],a2[MAXNN];
int sum=1;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
                //cout<<x<<" "<<y<<" "<<d<<endl;

                if(d==0){
                    if(y+1<1||y+1>m){
                        d=(d+1)%4;
                        continue;
                    }
                    if(a[x][y+1]=='x'){
                        d=(d+1)%4;
                        continue;
                    }
                    y=y+1;
                    a1[sum]=x,a2[sum]=y;
                    sum++;
                    ans++;
                }
                if(d==1){
                    if(x+1<1||x+1>n){
                        d=(d+1)%4;
                        continue;
                    }
                    if(a[x+1][y]=='x'){
                        d=(d+1)%4;
                        continue;
                    }
                    x=x+1;
                    a1[sum]=x,a2[sum]=y;
                    sum++;
                    ans++;
                }
                if(d==2){
                    if(y-1<1||y-1>m){
                        d=(d+1)%4;
                        continue;
                    }
                    if(a[x][y-1]=='x'){
                        d=(d+1)%4;
                        continue;
                    }
                    y=y-1;
                    a1[sum]=x,a2[sum]=y;
                    sum++;
                    ans++;
                }
                if(d==3){
                    if(x-1<1||x-1>n){
                        d=(d+1)%4;
                        continue;
                    }
                    if(a[x-1][y]=='x'){
                        d=(d+1)%4;
                        continue;
                    }

                    x=x-1;
                    a1[sum]=x,a2[sum]=y;
                    sum++;
                    ans++;
                }



        }
        int anss=-1;
        for(int i=1;i<=sum;i++){
            for(int j=i+1;j<=sum;j++){
                    if(a1[i]==a1[j]&&a2[i]==a2[j]){
                        a1[j]=anss,a2[j]=anss;
                        anss=anss-1;
                        ans--;
                    }
                }
            }
            //cout<<sum<<endl;
        //for(int i=1;i<=sum;i++) cout<<a1[i]<<" "<<a2[i]<<endl;
        //if(a1[sum]==0&&a2[sum]==0) ans--;
        //cout<<a1[sum]<<" "<<a2[sum]<<endl;
        for(int i=1;i<=sum;i++) a1[i]=0,a2[i]=0;
        sum=1,anss=-1;
        cout<<ans<<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005][4],b[100005][5];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,cs=0,by=0;
    cin>>T;
    int n,m,L,V;
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        b[x][1]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i][2]>=V&&a[i][3]>=0){
            cs++;
            b[a[i][1]][2]=1;
        }
        else if(a[i][2]>=V&&a[i][3]<0){
            double lenth,zb;
            int time=0;
            zb=(a[i][2]-V)/abs(a[i][3]);
            lenth=a[i][1]+a[i][2]*zb+0.5*a[i][3]*zb*zb;
            for(int i=a[i][1];i<=lenth;i++){
                if(b[i][1]==1&&time=0){
                    cs++;
                    b[a[i][1]][2]=1;
                    continue
                }
                else{
                    continue;
                }
            }
        }
        else if(a[i][2]<=V&&a[i][3]<=0){
            continue;
        }
        else{
            double lenth=(V-a[i][2])/a[i][3];
            int time=0;
            for(int i=a[i][1];i<=lenth;i++){
                if(b[i][1]==1&&time=0){
                    cs++;
                    b[a[i][1]][2]=1;
                    continue
                }
                else{
                    continue;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i][2]==0){
            by++;
        }
    }
    cout<<cs<<" "<<by;
    fclose(stdin);
    fclose(stdout);
}
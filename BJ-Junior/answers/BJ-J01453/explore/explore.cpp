#include <bits/stdc++.h>
using namespace std;
long long sum[10];
int a[1005][1005],really[1005][1005];
int main(){
    long long t,n,m,k,x0,y0,d0;
    long long x,y,d;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x0>>y0>>d0;
        for(int p=1;p<=n;p++){
            for(int q=1;q<=m;q++){
                char c;
                cin>>c;
                if(c=='.') a[p][q]=0;
                else a[p][q]=1;
                really[p][q]=0;
            }
        }
        x=x0;
        y=y0;
        d=d0;
        sum[i]=1;
        really[1][1]=1;
        long long step=0;
        while(step!=k){
            bool flag=true;
            while(flag){
                if(d==0){
                    if(y+1<=m&&a[x][y+1]==0){
                        if(really[x][y+1]==0) {
                            sum[i]+=1;
                            really[x][y+1]=1;
                        }
                        y+=1;
                        flag=false;
                        step++;
                    }
                    else {
                        d=(d+1)%4;
                        step++;
                    }
                }
                if(flag==false) break;
                if(step==k) break;
                if(d==1){
                    if(x+1<=n&&a[x+1][y]==0){
                         if(really[x+1][y]==0) {
                            sum[i]+=1;
                            really[x+1][y]=1;
                        }
                        x+=1;
                        flag=false;
                        step++;
                    }
                     else {
                        d=(d+1)%4;
                        step++;
                    }
                }
                if(flag==false) break;
                if(step==k) break;
                if(d==2){
                    if(y-1>=1&&a[x][y-1]==0){
                         if(really[x][y-1]==0) {
                            sum[i]+=1;
                            really[x][y-1]=1;
                        }
                        y-=1;
                        flag=false;
                        step++;
                    }
                    else {
                        d=(d+1)%4;
                        step++;
                     }
                }
                if(flag==false) break;
                if(step==k) break;
                if(d==3){
                    if(x-1>=1&&a[x-1][y]==0){
                         if(really[x-1][y]==0) {
                            sum[i]+=1;
                            really[x-1][y]=1;
                        }
                        x-=1;
                        flag=false;
                        step++;
                    }
                     else {
                        d=(d+1)%4;
                        step++;
                    }
                }
                if(flag==false) break;
                if(step==k) break;
            }
        }
    }
    for(int i=1;i<t;i++){
        cout<<sum[i]<<endl;
    }
    cout<<sum[t];
    return 0;
}

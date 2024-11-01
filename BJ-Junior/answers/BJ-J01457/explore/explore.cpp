#include<bits/stdc++.h>
using namespace std;
        int cnt[1005][1005];
        char mp[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long T,m,n,k,hcx,hcy,d,sum,q;
    scanf("%d",&T);
    while(T--){
            sum=0;
    cin>>n>>m>>k>>hcx>>hcy>>d;
  //      scanf("%d%d%d",&n,&m,&k);
    //    scanf("%d%d%d",&hcx,&hcy,&d);
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cnt[i][j]=0;
            }
        }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        cnt[hcx][hcy]=1;
        while(k--){
                q=0;
        //        cout<<hcx<<" "<<hcy<<" "<<d<<endl;
            if(d==0&&q==0){
                if(hcy+1>=1&&hcy+1<=m&&mp[hcx][hcy+1]!='x'){
                                    hcy++;
                }else{
                    d=(d+1)%4;
        q=1;
                }
            }
            if(d==1&&q==0){
                if(hcx+1>=1&&hcx+1<=n&&mp[hcx+1][hcy]!='x'){
                                  hcx++;
                }else{
                    d=(d+1)%4;
                    q=1;
                }
            }
            if(d==2&&q==0){
                if(hcy-1>=1&&hcy-1<=m&&mp[hcx][hcy-1]!='x'){
       hcy--;
                }else{
                    d=(d+1)%4;
                    q=1;
                }
            }
            if(d==3&&q==0){
                if(hcx-1>=1&&hcx+-1<=m&&mp[hcx-1][hcy]!='x'){
          hcx--;
                }else{
                    d=(d+1)%4;
                    q=1;
                }
            }
//cout<<hcx<<" "<<hcy<<" "<<d<<" "<<endl;
                    cnt[hcx][hcy]=1;
        }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                if(cnt[i][j]==1){ sum++;}
            }
        }
        cout<<sum<<endl;
    }
        fclose(stdin);
       fclose(stdout);
        return 0;
        }



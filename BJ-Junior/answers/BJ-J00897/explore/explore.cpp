#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long  num;
    cin>>num;
    long long ans[num];
    for(long long temp=0;temp<num;temp++){
        long long n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char map[n+1][m+1];
        long long a[n+1][m+1];
        for(long long i=0;i<=n;i++){
            for(long long j=0;j<=m;j++)
                map[i][j]='*';
        }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++)
                cin>>map[i][j];
        }
        for(long long i=0;i<=n;i++){
            for(long long j=0;j<=m;j++){
                if(map[i][j]=='*')
                    a[i][j]=5;
                if(map[i][j]=='.')
                    a[i][j]=0;
                if(map[i][j]=='x')
                    a[i][j]=2;
            }
        }
        long long newx=x,newy=y,newd=d,temp_1=1;
        for(long long i=0;i<k;i++){
            if(newd==0)
                newy+=1;
            if(newd==1)
                newx+=1;
            if(newd==2)
                newy-=1;
            if(newd==3)
                newx-=1;
            if(map[newx][newy]=='.'){
                if(a[newx][newy]==0){
                    temp_1++;
                    a[newx][newy]=1;
                }
            }
            else{
                if(newd==0)
                    newy-=1;
                if(newd==1)
                    newx-=1;
                if(newd==2)
                    newy+=1;
                if(newd==3)
                    newx+=1;
                newd=(newd+1)%4;
            }
        }
        ans[temp]=temp_1;
    }
    for(int i=0;i<num;i++)
       cout<<ans[i]<<endl;
    fclose(stdin);
    fclose(stdout);
return 0;
}

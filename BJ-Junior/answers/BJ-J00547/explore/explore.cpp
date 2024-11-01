#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int l;
    cin>>l;
    long long n,m,k,x,y,d,ans=0;
    for(int s=1;s<=l;s++){
        cin>>n>>m>>k>>x>>y>>d;ans=0;
        char a[n+1][m+1];long long b[n+1][m+1]={0};
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            for(int j=m-1;j>=0;j--){
                a[i][j+1]=a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            if(b[x][y]==0){
                ans++;
            }
            b[x][y]++;
            if(d==0){
                y++;
            }else if(d==1){
                x++;
            }else if(d==2){
                y--;
            }else if(d==3){
                x--;
            }
            if(x>n||y>m||x<1||y<1){
                if(d==0){
                    y--;
                }else if(d==1){
                    x--;
                }else if(d==2){
                    y++;
                }else if(d==3){
                    x++;
                }
                d=(d+1)%4;
            }else if(a[x][y]=='x'){
                if(d==0){
                    y--;
                }else if(d==1){
                    x--;
                }else if(d==2){
                    y++;
                }else if(d==3){
                    x++;
                }
                d=(d+1)%4;

            }
            if(b[x][y]==0&&i==k){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

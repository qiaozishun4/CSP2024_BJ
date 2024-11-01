#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,cnt=1;
char a[1005][1005];
long long b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld\n",&t);
    for(int i=0;i<t;i++){
        scanf("%lld%lld%lld\n",&n,&m,&k);
        scanf("%lld%lld%lld\n",&x,&y,&d);
        for(int j=1;j<=n;j++){
            for(int kk=1;kk<=m;kk++){
                scanf("%c",&a[j][kk]);
            }
        }
        b[x][y]=1;
        while(k>0){
            if(d==0){
                y++;
                k--;
            }
            else if(d==1){
                x++;
                k--;
            }
            else if(d==2){
                y--;
                k--;
            }
            else if(d==3){
                x--;
                k--;
            }
            if(a[x][y]=='.' && b[x][y]!=1){
                cnt++;
                b[x][y]==1;
            }
            else if(x<1 || x>n || y<1 || y>m || a[x][y]=='x'){
                if(d==0){
                    y--;
                }
                else if(d==1){
                    x--;
                }
                else if(d==2){
                    y++;
                }
                else if(d==3){
                    x++;
                }
                d=(d+1)%4;
            }
        }
        printf("%lld\n",cnt);
        cnt=1;
    }
    return 0;
}

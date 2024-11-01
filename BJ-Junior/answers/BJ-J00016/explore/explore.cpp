#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,h,o[10];
    char s[1010][1010];
    cin>>t;
    for(int i=1;i<=t;i++){
        h=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int a=1;a<=n;a++){
            for(int b=1;b<=m;b++){
                cin>>s[a][b];
            }
        }
        for(int j=1;j<=k;j++){
            if(d==0){
                if(s[x][y+1]!='x'&&y+1<=m) y+=1,h++;
                else d=1;
                continue;
            }
            if(d==1){
                if(s[x+1][y]!='x'&&x+1<=n) x+=1,h++;
                else d=2;
                continue;
            }
            if(d==2){
                if(s[x][y-1]!='x'&&y-1>0) y-=1,h++;
                else d=3;
                continue;
            }
            if(d==3){
                if(s[x-1][y]!='x'&&x-1>0) x-=1,h++;
                else d=0;
                continue;
            }
        }
        o[i]=h;
    }
    for(int i=1;i<=t;i++) cout<<o[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

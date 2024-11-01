#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
char s[1005][1005];
//bool a[1005][1005];
int vx[4]={0,1,0,-1},vy[4]={1,0,-1,0};
long long ans=0;
void f(){
    if(s[x+vx[d]][y+vy[d]]=='x'||s[x+vx[d]][y+vy[d]]=='X'||x+vx[d]<0||y+vy[d]<0){
        d++;
        if(d==4){
            d=0;
        }
        return;
    }
    x+=vx[d];
    y+=vy[d];
    ans++;
    //if(a[x][y]=false){
    //    ans++;
    //    a[x][y]=true;
    //}
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        //for(int j=0;j<1005;j++){
        //    for(int l=0;l<1005;l++){
        //        a[j][l]=false;
        //    }
        //}
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        x--;
        y--;
        //a[x][y]=true;
        for(int j=0;j<n;j++){
            for(int l=0;l<m;l++){
                cin>>s[j][l];
            }
        }
        for(int i=1;i<=k;i++){
            f();
        }
        ans++;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

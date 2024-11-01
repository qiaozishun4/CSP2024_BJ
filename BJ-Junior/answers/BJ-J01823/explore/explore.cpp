#include <bits/stdc++.h>
using namespace std;
bool map2[1005][1005];
char map1[1005][1005];
int x,y,d;
int m,n,k;
int ans,t;
int main(){
    cin>>t;
    for (int l=1;l<=t;l++){
        ans=1;
        memset(map2,false,sizeof(map2));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for (int i=1;i<=n;i++){
            cin>>map1[i]+1;
        }
        int xn;
        int yn;
        for (int j=1;j<=k;j++){
            if (d==0){
                xn=x;
                yn=y+1;
            }
            else if (d==1){
                xn=x+1;
                yn=y;
            }
            else if (d==2){
                xn=x;
                yn=y-1;
            }
            else{
                xn=x-1;
                yn=y;
            }
            if (map1[xn][yn]=='x'||xn<1||xn>n||yn<1||yn>m){
                d=(d+1)%4;
                continue;
            }
            if (map2[xn][yn]==false){
                ans++;
                map2[xn][yn]=true;
            }
            x=xn;
            y=yn;
        }
        cout<<ans<<endl;
    }
    return 0;
}

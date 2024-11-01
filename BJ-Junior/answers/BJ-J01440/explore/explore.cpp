#include<bits/stdc++.h>
using namespace std;
    int s,x,y,d;
    char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t=0;
    int cnt=0;
    int n,m,k;
    cin>>s;
    for(int i=1;i<=s;i++){
        cin>>n>>m>>k;
        for(int j=1;j<=n;i++){
            for(int c=1;c<=m;c++){
                cin>>a[j][c];
            }
        }
        cin>>x>>y>>d;
        while(t<=k){
        if(d==0){
            if(a[x][y+1]!=x&&a[x][y+1]!=0){
                y++;
                t++;
                cnt++;
            }
            else{
                d=(d+1)%4;
                t++;
            }
        }
        else if(d==1){
            if(a[x+1][y]!=x&&a[x+1][y]!=0){
                x++;
                t++;
                cnt++;
            }
            else{
                d=(d+1)%4;
                t++;
            }
        }
        else if(d==2){
            if(a[x][y-1]!=x&&a[x][y-1]!=0){
                y--;
                t++;
                cnt++;
            }
            else{
                d=(d+1)%4;
                t++;
            }
        }
        else if(d==3){
            if(a[x-1][y]!=x&&a[x-1][y]!=0){
                x--;
                t++;
                cnt++;
            }
            else{
                d=(d+1)%4;
                t++;
            }
        }
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

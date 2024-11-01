#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,y,d,N,l[10],num=1;
char a[1050][1050];
bool tmp(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=m && a[x][y]!='x'){
            a[x][y]='!';
            return true;
    }
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>n>>m>>t>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>a[j][l];
            }
        }
        a[x][y]='!';
        for(int j=1;j<=t;j++){
            if(d==0){
                if(tmp(x,y+1))y++;
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            else if(d==1){
                if(tmp(x+1,y))x++;
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            else if(d==2){
                if(tmp(x,y-1))y--;
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            else if(d==3){
                if(tmp(x-1,y))x--;
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        int count=0;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cout<<a[j][l];
                if(a[j][l]=='!')count++;
            }
            cout<<endl;
        }
        l[num]=count;
        num++;
    }
    for(int i=1;i<num;i++){
        cout<<l[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

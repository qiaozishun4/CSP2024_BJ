#include<bits/stdc++.h>
using namespace std;
int s=0;
int a[1000][1000],m,n,k;
int bfs(int x,int y,int d){
    if(k==0) return 13;
    if(d==0 && y+1<n && a[x][y+1]!=1){

        s++;
        k--;
        bfs(x,y+1,d);

    }if(d==1 && x+1<m && a[x+1][y]!=1){

        s++;

        k--;
        bfs(x+1,y,d);

    }if(d==2 && y-1>=0 && a[x][y-1]!=1){

        s++;

        k--;
        bfs(x,y-1,d);

    }if(d==3 && x-1>=0 && a[x-1][y]!=1){
        s++;

        k--;
        bfs(x-1,y,d);

    }else{
        d=(d+1)%4;
    }



}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    int b[1000],xx,yy,kk;
    cin>>T;
    string t;
    for(int gg=0;gg<T;gg++){
        cin>>n>>m>>k;
        cin>>xx>>yy>>kk;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>t;
                if(t=="x"){
                    a[i][j]=1;
                }else{
                    a[i][j]=0;
                }

            }
        }

        b[gg]=bfs(xx,yy,kk);
    }
    for(int i=0;i<T;i++){
        cout<<b[i]<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

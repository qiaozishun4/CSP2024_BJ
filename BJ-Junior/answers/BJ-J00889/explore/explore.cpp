#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,g=0;
int a[1010][1010];
char s[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        g=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int q=1;q<=n;q++){
            for(int p=1;p<=m;p++){
                a[q][p]=0;
            }
        }
        a[x][y]=1;
        for(int q=1;q<=n;q++){
            for(int p=1;p<=m;p++){
                cin>>s[q][p];
            }
        }
        for(int q=1;q<=k;q++){
            if(d==0){
                y=y+1;
                if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='.'){
                    a[x][y]=1;
                }else{
                    d=(d+1)%4;
                    y=y-1;
                }
            }else if(d==1){
                x=x+1;
                if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='.'){
                    a[x][y]=1;
                }else{
                    d=(d+1)%4;
                    x=x-1;
                }
            }else if(d==2){
                y=y-1;
                if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='.'){
                    a[x][y]=1;
                }else{
                    d=(d+1)%4;
                    y=y+1;
                }
            }else if(d==3){
                x=x-1;
                if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='.'){
                    a[x][y]=1;
                }else{
                    d=(d+1)%4;
                    x=x+1;
                }
            }
        }
        for(int q=1;q<=n;q++){
            for(int p=1;p<=m;p++){
                if(a[q][p]==1){
                    g++;
                }
            }
        }

        cout<<g<<endl;
    }



    fclose(stdin);
    fclose(stdout);

    return 0;
}

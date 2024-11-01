#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,xa,ya,da,xb,yb,ans;
bool b[1010][1010],book[1010][1010];
string s;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        xa=x;
        ya=y;
        da=d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++){
                if(s[j-1]=='.') b[i][j]=1;
                else b[i][j]=0;
                book[i][j]=0;
            }
        }
/*        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]) cout<<'.';
                else cout<<'x';
            }
            cout<<endl;
        }
        cout<<endl;*/
        ans=1;
        book[x][y]=1;
        for(int i=1;i<=k;i++){
            if(da==0){
                xb=xa;
                yb=ya+1;
            }
            else if(da==1){
                xb=xa+1;
                yb=ya;
            }
            else if(da==2){
                xb=xa;
                yb=ya-1;
            }
            else{
                xb=xa-1;
                yb=ya;
            }
            if(b[xb][yb]){
                if(!book[xb][yb]){
                    book[xb][yb]=1;
                    ans++;
       //             cout<<'+';
                }
                xa=xb;
                ya=yb;
            }
            else{
               da=(da+1)%4;
            }
        //    cout<<x0<<' '<<y0<<' '<<d0<<endl;
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
 //   fclose(stdout);
    return 0;
}
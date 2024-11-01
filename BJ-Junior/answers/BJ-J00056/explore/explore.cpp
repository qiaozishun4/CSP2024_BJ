#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int cnt=0;
        while (k--){
            int X=x,Y=y;
            if (d==0) Y++;
            if (d==1) X++;
            if (d==2) Y--;
            if (d==3) X--;
            if ((1<=X && X<=n) && 1(<=Y && Y<=m) && a[X][Y]!='x'){
                if (a[X][Y]=='.') cnt++;
                a[X][Y]=' ';
                x=X;
                y=Y;
            }
            else d=(d+1)%4;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
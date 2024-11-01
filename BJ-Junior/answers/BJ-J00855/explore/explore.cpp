#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,x,y,d,cnt;
bool ma[9999][9999],vis[9999][9999];
void go(int a,int b){
    if(ma[b][a]==1 or (a>m or b>n or a<1 or b<1)){
        d = (d+1)%4;
        //cout << a << '&' << b << '&' << d << '&' << ma[b][a] << '\n';
    }
    else{
        x=a;
        y=b;
        if(!vis[y][x]){
            vis[y][x]=1;
            cnt++;
            //cout << x << '*' << y <<'\n';
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> m >> k >> y >> x >> d;
        for(int i=1;i<=1111;i++){
            for(int j=1;j<=1111;j++){
                vis[j][i]=0;
                ma[j][i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            string x;
            cin >> x;
            for(int k=0;k<m;k++)
                if(x[k]=='x'){
                    ma[i][k+1]=1;
                    //cout << i << '%' << (k+1) << ' ';
                }
        }
        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=m;j++){
        //        cout << ma[i][j];
        //    }
        //    cout << "*&\n";
        //}
        cnt=1;
        ma[y][x]=1;
        while(k--){
            if(d==0){
                go(x+1,y);
            }
            else if(d==1){
                go(x,y+1);
            }
            else if(d==2){
                go(x-1,y);
            }
            else{
                go(x,y-1);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}


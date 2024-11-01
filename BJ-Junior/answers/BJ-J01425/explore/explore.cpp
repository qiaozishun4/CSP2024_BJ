#include<bits/stdc++.h>
using namespace std;
short ft[2][4] = {{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for(int pojpojpopo=0;pojpojpopo<T;pojpojpopo++){
        int n,m,k,x,y,d;
        cin >> n >> m >> k >> x >> y >> d;
        char a[1007][1007];
        bool b[1007][1007];
        memset(b,0,sizeof(n));
        bool flag = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
                if(a[i][j] == 'x') flag=1;
            }
        }
        while(k--){
            int xx=x+ft[d][0],yy=y+ft[d][1];
            if(xx<0||yy<0||xx>=n||yy>=m||a[xx][yy] == 'x') d = (d+1) % 4;
            else{
                a[xx][yy] = 1;
                x=xx;
                y=yy;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    fcolse(stdin);
    fclose(stdout);
    return 0;
}
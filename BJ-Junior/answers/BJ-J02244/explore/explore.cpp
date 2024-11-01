#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,x2,y2,cnt=1;
char c[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        x--;
        y--;
        x2 = x;
        y2 = y;
        for(int j = 0;j < n;j++){
            cin>>c[j];
        }
        c[x][y] = '^';
        for(int j = 0;j < k;j++){
            if(d==0) y2++;
            else if(d==1) x2++;
            else if(d==2) y2--;
            else x2--;
            if((x2>=0)&&(x2<n)&&(y2>=0)&&(y2<m)&&(c[x2][y2]!='x')){
                x = x2;
                y = y2;
            }
            else{
                y2 = y;
                x2 = x;
                d = (d+1)%4;
            }
            if(c[x][y]=='.'){
                c[x][y] = '^';
                cnt++;
            }
        }
        cout<<cnt<<endl;
        cnt = 1;
    }
    return 0;
}

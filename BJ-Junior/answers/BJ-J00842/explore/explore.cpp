#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n,m,k,x0,y0,d0,x1,y1,cnt,num;
    char maps[1005][1005];
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i = 1;i<=T;i++){
        num = 0;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int p = 1;p<=n;p++){
            for(int q = 1;q<=m;q++){
                cin>>maps[p][q];
            }
        }
        maps[x0][y0] = 'T';
        for(int j = 0;j<k;j++){
            cnt = 0;
            if(d0 == 0){
                x1 = x0;
                y1 = y0+1;
            }
            else if(d0 == 1){
                x1 = x0+1;
                y1 = y0;
            }
            else if(d0 == 2){
                x1 = x0;
                y1 = y0-1;
            }
            else if(d0 == 3){
                x1 = x0-1;
                y1 = y0;
            }
            cnt++;
            while(x1<1 || x1>n || y1<1 || y1>m || maps[x1][y1] == 'x'){
                if(j>=k){
                    cnt = -1;
                    break;
                }
                if(cnt>=4){
                    cnt = -1;
                    break;
                }
                d0 = (d0+1)%4;
                if(d0 == 0){
                    x1 = x0;
                    y1 = y0+1;
                }
                else if(d0 == 1){
                    x1 = x0+1;
                    y1 = y0;
                }
                else if(d0 == 2){
                    x1 = x0;
                    y1 = y0-1;
                }
                else if(d0 == 3){
                    x1 = x0-1;
                    y1 = y0;
                }
                j++;
                cnt++;
            }
            if(cnt==-1){
                break;
            }
            else{
                x0 = x1;
                y0 = y1;
                maps[x1][y1] = 'T';
            }
        }
        for(int p = 1;p<=n;p++){
            for(int q = 1;q<=m;q++){
                if(maps[p][q] == 'T'){
                    num++;
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}


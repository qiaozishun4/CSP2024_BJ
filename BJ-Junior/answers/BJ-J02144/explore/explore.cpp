#include<bits/stdc++.h>

using namespace std;

int T,n,m,k,x,y,d,cnt;
bool mmap[1005][1005];
bool visi[1005][1005];
char temp;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;

        cnt=1;
        memset(visi,0,sizeof visi);
        memset(mmap,0,sizeof mmap);
        visi[x][y] =true;

        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>temp;
                if(temp == '.'){
                    mmap[i][j]=true;
                }
            }
        }
        while(k--){
            if(d==0 && y+1<=m && y+1>=1 && mmap[x][y+1]==true){
                y++;
            }
            else if(d==1 && x+1<=n && x+1>=1 && mmap[x+1][y]==true){
                x++;
            }
            else if(d==2 && y-1<=m && y-1>=1 && mmap[x][y-1]==true){
                y--;
            }
            else if(d==3 && x-1<=n && x-1>=1 && mmap[x-1][y]==true){
                x--;
            }
            else{
                d = (d+1)%4;
            }
            if(visi[x][y]==false){
                cnt++;
            }
            visi[x][y] = true;
        }
        cout<<cnt<<endl;
    }

    return 0;
}

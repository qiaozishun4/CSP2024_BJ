#include<bits/stdc++.h>
using namespace std;
int t,cnt;
int book[1005][1005];
char m[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int n,l,k,x,y,d;
    for(int i=1;i<=t;i++){
        cnt=1;
        cin>>n>>l>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=l;j++){
                cin>>m[i][j];
            }
        }
        memset(book,0,sizeof(book));
        book[x][y]=1;
        while(k){
            if(d==0&&y+1>=1&&y+1<=l&&m[x][y+1]=='.'){
                if(!book[x][y+1]){
                    book[x][y+1]=1;
                    cnt++;
                }
                y+=1;
            }
            else if(d==1&&x+1>=1&&x+1<=n&&m[x+1][y]=='.'){
                if(!book[x+1][y]){
                    book[x+1][y]=1;
                    cnt++;
                }
                x+=1;
            }
            else if(d==2&&y-1>=1&&y-1<=l&&m[x][y-1]=='.'){
                if(!book[x][y-1]){
                    book[x][y-1]=1;
                    cnt++;
                }
                y-=1;
            }
            else if(d==3&&x-1>=1&&x-1<=n&&m[x-1][y]=='.'){
                if(!book[x-1][y]){
                    book[x-1][y]=1;
                    cnt++;
                }
                x-=1;
            }else d=(d+1)%4;
            k--;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

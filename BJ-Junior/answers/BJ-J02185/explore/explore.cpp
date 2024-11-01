#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
char a[1005][1005];
bool a1[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int aaa[10];
    int num=0;
        bool flag=0;
    int ans=1;
    int temp=0;
    for(int i=0;i<t;i++){
        ans=1;
        flag = false;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int x1=1;x1<=n;x1++){
            for(int y1=1;y1<=m;y1++){
                cin>>a[x1][y1];
            }
        }
        a1[x][y] = true;
        while(k--){
            flag = false;
            if(d==0){
                if(a[x][y+1]=='.'){
                    y++;
                    if(a1[x][y]==false){
                       ans++;
                       a1[x][y]=true;
                    }

                    flag=true;
                }
            }
            if(d==1){
                if(a[x+1][y]=='.'){
                    x++;
                    if(a1[x][y]==false){
                       ans++;
                       a1[x][y]=true;
                    }
                    flag=true;
                }
            }
            if(d==2){
                if(a[x][y-1]=='.'){
                    y--;
                    if(a1[x][y]==false){
                       ans++;
                       a1[x][y]=true;
                    }
                    flag=true;
                }
            }
            if(d==3){
                if(a[x-1][y]=='.'){
                    x--;
                    if(a1[x][y]==false){
                       ans++;
                       a1[x][y]=true;
                    }
                    flag=true;
                }
            }
            if(flag==false){
                d = (d+1)%4;
            }
        }
        for(int x1=1;x1<=n;x1++){
            for(int y1=1;y1<=m;y1++){
                a[x1][y1]=' ';
                a1[x1][y1]=0;
            }
        }
        aaa[temp++] = ans;
    }
    for(int i=0;i<t;i++){
        cout<<aaa[i]<<endl;
    }
    return 0;
}

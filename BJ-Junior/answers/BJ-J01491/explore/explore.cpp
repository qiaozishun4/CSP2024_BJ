#include <bits/stdc++.h>
using namespace std;

bool mp[1024][1024];
bool vis[1024][1024];

int Tanswer(){
    int s=1;
    int n,m,k;
    int x,y,d;
    cin>>n>>m>>k>>x>>y>>d;
    x-=1;
    y-=1;
    vis[x][y]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            cin>>temp;
            if(temp=='.') mp[i][j]=1;
        }
    }
    for(int i=0;i<k;i++){
        bool e=0;
        switch(d){
            case 0: if(!(mp[x][y+1]&&x<n&&y+1<m)) e=1; break;
            case 1: if(!(mp[x+1][y]&&x+1<n&&y<m)) e=1; break;
            case 2: if(!(mp[x][y-1]&&x<n&&y-1<m)) e=1; break;
            case 3: if(!(mp[x-1][y]&&x-1<n&&y<m)) e=1; break;
        }
        if(e==1) d=(d+1)%4;
        else {
            switch(d){
                case 0: y+=1;  break;
                case 1: x+=1; break;
                case 2: y-=1; break;
                case 3: x-=1; break;
            }
            if(vis[x][y]==0){
                vis[x][y]=1;
                s+=1;
            }
        }
        // cout<<x+1<<" "<<y+1<<endl;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return s;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int Ti=0;Ti<T;Ti++){
        for(int i=0;i<=1024;i++) memset(vis[i],0,sizeof(vis[i]));
        for(int i=0;i<=1024;i++) memset(mp[i],0,sizeof(mp[i]));
        cout<<Tanswer()<<endl;
    }
    return 0;
}
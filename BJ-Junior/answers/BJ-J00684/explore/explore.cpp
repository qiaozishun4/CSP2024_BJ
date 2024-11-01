#include<iostream>
using namespace std;
bool cbi[1000][1000],vis[1000][1000];
int n,m,k;
void turn_(int &d) {
    if(d==3) {
        d=0;
        return;
    }
    d++;
}
void r(int &x,int &y,int &d) {
    if(d==0) {
        if(y+1<m&&cbi[x][y+1]) {
            y++;
            return;
        }
        turn_(d);
        return;
    }
    if(d==1) {
        if(x+1<n&&cbi[x+1][y]) {
            x++;
            return;
        }
        turn_(d);
        return;
    }

    if(d==2) {
        if(y-1>=0&&cbi[x][y-1]) {
            y--;
            return;
        }
        turn_(d);
        return;
    }
    if(d==3) {
        if(x-1>=0&&cbi[x-1][y]) {
            x--;
            return;
        }
        turn_(d);
        return;
    }
}
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++) {
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        x--;y--;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        vis[i][j]=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                char c;
                cin>>c;
                if(c=='x') cbi[i][j]=false;
                if(c=='.') cbi[i][j]=true;
            }
        }
        vis[x][y]=true;
        for(int i=0;i<k;i++) {
            r(x,y,d);
            vis[x][y]=true;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(vis[i][j]) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}

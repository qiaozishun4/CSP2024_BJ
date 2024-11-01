#include<iostream>
#include<string>
using namespace std;
string s[100010];
int n, m, k,cnt=1;
bool b[10010][10010];
void dfs (int x, int y, int r, int d) {
    if (r==k) {
        return ;
        cout << r << endl << endl;
    }
    int xx, yy;
    if (d==0) {
        xx=x;
        yy=y+1;
    }
    else if (d==1) {
        xx=x+1;
        yy=y;
    }
    else if (d==2) {
        xx=x;
        yy=y-1;
    }
    else {
        xx=x-1;
        yy=y;
    }
    //if(s[xx][yy]=='x') cout << 1234567890 << endl << endl;
    if (s[xx][yy]!='x'&&xx<=n&&xx>0&&yy<m&&yy>-1) {
        if (!b[xx][yy]) {
            cnt++;
            cout << xx << ' ' << yy+1 <<  ' ' << d <<endl << endl;
        }
        b[xx][yy]=true;
        dfs(xx,yy,r+1,d);
    }
    else {
        dfs(x,y,r+1,(d+1)%4);
        cout << xx << ' ' << yy+1 <<  ' ' << d <<endl << endl;
    }
}
int main () {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        b[x][y-1]=true;
        for (int i=1;i<=n;i++) {
            cin >> s[i];
        }
        dfs(x, y-1, 1, d);
        cout << cnt << endl;
        n=0;m=0;d=0;
        cnt=1;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,t,ans,flag;
char mp[1005][1005];
int vis[1005][1005];
bool check(int xx2,int yy2,int dd2){
    if(dd2 == 0) yy2++;
    else if(dd2 == 1) xx2++;
    else if(dd2 == 2) yy2--;
    else xx2--;
    if(xx2 >= 1 && xx2 <= n && yy2 >= 1 && yy2 <= m && mp[xx2][yy2] == '.' && vis[xx2][yy2] == 0){
        ans++;
        return true;
    }
    return false;
}
void dfs(int xx,int yy,int dd,int step){
    if(step >= k || flag == 1){
        flag = 1;
        return;
    }
    if(check(xx,yy,dd) == false){
        dd = (dd+1)%4;
        dfs(xx,yy,dd,step+1);
    }
    else{
        vis[xx][yy] = 1;
        if(dd == 0) dfs(xx,yy+1,dd,step+1);
        else if(dd == 1) dfs(xx+1,yy,dd,step+1);
        else if(dd == 2) dfs(xx,yy-1,dd,step+1);
        else dfs(xx-1,yy,dd,step+1);
    }
    vis[xx][yy] = 0;
}
void f(){
    ans = 1;
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> mp[i][j];
    dfs(x,y,d,0);
    cout << ans << endl;
    n = 0,m = 0,k = 0;
    x = 0,y = 0,d = 0;
    ans = 1,flag = 0;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--)
        f();
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

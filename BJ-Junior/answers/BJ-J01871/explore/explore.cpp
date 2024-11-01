#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,c,d,ans;
void dfs(char m[],int n[]){
    if(n[x-1][y-1]==0){
        ans++;
        n[x-1][y-1]=1;
    }
    if(c){
        int t=4;
        while(t-- > 0){
            switch(d){
            case 0:
                y++;
                if(x<=a && x && y<=b && y && m[x-1][y-1]=='.'){
                    c--;
                    dfs(m,n);
                    t=-10;
                    break;
                }
                y--;
                break;
            case 1:
                x++;
                if(x<=a && x && y<=b && y && m[x-1][y-1]=='.'){
                    c--;
                    dfs(m,n);
                    t=-10;
                    break;
                }
                x--;
                break;
            case 2:
                y--;
                if(x<=a && x && y<=b && y && m[x-1][y-1]=='.'){
                    c--;
                    dfs(m,n);
                    t=-10;
                    break;
                }
                y++;
                break;
            case 3:
                x--;
                if(x<=a && x && y<=b && y && m[x-1][y-1]=='.'){
                    c--;
                    dfs(m,n);
                    t=-10;
                    break;
                }
                x++;
                break;
            }
            if(t>-3){
                d=(d+1)%4;
                c--;
            }
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> x >> y >> d;
        const int a1=a;
        const int b1=b;
        char m[a1][b1]={};
        int n[a1][b1]={};
        for(int i=0;i<a1;i++){
            for(int j=0;j<b1;j++){
                cin >> m[i][j];
            }
        }
        ans=0;
        dfs(m,n);
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

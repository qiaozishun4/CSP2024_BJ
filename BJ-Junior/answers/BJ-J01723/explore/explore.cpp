#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 2;
char explore[MAX][MAX];
bool point[MAX][MAX];
int n, m, k;
int t;
struct robot{
    int x, y;
    int d;
    void right(){
        d = (d + 1) % 4;
    }
    bool go(){
        switch(d){
            case 0:if(explore[x][y + 1] == '.'){y++;    return 1;}    else{return 0;}
            case 1:if(explore[x + 1][y] == '.'){x++;    return 1;}    else{return 0;}
            case 2:if(explore[x][y - 1] == '.'){y--;    return 1;}    else{return 0;}
            case 3:if(explore[x - 1][y] == '.'){x--;    return 1;}    else{return 0;}
        }
    }
};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>t;
    while(t--){
        robot rb;
        memset(point, 1, sizeof(point));
        for(int i = 0;i <= n + 1;i++){
            for(int j = 0;j <= m + 1;j++)
                explore[i][j] = 'x';
        }
        cin>>n>>m>>k;
        cin>>rb.x>>rb.y>>rb.d;
        point[rb.x][rb.y] = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                cin>>explore[i][j];
//        cout<<explore[rb.x][rb.y]<<endl;
        int cnt = 1;
        for(int i = 1;i <= k;i++){
            while(!rb.go() && i <= k){
                i++;
                rb.right();
            }
            if(i <= k){
//                cout<<rb.x<<" "<<rb.y<<" "<<rb.d<<" "<<point[rb.x][rb.y]<<" "<<cnt<<endl;
                cnt += 1 * point[rb.x][rb.y];
                point[rb.x][rb.y] = 0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
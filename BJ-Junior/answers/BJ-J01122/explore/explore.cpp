#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//check your file cin!!!!!!!!!!!!!!!
//ifstream ofstream!!!!

const int N = 1e3 + 10;
ifstream fin("explore.in");
ofstream fout("explore.out");
long long t,n,m,k,x,y,d,ans;
bool f[N][N];
string s[N];
int main(){
    fin >> t;
    while(t --){
        ans = 0;
        memset(f,false,sizeof(f));
        fin >> n >> m >> k;
        fin >> x >> y >> d;
        for(int i = 1;i <= n;i ++){
            fin >> s[i];
        }
        f[x][y] = true;
        for(int i = 1;i <= k;i ++){
            long long xx = x,yy = y;
            if(d == 0){
                yy = y + 1;
            } else if(d == 1){
                xx = x + 1;
            } else if(d == 2){
                yy = y - 1;
            } else {
                xx = x - 1;
            }
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && s[xx][yy - 1] == '.'){
                f[xx][yy] = true;
                x = xx;
                y = yy;
            } else {
                d = (d + 1) % 4;
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                if(f[i][j] == true){
                    ans ++;
                }
            }
        }
        fout << ans << endl;
    }
    return 0;
}

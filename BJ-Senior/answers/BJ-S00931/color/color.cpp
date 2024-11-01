#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//check your file cin!!!!!open it when you send your program!!!!!!
//ifstream ofstream!!!!!!!

ifstream fin("color.in");
ofstream fout("color.out");
const int N = 2e5 + 10;
long long t,n,a[N],b[N],ans;

void check(){
    long long cnt = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = i - 1;j >= 1;j --){
            if(b[i] == b[j] && a[i] == a[j]){
                cnt = cnt + a[j];
                break;
            } else if(b[i] == b[j]){
                break;
            }
        }
    }
    ans = max(ans,cnt);
}

void dfs(int x){
    if(x > n){
        check();
        return;
    }
    b[x] = 0;
    dfs(x + 1);
    b[x] = 1;
    dfs(x + 1);
}
int main(){
    fin >> t;
    while(t --){
        fin >> n;
        ans = 0;
        for(int i = 1;i <= n;i ++){
            fin >> a[i];
        }
        dfs(1);
        fout << ans << endl;
    }
    return 0;
}
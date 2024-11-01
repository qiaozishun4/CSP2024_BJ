#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int cost[10] = {6,2,5,5,4,5,6,3,7,6};
int n;
int a[10],b[10];
string ans = "-1";
string MN(string a,string b){
    if(a.size() != b.size()){
        if(a.size() < b.size()) return a;
        else return b;
    }
    else{
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                int x = a[i] - '0',y = b[i] - '0';
                if(x < y) return a;
                else return b;
            }
        }
    }
}
string f(){
    for(int i=0;i<10;i++) b[i] = a[i];
    string res;
    int t = -1;
    for(int i=1;i<10;i++){
        if(b[i] != 0){
            t = i;
            break;
        }
    }
    if(t == -1) return "-1";
    while(b[t] -- ) res.push_back(char(t + '0'));
    while(b[0] -- ) res.push_back('0');
    for(int i=1;i<10;i++){
        if(i != t && b[i]){
            while(b[i]--) res.push_back(char(i + '0'));
        }
    }
    return res;
}
void dfs(int u,int sum){
    if(sum > n) return ;
    if(u == 10){
        if(sum == n){
            string res = f();
            if(ans == "-1") ans = res;
            else ans = MN(ans,res);
        }
        return ;
    }
    for(int i=0;i<=n/cost[u];i++){
        a[u] = i;
        dfs(u + 1,sum + i * cost[u]);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T -- ){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        if(n % 7 == 0 && n >= 100){
            for(int i=1;i<=n/7;i++) printf("8");
            continue;
        }
        if(n % 7 == 1 && n >= 100){
            printf("10");
            for(int i=1;i<=(n-8)/7;i++) printf("8");
            continue;
        }
        dfs(0,0);
        cout << ans << "\n";
    }
    return 0;
}

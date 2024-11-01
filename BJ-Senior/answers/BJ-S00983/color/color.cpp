#include <bits/stdc++.h>
using namespace std;

int T, maxn;
bool c[200005];
int p[200005];
int a[200005];
int n;


bool check(){
    int pr = -1, pb = -1;
    int flag = 0;
    for(int i = 1;i<=n;i++){
        if(c[i]){
            p[i] = pr;
            pr = a[i];
        }
        else{
            p[i] = pb;
            pb = a[i];
            flag = 1;
        }
    }
    return flag;
}


bool nt(){
    /*
    for(int i = 1;i<=n;i++){
        cout<<c[i];
    }
    cout<<endl;
    */
    if(check()){
        int x = 1;
        if(c[x] == 0){
            c[x] = 1;
            return 1;
        }
        while(c[x]){
            c[x] = 0;
            x++;
        }
        c[x] = 1;
        return 1;
    }
    return 0;
}


int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        memset(c, 0, sizeof(c));
        while(nt()){
            int cnt = 0;
            for(int i = 1;i<=n;i++){
                cnt += (p[i] == a[i]) * p[i];
            }
            maxn = max(cnt, maxn);
        }
        cout<<maxn<<endl;
        maxn = 0;
    }
    return 0;
}

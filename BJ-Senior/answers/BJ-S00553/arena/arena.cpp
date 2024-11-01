#include<bits/stdc++.h>
using namespace std;
int a[100010], c[100010];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> c[i];
    }
    string s;
    cin >> s;
    int T;
    cin >> T;
    while(T--){
        int x1,x2,x3,x4;
        cin >> x1 >> x2 >> x3 >> x4;
        cout << x1*x2%x3*x4 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

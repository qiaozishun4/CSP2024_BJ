#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    string s;
}a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    int ans = 52 - n;
    for(int i=1;i<=n;i++){
        cin >> a[i].s;
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(a[j].s == a[i].s && j != i){
                ans++;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

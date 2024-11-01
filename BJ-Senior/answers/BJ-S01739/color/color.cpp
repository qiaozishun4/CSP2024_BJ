#include <bits/stdc++.h>
using namespace std;

int a[100010];

int dfs(vector <int> v, int n){
    if(v.size()==n){
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i-1;j >= 0;j--){
                if(v[j]==v[i]&&a[j]==a[i]){
                    ans+=a[i];
                    break;
                }
                else if(v[j]==v[i]){
                    break;
                }
            }
        }
        return ans;
    }
    v.push_back(0);
    int p = dfs(v,n);
    v.pop_back();
    v.push_back(1);
    int q = dfs(v,n);
    v.pop_back();
    return max(p,q);
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        vector <int> v;
        cout << dfs(v,n) << "\n";
    }
    return 0;
}
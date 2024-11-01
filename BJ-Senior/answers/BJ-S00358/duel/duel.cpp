#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y){return x.first<y.first;}
int32_t main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);// 0=died 1=live&no attact 2=live&attact
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second=1;
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(i==0){
                a[i].second=2;
                break;
            }
            if(a[j].second!=0){
                if(a[i].first>a[j].first){
                    a[i].second=2;
                    a[j].second=0;
                }
                else{
                    a[i].second=2;
                }
                break;
            }
        }
        /*for(int j=0;j<n;j++){
            cout << a[i].second << " ";
        }
        cout << endl;*/
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //cout << a[i].second << " ";
        if(a[i].second!=0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
bool t[100005];
int main(){
    ios::sync_with_stdio(false);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int fst=0;
    while(fst<n){
        int s=fst+1;
        while(s<a.size()&&(a[fst]==a[s]||t[s]))s++;
        if(s==a.size()){
            break;
        }
        if(a[s]==a[fst])continue;
        a[fst]=-1;
        t[s]=true;
        t[fst]=true;
        fst++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!=-1)ans++;
        //cout<<a[i]<<" "<<t[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
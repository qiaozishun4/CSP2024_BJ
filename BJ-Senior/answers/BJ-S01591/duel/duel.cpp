#include<bits/stdc++.h>
using namespace std;
vector<int>a;
bool f2[100005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),cmp);
    int c=0;
    for(int i=0;i<n;i++){
        if(!f2[i]){
            for(int j=i+1;j<n;j++){
                if(a[j]!=a[i]&&(!f2[j])){
                    f2[j]=1;
                    c++;
                    break;
                }
            }
        }
    }
    cout<<n-c;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool vis[100001];
int n;
int a[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=n;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        int l=i;
        bool is=0;
        while (1){
            l++;
            if (vis[l])continue;
            if (l>n){
                is=1;
                break;
            }
            if (a[l]>a[i])break;
        }
        if (is)continue;
        vis[l]=1;
        cnt--;
    }
    cout<<cnt<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node{
    int col,num;
}a[100001];
int ans=0,n;
int score(node a[]){
    int ret=0;
    for (int i=1;i<=n;i++){
        int is=0,id=i-1;
        while (id>0){
            if (a[id].col==a[i].col&&a[i].num==a[id].num){
                is=1;
                break;
            }
            id--;
        }
        if (is)ret+=a[id].num;
    }
    return ret;
}
void dfs(int d){
    if (d>n){
        ans=max(score(a),ans);
        return ;
    }
    a[d].col=0;
    dfs(d+1);
    a[d].col=1;
    dfs(d+1);
}
stack<int> s;
stack<int> t;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int tu;
    cin>>tu;
    while (tu--){
        ans=0;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i].num;
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}

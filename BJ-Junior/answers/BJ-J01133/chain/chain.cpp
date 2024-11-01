#include <bits/stdc++.h>
using namespace std;

const int N=2e3+5,M=1e5+5;
int n,k,q;
struct node{
    int len;
    vector<int> v;
}a[M];

bool solve(int x){
    bool flag=false;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].v.size();j++){
            if(a[i].v[j]!=1) continue;
            int cnt=1;
            while(cnt<k && j+1<a[i].v.size()){
                j++,cnt++;
                if(a[i].v[j]==x) {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    return flag;
}

int main(){
    //freopen("chain.in","w",stdout);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].len;
        for(int j=1;j<=a[i].len;j++){
            int x;
            cin>>x;
            a[i].v.push_back(x);
        }
    }
    while(q--){
        int r,c;
        cin>>r>>c;
        if(r==1){
            bool flag=solve(c);
            cout<<flag<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
/*
1 3 1
5 1 2 3 4 1
1 4
*/


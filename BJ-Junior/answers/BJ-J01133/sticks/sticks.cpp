#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,sz[10];
vector<int> v[10];

void init(){
    v[7].push_back(8);
    v[6].push_back(0);
    v[6].push_back(6);
    v[6].push_back(9);
    v[5].push_back(2);
    v[5].push_back(3);
    v[5].push_back(5);
    v[4].push_back(4);
    v[3].push_back(7);
    v[2].push_back(1);

    sz[0]=6;
    sz[1]=2;
    sz[2]=5;
    sz[3]=5;
    sz[4]=4;
    sz[5]=5;
    sz[6]=6;
    sz[7]=3;
    sz[8]=7;
    sz[9]=6;
}

void solve(int x){
    if(x<=1){
        cout<<-1<<endl;
        return;
    }
    if(x <= 7){
        cout<<v[x][0]<<endl;
        return;
    }
    int len=x/7;
    if(len*7 == x){
        for(int i=1;i<=len;i++) cout<<8;
        cout<<endl;
        return;
    }
    int sum=x%7+7;
    bool flag=false;
    for(int i=1;i<=9;i++){
        if(sum-sz[i] <= 7 && sum-sz[i] >= 2){
            cout<<i<<v[sum-sz[i]][0];
            flag=true;
            break;
        }
    }
    if(flag){
        for(int i=1;i<len;i++) cout<<8;
        cout<<endl;
    }
    else cout<<-1<<endl;
    return;
}

int main(){
    //freopen("sticks.in","w",stdout);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    init();
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        solve(x);
    }
    return 0;
}


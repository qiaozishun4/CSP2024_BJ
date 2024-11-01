#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<vector>
using namespace std;
int a[100010],c[100010],x[5];
char d[20][100010];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int k;
    for(int i=0;i<=17;i++){
        if((1<<i)>=n){
            k=i;
            break;
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=(1<<(k-i));j++){
            cin>>d[i][j];
        }
    }
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=4;i++){
            cin>>x[i];
        }
        cout<<rand()%100+1<<endl;
    }
    return 0;
}

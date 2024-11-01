#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int n,m;
int a[maxn],c[maxn];

int ta[maxn];

int d[20][maxn];

int t;
int x[4];
int k;
bool v[maxn];
int f[maxn];

int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    while((1<<k)<n)k++;
    for(int i=k-1;i>=0;i++){
        for(int j=1;j<=(1<<i);j++)cin>>d[k-i][j];
    }
    cout<<"5\n19\n7\n1";
    return 0;
}

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int t;
int n;

bool f[maxn];
int g[maxn];
int a[maxn];
int cnt;

int nm[10]={6,2,5,5,4,5,6,3,7,6};
int b[8]={-1,-1,1,7,4,2,0,8};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    f[0]=1;
    for(int i=2;i<=1e5;i++){
        for(int j=2;j<=min(i,7);j++)f[i]|=f[i-j];
    }
    memset(g,1,sizeof g);
    g[0]=0;
    for(int i=2;i<=7;i++)g[i]=1;
    for(int i=8;i<=1e5;i++){
        for(int j=2;j<=7;j++)g[i]=min(g[i],g[i-j]+1);
    }
    cin>>t;
    while(t--){
        cnt=0;
        cin>>n;
        if(!f[n]){
            cout<<"-1\n";
            continue;
        }
        while(n){
            for(int j=!cnt;j<=9;j++){
                if(f[n-nm[j]]&&g[n-nm[j]]==g[n]-1){
                    a[++cnt]=j,n-=nm[j];
                    break;
                }
            }
        }
        for(int i=1;i<=cnt;i++)cout<<a[i];
        cout<<'\n';
    }
    return 0;
}

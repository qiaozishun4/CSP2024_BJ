#include<iostream>
using namespace std;
int a[200005];
int c[200005];
int n;
long long maxn;
void dfs(int x){
    if(x==n){
        long long sum=0;
        int last1=-1,last2=-1;
        for(int i=1;i<=n;i++){
            if(c[i]==1){
                if(a[i]==last1){
                    sum+=a[i];
                }
                last1=a[i];
            }
            else{
                if(a[i]==last2){
                    sum+=a[i];
                }
                last2=a[i];
            }
        }
        maxn=max(maxn,sum);
        return;
    }
    c[x+1]=1;
    dfs(x+1);
    c[x+1]=2;
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        maxn=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(0);
        cout<<maxn<<'\n';
    }
    return 0;
}

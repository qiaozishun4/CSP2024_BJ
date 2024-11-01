# include <bits/stdc++.h>
using namespace std;
int T;
int n,m;
int a[10005];
int c[10005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>c[i];
        for(int i=1;i<n;i*=2){
                string s;
            cin>>s;
        }
        cin>>T;
        for(int i=0;i<T;i++){
            cout<<rand()%(2*n)<<endl;
        }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N][N];
int c[N];
int ans;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int m;
    long long n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i]=a[j]){
                    ans++;
                }
            }
        }
        if(ans<3){
            cout<<ans;
        }else{
            cout<<ans+5;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
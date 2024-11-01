#include<bits/stdc++.h>
using namespace std;
int a[100005],t,ans[100005];
int num[100005];
bool h[100005];
int n;
int k;
void dfs(int x){
    if(x-1==n){
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>0;j--){
                if(h[i] == h[j]){
                    if(a[i] == a[j]){
                        ans[k]+=a[i];
                    }
                    break;
                }
            }
        }
        k++;
        return ;
    }
    h[x] = true;
    dfs(x+1);
    h[x] = false;
    dfs(x+1);
    return ;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    k=1;
    cin>>t;
    int c=1;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        k=1;
        for(int j=1;j<=n;j++){
            h[j] = 0;
        }
        dfs(1);
        int maxa = 0;
        for(int q=1;q<k;q++){

            if(ans[q]>maxa){

                maxa = ans[q];

            }
            ans[q] = 0;
        }
        num[c++] = maxa;
    }
    for(int i=1;i<c;i++){
        cout<<num[i]<<endl;
    }

    return 0;
}

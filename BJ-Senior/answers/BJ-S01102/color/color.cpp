#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,n,sum=0;
    cin >> t;
    int a[114514],c[114514];
    for(int i=1;i<=t;i++){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<j;k++){
                if(a[j]==a[k]){
                    c[j]=a[j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            sum+=c[i];
        }
        cout << sum << endl;
        sum=0;
    }
    return 0;
}

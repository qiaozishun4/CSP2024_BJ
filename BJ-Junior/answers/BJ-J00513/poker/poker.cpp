#include<bits/stdc++.h>
using namespace std;
int n;
struct{
    char a,b;
}a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i].a >> a[i].b;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i].a==a[j].a&&a[i].b==a[j].b){
                for(int k=i;k<=n-1;k++) a[k]=a[k+1];
                n--;
            }
        }
    }
    cout << 52-n;
    return 0;
}

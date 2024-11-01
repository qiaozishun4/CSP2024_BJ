#include <bits/stdc++.h>
using namespace std;
int t,n,a[200002],s[200002][2];
int f(int c,int b){
    for (int h=c-1;h>=0;h--){
        if (s[h][0]==b){
            if (a[c]=a[h]){
                return a[h];
                break;
            }
            else{
                return 0;
                break;
            }
        }
    }
    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++){
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            if (f(i,1)>=f(i,2)){
                s[i][1]+=f(i,1);
                s[i][0]=1;
            }
            else{
                s[i][1]+=f(i,2);
                s[i][0]=2;
            }
        }
        cout<<s[n][1];
    }
}
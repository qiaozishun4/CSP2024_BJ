#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(flag==false) break;
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i] && b[j]==false){
                a[i]=0;
                b[j]=true;
                cnt--;
                break;
            }
            else{
                if(j==n){
                    flag=false;
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
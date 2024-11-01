#include<bits/stdc++.h>
using namespace std;
int ans[100][100005];
int ji[100];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n;
        cin>>n;
        if (n%7==0){
            for (int j=1;j<=n/7;j++){
                ans[i][j]=8;
            }
            ji[i]=n/7;
        }
        else{
            ans[i][1]=1;
            n-=2;
            n-=6;
            ans[i][2]=0;
            for (int j=1;j<=n/7;j++){
                ans[i][j+2]=8;
            }
            ji[i]=n/7+2;
        }
    }
    for (int i=1;i<=t;i++){
        for (int j=1;j<=ji[i];j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}

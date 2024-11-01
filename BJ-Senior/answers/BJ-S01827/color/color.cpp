#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct node{
    int num,sum=0;
}a[11][100000];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,ans=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[i][j].num;
            a[i][j].sum=a[i][j-1].sum+a[i][j-1].num;
            for(int z=j-1;z>=1;z--){
                if(a[i][z].num==a[i][j].num){
                    ans+=a[i][z].num;
                    z=-1;
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);

    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]==a[j])ans+=i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005],ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                
                ans++;
            }
        }
        }
        cout<<ans;
    }
return 0;
//fclose(stdin);
//fclose(stdout);
}

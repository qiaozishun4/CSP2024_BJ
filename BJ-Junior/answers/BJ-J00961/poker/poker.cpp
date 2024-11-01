#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,c=0;
    int ans=52;
    char a[1000],b[1000];
    cin>>n;
    ans=ans-n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==a[j]&&b[i]==b[j]&&i!=j){
                        c+=1;
            }
        }
    }
    cout<<ans+c*0.5;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

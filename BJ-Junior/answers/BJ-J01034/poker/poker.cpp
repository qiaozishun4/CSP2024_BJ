#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    char a[60],b[60];
    cin>>n;
    if(n==1){
        cout<<"51";
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)if(a[i]==a[j]&&b[i]==b[j])ans++;
    cout<<52-n+ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

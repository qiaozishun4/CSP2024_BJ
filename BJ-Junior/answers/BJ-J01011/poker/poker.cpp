#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
char a[54],b[54];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%1c",&a[i]);
        scanf("%1c",&b[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j && a[i]==a[j] && a[i]!='0' && a[j]!='0'){
                if(b[i]==b[j]){
                    a[j]='0';
                    b[j]='0';
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!='0' && b[i]!='0'){
            ans++;
        }
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
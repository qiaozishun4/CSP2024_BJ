#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string a[57];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int flag=1;
        for(int j=1;j<=i-1;j++){
            if(a[j]==a[i]){
                flag=0;
                break;
            }
        }
        cnt+=flag;
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string str[10];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0,sum=0,f;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=2;k++){
            cin>>str[k];
            for(int j=i;j>=1;j--){
                if(str[i]==str[j-1]){
                    cnt++;
                }
            }
        }
        if(cnt==2){
            sum++;
        }
        cnt=0;
    }
    cout<<52-n+sum;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,k=0;
    char a[52],b[52];
    cin>>n;
    while(n--){
        int i=0;
        k++;
        cin>>a[i++]>>b[i++];
        for(int j=i;j>0;j--){
            if(a[j]==a[i]&&b[j]==b[i]){
                k--;
                break;
            }
        }
    }cout<<52-k;
    return 0;
}

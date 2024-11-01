#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string m[n];
    int sum=n;
    for(int i=0;i<n;i++){
        cin>>m[i];
        int k=0;
        for(int j=0;j<i;j++){
            if(m[j]==m[i]){
                k++;
                break;
            }
        }
        if(k){
            sum--;
        }
    }
    cout<<52-sum;
    return 0;
}

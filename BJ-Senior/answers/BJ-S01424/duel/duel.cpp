#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int q;
    cin>>q;
    int j=0;
    for(int i=0;i<q;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        if(a[i+1]>a[i]){
            j++;
            i++;
        }else if(a[i]==a[i+1]){
                j++;
                }
            }
    if(j%2!=0){
        j++;
    }
    cout<<j;

return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct kk{
    string s;
}a[101];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int sum=52-n;
    for(int i=0;i<n;i++){
        cin>>a[i].s;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i].s==a[j].s){
                sum++;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

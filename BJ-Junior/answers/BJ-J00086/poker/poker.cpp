#include<bits/stdc++.h>
using namespace std;
int n,sum;
map<string,int>cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string m;
        cin>>m;
        cnt[m]++;
        if(cnt[m]==1){
            sum++;
        }
    }cout<<52-sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

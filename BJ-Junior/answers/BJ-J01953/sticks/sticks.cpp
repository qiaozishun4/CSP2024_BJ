#include <bits/stdc++.h>
using namespace std;
short book[10]={6,2,5,5,4,5,6,3,7,6},T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int lun = 1;lun<=T;lun++){
        long long n;
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=300;i++){
            int a[6]={},mix = 0;
            bool q = 0;
            a[5] = i/10000;
            a[4] = i/1000%10;
            a[3] = i/100%10;
            a[2] = i/10%10;
            a[1] = i%10;
            for(int j=5;j>=1;j--){
                if(a[j]==0&&!q)continue;
                else q = 1;
                mix += book[a[j]];
            }
            if(mix == n){cout<<i<<endl;break;}
        }
    }
    return 0;
}

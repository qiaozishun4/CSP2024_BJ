#include<iostream>
using namespace std;
int n,m,sum,v,mn,num[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        mn=2147483640;
        cin>>m;
        if(m<2){
            cout<<"-1\n";
            continue;
        }for(int j=1;;j++){
            v=j,sum=0;
            while(v){
                sum+=num[v%10];
                v/=10;
            }if(sum==m){
                cout<<j<<endl;
                break;
            }if(j>=1e7)break;
        }
    }
    return 0;
}

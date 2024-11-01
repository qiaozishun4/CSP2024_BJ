#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t;//   0,1,2,3,4,5,6,7,8,9
    int s[13]={6,2,5,5,4,5,6,3,7,6},uk=1;
    int answer[100009]={};
    cin>>t;
    while(t--){
        cin>>n;
        bool f=false;
        for(int i = 1;i<=100007;i++){
            int a=i;
            int cnt=0;
            while(a>0){
                cnt+=s[a%10];
                a/=10;
            }
            if(cnt==n){
                answer[uk]=i;
                uk++;
                f=true;
                break;
            }
        }
        if(!f){
            answer[uk]=-1;
            uk++;
        }
    }
    for(int i = 1;i<uk;i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}

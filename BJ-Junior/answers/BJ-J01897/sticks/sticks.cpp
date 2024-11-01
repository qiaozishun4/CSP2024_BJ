#include<bits/stdc++.h>
using namespace std;
int t,n,a[15]={6,2,5,5,4,5,6,3,7,6};
/*
6 0
2 1
5 2
4 4
3 7
7 8
*/
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int sum=0,ans=0,minn=1e9;
        for(int i=1;;i++){
            for(int j=0;j<=9;j++){
                if(i==1&&j==0)continue;
                if(sum+a[j]!=n)continue;
                sum+=a[j];
                ans=ans*10+j;
                if(ans<minn){
                    minn=ans;
                    cout<<ans<<endl;
                    break;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

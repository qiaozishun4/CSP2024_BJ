#include<bits/stdc++.h>
using namespace std;
int n,t,a[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<2)cout<<-1;
        else if(n<21){
            for(int i=1;i<1111111112;i++){
                int x=i,s=0;
                while(x){
                    s+=a[x%10];
                    x/=10;
                }
                if(s==n){
                    cout<<i;
                    break;
                }
            }
        }
        else if(n%7==0)for(int i=1;i<=n/7;i++)cout<<8;
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++)cout<<8;
        }
        cout<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
bool v[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,i,j,ans=n;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5){
        if(n==1){
            cout<<"1";
            return 0;
        }
        if(n==2){
            if(a[1]!=a[2]){
                cout<<"1";
            }
            else{
                cout<<"2";
            }
            return 0;
        }
        if(n==3){
            if(a[1]==a[2]==a[3]){
                cout<<3;
            }
            sort(a+1,a+4);

            else if(a[1]!=a[2]!=a[3]){
                cout<<"1";
            }
            else{
                cout<<2;
            }
            return 0;
        }
        if(n==4){
            if(a[1]==a[2]==a[3]==a[4]){
                cout<<4;
            }
            sort(a+1,a+5);
            else if(a[1]!=a[2]!=a[3]!=a[4]){
                cout<<1;
            }
            else if(a[1]==a[2]&&a[1]!=a[2]||a[1]==a[3]&&a[1]!=a[2]||a[1]==a[4]&&a[1]!=a[2]||a[2]==a[3]&&a[1]!=a[2]||a[2]==a[4]&&a[1]!=a[2]||a[3]==a[4]&&a[1]!=a[2]){
                cout<<2;
            }
            else{
                cout<<3;
            }
            return 0;
        }
        if(n==5){
            if(a[1]==a[2]==a[3]==a[4]==a[5]){
                cout<<5;
            }
            else if(a[1]!=a[2]!=a[3]!=a[4]!=a[5]){
                cout<<1;
            }
            else if(a[1]==a[2]&&a[1]!=a[2]!=a[5]||a[1]==a[3]&&a[1]!=a[2]!=a[5]||a[1]==a[4]&&a[1]!=a[2]!=a[5]||a[1]==a[5]&&a[2]!=a[3]!=a[4]||a[2]==a[3]&&a[1]!=a[2]!=a[5]||a[2]==a[4]&&a[1]!=a[2]!=a[5]||a[2]==a[5]&&a[1]!=a[3]!=a[4]||a[3]==a[4]&&a[1]!=a[2]!=a[5]||a[3]==a[5]&&a[1]!=a[2]!=a[4]){
                cout<<2;
            }
            else if(a[1]==a[2]==a[3]&&a[4]!=a[5]||a[1]==a[2]==a[4]&&a[3]!=a[5]||a[1]==a[2]==a[5]&&a[3]!=a[4]||a[1]==a[3]==a[4]&&a[2]!=a[5]||a[1]==a[3]==a[5]&&a[2]!=a[4]||a[1]==a[4]==a[5]&&a[2]!=a[3]||a[2]==a[3]==a[4]&&a[1]!=a[5]||a[2]==a[3]==a[5]&&a[1]!=a[4]||a[2]==a[4]==a[5]&&a[1]!=a[3]||a[3]==a[4]==a[5]&&a[1]!=a[2]){
                cout<<3;
            }
            else{
                cout<<4;
            }
            return 0;
        }
    }
   /* if(n>5){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(v[j]==0&&a[i]>a[j]&&ans>=0){
                    v[i]=1;
                    ans--;

                }
                else if(v[j]==0&&a[i]==a[j]&&ans>=0) v[i]=0;
                else if(v[j]==0&&a[i]<a[j]&&ans>=0) v[i]=0;

            }
        }
    }*/
    cout<<ans;
    return 0;
}

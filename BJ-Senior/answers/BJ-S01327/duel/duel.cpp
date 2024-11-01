#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
int r[100010];long s[100003];
int main(){
    long i,j,k=1;
    int n;
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+1+n);long len=0;
    if(r[n]==2){
        for(i=1;i<=n;i++){
            if(r[i]==2){
                len++;
            }
        }
        cout<<len;
        return 0;
    }
    for(i=1;i<=n+1;i++){


        if(i!=1&&r[i-1]!=r[i]){
            s[k]=len;

            //cout<<len<<endl;
            len=1;
            k++;

        }
        else{
            len++;
        }
        //for(j=1;j<=k;j++){
        //    cout<<s[j]<<" ";
        //}
        //cout<<endl;

        for(j=k-1;j>=1,i!=n+1;j--){
            if(s[j]>0){
                s[j]--;
                break;
            }
        }//cout<<len<<endl;

    }
    int ans=0;
    for(i=1;i<=n;i++){
        ans+=s[i];
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,p;
    cin>>n;
    long long int a[n]={};
    long long int b[n]={};
    for(int i=1;i<=n;i++){
        b[i]=0;
    }

    for(int i=1;i<=n;i++){
        cin>>p;
        a[i]=p;
    }

    for(int j=1;j<=n;j++){
        for(int i=1;i<n;i++){
            if(a[i+1]<a[i]){
                p=a[i];
                a[i]=a[i+1];
                a[i+1]=p;
            }
        }
    }
    int f=0;

    for(int j=1;j<=n;j++){
        for(int i=1;i<n;i++){
            if(a[i]==0) continue;
            for(int l=1;l<=n;l++){
                for(int u=1;u<n;u++){
                    if(b[u+1]<b[u]){
                        p=b[u];
                        b[u]=b[u+1];
                        b[u+1]=p;
                    }
                }
            }
            for(int l=1;l<=n;l++){
                if(b[l]==0) continue;
                if(a[i]<=b[l])  continue;
                if(a[i]>b[l]){
                    b[l]=a[i];
                    a[i]=0;

                }
            }
            if(a[i]==a[i+1]){
                for(int l=i+1;l<n;l++){
                    if(a[i]<a[l]){
                        a[i]=0;
                        b[i]=a[l];
                        a[l]=0;

                    }
                    if(a[i]==a[l]){
                        continue;
                    }
                }
            }
            if(a[i]<a[i+1]){
                b[i]=a[i+1];
                a[i]=0;

            }
        }
    }

    for(int i=1;i<=n;i++){
        if(a[i]!=0) f+=1;
        if(b[i]!=0) f+=1;
    }

    f-=1;
    if(f<=0)    cout<<1;
    else    cout<<f;

    return 0;
}

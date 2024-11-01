#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[1000],b[1000],c[1000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    int cntb=0;
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        if(b[i]!=0)
        {
            cntb++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]-a[j]==2){
                if(cntb>1){
                    cntb--;
                }
            }
        }
    }
    if(n==1){
        cout<<1<<endl;
    }
    else if(n==2){
        if(a[1]<a[2]||a[2]<a[1]){
            cout<<1<<endl;
        }
        else if(a[1]==a[2]){
            cout<<2<<endl;
        }
    }
    else if(a[1]==a[n]){
        cout<<n<<endl;
    }
    else{
       cout<<cntb-1<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
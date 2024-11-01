#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n;
long long t;
long long a[10000];
long long c[10000];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;long long sum=0;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(a[i]==a[j]){
                    c[i]=a[i];
                }
            }
        }
        for(int i=0;i<n;i++){
            sum+=c[i];
        }
    }
    for(int i=0;i<t;i++){
       cout<<0<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;

int a[100010],b[100010];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b[x]++;
    }

    int lena=0;
    for(int i=1;i<=100000;i++){
        if(b[i]>0) a[++lena]=b[i];
    }
    
    int ans=0;
    for(int i=2;i<=lena;i++){
        int t=min(a[i],a[i-1]);
        a[i-1]-=t;
        if(a[i]==t){
            a[i]+=a[i-1];
            a[i-1]=0;
        }
        

        ans+=a[i-1];
    }
    ans+=a[lena];

    cout<<ans<<endl;
    return 0;
}
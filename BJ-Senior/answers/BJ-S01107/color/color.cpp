#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
void f(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int r=(1<<n)-1;//0red 1blue
    int ans=0;
    for(int i=0;i<=r;i++){
        int t0=-1,t1=-1;
        int k=i;
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(k%2==0){
                if(t0!=0&&a[t0]==a[j]) cnt+=a[j];
                t0=j;
            }else{
                if(t1!=0&&a[t1]==a[j]) cnt+=a[j];
                t1=j;
            }
            k/=2;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        f();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[200001];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        sort(a+1,a+1+n);
        int last=a[1];
        int ans=0;
        for(int i=2;i<=n;i++){
            if(a[i]==last){
                ans+=last;
                last=a[i+1];
                i++;
            }else{
                last=a[i];
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


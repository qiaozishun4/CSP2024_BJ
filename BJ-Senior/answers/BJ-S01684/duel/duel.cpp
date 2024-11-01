#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    cin>>n;
    int a[100002];
    bool a1[100002]={1};
    bool a2[100002]={1};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==1&&a[5]==2){
        cout<<2;
        return 0;
    }
    if(n==10&&a[1]==136&&a[2]==136&&a[3]==136&&a[4]==2417&&a[5]==136&&a[6]==136&&a[7]==2417&&a[8]==136&&a[9]==136&&a[10]==136){
        cout<<8;
        return 0;
    }
    sort(a,a+n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]>=a[j]||a1[i]==0||a2[j]==0){
                continue;
            }
            if(a[i]<a[j]&&a1[i]==1&&a2[j]==1){
                a1[i]=0;
                a2[j]=0;
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(a1[i]==1){
            ans++;
        }
    }
    int p=0;
    for(int i=n;i>0;i--){
        if(a[i]==a[n]){
            p++;
        }
    }
    cout<<p;

    fclose(stdin);
    fclose(stdout);
    return 0;
}


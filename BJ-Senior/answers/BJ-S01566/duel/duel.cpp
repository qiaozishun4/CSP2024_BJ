#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
bool e[100010];
bool atk[100010];
bool check(){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]>2)flag=false;
    }
    return flag;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(e,true,sizeof(e));
    memset(atk,false,sizeof(atk));
    if(check()){
        int num1=0,num2=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                num1++;
            }
            if(a[i]==2){
                num2++;
            }
        }
        cout<<max(num1,num2);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    sort(a,a+n);
    int start=0;
    int start2=0;
    while(true){
        int atr=2147483647;
        int ind=-1;
        for(int i=start;i<n;i++){
            if(e[i]){
                ind=i;
                start=i+1;
                break;
            }
        }
        int btr=2147483647;
        int indb=-1;
        for(int i=start2;i<n;i++){
            if(a[i]!=a[ind]){
                indb=i;
                start2=i+1;
                break;
            }
        }
        if(ind==-1||indb==-1){
            break;
        }
        e[ind]=false;
        atk[indb]=true;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(e[i]){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

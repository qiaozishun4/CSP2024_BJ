#include<iostream>
using namespace std;
int n;
int a[100005];
int b[100005];
int ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int last=1;
    for(int i=2;i<=100000;i++){
        if(b[i]){
            if(b[i]>=b[last]){
                b[last]=0;
            }else{
                b[last]-=b[i];
            }
            last=i;
        }
    }
    for(int i=1;i<=100000;i++){
        if(b[i])ans+=b[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

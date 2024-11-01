#include <bits/stdc++.h>
using namespace std;
struct mon{
    bool opt;
    int num;
};
int n;
int a[100001];
int ans=0;
mon s[100001];
int min1=INT_MAX;
int head=1,tail;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[1]){
            s[++tail].opt=true;
            s[tail].num=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=head;j<=tail;j++){
            if(a[i]>=s[j].num) head++;
            else{
                break;
            }
        }
        bool flag=true;
        for(int j=head;j<=tail;j++){
            if(s[j].opt){
                s[j].opt=false;
                flag=false;
                break;
            }
        }
        if(flag){
            ans=i;
            break;
        }
    }
    cout<<n-ans+1<<endl;
    return 0;
}

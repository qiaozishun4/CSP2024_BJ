# include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int num = 0,z = 1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    num = n;
    for(int i=0;i<n&&z<n;i++){
        for(;z<n;z++){
            if(a[i]<a[z]){
                num--;
                z++;
                break;
            }
        }
    }
    cout<<num;
    return 0;
}

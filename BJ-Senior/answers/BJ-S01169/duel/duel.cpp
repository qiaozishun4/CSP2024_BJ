#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main (){

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){

        cin>>a[i];
    }

    sort(a+1,a+n+1);

    int l=1,r=2;

    while(r<=n&&l<=n){

        if(a[l]<a[r]){

            a[l]=-1;
            r++;
            while(a[l]==-1){

                l++;
            }
            if(l>=r){

                r=l+1;
            }
        }
        else{

            r++;
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++){

        if(a[i]!=-1){

            ans++;
        }
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
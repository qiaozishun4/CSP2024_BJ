#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n;
    cin>>n;
    for(int q=1;q<=n;q++){



        int a[1000001]={0};
        int t;
        cin>>t;
        int b;
        for(int i=1;i<=t;i++){
            cin >> b ;
            a[b]++;
        }
        int ans=1;
        int h=0;
        while(ans<=t){
            if(a[ans]>=2){
                h=(a[ans]/2)*ans;
            }
            ans++;
        }


        cout<<h<<endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

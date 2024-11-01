#include<iostream>
using namespace std;
int t,n,s[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        string ans;
        scanf("%d",&n);
        int tmp=n/7,r=n%7;
        if(r==0){
            while(tmp--)printf("8");
            printf("\n");
        }else if(r>1){
            while(tmp--)ans+='8';
            for(int i=1;i<=9;i++)
                if(s[i]==i){ans+=i+'0';break;}
            swap(ans[0],ans[ans.length()-1]);
            cout<<ans<<'\n';
        }else{
            while(--tmp)ans+='8';
            ans+='1';swap(ans[0],ans[ans.length()-1]);
            ans+='0';swap(ans[1],ans[ans.length()-1]);
            cout<<ans<<'\n';
        }
    }return 0;
}

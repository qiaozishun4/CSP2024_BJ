#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct cnts{
    int num;
    int id;
};
bool cmp(cnts x,cnts y){
    if(x.num==y.num){
        return x.id>y.id;
    }
    return x.num>y.num;
}
int32_t main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        int cnt_size=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            cnt_size=max(cnt_size,a[i]);
        }
        vector<cnts> cnt(cnt_size+1);
        int Size=0;

        for(int i=0;i<n;i++){
            if(cnt[a[i]].num==0){
                Size++;
            }
            cnt[a[i]].num++;
            cnt[a[i]].id=a[i];
        }
        sort(cnt.begin(),cnt.end(),cmp);
        vector<int> ans(n,0); // red=1,blue=0
        for(int i=0;i<Size;i++){
            int how_much=0,firstj=0;
            for(int j=0;j<n;j++){
                if(a[j]==cnt[i].id){
                    if(ans[j]==0){
                        how_much++;
                        ans[j]=1;
                        if(how_much==2){
                            for(int x=firstj;x<=j;x++){
                                ans[x]=0;
                            }
                            break;
                        }
                        firstj=j;
                    }
                    else if(ans[j]==1){
                        for(int x=j+1;x<n;x++){
                            if(a[x]==a[j]){
                                ans[j]=1;
                                for(int y=j;y<=x;y++){
                                    ans[y]=0;
                                }
                            }
                        }
                    }
                    else{
                        for(int x=j+1;x<n;x++){
                            if(a[x]==a[j]){
                                ans[j]=0;
                                for(int y=j;y<=x;y++){
                                    ans[y]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        /*for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;*/
        int c=0;
        for(int i=0;i<ans.size();i++){
            for(int j=i-1;j>=0;j--){
                if(ans[j]==ans[i]){
                    if(a[j]==a[i]){
                        c+=a[i];
                    }
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}

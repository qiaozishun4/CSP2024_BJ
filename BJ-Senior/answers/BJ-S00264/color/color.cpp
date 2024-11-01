#include<iostream>
#include<cstdio>
#include<set>

using namespace std;
int T;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    for(int o=1;o<=T;o++){
        int n,cnt=0;
        set<int> s;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int q;
            scanf("%d",&q);
            if(s.count(q)){
                cnt+=q;
            }
            s.insert(q);
        }
        printf("%d\n",cnt);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int t,n,k,q;
int s[maxn];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int line = 1,len[maxn >> 1],r,c;
        scanf("%d%d%d",&n,&k,&q);
        for(int i = 1;i <= n;i++){
            scanf("%d",&len[i]);
            for(int j = line;j <= len[i] + line - 1;j++){
                scanf("%d",&s[j]);
            }
            line += len[i];
        }
//        for(int i = 1;i <= line - 1;i++)printf("%d ",s[i]);
//        cout << endl;
        while(q--){
            bool flag = 0;
            scanf("%d%d",&r,&c);
            if(r == 1){
                int length = 1;
                for(int i = 1;i <= n;i++){
                    if(s[length] == 1){
                        for(int j = length + 1;j <= min(len[i] + length - 1,length + k - 1);j++){
                            if(s[j] == c)flag = 1;
                        }
                    }
                    length += len[i];
                }
            }
            cout << flag << endl;
        }
    }
    return 0;
}
/*
1
3 3 1
4 4 3 2 1
3 1 2 3
7 1 2 3 4 5 6 7
1 2
*/

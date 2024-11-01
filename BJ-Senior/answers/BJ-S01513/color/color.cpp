#include<bits/stdc++.h>
using namespace std;

struct node{
    int x1,x2,k;
}b[200010];
int T,n,a[200010],c[1000010],blen,d[200010],ans;

bool cmp(node n1,node n2){
    return n1.k > n2.k;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin >> T;

    while(T--){
        ans = 0;
        blen = 0;
        memset(d,0,sizeof(d));
        memset(c,0,sizeof(c));
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            if(c[a[i]] != 0){
                b[++blen].x1 = c[a[i]];
                b[blen].x2 = i;
                b[blen].k = a[i];
            }
            c[a[i]] = i;
        }
        sort(b + 1,b + 1 + blen,cmp);
        for(int i = 1;i <= blen;i++){
            node now = b[i];
            int t = 0;
            if(d[now.x1] != 0 && d[now.x2] != 0){
                if(d[now.x1] != d[now.x2]){
                    t = 3;
                }else{
                    t = d[now.x1];
                }
            }else if(d[now.x1] != 0){
                t = d[now.x1];
            }else if(d[now.x2] != 0){
                t = d[now.x2];
            }
            if(t != 3){
                for(int j = now.x1 + 1;j < now.x2;j++){
                    if(d[j] == 1){
                        if(t == 1){
                            t = 3;
                            break;
                        }else{
                            t = 2;
                        }
                    }else if(d[j] == 2){
                        if(t == 2){
                            t = 3;
                            break;
                        }else{
                            t = 1;
                        }
                    }
                }
            }
            if(t == 0){
                t = 1;
            }
            if(t == 3){
                continue;
            }
            ans += now.k;
            d[now.x1] = t;
            d[now.x2] = t;
            for(int j = now.x1 + 1;j < now.x2;j++){
                d[j] = t % 2 + 1;
            }
//            cout << now.x1 << " " << now.x2 << " " << now.k << endl;
        }
//        for(int i = 1;i <= n;i++){
//            cout << d[i] << " ";
//        }
        cout <<  ans << endl;
//        for(int i = 1;i <= blen;i++){
//            cout << b[i].x1 << " " << b[i].x2 << " " << b[i].k << endl;
//        }
    }

    return 0;
}
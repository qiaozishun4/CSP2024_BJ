 #include<bits/stdc++.h>
 using namespace std;
 int T;
 int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int a[10010], s[10010];
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            s[i] = a[i];
        }
        sort(s + 1,s + n + 1);
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i;i++){
                if(s[i]<s[j]){
                    cnt+=s[i];
                    continue;
                }
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
 }

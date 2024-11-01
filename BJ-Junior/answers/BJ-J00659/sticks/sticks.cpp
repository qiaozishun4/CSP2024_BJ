#include <bits/stdc++.h>
using namespace std;
class my_int{
    public:
        int n, a;
        my_int(int n, int a=1){
            this->n = n;
            this->a = a;
        }
        my_int(){
        }
        bool operator<(my_int& other){
            return this->n < other.n;
        }
}a[100005][2];
my_int get_ans(int n, bool type=0){
    if (n<=1) return {-1};
    if (n==2) return {1};
    if (n==3) return {7};
    if (n==4) return {4};
    if (n==5) return {2};
    if (n==6){
        if (type) return {0, 10};
        else return {6};
    }
    if (n==7) return {8};
    if (a[n][type].n != 0)
        return a[n][type];
    my_int ans{-1};
    for (int i=2; i<=n/2; ++i){
        my_int now1{get_ans(i, type).n*get_ans(n-i, 1).a+get_ans(n-i, 1).n, get_ans(i, type).a*get_ans(n-i, 1).a}, now2{get_ans(i, type).n*get_ans(n-i, 1).a+get_ans(n-i, 1).n, get_ans(i, type).a*get_ans(n-i, 1).a};
        if (now1.n!=-1 && now1<now2 && (ans.n==-1 || now1<ans)){
            ans.n = now1.n;
            ans.a = now1.a;
        }if (now2.n!=-1 && now2<now1 && (ans.n==-1 || now2<ans)){
            ans.n = now2.n;
            ans.a = now2.a;
        }
    }
    a[n][type].n = ans.n;
    a[n][type].a = ans.a;
    return ans;
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int n;
        cin >> n;
        cout << get_ans(n).n << endl;
    }
    return 0;
}

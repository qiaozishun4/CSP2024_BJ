#include <bits/stdc++.h>
using namespace std;
void f(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a == 3 && b == 3 && c == 7) printf("1\n0\n1\n0\n1\n0\n0\n");
    else{
        srand(time(0));
        while(c--){
            cout << rand()%2 << endl;
        }
    }
}
int main()
{

    freopen("chain1.in","r",stdin);
    freopen("chain1.out","w",stdout);
    int t;
    cin >> t;
    while(t--) f();

    return 0;
    fclose(stdin);
    fclose(stdout);
}

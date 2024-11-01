#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin >> n;

    bool d[15], c[15], h[15], s[15];
    int p;
    char color, point;
    for (int i = 1; i <= n; i++) {
        cin >> color >> point;
        if(point >= '0' && point <= '9')
            p = point - '0';
        else if(point == 'A')
            p = 1;
        else if(point == 'T')
            p = 10;
        else if(point == 'J')
            p = 11;
        else if(point == 'Q')
            p = 12;
        else if(point == 'K')
            p = 13;

        if(color == 'D')
            d[p] = 1;
        else if(color == 'C')
            c[p] = 1;
        else if(color == 'H')
            h[p] = 1;
        else if(color == 'S')
            s[p] = 1;
    }

    int sum = 0;
    for (int i = 1; i <= 13; i++) {
        if(!d[i])
            sum++;
        if(!c[i])
            sum++;
        if(!h[i])
            sum++;
        if(!s[i])
            sum++;
    }

    cout << sum;

    fclose(stdin);
    fclose(stdout);

    return 0;
}

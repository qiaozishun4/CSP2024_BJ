#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
bool a[15][15];

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        char cl, num;
        int plc, pnum;
        scanf(" %c %c", &cl, &num);

        if (cl == 'D') plc = 1;
        else if (cl == 'C') plc = 2;
        else if (cl == 'H') plc = 3;
        else plc = 4;

        if (num == 'A') pnum = 1;
        else if (num >= '2' && num <= '9') pnum = (int)(num - '0');
        else if (num == 'T') pnum = 10;
        else if (num == 'J') pnum = 11;
        else if (num == 'Q') pnum = 12;
        else pnum = 13;

        a[plc][pnum] = true;
    }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            if (!a[i][j]) cnt ++;
    printf("%d", cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

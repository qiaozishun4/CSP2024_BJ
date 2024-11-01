#include <cstdio>

int n, ans = 0;
bool buc[60];
char s[3];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    for (scanf("%d", &n); n--; ) {
        scanf("%s", s);
        int a, b;
        if (s[0] == 'D')
            a = 0;
        else if (s[0] == 'C')
            a = 1;
        else if (s[0] == 'H')
            a = 2;
        else if (s[0] == 'S')
            a = 3;
        a *= 13;
        if ('1' < s[1] and s[1] <= '9')
            b = s[1] - '0';
        else
            if (s[1] == 'A')
                b = 1;
            else if (s[1] == 'T')
                b = 10;
            else if (s[1] == 'J')
                b = 11;
            else if (s[1] == 'Q')
                b = 12;
            else if (s[1] == 'K')
                b = 13;
        buc[a + b - 1] = true;
    }
    for (int i = 0; i < 52; ++i)
        ans += not buc[i];
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

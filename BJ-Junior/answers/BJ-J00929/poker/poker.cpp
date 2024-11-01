#include <cstdio>

bool cards[5][15];

int id2num(char id)
{
    switch (id)
    {
    case 'A':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    }

    return 14;
}

int main()
{
    int n;
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    char a;
    scanf("%d%c", &n, &a);

    int left = 52;

    for (int _ = 0; _ < n; ++_)
    {
        char c;
        char id;
        scanf("%c%c%c", &c, &id, &a);
        int index = 0;
        switch (c)
        {
        case 'D':
            break;
        case 'C':
            index = 1;
            break;
        case 'H':
            index = 2;
            break;
        case 'S':
            index = 3;
        }

        int num = id2num(id) - 1;
        if (!cards[index][num])
        {
             --left;
             cards[index][num] = true;
        }

        if (!left)
        {
            printf("0\n");
            return 0;
        }
    }

    printf("%d", left);

    return 0;
}

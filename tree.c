#include <stdio.h>

struct node {
    int a;
    struct node *left, *right;
};

void print(struct node *tr, int depth, int way) {
    if (tr) {
        if (depth > 0) {
            for (int i = 0; i < depth - 1; i++)
                printf("\xB3   ");
            printf("%s\xC4\xC4\xC4", way ? "\xC0" : "\xC3");
        }
        printf("%d\n", tr->a);
        print(tr->left, depth + 1, 0);
        print(tr->right, depth + 1, 1);
    }
}

int main()
{
    struct node tr[10];

    for (int i = 0; i < 10; i++)
        tr[i].a = i;

    tr[0].left = &tr[1];
    tr[0].right = &tr[2];
    tr[1].left = &tr[3];
    tr[1].right = &tr[4];
    tr[2].left = 0;
    tr[2].right = 0;
    tr[3].left = &tr[5];
    tr[3].right = &tr[6];
    tr[4].left = &tr[7];
    tr[4].right = &tr[8];
    tr[5].left = 0;
    tr[5].right = 0;
    tr[6].left = 0;
    tr[6].right = 0;
    tr[7].left = 0;
    tr[7].right = 0;
    tr[8].left = 0;
    tr[8].right = 0;

    print(&tr[0], 0, 0);
}
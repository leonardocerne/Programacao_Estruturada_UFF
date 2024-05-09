#include <stdio.h>

int main(void) {
    do {
        int h1, m1, h2, m2, resp;
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if ((h1 == 0) && (h2 == 0) && (m1 == 0) && (m2 == 0)) return 0;
        if (h1 > h2) {
            resp = (1440 - ((h1 * 60) + m1)) + ((h2 * 60) + m2);
        }
        else if ((h1 == h2) && (m1 > m2)) {
            resp = 1440 - (m1 - m2);
        }
        else {
            resp = ((h2 * 60) + m2) - ((h1 * 60) + m1);
        }
        printf("%d minutos\n", resp);
    } while (1);
}
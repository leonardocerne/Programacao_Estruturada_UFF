#include <stdio.h>

typedef struct ponto{
    int x;
    int y;
}TPTO2D;

int dentroRet (TPTO2D *inf, TPTO2D *sup, TPTO2D *p){
    if(sup->x < inf->x) {
        if((p->x >= sup->x) && (p->x <= inf->x) && (p->y <= sup->y) && (p->y >= inf->x)) return 1;
        return 0;
    }
    else {
        if((p->x >= inf->x) && (p->x <= sup->x) && (p->y <= sup->y) && (p->y >= inf->x)) return 1;
        return 0;
    }
}

int main(void) {
    TPTO2D inf, sup, p;
    scanf("%d%d", &inf.x, &inf.y);
    scanf("%d%d", &sup.x, &sup.y);
    if(inf.y > sup.y){
        printf("Retangulo invalido");
    }
    else{
        scanf("%d%d", &p.x, &p.y);
        int x = dentroRet(&inf, &sup, &p);
        printf("%d", x);
    }
    return 0;
}
#include <stdio.h>


int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    if(a == b){
        printf("%d\n%d\n", a, b);
        printf("iguais\n");
    }else{
        if(a > b){
            printf("%d\n%d\n", a, b);
        }else{
            printf("%d\n%d\n", b, a);
        }
        printf("diferentes\n");
    }
    return 0;
}

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    if(n%3 == 0 && n%5 == 0){
        printf("%d é divisivel por 3 e 5\n", n);
    }else{
        printf("%d não é divisivel por 3 e 5\n", n);
    }
    

    return 0;
}

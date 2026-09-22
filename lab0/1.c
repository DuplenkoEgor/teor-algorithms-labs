// 1) Пошук заданого елемента в одновимірному масиві з n числових елементів.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    srand(time(NULL));
    int n;
    int target;
    
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter target: ");
    scanf("%d", &target);
    
    char mass[n];

    for(int i = 0; i < n + 1; i++){
        int random_int = rand() % 10;
        mass[i] = random_int;
    }

    printf("Array elemment: \n");
    for(int i = 0; i < n + 1; i++){
        // printf("%d) elem: %d\n", i, mass[i]);
        if(mass[i] == target){printf("Target %d found! Pos %d\n", target, i); break;}

        else{printf("%d) elem: %d\n", i, mass[i]);}
    }
    
    return 0;
}
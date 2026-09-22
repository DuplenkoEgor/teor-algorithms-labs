// Пошук мінімального (максимального) елемента в одновимірному масиві з n числових елементів.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    srand(time(NULL));
    
    int n;

    printf("Enter n:");
    scanf("%d", n);
    char mass[n];

    for(int i = 0; i < n + 1; i++){
        int random_int = rand() % 10;
        mass[i] = random_int;
    }

    int max = -1;
    int min = 1000;
    for(int i = 0; i < n + 1; i++){

        if(mass[i] > max){
            max = mass[i];
        }
        if(mass[i] < min){
            min = mass[i];
        }
    }
    
    for(int i = 0; i < n + 1; i++){
        printf("%d) elem: %d\n", i, mass[i]);
    }


    return 0;
}
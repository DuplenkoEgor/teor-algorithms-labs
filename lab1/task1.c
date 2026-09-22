// Варіант №17
// Створити стек n цілих чисел і знайти у ньому кількість двозначних чисел та їх суму, передбачивши 
// перегляд вже створеного попередньо стека.

#include <stdio.h>
#include <stdlib.h>


int isEmpty(int i) {
    return i == -1;
}

int isFull(int i, int n) {
    return i == n - 1;
}

int top(int stack[], int i){
    return stack[i];
}

void push(int stack[], int *i, int n, int number){
    if (isFull(*i, n)) {
        printf("Error: Stack overflow!");
        return;
    }
    *i += 1; 
    stack[*i] = number;
}

int pop(int stack[], int *i){
    if (isEmpty(*i)) {
        printf("Error: Stack is empty!");
        return -1;
    }
    
    int num = stack[*i];
    *i -= 1;
    return num;
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int stack[n];
    int i = -1;

    int supportStack[n];
    int supportI = -1;

    int sum = 0;
    int count = 0;
    
    for(int j = 0; j < n; j++) {
        int number;
        printf("Enter number: ");
        scanf("%d", &number);
        push(stack, &i, n, number); 
    }

    for(int j = 0; j < n; j++) {
        int num = pop(stack, &i);
        if(abs(num) >= 10 &&abs(num) <= 99) {
            count += 1;
            sum += num;
        }
        push(supportStack, &supportI, n, num);
    }

    printf("\n");
    for(int j = 0; j < n; j++) {
        int num = pop(supportStack, &supportI);
        push(stack, &i, n, num);
    }

    printf("Кількість двозначних чисел: %d\n", count);
    printf("Сума всіх двозначних чисел: %d\n", sum);

    return 0;
}
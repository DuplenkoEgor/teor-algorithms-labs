// Варіант №17
// Дана черга з n цілих чисел. Поміняти в черзі перший елемент з другим, третій з четвертим і так далі 
// до кінця черги, використавши додаткову чергу.

#include <stdio.h>

void push(int queue[], int n, int *rear, int number) {
    if (*rear == n - 1) {
        printf("Error: Queue overflow!\n");
        return;
    }
    *rear += 1;
    queue[*rear] = number;
}

int pop(int queue[], int *front, int rear) {
    if (*front > rear) {
        printf("Error: Queue is empty!\n");
        return -1;
    }
    int num = queue[*front]; 
    *front += 1;
    return num;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int queue[n];
    int supportQueue[n];

    int front = 0;
    int rear = -1;
    int supportFront = 0;
    int supportRear = -1;

    for (int i = 0; i < n; i++) {
        int number;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &number);
        push(queue, n, &rear, number);
    }

    while (front <= rear) {
        int first = pop(queue, &front, rear);

        if (front <= rear) {
            int second = pop(queue, &front, rear);

            push(supportQueue, n, &supportRear, second);
            push(supportQueue, n, &supportRear, first);
        } 
        else {
            push(supportQueue, n, &supportRear, first);
        }
    }

    printf("\n Result work:\n");
    while (supportFront <= supportRear) {
        int num = pop(supportQueue, &supportFront, supportRear);
        printf("%d ", num);
        // push(queue, n, &rear, num);
    }
    printf("\n");

    return 0;
}

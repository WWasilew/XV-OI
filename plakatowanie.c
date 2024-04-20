#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 250000 // maksymalny rozmiar stosu

typedef struct   // utworzenie struktury stosu i jego podstawowych funkcji
{
    int *array; // wartości na stosie
    int top;    // sskaźnik stosu
} Stack;

void initStack(Stack *stack)
{
    stack->array = (int *)malloc(STACK_MAX_SIZE * sizeof(int));
    stack->top = -1;
}

void push(Stack *stack, int value)
{
    stack->top++;
    stack->array[stack->top] = value;
}

void pop(Stack *stack)
{
    stack->top--;
}

int top(Stack *stack)
{
    return stack->array[stack->top];
}

int isEmpty(Stack *stack)
{
    if(stack->top==-1)
        return 0;
    return 1;
}

void freeStack(Stack *stack)
{
    free(stack->array);
}

int main()
{
    int n;          //liczba bloków
    scanf("%d", &n);

    int widths[n];  //szerokości bloków - niepotrzebne
    int heights[n]; //wysokości bloków

    for (int i = 0; i < n; ++i) //czytanie wartości
    {
        scanf("%d %d", &widths[i], &heights[i]);
    }

    Stack stack_of_buildings;  //stos przechowujący bloki
    initStack(&stack_of_buildings);
    int number_of_posters = 0;  //liczba potrzebnych plakatów

    for(int i = 0; i < n; ++i) //implementacja pseudoalgorytmu
    {
        while(!isEmpty(&stack_of_buildings) && heights[top(&stack_of_buildings)] > heights[i])
        {
            pop(&stack_of_buildings);
        }
        if(isEmpty(&stack_of_buildings) || heights[i] > heights[top(&stack_of_buildings)])
        {
            push(&stack_of_buildings, i);
            ++number_of_posters;
        }
    }

    printf("%d", number_of_posters);
    freeStack(&stack_of_buildings);

    return 0;
}
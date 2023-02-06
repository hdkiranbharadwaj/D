/*Develop a menu driven program to implement the following operations on an array of
integers with dynamic memory allocation.
i) Insert by position
ii) Delete by position
iii) Insert by key
iv) Delete by key
v) Insert by order
vi) Search by key
vii) Search by position
viii) Reverse the contents.*/

#include <stdio.h>
#include <stdlib.h>
int SIZE, N;
int *Read(int *);
void Display(int *);
int *Realloc(int *);
int *deletebykey(int *);

int *insertbypos(int *);
void deletebypos(int *);
int *insertbyorder(int *);
void sort(int *);
void searchbyposion(int *);
int searchbykey(int *);
int *reverse(int *);
void main()
{
    int *A, choice, index;
    system("clear");
    printf("Enter array size\n");
    scanf("%d", &SIZE);
    A = (int *)malloc(SIZE * sizeof(int));
    if (A == NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    for (;;)
    {
        printf("Enter choice\n 1.Read\n 2.Display\n 3.insertbypos\n 4.deletebypos\n 5.deletebykey\n 6.insertbyorder\n 7.search by key\n 8.search by position\n 9.reverse");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            A = Read(A);
            break;
        case 2:
            Display(A);
            break;
        case 3:
            A = insertbypos(A);
            Display(A);
            break;
        case 4:
            deletebypos(A);
            Display(A);
            break;

        case 5:
            deletebykey(A);
            Display(A);
            break;
        case 6:
            A = insertbyorder(A);
            Display(A);
            break;
        case 7:
            index = searchbykey(A);
            if (index == -1)
                printf("Not present\n");
            else
                printf("%d present at %d\n", A[index], index + 1);
            break;
        case 8:
            searchbyposition(A);
            break;
        case 9:
            A = reverse(A);
            Display(A);
            break;
        default:
            exit(0);
        }
    }
}
int *Read(int *p)
{
    int i;
    printf("Enter the value of N\n");
    scanf("%d", &N);
    if (N > SIZE)
    {
        p = Realloc(p);
    }
    printf("Enter the numbers\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", p + i);
    }
    return (p);
}
void Display(int *p)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d\n", *(p + i));
    }
}
int *deletebykey(int *p)
{
    int i, j, item;
    printf("Enter the item\n");
    scanf("%d", &item);
    for (i = 0; i < N; i++)
    {
        if (*(p + i) == item)
        {
            for (j = i; j < N - 1; j++)
            {
                *(p + j) = *(p + j + 1);
            }
        }
    }
    N--;
    return p;
}
int *Realloc(int *p)
{
    p = (int *)realloc(p, (SIZE * 2) * sizeof(int));
    if (p == NULL)
    {
        printf("Memory Full\n");
        exit(0);
    }
    return (p);
}

int *insertbypos(int *p)
{
    int i, pos, item;
    if (N == SIZE)
    {
        printf("Array Full\n");
        p = Realloc(p);
    }
L1:
    printf("Enter the position from 1 to %d\n", N + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > N + 1)
        goto L1;
    printf("Enter the item\n");
    scanf("%d", &item);
    for (i = N - 1; i >= pos - 1; i--)
    {
        *(p + i + 1) = *(p + i);
    }
    *(p + pos - 1) = item;
    N++;
    return (p);
}

void deletebypos(int *p)
{
    int i, pos;
    if (N == 0)
    {
        printf("Array Empty\n");
        return;
    }
L1:
    printf("Enter the position from 1 to %d\n", N);
    scanf("%d", &pos);
    if (pos < 1 || pos > N)
        goto L1;
    for (i = pos - 1; i < N; i++)
    {
        *(p + i) = *(p + i + 1);
    }
    N--;
}
int *insertbyorder(int *p)
{
    int i, item;
    if (N == SIZE)
        p = Realloc(p);
    printf("Enter the item\n");
    scanf("%d", &item);
    for (i = N - 1; i >= 0 && *(p + i) > item; i--)
        *(p + i + 1) = *(p + i);
    *(p + i + 1) = item;
    N++;
    return (p);
}
int searchbykey(int *p)
{
    if (N == 0)
        return -1;
    int i, item;
    printf("Enter item to be searched\n");
    scanf("%d", &item);
    for (i = 0; i <= N - 1; i++)
    {
        if (*(p + i) == item)
            return i;
    }
    return -1;
}
void searchbyposition(int *p)
{
    int pos;
L1:
    printf("Enter the position from 0 to %d", N - 1);
    scanf("%d", &pos);
    if (pos > 0 && pos < N)
    {
        printf("The element at that postion is %d", *(p + pos));
    }
    else
        goto L1;
}
void sort(int *p)
{
    int i, j, temp;
    for (j = 0; j < N - i - 1; j++)
    {
        if (*(p + j) > *(p + j + 1))
        {
            temp = *(p + j);
            *(p + j) = *(p + j + 1);
            *(p + j + 1) = temp;
        }
    }
}
int *reverse(int *p)
{
    int i, j, temp;
    for (i = 0; i < N / 2; i++)
    {
        temp = *(p + N - 1 - i);
        *(p + N - 1 - i) = *(p + i);
        *(p + i) = temp;
    }
    return p;
}

/*1a) Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and
average_ marks.
Develop a menu driven program to perform the following by writing separate function for each
operation: a) read information of N students b) display student’s information c) to calculate the
average of best two test marks of each student.
Note: Allocate memory dynamically and illustrate the use of pointer to an array of structure.*/
struct student
{
    int regno;
    char Name[20];
    int M[3];
    float avg;
};
typedef struct student STD;
void read(STD *);
void Disp(STD *);
void Avg(STD *);
int SIZE, N;

#include <stdio.h>
#include <stdlib.h>
void main()
{
    int choice;
    STD *p;
    printf("Enter the size\n");
    scanf("%d", &SIZE);
    p = (STD *)malloc(SIZE * sizeof(STD));
    for (;;)
    {
        printf("Enter the choice\n1:Read\n2:Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            read(p);
            break;
        case 2:
            Disp(p);
            break;
        default:
            exit(1);
        }
    }
}
void read(STD *s)
{
    int i, j;
    printf("Read N");
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        printf("Enter Regno,Name and 3 test marks of the student %d\n", (i + 1));
        scanf("%d%s", &(s + i)->regno, (s + i)->Name);
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &(s + i)->M[j]);
        }
    }
    Avg(s);
}

void Disp(STD *s)
{
    int i, j;

    printf("Regno\tName\tTest1\tTest2\tTest3\tAverage\n");
    printf("----------------------------------------------------------------------------------------\n");
    for (i = 0; i < N; i++)
    {
        printf("%d\t%s\t", (s + i)->regno, (s + i)->Name);
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", (s + i)->M[j]);
        }
        printf("%f\n", (s + i)->avg);
    }
}

void Avg(STD *s)
{
    int i, j, sum, min;
    for (i = 0; i < N; i++)
    {
        sum = min = (s + i)->M[0];
        for (j = 1; j < 3; j++)
        {
            sum = sum + (s + i)->M[j];
            if ((s + i)->M[j] < min)
            {
                min = (s + i)->M[j];
            }
        }
        (s + i)->avg = (sum - min) / 2.0;
    }
}
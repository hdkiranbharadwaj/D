/*1b) Define a structure called Time containing 3 integer members (Hour, Minute, Second).
Develop a menu driven program to perform the following by writing separate function for
each operation.
a) Read (T) :To read time b) Display (T):To display time c) update(T):To Update time d) Add
(T1, T2) : Add two time variables.
Update function increments the time by one second and returns the new time (if the increment
results in 60 seconds, then the second member is set to zero and minute member is incremented
by one.
If the result is 60 minutes, the minute member is set to zero and the hour member is
incremented by one.
Finally, when the hour becomes 24, Time should be reset to zero. While
adding two time variables, normalize the resultant time value as in the case of update function.
Note: Illustrate the use of pointer to pass time variable to different functions.*/

#include <stdio.h>
#include <stdlib.h>
struct time
{
    int H, M, S;
};
typedef struct time TIME;
void Read(TIME *);
void Display(TIME *);
void init(TIME *);
void normalise(TIME *T);
void Update(TIME *);
void Add(TIME *, TIME *, TIME *);
void main()
{
    TIME T1, T2, T3;
    int choice;
    init(&T1);
    init(&T2);
    init(&T3);
    for (;;)
    {
        printf("Enter choice\n 1.Read\n 2.Display\n 3.Update\n 4.Add\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter time 1");
            Read(&T1);
            printf("Enter time 2");
            Read(&T2);
            break;
        case 2:
            printf("TIME 1= \n");
            Display(&T1);
            printf("TIME 2= ");
            Display(&T2);
            break;
        case 3:
            Update(&T1);
            Display(&T1);
            break;
        case 4:
            Add(&T1, &T2, &T3);
            Display(&T3);
            break;
        default:
            exit(0);
        }
    }
}
void init(TIME *T)
{
    T->H = T->M = T->S = 0;
}
void Read(TIME *T)
{
    printf("\nEnter the hour, min and sec\n");
    scanf("%d%d%d", &T->H, &T->M, &T->S);
    normalise(T);
}
void Display(TIME *T)
{
    printf("%d:%d:%d\n", T->H, T->M, T->S);
}
void Update(TIME *T)
{
    T->S++;
    normalise(T);
}
void Add(TIME *T1, TIME *T2, TIME *T3)
{
    T3->H = T1->H + T2->H;
    T3->M = T1->M + T2->M;
    T3->S = T1->S + T2->S;
    normalise(T3);
}
void normalise(TIME *T)
{
    if (T->S >= 60)
    {
        T->M = T->M + (T->S / 60);
        T->S = T->S % 60;
    }
    if (T->M >= 60)
    {
        T->H = T->H + (T->M / 60);
        T->M = T->M % 60;
    }
    if (T->H >= 24)
    {
        init(T);
    }
}
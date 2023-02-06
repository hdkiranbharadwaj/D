/*12. Develop a menu driven program to implement the following types of Queues by allocating
memory dynamically.
i) Circular Queue
ii) Double ended Queue
iii) Priority Queue*/

// i)
#include <stdio.h>
#include <stdlib.h>
struct cQueue
{
    int *item;
    int F, R, cnt;
};
typedef struct cQueue cQUE;
int SIZE;
void Insert(cQUE *);
void Delete(cQUE *);
void Display(cQUE *);

void main()
{
    int choice;
    printf("Enter the size of the queue");

    scanf("%d", &SIZE);
    cQUE cQ;
    cQ.item = (int *)malloc(SIZE * sizeof(int));
    cQ.F = 0;
    cQ.R = -1;
    cQ.cnt = 0;
    for (;;)
    {

        printf("Enter your choice \n1.Insert\n2.Delete\n3.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert(&cQ);
            Display(&cQ);
            break;
        case 2:
            Delete(&cQ);
            Display(&cQ);
            break;
        case 3:
            Display(&cQ);
            break;
        default:
            exit(0);
        }
    }
}
void Insert(cQUE *PQ)
{
    int item;
    if (PQ->cnt == SIZE)
    {
        printf("Full");
        return;
    }
    printf("Enter the item\n");
    scanf("%d", &item);
    PQ->R = (PQ->R + 1) % SIZE;
    *(PQ->item + PQ->R) = item;
    PQ->cnt++;
}
void Delete(cQUE *PQ)
{
    if (PQ->cnt == 0)
    {
        printf("Empty\n");
        return;
    }
    printf("Deleted is %d", PQ->item[PQ->F]);
    PQ->F = (PQ->F + 1) % SIZE;
    PQ->cnt--;
    if (PQ->cnt == 0)
    {
        PQ->F = 0;
        PQ->R = -1;
    }
}

void Display(cQUE *Q)
{
    int i, j = Q->F;
    if (Q->cnt == 0)
    {
        printf("Empty\n");
        return;
    }
    printf("DATA IS\n");
    for (i = 1; i <= Q->cnt; i++)
    {
        printf("%d\n", *(Q->item + j));
        j = (j + 1) % SIZE;
    }
}

// ii)--------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
int SIZE;

struct Queue
{
    int *item;
    int F, R;
};

typedef struct Queue QUE;

void Insert(QUE *);
void Delete(QUE *);
void Display(QUE);
void InsertFront(QUE *);
void DeleteRear(QUE *);

void main()
{
    QUE Q;
    Q.F = 0;
    int choice;
    Q.R = -1;
    for (;;)
    {
        printf("Enter Your Choice \n1.Insert\n2.Delete\n3.Display\n4.InsertFront\n5.DeleteRear");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert(&Q), Display(Q);
            break;
        case 2:
            Delete(&Q), Display(Q);
            break;
        case 3:
            Display(Q);
            break;
        case 4:
            InsertFront(&Q);
            Display(Q);
            break;
        case 5:
            DeleteRear(&Q);
            Display(Q);
            break;
        default:
            exit(0);
        }
    }
}

void Insert(QUE *PQ)
{
    int item;
    if (PQ->R == SIZE - 1)
    {
        printf("Full\n");
        return;
    }
    printf("Enter The Item : ");
    scanf("%d", &item);

    PQ->R++;
    PQ->item[PQ->R] = item;
}

void Delete(QUE *PQ)
{
    if (PQ->F > PQ->R)
    {
        printf("Empty \n");
    }
    printf("Deleted is %d\n", PQ->item[PQ->F]);
    PQ->F++;

    if (PQ->F > PQ->R)
    {
        PQ->F = 0;
        PQ->R = -1;
    }
}

void Display(QUE Q)
{
    if (Q.F > Q.R)
    {
        printf("Empty ");
        return;
    }
    while (Q.F <= Q.R)
        printf("%d\t", Q.item[Q.F++]);
}
void InsertFront(QUE *PQ)
{

    int items;
    if (PQ->R == SIZE - 1)
    {
        printf("Full\n");
        return;
    }
    printf("Enter The Item : ");
    scanf("%d", &items);
    if (PQ->F == 0 && PQ->R == -1)

        PQ->item[++PQ->R] = items;
    else if (PQ->F != 0)
        PQ->item[--PQ->F] = items;
    else
        printf("Front Insertion Not POssible ..");
}

void DeleteRear(QUE *PQ)
{
    if (PQ->F > PQ->R)
    {
        printf("Empty \n");
        return;
    }
    printf("Deleted is %d", PQ->item[PQ->R]);
    PQ->R--;
    if (PQ->F > PQ->R)
    {
        PQ->F = 0;
        PQ->R = -1;
    }
}

// iii)------------------------------------------------------------------------------------------------------------
#include <stdio.h>
int SIZE;
struct Queue
{
    int *items;
    int f, r;
};

typedef struct Queue QUE;
void Insert(QUE *);
void Delete(QUE *);
void Disp(QUE *);

void main()
{
    int ch;
    QUE Q;
    Q.f = 0;
    Q.r = -1;
    clrscr();
    for (;;)
    {
        printf("enter choice:\n1:Insert\n2:Delete\n3:Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Insert(&Q);
            Disp(&Q);
            break;
        case 2:
            Delete(&Q);
            Disp(&Q);
            break;
        case 3:
            Disp(&Q);
            break;
        default:
            exit(0);
        }
    }
}
void Insert(QUE *Q) // Inserting in Ascending order
{
    int item, j;
    if (Q->r == size - 1)
    {
        printf("Queue Full\n");
        return;
    }
    printf("enter item:");
    scanf("%d", &item);
    // Q->r++;
    j = Q->r;
    while (j >= 0 && *(Q->items + j) > item)
    {

        *(Q->items + j + 1) = *(Q->items + j);
        j--;
    }

    *(Q->items + j + 1) = item;
    Q->r++;
}
void Delete(QUE *Q) // Deleting front item which has the highest priority
{
    if (Q->f > Q->r)
    {
        printf("Queu Empty\n");
        return;
    }
    printf("deleted:%d\n", Q->items[Q->f++]);
    if (Q->f > Q->r)
    {
        Q->f = 0;
        Q->r = -1;
    }
} //       30  40  50   f = 2  r = 4  f = 0

void Disp(QUE *Q)
{
    int i;
    if (Q->f > Q->r)
    {
        printf("Queu Empty\n");
        return;
    }
    for (i = Q->f; i <= Q->r; i++)

        printf("%d  ", Q->items[i]);
}
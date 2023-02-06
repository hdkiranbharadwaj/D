/*Implement circular double linked list to perform the following operations
i) Insert by order
ii ) Delete by key
iii) Search by position
Display the list contents after each operation*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *RL;
    struct node *LL;
};
typedef struct node *NODE;
void insertbyorder(NODE ph)
{
    NODE NN = createnode();
    NODE TP = ph->RL;
    printf("Enter");
    scanf("%d", &NN->info);
    if (ph->info == 0)
    {
    }
    while (TP != ph && TP->info < NN->info)
    {
        TP = TP->RL;
    }
    NN->LL = TP->LL;
    NN->RL = TP;
    TP->LL->RL = NN;
    TP->LL = NN;
    ph->info++;
}
void deletebykey(NODE PH, int key)
{
    NODE TP = PH->RL;
    NODE ND;
    int f = 0;
    while (TP != PH)
    {
        if (TP->info == key)
        {
            ND = TP;
            TP->LL->RL = TP->RL;
            TP->RL->LL = TP->LL;
            free(ND);
            f = 1;
            break;
        }
        TP = TP->RL;
    }
    if (f == 0)
    {
        prinf("Element not found");
    }
}

// for search by position just validate the position and traverse till it

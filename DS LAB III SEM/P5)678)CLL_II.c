/*5. Implement circular single linked list to perform the following operations
i) Insert front
ii) Insert rear
iii) Delete a node with the given key
iv) Search for an item by position
Display the list contents after each operation

7. Implement circular single linked list to perform the following operations
i) Insert by position
ii) Delete rear
iii) Delete Front
iv) Search for an item by value
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
void insertfront(NODE PH)
{
    NODE NN;
    NN = createnode();
    printf("Enter the data\n");
    scanf("%d", &NN->info);
    NN->LL = PH;
    NN->RL = PH->RL;
    PH->RL = NN;
    NN->RL->LL = NN;
    PH->info++;
}
void insertrear(NODE PH)
{
    NODE NN = createnode();
    printf("Enter the data\n");
    scanf("%d", &NN->info);
    NN->LL = PH->LL;
    NN->RL = PH;
    NN->LL->RL = NN;
    NN->RL->LL = NN;
    PH->info++;
}
void insertbypos(NODE PH)
{
    NODE NN, TP;
    int pos, cnt = 1;
    NN = createnode();
    printf("Enter the data\n");
    scanf("%d", &NN->info);
L1:
    printf("Enter position between 1 to %d", (PH->info + 1));
    scanf("%d", &pos);
    if (pos < 1 || pos > PH->info + 1)
        goto L1;
    TP = PH->RL;

    while (cnt != pos)
    {
        TP = TP->RL;
        cnt++;
    }
    NN->LL = TP->LL;
    NN->RL = TP;
    NN->LL->RL = NN;
    TP->LL = NN;
    PH->info++;
}
void deleterear(NODE PH)
{
    if (PH->info == 0)
    {
        printf("Empty");
        return;
    }
    NODE LN = PH->LL;
    PH->LL = LN->LL;
    LN->LL->RL = PH;
    printf("Deleted info is %d \n", LN->info);
    free(LN);
    PH->info--;
}
void deletefront(NODE PH)
{
    NODE FN;
    if (PH->info == 0)
    {
        printf("Empty\n");
        return;
    }
    FN = PH->RL;
    PH->RL = FN->RL;
    FN->RL->LL = PH;
    printf("Deleted info is %d\n", FN->info);
    free(FN);
    PH->info--;
}
NODE searchbykey(NODE PH)
{
    if (PH->info == 0)
    {
        return NULL;
    }
    int key;
    printf("Enter key");
    scanf("%d", &key);
    NODE TP = PH->RL;
    while (TP != PH)
    {
        if (TP->info == key)
        {
            return (TP);
        }
        TP = TP->RL;
    }
    return NULL;
}
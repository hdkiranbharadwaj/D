/*3. Implement circular single linked list to perform the following operations
i) Insert by order ii ) Delete by position iii) Search for an item by key
Display the list contents after each operation*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *link;
};
typedef struct node *NODE;
void insertbyorder(NODE);
void deletebypos(NODE);
void searchbykey(NODE);
void Display(NODE);
NODE createnode();
void main()
{
    NODE Head = createnode();
    Head->link = Head;
    int ch;
    for (;;)
    {
        printf("Enter the choice\n1ins\n2del\n3sea");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertbyorder(Head);
            Display(Head);
            break;
        case 2:
            deletebypos(Head);
            Display(Head);
            break;
        case 3:
            searchbykey(Head);
            Display(Head);
            break;
        default:
            exit(1);
        }
    }
}
NODE createnode()
{
    return ((NODE)malloc(sizeof(struct node)));
}
void insertbyorder(NODE p)
{
    NODE h = p;
    p = p->link;
    int it;
    NODE pn = h;
    printf("Enter the number");
    scanf("%d", &it);
    while ((p != h) && (p->item < it))
    {
        pn = p;
        p = p->link;
    }
    NODE NN = createnode();
    NN->link = p;
    pn->link = NN;
    NN->item = it;
}
void deletebypos(NODE p)
{
    int i = 0, pos;
    NODE pn = p;
    printf("Enter the number");
    scanf("%d", &pos);
    while (i != pos)
    {
        pn = p;
        p = p->link;
        i++;
    }
    pn->link = p->link;
    free(p);
}
void searchbykey(NODE p)
{
    NODE h = p;
    int it;
    NODE pn = h;
    p = p->link;
    printf("Enter the number");
    scanf("%d", &it);
    while ((p != h) && (p->item != it))
    {
        p = p->link;
    }
    if (p == h)
    {
        printf("Not found");
    }
    else
    {
        printf("%d", p->item);
    }
}
void Display(NODE p)
{
    NODE h = p;
    do
    {
        p = p->link;
        printf("%d\n", p->item);
    } while (p->link != h);
}
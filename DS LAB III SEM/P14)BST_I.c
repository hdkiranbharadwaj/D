/*14. Develop a menu driven program to implement Binary Search tree with the following
operations.
i) Construction
ii) Traversals ( Pre, In and Post Order)
iii) Searching a node by key and displaying its information along with its parent is exists, otherwise a suitable message.
iv) Counting all types of nodes.
v) Finding height*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE Construct(NODE R)
{
    NODE pn, nn, tp;
    int ch;
    for (;;)
    {
        printf("Enetr the or -1");
        scanf("%d", &ch);
        if (ch == -1)
            break;
        nn = createnode();
        nn->info = ch;
        nn->llink = nn->rlink = NULL;
        if (R == NULL)
            return nn;
        tp = R;
        while (tp != NULL)
        {
            pn = tp;
            if (tp->info < nn->info)
            {
                tp = tp->rlink;
            }
            else
                tp = tp->llink;
        }
        if (nn->info < pn->info)
            pn->llink = nn;
        else
            pn->rlink = nn;
    }
    return R;
}
void Preorder(NODE R)
{
    if (R == NULL)
        return;
    printf("%d", R->info);
    Preorder(R->llink);
    Preorder(R->rlink);
}
void Postorder(NODE R)
{
    if (R == NULL)
        return;
    Postorder(R->llink);
    Postorder(R->rlink);
    printf("%d", R->info);
}
void Inorder(NODE R)
{
    if (R == NULL)
        return;
    Inorder(R->llink);
    printf("%d", R->info);
    Inorder(R->rlink);
}
NODE Search(NODE R, int key)
{
    NODE SN = NULL;
    if (R == NULL)
        return NULL;
    if (R->info == key)
        SN = R;
    if (SN == NULL)
    {
        if (key < R->info)
            SN = Search(R->llink, key);
        else
            SN = Search(R->rlink, key);
    }
    return SN;
}
int CountLeafNode(NODE R)
{

    if (R == NULL)
    {
        return 0;
    }
    int count = 0;
    if (R->rlink == NULL && R->llink == NULL)
    {
        count++;
    }
    count = count + CountLeafNode(R->llink);
    count = count + CountLeafNode(R->rlink);
    return count;
}
int Count(NODE R)
{
    if (R == NULL)
        return 0;
    int count = 0;
    count++;
    count = count + Count(R->rlink);
    count = count + Count(R->llink);
    return count;
}
int Height(NODE R)
{
    if (R == NULL)
    {
        return -1;
    }
    return (1 + Max(Height(R->llink), Height(R->rlink)));
}
int Max(int a, int b)
{
    return a > b ? a : b;
}
int NonLeafNode(NODE R)
{
    return (Count(R) - CountLeafNode(R));
}
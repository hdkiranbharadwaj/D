/*Develop a menu driven program to implement Binary Search tree with the following
operations.
i) Construction
ii) Traversals( Pre, In and Post Order)
iii) Searching a node by key
iv) deleting if exists ( node to be deleted may be leaf or non- leaf with one child or two children)*/
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
NODE Delete(NODE R, int key)
{
    if (R == NULL)
        return R;

    if (key < R->info)
        R->llink = Delete(R->llink, key);
    else if (key > R->info)
        R->rlink = Delete(R->rlink, key);
    else
    {
        if (R->llink == NULL)
        {
            NODE temp = R->rlink;
            free(R);
            return temp;
        }
        else if (R->rlink == NULL)
        {
            NODE temp = R->llink;
            free(R);
            return (temp);
        }
        NODE temp = Min(R->rlink);
        R->info = temp->info;
        R->rlink = Delete(R->rlink, temp->info);
    }
    return R;
}
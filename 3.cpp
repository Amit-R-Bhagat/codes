// Practical 3

#include<stdio.h>
#include<conio.h>
struct node
{	
    int x, y;
    struct node *next;
}*root, *left, *right;

void main()
{
    int jug1, jug2, f1, f2;
    printf("Capacity of jug1 : ");
    scanf("%d", &jug1);
    printf("Capacity of jug2 : ");
    scanf("%d", &jug2);
    printf("Required water in jug1 : ");
    scanf("%d", &f1);
    printf("Required water in jug2 : ");
    scanf("%d", &f2);
    generateTree(jug1, jug2, f1, f2);
    DFS();
    getch();
}

int isNodePresent(struct node *next, int jug1, int jug2, int f1, int f2)
{
    struct node *temp;
    if((next->x == f1) && (next->y == f2)){
        return(0);
    }
    if((next->x == jug1) && (next->y == jug2)){
        return(1);
    }
    if((next->x == 0) && (next->y == 0)){
        return(1);
    }
    temp = left;
    while(1)
    {
        if((temp->x == next->x) && (temp->y == next->y)){
            return(1);
        }
        else if(temp->next == NULL){
            break;
        } else {
            temp = temp->next;
        }
    }
    temp = right;
    while(1)
    {
        if((temp->x == next->x) && (temp->y == next->y)){
            return(1);
        } else if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }
    return(0);
}

void DFS()
{
    struct node *temp;
    temp = left;
    printf("Start State : (%d,%d)\n", root->x, root->y);
    printf("Solution : \n");
    while(1)
    {
        printf("(%d,%d)\n", temp->x, temp->y);
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }
    temp = right;
}


struct node* genNewState(struct node *current, int jug1, int jug2, int f1, int f2)
{
    int d;
    struct node *next;
    next = (struct node*)malloc(sizeof(struct node));
    next->x = jug1;
    next->y = current->y;
    if(isNodePresent(next, jug1, jug2, f1, f2) != 1){
        return(next);
    }
    next->x = current->x;
    next->y = jug2;
    if(isNodePresent(next, jug1, jug2, f1, f2) != 1){
        return(next);
    }
    next->x = 0;
    next->y = current->y;
    if(isNodePresent(next, jug1, jug2, f1, f2) != 1){
        return(next);
    }
    next->y = 0;
    next->x = current->x;
    if(isNodePresent(next, jug1, jug2, f1, f2) != 1){
        return(next);
    }
    if((current->y < jug2) && (current->x != 0))
    {
        d = jug2 - current->y;
        if(d >= current->x)
        {
            next->x = 0;
            next->y = current->y + current->x;
        } else {
            next->x = current->x - d;
            next->y = current->y + d;
        }
        if(isNodePresent(next, jug1, jug2, f1, f2) != 1){
            return(next);
        }
    }
    if((current->x < jug1) && (current->y != 0))
    {
        d = jug1 - current->x;
        if(d >= current->y) {
            next->y = 0;
            next->x = current->x + current->y;
        } else {
            next->y = current->y - d;
            next->x = current->x + d;
        }
        if(isNodePresent(next, jug1, jug2, f1, f2) != 1){
            return(next);
        }
    }
    return(NULL);
}

void generateTree(int jug1, int jug2, int f1, int f2)
{
    int flag1, flag2;
    struct node *tempLeft, *tempRight;
    root  = (struct node*)malloc(sizeof(struct node));
    root->x = 0; root->y = 0; root->next = NULL;
    left = (struct node*)malloc(sizeof(struct node));
    left->x = 0; left->y = jug2; left->next = NULL;
    right = (struct node*)malloc(sizeof(struct node));
    right->x = jug1; right->y = 0; right->next = NULL;
    tempLeft = left;
    tempRight = right;
    while(1)
    {
        flag1 = 0; flag2 = 0;
        if((tempLeft->x != f1) || (tempLeft->y != f2))
        {
            tempLeft->next = genNewState(tempLeft, jug1, jug2, f1, f2);
            tempLeft = tempLeft->next;
            tempLeft->next = NULL;
            flag1 = 1;
        }
        if((tempRight->x != f1) || (tempRight->y != f2))
        {
            tempRight->next = genNewState(tempRight, jug1, jug2, f1, f2);
            tempRight = tempRight->next;
            tempRight->next = NULL;
            flag2 = 1;
        }
        if((flag1 == 0) && (flag2 == 0))
            break;
    }
}

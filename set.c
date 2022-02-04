#include <stdio.h>
#include <stdlib.h>


struct node {
  int data;
  struct node *next;
} *LLOne, *LLTwo, *unionLL, *intersectionLL;

void initialize()
{
    LLOne = LLTwo = NULL;
}
void insert(struct node **head, int num) {

    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;

    newNode->next = *head;

    *head = newNode;
}


int search(struct node *head, int num) {
    while (head != NULL) {
        if (head->data == num){
            return 1;
        }
        head = head->next;
    }
    return 0;
}


struct node* findunion(struct node *LLOne, struct node *LLTwo) {
    unionLL = NULL;

    struct node *temp = LLOne;
    while(temp != NULL){
        insert(&unionLL, temp->data);
        temp = temp->next;
    }

    while(LLTwo != NULL){
        if(!search(LLOne, LLTwo->data)){
            insert(&unionLL, LLTwo->data);
        }
        LLTwo = LLTwo->next;
    }
    return unionLL;
}

struct node* intersection(struct node *LLOne, struct node *LLTwo) {
    intersectionLL = NULL;

    while(LLOne != NULL){
        if(search(LLTwo, LLOne->data)){
            insert(&intersectionLL, LLOne->data);
        }
        LLOne = LLOne->next;
    }
    return intersectionLL;
}

void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}

int main() {
    int i, LLOneCount, LLTwoCount, temp;
    initialize();

    printf("Enter number of nodes in first Linked List\n");
    scanf("%d", &LLOneCount);
    printf("Enter %d integers\n", LLOneCount);
    for(i=0; i<LLOneCount; i++){
        scanf("%d", &temp);
        insert(&LLOne, temp);
    }
    printLinkedList(LLOne);
    printf("\nEnter number of nodes in second Linked List\n");
    scanf("%d", &LLTwoCount);
    printf("Enter %d integers\n", LLTwoCount);
    for(i=0; i<LLTwoCount; i++){
        scanf("%d", &temp);
        insert(&LLTwo, temp);
    }
    printLinkedList(LLTwo);

    findunion(LLOne, LLTwo);
    intersection(LLOne, LLTwo);
    printf("\nUnion Linked List\n");
    printLinkedList(unionLL);
    printf("\nIntersection Linked List\n");
    printLinkedList(intersectionLL);

    return 0;
}

#include<stdio.h>
typedef struct node Node;
struct node{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error!, Could not create new node!\n");
        return;
    }
    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *search_node(Node *head, int item)
{
    Node *current_node = head;
    while(current_node != NULL){
        if(current_node->data == item){
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

Node *prepend(int item, Node *head)
{
    Node *new_node = create_node(item, head);
    return new_node;
}

int main()
{
    Node *n1,*n2,*n3,n4,*head;
    n1 = create_node(10, NULL);
    head = n1;
    head = prepend(20, head);
    n2 = head;
    printf("First data = %d\n", n2->data);
    n3 = n2->next;
    printf("Second data = %d\n", n3->data);

    search_node(head, 50)?printf("Yes\n"): printf("No\n");
    return 0;
}

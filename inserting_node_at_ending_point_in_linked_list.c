#include<stdio.h>
typedef struct node Node;
struct node{
    int data;
    Node *next;
};
Node *create_node(int item, Node *next)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error! Could not create new node\n");

        return;
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}
Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    if(head == NULL){
        return new_node;
    }
    Node *current_node = head;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    while(current_node != NULL){
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int count(Node *head)
{
    Node *current_node = head;
    int counter = 0;
    while(current_node != NULL){
        counter++;
        current_node = current_node->next;
    }
    return counter;
}
int main()
{
    Node *n1, *head;
    n1 = create_node(10, NULL);
    head = n1;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = prepend(head, 30);
    print_linked_list(head);

    printf("Node present in list: %d \n", count(head));
    return 0;
}

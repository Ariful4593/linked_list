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
        printf("Error! Could Not Create A New Node\n");
        exit(1);
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

Node *remove_node(Node *head, Node *node)
{
    if(node == head){
        head = node->next;
        free(node);

        return head;
    }
    Node *current_node = head;
    while(current_node != NULL){
        if(current_node->next == node){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node == NULL){
        return head;
    }
    current_node->next = node->next;
    free(node);

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
int main()
{
    Node *n1, *n2, *n3, *head;
    n1 = create_node(10, NULL);

    head = n1;
    print_linked_list(head);
    head = prepend(head, 20);
    print_linked_list(head);

    head = prepend(head, 30);
    print_linked_list(head);

    head = remove_node(head, n1);
    print_linked_list(head);

    n2 = head;
    head = remove_node(head, n2);
    print_linked_list(head);

    return 0;
}
/*
    Sample Output:
    10
    20 10
    30 20 10
    30 20
    20
*/

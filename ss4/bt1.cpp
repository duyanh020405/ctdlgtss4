#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* append(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void printReverse(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Hàm chính
int main() {
    Node* head = NULL;
    head = append(head, 1);
    head = append(head, 3);
    head = append(head, 5);
    head = append(head, 7);
    printf("Danh sach nguoc l?i:\n");
    printReverse(head);
    Node* head2 = NULL;
    head2 = append(head2, 10);
    head2 = append(head2, 20);
    printf("Danh sach nguoc l?i:\n");
    printReverse(head2);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
// Define the structure of a node for a doubly linked list
struct node {
int data;
struct node *prev;
struct node *next;
};
// Function to create a doubly linked list
struct node* createDoublyLinkedList(int n) {
struct node *head = NULL, *temp = NULL, *newNode = NULL;
int value, i;
for (i = 1; i <= n; i++) {
newNode = (struct node*)malloc(sizeof(struct node));
if (newNode == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
printf("Enter value for node %d: ", i);
scanf("%d", &value);
newNode->data = value;
newNode->prev = NULL;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
} else {
temp->next = newNode;
newNode->prev = temp;
}
temp = newNode;
}
return head;
}
// Function to traverse and print the doubly linked list
void traverseDoublyLinkedList(struct node *head) {
struct node *temp = head;
printf("Doubly Linked List: ");
while (temp != NULL) {
printf("%d <-> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
// Insert before a given value
struct node* insertBeforeValue(struct node *head, int target, int newValue) {
struct node *temp = head;
struct node *newNode;
while (temp != NULL && temp->data != target) {
temp = temp->next;
}

if (temp == NULL) {
printf("Value %d not found in the list.\n", target);
return head;
}
newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = newValue;
newNode->prev = temp->prev;
newNode->next = temp;
if (temp->prev != NULL) {
temp->prev->next = newNode;
} else {
head = newNode; // If inserting before the head
}
temp->prev = newNode;
printf("Inserted %d before %d successfully.\n", newValue, target);
return head;
}
// Delete node by position
struct node* deleteByPosition(struct node *head, int position) {
struct node *temp = head;
int i;
if (head == NULL) {
printf("List is empty.\n");
return head;
}
if (position == 1) {
head = head->next;
if (head != NULL) head->prev = NULL;
free(temp);
printf("Node at position 1 deleted.\n");
return head;
}
for (i = 1; temp != NULL && i < position; i++) {
temp = temp->next;
}
if (temp == NULL) {
printf("Position %d not found in the list.\n", position);
return head;
}
if (temp->next != NULL) {
temp->next->prev = temp->prev;
}
if (temp->prev != NULL) {
temp->prev->next = temp->next;
}
free(temp);
printf("Node at position %d deleted.\n", position);
return head;
}

int main() {
struct node *head = NULL;
int n, key, newValue, pos;
printf("Enter the number of nodes: ");
scanf("%d", &n);
head = createDoublyLinkedList(n);
traverseDoublyLinkedList(head);
// Insert before value
printf("\nEnter value before which you want to insert: ");
scanf("%d", &key);
printf("Enter new value to insert: ");
scanf("%d", &newValue);
head = insertBeforeValue(head, key, newValue);
traverseDoublyLinkedList(head);
// Delete by position
printf("\nEnter position to delete: ");
scanf("%d", &pos);
head = deleteByPosition(head, pos);
traverseDoublyLinkedList(head);
return 0;
}









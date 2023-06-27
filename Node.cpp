#include <bits/stdc++.h>
#include <string>
#include "Node.h"
using namespace std;
void push(Node** head_ref, int new_data) //**  nghigx là 1 con  trỏ trỏ đến 1 con trỏ khác // thêm node vào đầu ds 
{
    // Allocate node
    Node* new_node = new Node();
 
    // Put in the data
    new_node->data = new_data;
 
    // đặt con trỏ next của nút mới thành đầu danh sách 
    //hiện tại và con trỏ prev của nó thành NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    // Nếu danh sách không trống, nó đặt con trỏ prev 
    //của đầu danh sách hiện tại thành nút mới
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // Cập nhật đầu danh sách để trỏ đến nút mới.
    (*head_ref) = new_node;
}

void insertBefore(Node* next_node, int new_data) // thêm node vào trước một node khác trong ds 
{
    // Check if the given next_node is NULL
    if (next_node == NULL) {
        printf("the given next node cannot be NULL");
        return;
    }
 
    // 1. Allocate new node
    Node* new_node = new Node();
 
    // 2. Put in the data
    new_node->data = new_data;
 
    // 3. Make previous of new node as previous of next_node
    new_node->prev = next_node->prev;
 
    // 4. Make the previous of next_node as new_node
    next_node->prev = new_node;
 
    // 5. Make next_node as next of new_node
    new_node->next = next_node;
 
    // 6. Change next of new_node's previous node
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        head = new_node;
}

void insertAfter(Node* prev_node, int new_data) // thêm node vào sau một node khác trong ds 
{
    // Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }
 
    // 1. allocate new node
    Node* new_node = new Node();
 
    // 2. put in the data
    new_node->data = new_data;
 
    // 3. Make next of new node as next of prev_node
    new_node->next = prev_node->next;
 
    // 4. Make the next of prev_node as new_node
    prev_node->next = new_node;
 
    // 5. Make prev_node as previous of new_node
    new_node->prev = prev_node;
 
    // 6. Change previous of new_node's next node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(Node** head_ref, int new_data) // thêm node vào cuối ds 
{
    // 1. allocate node
    Node* new_node = new Node();
 
    Node* last = *head_ref; /* used in step 5*/
 
    // 2. put in the data
    new_node->data = new_data;
 
    // 3. This new node is going to be the last node, so
    // make next of it as NULL
    new_node->next = NULL;
 
    // 4. If the Linked List is empty, then make the new
    // node as head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    // 5. Else traverse till the last node
    while (last->next != NULL)
        last = last->next;
 
    // 6. Change the next of last node
    last->next = new_node;
 
    // 7. Make last node as previous of new node
    new_node->prev = last;
 
    return;
}


void deleteNode(Node** head_ref, Node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    /* Change next only if node to be 
    deleted is NOT the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be 
    deleted is NOT the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    /* Finally, free the memory occupied by del*/
    free(del); 
    return; 
} 
// Function to traverse the Doubly LL
// in the forward & backward direction
void printList(Node* node)
{
    Node* last;
 
    cout << "\nTraversal in forward"
         << " direction \n";
    while (node != NULL) {
 
        
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
 
    cout << "\nTraversal in reverse"
         << " direction \n";
    while (last != NULL) {
 
        // Print the data
        cout << " " << last->data << " ";
        last = last->prev;
    }
}
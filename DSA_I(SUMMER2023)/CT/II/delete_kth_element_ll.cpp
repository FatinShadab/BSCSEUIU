#include <bits/stdc++.h>
using namespace std;

/*
    Delete at Kth position from the start of
    a single linked list

    input : 3 -> 8 -> 2 -> 21 -> 9 -> 11
            2

    output : 3 -> 2 -> 21 -> 9 -> 11
*/


class Node{
    public:
        int data;
        Node* next;
    
        Node(){}

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        Node(int data, Node* next) : Node(data) {
            this->next = next;
        }
};


void printArray(Node* &head){
    printf("The Single Linked List : ");

    Node* temp = head;

    while (temp){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return;
}

void delete_kth_node(Node* &head, int k){
    int pos = 1;
    Node* temp = head;

    if (temp == NULL) return;
    
    if (pos == k){
        head = head->next;
        free(temp);
        return;
    }

    Node* prev_temp;

    while(temp != NULL && pos < k){
        prev_temp = temp;
        temp = temp->next;
        pos++;
    }

    if (temp == NULL){
        return;
    }

    prev_temp->next = temp->next;
    free(temp);

    return;
}

int main(){
    int k;

    Node* n5 = new Node(11);
    Node* n4 = new Node(9, n5);
    Node* n3 = new Node(21, n4);
    Node* n2 = new Node(2, n3);
    Node* n1 = new Node(8, n2);
    Node* head = new Node(3, n1);

    printf("Enter the k'th position : ");
    scanf("%d", &k);

    printf("Before deletion :\n\t");
    printArray(head);

    delete_kth_node(head, k);

    printf("After deletion:\n\t");
    printArray(head);

    return 0;
}
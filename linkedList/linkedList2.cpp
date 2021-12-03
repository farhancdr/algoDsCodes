#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
void insert_at_beginning(Node* head, int v)
{
        Node *temp = new Node();
        temp->data = v;
        temp->next = head;
        head = temp;
}
void printLinkedList(Node* head){
    
}
int main(){

    Node* head = NULL;

    insert_at_beginning(head,4);
    insert_at_beginning(head,5);
    insert_at_beginning(head,6);
    insert_at_beginning(head,7);

}
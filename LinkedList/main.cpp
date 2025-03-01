#include <iostream>
#include <string>
using namespace std;

/*
If a function returns a static object, a temporary copy of the static object
is created and passed back from the function. Since the static object will be
destroyed soon, a more efficient approach is to define move operations to
transfer the data from the static object to the temporary copy. Thus, a
modern practice since C++11 recommends the rule of five. The five member
functions to be defined together are: destructor, copy constructor, copy
assignment operator, move constructor, and move assignment operator. While
the rule of three is a rule to ensure that classes with dynamically allocated
data are handled correctly, the rule of five is primarily a rule for handling
such data efficiently.
 */


class LinkedList {
    public:
        LinkedList(int num = 0, LinkedList* next = nullptr, LinkedList* previous = nullptr);
        void InsertAfter (LinkedList* node);
        void InsertBefore (LinkedList* node);
        LinkedList* GetNext();
        LinkedList* GetPrevious();
        void PrintNodeData();
    private:
        LinkedList* nextNode;
        LinkedList* previousNode;
        int value;
        void SetNextNode(LinkedList* node);
        void SetPreviousNode(LinkedList* node);
};

LinkedList::LinkedList(int num, LinkedList* next, LinkedList* previous) {
    value = num;
    nextNode = next;
    previousNode = previous;
}

void LinkedList::InsertAfter(LinkedList* node) {
    if (nextNode != nullptr) {
        nextNode->SetPreviousNode(node);
    }
    node->SetNextNode(nextNode);
    node->SetPreviousNode(this);
    SetNextNode(node);
}

void LinkedList::InsertBefore(LinkedList* node) {
    node->SetNextNode(this);
    node->SetPreviousNode(previousNode);
    previousNode->SetNextNode(node);
    previousNode = node;
}

void LinkedList::PrintNodeData() {
    cout << value << endl;
}

LinkedList* LinkedList::GetNext() {
    return nextNode;
}

LinkedList* LinkedList::GetPrevious() {
    return previousNode;
}

void LinkedList::SetNextNode(LinkedList* node) {
    nextNode = node;
}

void LinkedList::SetPreviousNode(LinkedList* node) {
    previousNode = node;
}

int main (){
    LinkedList* headObj  = nullptr; // Create IntNode pointers
    LinkedList* nodeObj1 = nullptr;
    LinkedList* nodeObj2 = nullptr;
    LinkedList* nodeObj3 = nullptr;
    LinkedList* nodeObj4 = nullptr;
    LinkedList* currObj  = nullptr;

    // Front of nodes list
    headObj = new LinkedList(-1);

    // Insert nodes
    nodeObj1 = new LinkedList(555);
    headObj->InsertAfter(nodeObj1);

    nodeObj2 = new LinkedList(999);
    nodeObj1->InsertAfter(nodeObj2);

    nodeObj3 = new LinkedList(777);
    nodeObj2->InsertAfter(nodeObj3);

    nodeObj4 = new LinkedList(222);
    nodeObj3->InsertBefore(nodeObj4);

    currObj = headObj;
    while (currObj != nullptr) {
        currObj->PrintNodeData();
        currObj = currObj->GetNext();
    }
};
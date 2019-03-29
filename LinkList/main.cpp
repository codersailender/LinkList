//
//  main.cpp
//  LinkList
//
//  Created by Sailender Singh on 28/03/19.
//  Copyright © 2019 Sailender Singh. All rights reserved.
//

#include <iostream>

using namespace std;

class LinkList {
    struct Node {
        int key;
        struct Node* next;
        Node() {
            key = 0;
            next = NULL;
        }
    };
    
    int LLLength = 0;
    struct Node* root = NULL;
    
    Node* getNode(int key) {
        struct Node* node = new Node();
        node->key = key;
        return node;
    }
    
    struct Node* sortedList = NULL;
    void insertInSortedList(int item) {
        if (sortedList == NULL) {
            sortedList = getNode(item);
        } else {
            Node* prev = NULL;
            Node* current = sortedList;
            bool isAdded = false;
            while (current != NULL) {
                if (current -> key >= item) {
                    Node* node = getNode(item);
                    node -> next = current;
                    //NULL check if insertion happening a front.
                    if (prev != NULL) {
                        prev -> next = node;
                    } else {
                        sortedList = node;
                    }
                    isAdded = true;
                    break;
                }
                prev = current;
                current = current -> next;
            }
            
            //incase list has reached the end & insertion has not uet happened.
            if (!isAdded && prev != NULL) {
                Node* node = getNode(item);
                prev -> next = node;
            }
            
        }
    }
    
public:
    
    bool isEmpty() {
        return (root == NULL || LLLength == 0);
    }
    
    bool isValid() {
        if (isEmpty()) {
            cout << endl << "LinkList is empty" << endl;
            return false;
        }
        return true;
    }
    
    void printLL() {
        if (!isValid()) { return; }
        Node* temp = root;
        cout << endl << "No of Nodes: "<< LLLength << endl;
        while (temp != NULL) {
            if (temp->next == NULL) {
                cout << temp -> key;
            } else {
                cout << temp -> key << " --> ";
            }
            temp = temp->next;
        }
        
        cout << endl << endl;
    }
    
    //inserting as a stack;
    void insert(int key) {
        struct Node* node = getNode(key);
        node->next = root;
        root = node;
        LLLength++;
    }
    
    //It will reverse the linklist. e.g 1->2->3 to 3->2->1;
    void reverse() {
        if (!isValid()) { return; }
        Node* temp = root->next;
        Node* prev = root;
        prev->next = NULL;
        while (temp != NULL) {
            Node* tempNxt = temp->next;
            if (tempNxt == NULL) {
                root = temp;
            }
            temp->next = prev;
            prev = temp;
            temp = tempNxt;
        }
        
    }
    
    //Deletes given item from the list if present.
    bool deleteItem(int item) {
        if (!isValid()) { return  false; }
        Node* prev = root;
        if (prev->key == item) {
            root = prev -> next;
            delete prev;
            LLLength--;
            return true;
        } else {
            Node* current = prev->next;
            while (current != NULL) {
                if (current -> key == item) {
                    prev->next = current->next;
                    delete current;
                    LLLength--;
                    return true;
                }
                prev = current;
                current = current->next;
            }
        }
        
        return false;
    }
    
    void sort() {
        Node* temp = root;
        while (temp != NULL) {
            insertInSortedList(temp->key);
            Node* localTemp = temp;
            temp = temp -> next;
            delete localTemp;
        }
        root = sortedList;
        sortedList = NULL;
    }
};

void deleteItem(int item, LinkList* list) {
    bool isDeleted = list->deleteItem(item);
    if (isDeleted) {
        list->printLL();
    } else {
        cout << endl << "Item " << item << " not found" << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //63 9 837 669 -1 2 -2 0037 73 77 77 190 532 6 7
    LinkList *LL = new LinkList();
    cout << "Enter no. of elemnts: ";
    int N;
    cin >> N;
    int key;
    for (int i=0; i<N; i++) {
        cin >> key;
        LL->insert(key);
    }
    
    LL->printLL();
    deleteItem(5, LL);
    deleteItem(1, LL);
    deleteItem(10, LL);
    deleteItem(5, LL);
    
    LL->sort();
    LL->printLL();
    
    LL->reverse();
    LL->printLL();
    LL->reverse();
    LL->printLL();
    
    LL->insert(6);
    LL->insert(7);
    LL->printLL();
    
    LL->sort();
    LL->printLL();
    LL->reverse();
    LL->printLL();
    
    /*
    LL->insert(8);
    LL->insert(9);
    LL->printLL();
    LL->reverse();
    LL->printLL();
   
    LL->insert(10);
    LL->printLL();
    LL->reverse();
    LL->printLL();*/
    
    return 0;
}

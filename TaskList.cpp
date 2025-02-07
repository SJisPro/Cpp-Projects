#include<bits/stdc++.h>
using namespace std;

struct Node {
  string task;
  Node* next;
};
Node* head = nullptr;

void addtask(const string& newtask) {
    cout<<endl;
    Node* newnode = new Node{newtask, head};
    if(head==nullptr) {
        head = newnode;
    }
    else {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = nullptr;
    }
    cout<<"Task Added: "<<newtask<<endl;
    cout<<endl;
}

void removetask(const string& task) {
    cout<<endl;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp && temp->task!=task) {
        prev = temp;
        temp = temp->next;
    }
    if(!temp) {
        cout<<"Task "<<task<<" not found!"<<endl;
        cout<<endl;
        return;
    }
    if(!prev) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }
    delete temp;
    cout<<"Task Removed: "<<task<<endl;
    cout<<endl;
}

int count() {
    int c = 0;
    Node* temp = head;
    while(temp) {
        c++;
        temp = temp->next;
    }
    return c;
}

void display() {
    cout<<endl;
    if(head==nullptr) {
        cout<<"The List is Empty\n"<<endl;
        return;
    }
    cout<<"Your Task List is: "<<endl;
    Node* temp = head;
    while(temp) {
        cout<<" -> "<<temp->task<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

void clearlist() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout<<"List cleared"<<endl;
}

int main() {
    int choice;
    string task;
    do {
        cout<<"1. Add a new task"<<endl;
        cout<<"2. Remove a task"<<endl;
        cout<<"3. Display all tasks"<<endl;
        cout<<"4. Total count of tasks"<<endl;;
        cout<<"0. Exit\n"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice) {
            case 1: cout<<"Enter the new task to add: ";
            cin>>task;
            addtask(task);
            break;
            case 2: if(head==nullptr) {
            cout<<"\nThe list is Empty"<<endl;
            cout<<endl;
            break;
            }
            cout<<"Enter the task to remove: ";
            cin>>task;
            removetask(task);
            break;
            case 3: display();
            break;
            case 4: cout<<"\nTotal number of tasks in the list: "<<count()<<endl;
            cout<<endl;
            break;
            case 0: cout<<"\nGoodbye"<<endl;
            clearlist();
            break;
            default: cout<<"Invalid choice"<<endl;
        }
    }while(choice);
    
    return 0;
}
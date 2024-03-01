#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(T val, Node<T>* nxt = nullptr, Node<T>* prv = nullptr) {value = val; next = nxt; prev = prv;};
};

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();                  // Default Constructor
    ~DoublyLinkedList();                 // Destructor

    void Append(T value);              // Add a value to the end of the list
    T operator[](int index);           // Return the value at the index requested
    bool Find(T value);                // Returns true if the value is found and false if not
    void Insert(int index, T value);   // Insert value at index
    bool IsEmpty();                      // True if the list is currently empty
    void Print();
    void PrintReverse();
    bool Delete(T value);              // Delete the first occurrence of value; true if successful
    bool DeleteAt(int index);            // Delete the value at the location; true if successful
    int Size();                          // Number of elements in the list

private:
    Node<T>* head;                          // Items are linked to the head
    int size;
};

   template <typename T> DoublyLinkedList<T>::DoublyLinkedList(){
      size = 0;
      head = nullptr;
      
   };                  // Default Constructor
  
   template <typename T> DoublyLinkedList<T>::~DoublyLinkedList(){
      while(head != nullptr) {
         Node<T>* current = head;
         head = head-> next;
         delete current;
      }
      size =0;
   };                 // Destructor

   template <typename T> void DoublyLinkedList<T>::Append(T value){
      size++;
      if (head == nullptr) {
         head = new Node<T>(value);
         return;
      }
      
      Node<T>* current = head;
      
      while(current->next != nullptr) {
         current = current -> next;
      }
      
      current -> next = new Node<T>(value,nullptr, current);
      
   };              // Add a value to the end of the list
   
   template <typename T> T DoublyLinkedList<T>::operator[](int index){
      if ( index < 0) {
         index += size;
      }
      Node<T>* current = head;
      int count = 0;
      while (current != nullptr) {
         if ( count == index) {
            return current -> value;
         }
         count ++;
         current = current -> next;
      }
   };           // Return the value at the index requested
  
   template <typename T> bool DoublyLinkedList<T>::Find(T value){
      if (head == nullptr) {
         return false;
      }
      
      Node<T>* current = head;
      while(current != nullptr) {
         if ( current -> value == value) {
            return true;
         }
         current = current -> next;
      }
      
      return false;
   };                // Returns true if the value is found and false if not
   
   template <typename T> void DoublyLinkedList<T>::Insert(int index, T value){
      if (index < 0) {
         index += size;
      }
      
      size++;
      
      if (head == nullptr) {
         head = new Node<T>(value);
         return;
      }
      
      Node<T>* current = head;
      if ( index == 0) {
         head = new Node<T>(value, current);
         return;
      }
      int count = 1;
      
      while(current->next != nullptr) {
         if(count == index) {
            Node<T>* temp = new Node<T>(value,current-> next);
            current->next = temp;
         }
         count ++;
         current = current -> next;
      }
      current -> next = new Node<T>(value);
      
   };   // Insert value at index
   
   template <typename T> bool DoublyLinkedList<T>::IsEmpty(){
      return head == nullptr;
   };                      // True if the list is currently empty
   
   template <typename T> void DoublyLinkedList<T>::Print(){
      Node<T>* current = head;
      
      while(current != nullptr){
         cout << current->value;
         current = current->next;
         if(current != nullptr) {
            cout << "->";
         }
      } 
      cout << endl;
   };
   
   template <typename T> void DoublyLinkedList<T>::PrintReverse(){
      // Node<T>* current = head;
      // while( current->next !=nullptr) {
      //    current = current-> next;
      // }
      // while (current != nullptr) {
      //    cout << current -> value;
      //    if ( current -> prev != nullptr) {
      //       cout << "->";
      //    }
      //    current = current ->prev;
      // }
      // cout << endl;
       Node<T>* current = head;
      while (current != nullptr && current-> next!= nullptr) {
         current = current -> next;
      } 
      
      while(current!= nullptr) {
         cout << current -> value;
         current = current->prev;
         if (current!= nullptr) {
            cout << "->";
         }
      }
      
      cout << endl;
   };
   
   template <typename T> bool DoublyLinkedList<T>::Delete(T value){
      if (head == nullptr) {
         return false;
      }
      
      if (head -> value == value) {
         Node<T>* current = head;
         head = head->next;
         delete current;
         size--;
         return true;
      }
      
      Node<T>* previous = head;
      Node<T>* current = head -> next;
      while(current != nullptr) {
         if ( current -> value == value) {
            previous->next = current -> next;
            delete current;
            size --;
            return true;
         }
         previous = current;
         current = current ->next;
      }
      
      return false;
   };              // Delete the first occurrence of value; true if successful
   
   template <typename T> bool DoublyLinkedList<T>::DeleteAt(int index){
      if(index<0){
         index+=size;
      }
      if (head ==nullptr || index >= size) {
         return false;
      }
      
      if (index ==0) {
         Node<T>* temp = head;
         head = head->next;
         delete temp;
         size--;
         return true;
      }
      
      int count = 1;
      Node<T>* previous = head;
      Node<T>* current = head -> next;
      while(current != nullptr) {
         if (index == count) {
            previous -> next = current -> next;
            delete current;
            size--;
            return true;
         }
         count ++;
         previous=current;
         current = current -> next;
      }
      
      return false;
   };            // Delete the value at the location; true if successful
   
   template <typename T> int DoublyLinkedList<T>::Size(){
      return size;
   };
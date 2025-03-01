#include <iostream>
#include <cassert>
#include "Sequence.h"
using namespace std;
using namespace cs_sequence;

/*
Aiden Man
CS 2B - Harden
11/24/2024
Project 26.2 - Sequence.cpp
*/

namespace cs_sequence{
    typedef int value_type;
    typedef size_t size_type;

    Sequence::Sequence(){
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        numItems = 0;
    }






    Sequence::~Sequence() {
        clear();
    }






    Sequence::Sequence(const Sequence& copiedSequence) {
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        numItems = 0;
        copy(copiedSequence);
    }






    Sequence& Sequence::operator=(const Sequence& copiedSequence) {
        if (this != &copiedSequence) {
            clear();
            copy(copiedSequence);
        }
        return *this;
    }






    void Sequence::start(){
        cursor = headPtr;
        precursor = nullptr;
    }






    void Sequence::advance(){
        assert(is_item());
        precursor = cursor;
        cursor = cursor->next;
        if (cursor == nullptr) {
            cursor = nullptr;
            precursor = nullptr;
        }
    }






    void Sequence::insert(const value_type& entry){
        numItems++;
        node* tempptr = new node;
        tempptr->data = entry;

        if(precursor == nullptr && cursor != nullptr){
            tempptr->next = cursor;
            headPtr = tempptr;
            cursor->prev = tempptr;

        } else if(precursor == nullptr && cursor == nullptr){
            tempptr->next = headPtr;
            tempptr->prev = nullptr;

            if (tailPtr == nullptr) {
                tailPtr = tempptr;
            } else {
                headPtr->prev = tempptr;
            }
            headPtr = tempptr;

        } else {
            precursor->next = tempptr;
            cursor->prev = tempptr;
            tempptr->next = cursor;
            tempptr->prev = precursor;
        }
        cursor = tempptr;
        precursor = tempptr->prev;
    }






    void Sequence::attach(const value_type& entry){
        numItems++;
        node* tempptr = new node;
        tempptr->data = entry;

        if (headPtr == nullptr) {
            tempptr->prev = nullptr;
            tempptr->next = nullptr;
            headPtr = tempptr;
            tailPtr = tempptr;

        } else if(cursor == tailPtr || cursor == nullptr){
            tempptr->prev = tailPtr;
            tempptr->next = nullptr;
            tailPtr->next = tempptr;
            tailPtr = tempptr;

        } else {
                tempptr->prev = cursor;
                tempptr->next = cursor->next;
                cursor->next->prev = tempptr;
                cursor->next = tempptr;
        }
        cursor = tempptr;
        precursor = tempptr->prev;
    }






    void Sequence::remove_current() {
        assert(is_item());
        numItems--;
        if (cursor == headPtr && cursor == tailPtr) {
            if (cursor != nullptr) {
                delete cursor;
            }
            headPtr = nullptr;
            tailPtr = nullptr;
            cursor = nullptr;
            precursor = nullptr;
        } else if (cursor == headPtr) {
            headPtr = cursor->next;
            headPtr->prev = nullptr;
            delete cursor;
            cursor = headPtr;
        } else {
            precursor->next = cursor->next;
            if (cursor != tailPtr) {
                cursor->next->prev = cursor->prev;
                delete cursor;
                cursor = precursor->next;
                precursor = cursor->prev;
            } else {
                tailPtr = cursor->prev;
                delete cursor;
                cursor = nullptr;
                precursor = nullptr;
            }
        }
    }






    size_type Sequence::size() const{
        return numItems;
    }






    bool Sequence::is_item() const{
        return (cursor != nullptr);
    }






    value_type Sequence::current() const{
        assert(is_item());
        return (cursor->data);
    }






    void Sequence::copy(const Sequence& copiedSequence) {
        node* copyCursor = copiedSequence.headPtr;
        while(copyCursor != nullptr) {
            attach(copyCursor->data);
            copyCursor = copyCursor->next;
        }

        if (copiedSequence.cursor == nullptr) {
            cursor = nullptr;
            precursor = nullptr;
        } else {
            start();
            while (copiedSequence.current() != current()) {
                advance();
            }
        }
    }






    void Sequence::clear() {
        while (is_item()) {
            start();
            remove_current();
        }
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        numItems = 0;
    }
}
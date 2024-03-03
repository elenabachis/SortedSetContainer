#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    //TODO - Implementation
    this->current=multime.head;
}


void SortedSetIterator::next() {
    //TODO - Implementation
    if(!valid()){
        throw exception();
    }
    this->current=this->current->next;
}

bool SortedSetIterator::valid() const {
    //TODO - Implementation
    return this->current!= nullptr;
}
void SortedSetIterator::first()
{
    this->current = this->multime.head;
}


TElem SortedSetIterator::getCurrent() {
    //TODO - Implementation
    if(!valid()){
        throw exception();
    }
    return this->current->info;
}

void SortedSetIterator::deleteCurrent() {

    ///wenn ich richtig gemacht wurde, wird die Komplexitat O(length)
    ///best case:theta(1) wenn das Element das erste ist und worst:theta(n) wenn das Element das letzte ist
    Node* prevNode = this->current->prev;
    Node* nextNode = this->current->next;

    if(prevNode== nullptr){ //das Element ist das erste
        this->current=nextNode;
    }
    else{
        prevNode->next=nextNode;
    }

    if (nextNode == nullptr) { //das Element ist das letzte
      this->current = prevNode;
    } else {
        nextNode->prev = prevNode;
    }
    Node* oldNode = this->current;
    this->current = nextNode;
    delete oldNode;
}

#ifndef BQUEUE
#define BQUEUE

class bqnode{ //node class
    public:
        int priority; //data value
        bqnode *prev, *next; //previous and next pointers (circular/double linked)
};

class bqueue{ //queue class
    public:
        bqueue(); //default constructor, sets front to null/0
        ~bqueue(); //destructor, deallocates dynamic memeory of nodes
        bqueue(const bqueue &); //copy constructor (deep copy due to pointers)
        void enqueue(int); //same as push, adds to back
        void dequeue(); //same as pop, removes from front
        void print(); //prints entire queue
        bool empty(); //determined whether or not queue is empty
    private:
        bqnode *front; //pointer to front node
};

#endif
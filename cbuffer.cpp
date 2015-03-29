#include <iostream>
#include <string.h>

using namespace std;

class cbuffer
{
 private:
    void *buffer;
    void *head;
    void *tail;
    void *end;
    int   capacity;
    int   current_size;
    int   element_size;

 public:
    cbuffer(int max_size, int ele_size)
        {
            capacity = max_size;
            current_size = 0;
            element_size = ele_size;
            buffer = new char[capacity * ele_size];
            head   = buffer;
            tail   = buffer;
            end    = (char*)buffer + capacity * ele_size;
        }

    bool isFull()
    {
        return (current_size == capacity);
    }

    bool isEmpty()
    {
        return (current_size == 0);
    }

    bool add(void *data)
    {
        if (!isFull()) {
            memcpy(head, data, element_size);
            current_size++;
            head = (char*)head + element_size;
            if (head == end) {
                head = buffer;
            }
            return true;
        }
        return false;
    }

    bool pop(void *data)
    {
        if (!isEmpty()) {
            memcpy(data, tail, element_size);
            current_size--;
            tail = (char*)tail + element_size;
            if (tail == end) {
                tail = buffer;
            }
            return true;
        }
        return false;
    }
};

int main()
{
    cbuffer buf(4, 1);
    void   *data = new char;
    
    buf.add((void*)"H");
    buf.add((void*)"I");
    buf.add((void*)"M");
    buf.add((void*)"A");
    if (!buf.add((void*)"N")) {
        cout << "Buffer full" << endl;   
    }

    buf.pop(data);
    cout << "Popped data: " << (char*)data << endl;
    buf.pop(data);
    cout << "Popped data: " << (char*)data << endl;


    return 0;
}

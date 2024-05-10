#pragma once
#include <cstddef>

template <class T>
class DLList
{
    struct Node
    {
        Node( const T& value, Node* prev, Node* next ){
            this->value = value;
            this->prev = prev;
            this->next = next;
        }

        T value;
        Node* prev;
        Node* next;
    }
    ;
    private:
        Node* head;
        Node* tail;
        int count;

    public:
        DLList(): head{ nullptr}, tail{ nullptr}, count{0}{};
        DLList( const DLList& other ): head{ nullptr}, tail{ nullptr}, count{0}
        {
            Node* tmp = other.head;
            while( tmp != nullptr){
                push_back( tmp->value );
                tmp = tmp->next;
            }
        };

        ~DLList(){
            clear();
        };

        void push_front( T val )
        {
            if (head != nullptr)
            {
                head->prev = new Node(val, nullptr, head);
                head = head->prev;
            }
            else
            {
                head = new Node(val, nullptr, nullptr);
                tail = head;
            }
            ++count;
        }

        void push_back( T val )
        {
            if (head != nullptr)
            {
                tail->next = new Node(val, tail, nullptr);
                tail = tail->next;
            }
            else
            {
                head = new Node(val, nullptr, nullptr);
                tail = head;
            }
            ++count;
        }

        // Retrieve the value at the beginning of the list and remove it.
        T pop_front()
        {
            T val;
            if( head != nullptr ){
                Node* tmp = head;
                head = head->next;
                val = tmp->value;
                delete tmp;
                --count;
                if (head == nullptr) tail = nullptr;
                return val;
            }

            // I need to throw an error here if the list is empty.
        }

        // Retrieve the value at the end of the list and remove it.
        T pop_back()
        {
            T val;
            if (tail == head) {
                val = pop_front();
                return val;
            } 

            tail = tail->prev;
            val = tail->next->value;
            delete tail->next;
            tail->next = nullptr;
            --count;
            return val;
        }

    void display()
    {
        if ( count == 0 ) 
        {
            std::cout << "EMPTY LIST" << std::endl;
        }

        Node* tmp = head;

        while ( tmp != nullptr )
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    void clear()
    {
        Node* tmp = head;
        while (tmp != nullptr)
        {
            head = tmp;
            tmp = tmp->next;
            delete head;
            --count;
        }

        head = tail = nullptr;
    }

    bool insert_after ( const T& val, const T& new_val )
    {

        if( tail == nullptr ) return false;

        if( val == tail->value ){
            push_back( new_val );
            return true;
        }

        // This should not happen by I want to check anyway.
        if (head == nullptr ) return false;

        Node* tmp;
        Node* t1 = new Node( new_val, nullptr, nullptr );

        if (val == head->value){
            t1->next = head->next;
            head->next->prev = t1;
            head->next = t1;
            t1->prev = head;
            ++count;
            return true;
        }

        tmp = head->next;

        while( tmp != nullptr )
        {
            if( tmp->value == val )
            {
                t1->next = tmp->next;
                tmp->next->prev = t1;
                tmp->next = t1;
                t1->prev = tmp;

                ++count;
                return true; 
            }
            tmp = tmp->next;
        }

        return false;
    }

    bool remove( const T& val )
    {
        if( head == nullptr ) return false;
        if (val == head->value) { pop_front(); return true; }

        Node* tmp = head->next;
        while (tmp != tail)
        {
            if (tmp->value == val)
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                --count;
                return true;
            }
            tmp = tmp->next;
        }
        if (val == tail->value) { pop_back(); return true; }

        return false;
    }

    int size() { return count;}
};


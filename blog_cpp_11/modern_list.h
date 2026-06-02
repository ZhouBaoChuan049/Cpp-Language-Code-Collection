#pragma once
#include "ModernString.h"
namespace mylist
{
    template<class T>
    struct ListNode
    {
        ListNode<T>* _next;
        ListNode<T>* _prev;
        T _data;
		ListNode() = default;
        ListNode(const T& data )
            : _next(nullptr)
            , _prev(nullptr)
            , _data(data)
        {}
		template<class U>
        ListNode(U&& data)
            : _next(nullptr)
            , _prev(nullptr)
            , _data(move(data))
        { }
    };

    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T> Node;
        typedef ListIterator<T, Ref, Ptr> Self;
        Node* _node;

        ListIterator(Node* node)
            : _node(node)
        {
        }

        Self& operator++()
        {
            _node = _node->_next;
            return *this;
        }

        Ref operator*()
        {
            return _node->_data;
        }

        bool operator!=(const Self& it)
        {
            return _node != it._node;
        }
    };

    template<class T>
    class list
    {
        typedef ListNode<T> Node;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;

        iterator begin()
        {
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        void empty_init()
        {
            _head = new Node();
            _head->_next = _head;
            _head->_prev = _head;
        }

        list()
        {
            empty_init();
        }

        template<class U>
        void push_back(const U& x)
        {
            insert(end(), forward<U>(x));
        }
        iterator insert(iterator pos, const T& x)
        {
            Node* cur = pos._node;
            Node* newnode = new Node(x);
            Node* prev = cur->_prev;

            // prev  newnode  cur
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;

            return iterator(newnode);
        }
        template<class U>
        iterator insert(iterator pos, U&& x)
        {
            Node* cur = pos._node;
            Node* newnode = new Node(forward<U>(x));
            Node* prev = cur->_prev;

            // prev  newnode  cur
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;

            return iterator(newnode);
        }
    private:
        Node* _head;
    };
}
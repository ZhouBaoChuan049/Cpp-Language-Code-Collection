#pragma once
#include <iostream>
#include <utility>

namespace bit
{

    template<class T>
    struct ListNode
    {
        ListNode<T>* _next;
        ListNode<T>* _prev;
        T _data;

        // ✅ 默认构造（给哨兵节点用）
        ListNode()
            : _next(nullptr)
            , _prev(nullptr)
            , _data()
        {
        }

        // 左值
        ListNode(const T& data)
            : _next(nullptr)
            , _prev(nullptr)
            , _data(data)
        {
        }

        // 右值
        ListNode(T&& data)
            : _next(nullptr)
            , _prev(nullptr)
            , _data(std::move(data))
        {
        }

        // 完美转发
        template <class... Args>
        ListNode(Args&&... args)
            : _next(nullptr)
            , _prev(nullptr)
            , _data(std::forward<Args>(args)...)
        {
        }
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

        Self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }

        Ref operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
            return &_node->_data;
        }

        bool operator!=(const Self& it) const
        {
            return _node != it._node;
        }

        bool operator==(const Self& it) const
        {
            return _node == it._node;
        }
    };

    template<class T>
    class list
    {
    public:
        typedef ListNode<T> Node;
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

        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        void clear()
        {
            Node* cur = _head->_next;
            while (cur != _head)
            {
                Node* next = cur->_next;
                delete cur;
                cur = next;
            }
            _head->_next = _head;
            _head->_prev = _head;
        }

        // --------------------------
        // push_back
        // --------------------------

        void push_back(const T& x)
        {
            insert(end(), x);
        }

        void push_back(T&& x)
        {
            insert(end(), std::move(x));
        }

        // --------------------------
        // insert（只保留两种，避免污染）
        // --------------------------

        iterator insert(iterator pos, const T& x)
        {
            Node* cur = pos._node;
            Node* prev = cur->_prev;

            Node* newnode = new Node(x);

            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;

            return iterator(newnode);
        }

        iterator insert(iterator pos, T&& x)
        {
            Node* cur = pos._node;
            Node* prev = cur->_prev;

            Node* newnode = new Node(std::move(x));

            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;

            return iterator(newnode);
        }

        // --------------------------
        // emplace_back（正确实现）
        // --------------------------

        template <class... Args>
        void emplace_back(Args&&... args)
        {
            Node* newnode = new Node(std::forward<Args>(args)...);

            Node* tail = _head->_prev;

            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next = _head;
            _head->_prev = newnode;
        }

    private:
        Node* _head;
    };

}
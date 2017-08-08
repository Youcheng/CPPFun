#pragma once
#include <memory>
#include <mutex>

template<typename T>
class threadsafe_queue
{
private:
    struct node
    {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
    };

    std::mutex head_mutex;
    std::unique_ptr<node> head;
    std::mutex tail_mutex;
    node* tail;

    node* get_tail()
    {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        return tail;
    }

    std::unique_ptr<node> pop_head()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get()==get_tail())
        {
            return nullptr;
        }

        // move ctor to move node pointed by head
        std::unique_ptr<node> old_head=std::move(head);
        head=std::move(old_head->next);
        return old_head;
    }

public:
    // at construction, it has one node
    // head->next = nullptr, head->data = nullptr
    // tail->next = nullptr, tail->data = nullptr
    threadsafe_queue():
            head(new node),tail(head.get())
    {}

    threadsafe_queue(const threadsafe_queue& other)=delete;

    threadsafe_queue& operator=(const threadsafe_queue& other)=delete;

    std::shared_ptr<T> try_pop()
    {
        std::unique_ptr<node> old_head=pop_head();
        return old_head ? old_head->data : std::shared_ptr<T>();
    }

    void push(T new_value)
    {
        // shared pointer to real data to be saved in existing tail node
        std::shared_ptr<T> new_data(
                std::make_shared<T>(std::move(new_value)));

        // unique pointer to next empty node to be pointed by the new tail
        std::unique_ptr<node> p(new node);

        node* const new_tail=p.get();
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        tail->data=new_data;
        tail->next=std::move(p);
        tail=new_tail;
    }
};
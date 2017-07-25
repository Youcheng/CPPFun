unique_ptr
----------
    template< class T, class Deleter = std::default_delete<T> > 
    class unique_ptr;
    
    same size as raw pointer when use default deleter
    function object deleters with extensive state can increase the size of the unique_ptr greatly
    a custom stateless function objects is preferred since it incur no size penalty, like captureless lambda expression

    move-only type(source pointer is set to nullptr)

shared_ptr_control_block
------------------------
![shared_ptr_control_block](https://github.com/Youcheng/CPPFun/blob/master/SmartPointer/controlblock.png)


weak_ptr
--------
    A smart pointer acting like std::shared_ptr but doesn't participate the shared ownership 
    of the pointed-to object's reference count.
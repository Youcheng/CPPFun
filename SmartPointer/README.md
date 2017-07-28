unique_ptr
----------
    template< class T, class Deleter = std::default_delete<T> > 
    class unique_ptr;
    
    same size as raw pointer when use default deleter
    function object deleters with extensive state can increase the size of the unique_ptr greatly
    a custom stateless function objects is preferred since it incur no size penalty, like captureless lambda expression

    move-only type(source pointer is set to nullptr)

shared_ptr
----------
* raw pointers in shared_ptr
   * raw pointer to the managed resource
   * raw pointer to the resource's reference count

* reference count
  * shared_ptr normal constructor increment the resource's reference count
  * shared_ptr normal copy assignment sp1 = sp2,the reference count for the object originally pointed by sp1 is decremented,
    while that for the object pointed by sp2 is increamented
  * shared_ptr move constructor set source to null, no reference count manipulation is required
  * shared_ptr move assignment set source to null, no reference count manipulation is required
  * shared_ptr destructor decrement the resource's reference count

shared_ptr_control_block
------------------------
![shared_ptr_control_block](https://github.com/Youcheng/CPPFun/blob/master/SmartPointer/controlblock.png)


weak_ptr
--------
    A smart pointer acting like std::shared_ptr but doesn't participate the shared ownership 
    of the pointed-to object's reference count.
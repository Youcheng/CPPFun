hardware thread
---------------
    The threads that actually perform computation.
    Contemporary machine architectures offer one or more hardware threads per CPU core.


software thread(OS/system thread)
---------------------------------
    The threads that the operating system 15 manages across all processes and
    schedules for execution on hardware threads.

    Software threads are a limited resource. If you try to create more than the
    system can provide, a std::system_error exception is thrown.



std::thread
-----------
    Objects in a C++ process that act as handles to underlying software threads.

    Joinable std::thread
    1. A joinable std::thread corresponds to an underlying asynchronous thread
       of execution that is or could be running.
    2. A std::thread corresponding to an underlying thread that’s blocked
       or waiting to be scheduled is joinable.


    Unjoinable std::thread
    1. Some std:thread objects represent "null" handles, i.e., correspond to no software thread,
       because they’re in a default-constructed state (hence have no function to execute);
    2. Some std:thread objects have been moved from (the moved-to std::thread then
       acts as the handle to the underlying software thread);
    3. Some std:thread objects have been joined (the function they were to run has finished);
    4. Some std:thread objects have been detached (the connection between them
       and their underlying software thread has been severed)


oversubscription
----------------
    That’s when there are more ready-to-run (i.e., unblocked) software threads than hardware threads.
    When that happens, the thread scheduler (typically part of the OS) time-slices the software threads on the hardware.

    Such context switches increase the overall thread management overhead of the system,
    and they can be particularly costly when the hardware thread on which a software thread is scheduled is
    on a different core than was the case for the software thread during its last time-slice.

    In that case,
    (1) the CPU caches are typically cold for that software thread
        (i.e., they contain little data and few instructions useful to it) and
    (2) the running of the “new” software thread on that core “pollutes” the CPU caches for “old” threads
        that had been running on that core and are likely to be scheduled to run there again.


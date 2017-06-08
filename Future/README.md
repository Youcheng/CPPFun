Threads are very different from tasks.
For the communication between the creator thread and the created thread you have to use a shared
variable. The task communicates via its data channel, which is implicitly protected. Therefore a task
must not use a protection mechanism like a mutex.
The creator thread is waiting for its child with the join call. The future fut is using the ‘fut.get()
call which is blocking if no result is there.
If an exception happens in the created thread, the created thread will terminate and therefore the
creator and the whole process. On the contrary, the promise can send the exceptions to the future,
which has to handle the exception.
A promise can serve one or many futures. It can send a value, an exception or only a notification.
You can use a task as a safe replacement for a condition variable.
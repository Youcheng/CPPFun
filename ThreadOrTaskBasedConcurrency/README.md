Ways to run a function doAsyncWork
----------------------------------
1. thread-based
```
int doAsyncWork();
std::thread t(doAsyncWork);

Thread-based programming calls for manual management of thread exhaustion,
oversubscription, load balancing, and adaptation to new platforms.

The std::thread API offers no direct way to get return values from asynchronously
run functions, and if those functions throw, the program is terminated.

```

2. task-based
```
auto fut = std::async(doAsyncWork);

It doesn’t guarantee that it will create a new software thread. Rather,
it permits the scheduler to arrange for the specified function (in this example, doAsyncWork)
to be run on the thread requesting doAsyncWork’s result.

```




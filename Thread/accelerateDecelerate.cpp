#include <functional>
#include <sys/prctl.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "error.h"
#include "string.h"

int main() {
    prctl(PR_SET_NAME, "youcheng_thread", 0 ,0, 0);

    pthread_t thread = pthread_self();
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    //CPU_SET(17, &cpuset);
    CPU_SET(18, &cpuset);
    CPU_SET(19, &cpuset);

    /*
     * The pthread_setaffinity_np() function sets the CPU affinity mask of the thread to the CPU set pointed to by cpuset.
     * If the call is successful, and the thread is not currently running on one of the CPUs in cpuset,
     * then it is migrated to one of those CPUs.
     */
    int affinityResult = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if (affinityResult!=0) {
        std::cout << "fail to pin" << std::endl;
    }
    else {
        int which = PRIO_PROCESS;
        int result = setpriority(which, 0, -15);
        if (result!=0 ){
            // it has to be root to run the binary so that we could configure priority value.
            std::cout << "cannot set nice level with error: " << strerror(errno) << std::endl;
        }
        else{
            std::cout << " set nice level: " << getpriority(which,0) << std::endl;
        }
        /* Check the actual affinity mask assigned to the thread */
        int s = pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
        std::cout << "CPU_SETSIZE: " << CPU_SETSIZE << std::endl
                  << "CPU affinity mask of the thread: " << std::endl;

        if (s != 0) {
            std::cout << "fail to get affinity mask for this thread" << std::endl;
        } else {
            for (int j = 0; j < CPU_SETSIZE; j++) {
                if (CPU_ISSET(j, &cpuset)) {
                    std::cout << "cpu: " << j << std::endl;
                }
            }
        }

        // successfully pinned
        int policy = 0;
        sched_param schedparam;
        pthread_getschedparam(thread, &policy, &schedparam);
        std::cout << "process id: " << getpid() << std::endl
                  << "thread id: " << syscall(SYS_gettid) << std::endl
                  << "policy: " << policy << std::endl
                  << "sched_get_priority_min: " << sched_get_priority_min(policy) << std::endl
                  << "sched_get_priority_max: " << sched_get_priority_max(policy) << std::endl
                  << "schedparam.__sched_priority: " << schedparam.__sched_priority << std::endl
                  << "sleeping... " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(120));
    }

    {
        // unpinned
        int policy = SCHED_BATCH;
        sched_param schedparam;
        schedparam.__sched_priority = sched_get_priority_min(policy);

        int scheduleResult = pthread_setschedparam(thread, policy, &schedparam);

        if (scheduleResult !=0) {
            std::cout << "fail to unpin" << std::endl;
        }
        else {
            pthread_getschedparam(thread, &policy, &schedparam);
            std::cout << "process id: " << getpid() << std::endl
                      << "thread id: " << syscall(SYS_gettid) << std::endl
                      << "policy: " << policy << std::endl
                      << "sched_get_priority_min: " << sched_get_priority_min(policy) << std::endl
                      << "sched_get_priority_max: " << sched_get_priority_max(policy) << std::endl
                      << "schedparam.__sched_priority: " << schedparam.__sched_priority << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(120));
        }
    }
}


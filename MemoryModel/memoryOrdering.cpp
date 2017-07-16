#include <iostream>
#include <thread>
#include <mutex>
#include <sys/prctl.h>

char b = 0;
char c = 0;

// b and c might be a word, which is the smallest thing
// the cpu could load or write


std::mutex g_mutex;

void f() {
    prctl(PR_SET_NAME, "threadF", 0 ,0, 0);
    pthread_t thread = pthread_self();
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int affinityResult = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);

    c=1;
    int x = b;
    std::lock_guard<std::mutex> lock(g_mutex);
    std::cout << "x = " << x << std::endl;
}

void g() {
    prctl(PR_SET_NAME, "threadG", 0 ,0, 0);
    pthread_t thread = pthread_self();
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    int affinityResult = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);


    b=1;
    int y = c;
    std::lock_guard<std::mutex> lock(g_mutex);
    std::cout << "y = " << y << std::endl;
}

int main() {
    std::cout << "&b " << (void *)&b << std::endl;
    std::cout << "&c " << (void *)&c << std::endl;

    std::thread t2(g);
    std::thread t1(f);

    t1.join();
    t2.join();
}


// possible execution orders

// c=1
// x=b=0
// b=1
// y=c=1

// b=1
// y=c=0
// c=1
// x=b=1





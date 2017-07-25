#include <iostream>
#include <sys/file.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdio>
#include <unistd.h>

const char* CONFIG_FILE = "/tmp/test.txt";


int main() {

    const int fd = open(CONFIG_FILE, O_RDONLY | O_NONBLOCK);

    if (fd == -1) {
        std::cerr << "Cannot open config file: " << CONFIG_FILE << ": " << strerror(errno) << std::endl;
        return 1;
    }

    if (flock(fd, LOCK_EX | LOCK_NB) == -1) {
        std::cerr << "The config file is already opened by a different process. " << strerror(errno) << std::endl;
        return 1;
    }

    char buf[20];
    size_t nbytes;
    ssize_t bytes_read;

    nbytes = sizeof(buf);
    bytes_read = read(fd, buf, nbytes);

    std::cout << "The config file is" << std::endl
              << buf << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(120));
}
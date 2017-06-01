#include <dlfcn.h>
#include "CNhMdApi.h"
#include <string>
#include <iostream>
#include <pthread.h>

class testClass : private CNhMdSpi
{
public:
    testClass() = default;
    ~testClass() = default;

    int do_start() {
        std::string library = "../Library/dlopen/libnhmdapi.so";
        void* handle;

        handle = dlopen(library.c_str(), RTLD_NOW);
        if (!handle) {
            std::cout << "Cannot load library: " << dlerror() << std::endl;
            return 1;
        }

        /*
         * [crtrader@CRT-017 dlopen (master)]$ nm libnhmdapi.so | grep CreateMdApi
         * 00000000000485e0 T _ZN8CNhMdApi11CreateMdApiEv
         * 000000000032913c r _ZN8CNhMdApi11CreateMdApiEv$$LSDA
         */

        typedef CNhMdApi* (*creator)();
        creator create = (creator)dlsym(handle, "_ZN8CNhMdApi11CreateMdApiEv");
        if (!create) {
            std::cout << "Cannot find symbol: " << dlerror() << std::endl;
            return 1;
        }

        m_api = create();

        return 0;
    }

    void get_api_version() {
        int major, minor;
        m_api->GetVersion(major, minor);
        std::cout << "major " << major << std::endl
                  << "minor " << minor << std::endl;
    }

private:
        CNhMdApi* m_api;

};

int main() {
    testClass t;
    t.do_start();

    t.get_api_version();

}
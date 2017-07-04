#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

// completion handler
void print(const boost::system::error_code& /*e*/)
{

    std::cout << boost::this_thread::get_id() << std::endl
              << "Hello, print!" << std::endl;
}

class printer{
public:
    printer(boost::asio::io_service& io, boost::posix_time::seconds timer_interval, int* count)
            : strand_(io),
              timer_interval_{timer_interval},
              timer1_{io, timer_interval},
              timer2_{io, timer_interval},
              count_{count} {

        // Synchronising handlers in multithreaded programs
         /*An boost::asio::strand guarantees that, for those handlers that are dispatched through it,
         an executing handler will be allowed to complete before the next one is started.
         This is guaranteed irrespective of the number of threads that are calling io_service::run().
         By wrapping the handlers using the same boost::asio::strand,
         we are ensuring that they cannot execute concurrently.*/

        timer1_.async_wait(strand_.wrap(boost::bind(&printer::RepeatedTask1, this, boost::asio::placeholders::error)));
        timer2_.async_wait(strand_.wrap(boost::bind(&printer::RepeatedTask2, this, boost::asio::placeholders::error)));
    }

    // completion handler with arguments
    void RepeatedTask1(const boost::system::error_code& /*e*/)
    {
        if (*count_ < 6)
        {
            ++(*count_);

            timer1_.expires_at(timer1_.expires_at() + timer_interval_);
            timer1_.async_wait(strand_.wrap(boost::bind(&printer::RepeatedTask1, this, boost::asio::placeholders::error)));
            std::cout << *count_ << " th timer1 starts on thread: " << boost::this_thread::get_id() << std::endl
                      << "will expire at " << timer1_.expires_at() << std::endl << std::endl;
        }
    }

    void RepeatedTask2(const boost::system::error_code& /*e*/)
    {
        if (*count_ < 6)
        {
            ++(*count_);

            timer2_.expires_at(timer2_.expires_at() + timer_interval_);
            timer2_.async_wait(strand_.wrap(boost::bind(&printer::RepeatedTask2, this, boost::asio::placeholders::error)));
            std::cout << *count_ << " th timer2 starts on thread: " << boost::this_thread::get_id() << std::endl
                      << "will expire at " << timer2_.expires_at() << std::endl << std::endl;
        }
    }

private:
    boost::asio::io_service::strand strand_;
    boost::posix_time::seconds timer_interval_;
    boost::asio::deadline_timer timer1_;
    boost::asio::deadline_timer timer2_;
    int* count_;
};




int main() {

    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
    t.async_wait(&print);

    //The asio library provides a guarantee that callback handlers
    // will only be called from threads that are currently calling io_service::run().
    // Therefore unless the io_service::run() function is called
    // the callback for the asynchronous wait completion will never be invoked.

    //The io_service::run() function will also continue to run while there is still "work" to do.
    // In this example, the work is the asynchronous wait on the timer,
    // so the call will not return until the timer has expired and the callback has completed.

    int count = 0;
    auto timer_interval = boost::posix_time::seconds(5);
    printer p(io, timer_interval, &count);

    boost::thread thread1(boost::bind(&boost::asio::io_service::run, &io));

    try {
        thread1.join();
        io.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;

class Timer {
public:
    Timer() : m_time_begin(high_resolution_clock::now()) {}

    void reset() {m_time_begin = high_resolution_clock::now();}

    long elapsed() const {
        return duration_cast<milliseconds>(high_resolution_clock::now() - m_time_begin).count();
    }

    long elapsed_micro() const {
        return duration_cast<microseconds>(high_resolution_clock::now() - m_time_begin).count();
    }

    long elapsed_nano() const {
        return duration_cast<nanoseconds>(high_resolution_clock::now() - m_time_begin).count();
    }

    long elapsed_second() const {
        return duration_cast<seconds>(high_resolution_clock::now() - m_time_begin).count();
    }

    long elapsed_minute() const {
        return duration_cast<minutes>(high_resolution_clock::now() - m_time_begin).count();
    }

private:
    std::chrono::time_point<high_resolution_clock> m_time_begin;
};



int main() {

    Timer t;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << t.elapsed() << "\t" <<  t.elapsed_micro() << "\t" << t.elapsed_nano() << "\t"
              << t.elapsed_second() << "\t" << t.elapsed_minute() << std::endl;

    t.reset();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << t.elapsed() << "\t" <<  t.elapsed_micro() << "\t" << t.elapsed_nano() << "\t"
              << t.elapsed_second() << "\t" << t.elapsed_minute() << std::endl;


    return 0;
}
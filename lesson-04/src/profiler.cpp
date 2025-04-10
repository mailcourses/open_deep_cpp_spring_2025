#include <iostream>
#include <chrono>
#include <thread>
#include <source_location>

using namespace std::chrono_literals;

struct Profiler
{
    Profiler(const std::string& func_name) : func_name(func_name) {
        // получаем текущее время
        start_ts = std::chrono::system_clock::now();
    }

    Profiler(const std::source_location &location = std::source_location::current()) : func_name(location.function_name()) {
        // получаем текущее время
        start_ts = std::chrono::system_clock::now();
        std::cout << "Filename: " << location.file_name() << std::endl;
    }
    ~Profiler() {
        // сохраняем время между вызовами конструктора и деструктора
        std::chrono::time_point<std::chrono::system_clock> end_ts = std::chrono::system_clock::now();
        uint64_t delta = std::chrono::duration_cast<std::chrono::milliseconds>( end_ts - start_ts ).count();
        std::cout << "Time of execution function [" << func_name << "] is " << delta << "ms\n";
    }

    std::chrono::time_point<std::chrono::system_clock> start_ts;
    std::string func_name;
};

void someFunction()
{
    Profiler prof("someFunction");
    // ...
    std::this_thread::sleep_for(200ms);
}

void anotherFunction()
{
    Profiler prof;
    // ...
    std::this_thread::sleep_for(500ms);
}

int main()
{
    someFunction();
    anotherFunction();
}

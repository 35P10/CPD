#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

class Timer{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
public:
    Timer(){};
    void start(){
        _start = std::chrono::high_resolution_clock::now();       
    }
    void stop(){
        std::chrono::time_point<std::chrono::high_resolution_clock> _end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float,std::milli> duration = _end - _start;
        std::cout<<duration.count()<<" ms.\n";
    }
};

#include <chrono>
#include <iostream>

class TimeMeasure
{
private:
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
public:
    int getMsDuration();
    int getNsDuration();
    int getSecDuration();
    void startMeasure();
    void endMeasure();
};

void TimeMeasure::startMeasure(){
    TimeMeasure::begin = std::chrono::steady_clock::now();
}
void TimeMeasure::endMeasure(){
    TimeMeasure::end = std::chrono::steady_clock::now();
}

int TimeMeasure::getMsDuration(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(TimeMeasure::end - TimeMeasure::begin).count();
}

int TimeMeasure::getNsDuration(){
    return std::chrono::duration_cast<std::chrono::microseconds>(TimeMeasure::end - TimeMeasure::begin).count();
}
int TimeMeasure::getSecDuration(){
    return std::chrono::duration_cast<std::chrono::seconds>(TimeMeasure::end - TimeMeasure::begin).count();
}



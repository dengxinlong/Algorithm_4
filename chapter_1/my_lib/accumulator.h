#include <string>

using namespace std;

class Accumulator
{
public:
    Accumulator(void)
    : _total(0)
    , _N(0)
    {}

    void add_data_value(double value)
    {
        _N++;
        _total += value;
    }

    double mean(void)
    {
        return _total / _N;
    }

    string to_string(void)
    {
        return string() + "Mean (" + std::to_string(_N) + " values): " + \
               std::to_string(mean());
    }


private:
    double _total;
    int _N;
};
#include <iostream>

#include "counter.h"
#include "date.h"
#include "Random.h"
#include "accumulator.h"

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        cout << "Argument is error.\n";
        return -1;
    }
    Counter heads("heads");
    Counter tails("tails");

    heads.increment();
    heads.increment();
    tails.increment();

    cout << heads.to_string() << endl;

    Date date(12, 2, 2019);
    cout << date.to_string() << endl;

    Random random;
    Accumulator accumulator;
    for (int i = 0; i < std::stoi(argv[1]); ++i)
    {
        accumulator.add_data_value(random.random());
    }
    cout << accumulator.to_string() << endl;

    return 0;
}
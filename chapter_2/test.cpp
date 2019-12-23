// #include "queue.h"

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(string path)
    {
        DIR * dirp = opendir(path.c_str());
        if (!dirp)
        {
            perror("opendir");
            exit(-1);
        }
        struct dirent * dirent;
        while (dirent = readdir(dirp))
        {
            if (dirent->d_type == DT_DIR)
            {
                cout << path + "/" + dirent->d_name << endl;
            }  
        }
        
    }
};

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        cout << "Argument is fail.\n";
        return -1;
    }

    Test::test(argv[1]);
        


    return 0;
}
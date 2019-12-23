#include "queue.h"

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(string path)
    {
        Queue<string> helper;
        helper.enqueue(path);
        //cout << path;
        string dir = path;
        while (!helper.isEmpty())
        {
            string path = helper.dequeue();
            cout << endl << path << "\t";
            DIR * dirp = opendir(path.c_str());
            if (!dirp)
            {
                perror("opendir");
                exit(-1);
            }
            struct dirent * dirent;
            while (dirent = readdir(dirp))
            {
                if (dirent->d_type == DT_DIR && string(dirent->d_name) != "."
                    && string(dirent->d_name) != "..")
                {
                    dir = dirent->d_name;
                    helper.enqueue(path + "/" + dirent->d_name);
                    // helper.enqueue(dirent->d_name);
                }
                else
                    cout << endl << "\t" << dirent->d_name;
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
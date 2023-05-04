//made by Bertrand -> https://github.com/Bertrand-DB
#ifndef NAMED_PIPE_H
#define NAMED_PIPE_H

#include <iostream>
#include <fstream>  
#include <sys/stat.h>
#include <errno.h>
#include <cstring>

#define DEFAULT_PATH "Default_Pipe"
#define DIDNT_CREATE -1
#define DONT_EXIST errno != EEXIST
#define READWRITE_MODE 0777

class Named_Pipe
{
public:
    Named_Pipe();
    Named_Pipe(const char* pipe_path);
    ~Named_Pipe();

    void pipeWrite(std::string data);
    std::string pipeRead();
    void pipeDelete();

private:
    std::string getErrorDetails();

    std::ofstream writingStream;
    std::ifstream readingStream;
    bool delete_flag;
    const char* path;
};
#endif

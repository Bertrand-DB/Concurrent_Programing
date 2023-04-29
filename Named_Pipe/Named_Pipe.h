//made by Bertrand -> https://github.com/Bertrand-DB
#ifndef NAMED_PIPE_H
#define NAMED_PIPE_H

#include <iostream>
#include <fstream>  
#include <sys/stat.h>
#include <errno.h>
#include <cstring>

#define DEFALT_PATH "Defalt_Pipe"

class Named_Pipe
{
public:
    Named_Pipe();                           // Constructor without arguments
    Named_Pipe(const char* pipe_path);      // Constructor with pipe path argument
    ~Named_Pipe();                          // Destructor

    void pWrite(std::string data);               // Function to write to the pipe
    std::string pRead();                         // Function to read from the pipe
    void getError();                        // Function to print error messages
    void pDelete();                         // Function to delete the pipe

private:
    std::ofstream pipeWR;                        // Output file stream for writing to the pipe
    std::ifstream pipeRD;                        // Input file stream for reading from the pipe
    int erro;                               // Error code
    bool del_flag;                          // Flag to indicate if the pipe should be deleted on close
    const char* path;                       // Path to the pipe

};

#endif

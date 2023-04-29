//made by Bertrand -> https://github.com/Bertrand-DB
#include "Named_Pipe.h"

Named_Pipe::Named_Pipe()
{
    path = DEFALT_PATH;                     // Use default pipe path
    del_flag = true;                        // Set delete flag to true by default
    erro = 0;                               // Set error code to 0 by default
}

Named_Pipe::Named_Pipe(const char* pipe_path)
{
    path = pipe_path;                       // Set pipe path to provided path
    del_flag = false;                       // Set delete flag to false by default
    erro = 0;                               // Set error code to 0 by default
}

Named_Pipe::~Named_Pipe()
{

}


void Named_Pipe::pDelete()
{
    if (remove(path) == -1)
        erro = 4;                           // Failed to delete pipe
}

void Named_Pipe::pWrite(std::string data)
{
                                            // Create pipe with permissions 0777
    if (mkfifo(path, 0777) == -1 && errno != EEXIST)           
        erro = 1;                           // Failed to create pipe


    pipeWR.open(path, std::ios::out);            // Open pipe for writing
    
    if (!pipeWR.is_open())
        erro = 2;                           // Failed to open pipe for writing

 
    pipeWR << data;                         // Write data to the pipe

  
    pipeWR.close();                         // Close pipe for writing

    if (pipeWR.is_open()) 
        erro = 3;                           // Failed to close pipe for writing
    
    if(del_flag)
        pDelete();                          // Delete pipe if delete flag is set
}

std::string Named_Pipe::pRead()
{
    std::string msg;
    
    if (mkfifo(path, 0777) == -1 && errno != EEXIST)
        erro = 1;                           // Failed to create pipe

    pipeRD.open(path, std::ios::in);             // Open pipe for reading
    
    if (!pipeRD.is_open()) 
        erro = 2;                           // Failed to open pipe for reading

  
    getline(pipeRD, msg);                   // Read from the pipe

  
    pipeRD.close();                         // Close pipe for reading

    if (pipeRD.is_open())
        erro = 3;                           // Failed to close pipe for reading

    if (del_flag)
        pDelete();                          // Delete pipe if delete flag is set
    
    return msg;                             // Return read data
}

void Named_Pipe::getError()
{
    switch (erro)
    {
    case 1:
        std::cerr << "[ERROR]: Failed to create the pipe\n";
        break;

    case 2:
        std::cerr << "[ERROR]: Failed to open the pipe\n";
        break;

    case 3:
        std::cerr << "[ERROR]: Failed to close the pipe\n";
        break;

    case 4:
        std::cerr << "[ERROR]: Failed to delete the pipe\n";
        break;
    
    default:
        break;
    }
}



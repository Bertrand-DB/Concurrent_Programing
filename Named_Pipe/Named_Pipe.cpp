//made by Bertrand -> https://github.com/Bertrand-DB
#include "Named_Pipe.h"

Named_Pipe::Named_Pipe()
{
    path = DEFAULT_PATH;
    delete_flag = true;
}

Named_Pipe::Named_Pipe(const char* pipe_path)
{
    path = pipe_path;
    delete_flag = false;
}

Named_Pipe::~Named_Pipe()
{

}

std::string Named_Pipe::getErrorDetails()
{
    std::string error;
    
    switch (errno) {
        case EBUSY:
            error = " (Resource busy)";
            break;
        case EACCES:
            error = " (Permission denied)";
            break;
        case ENOENT:
            error = " (No such file or directory)";
            break;
        case EINVAL:
            error = " (Invalid argument)";
            break;
        case ENXIO:
            error = " (No such device or address)";
            break;
        case EIO:
            error = " (Input/output error)";
            break;
        case EINTR:
            error = " (Interrupted function call)";
            break;
        default:
            error = " (Unknown error)";
            break;
    }
    return error;
}

void Named_Pipe::pipeDelete()
{
    try
    {
        if (remove(path))
            throw "[EXCEPTION] Failed to delete the pipe";
    }
    catch(const char* generic_error)
    {
        std::string error_messege = generic_error + getErrorDetails() + "\n";
        std::cerr << error_messege;
    }
}

void Named_Pipe::pipeWrite(std::string data)
{
    try
    {
        if (mkfifo(path, READWRITE_MODE) == DIDNT_CREATE && DONT_EXIST)
        throw "[EXCEPTION] Failed to create the pipe";

        writingStream.open(path, std::ios::out);
    
        if (!writingStream.is_open())
            throw "[EXCEPTION] Failed to open the pipe for writing";

        writingStream << data;

        writingStream.close();

        if (writingStream.is_open()) 
            throw "[EXCEPTION] Failed to close the pipe after writing";
    
        if(delete_flag)
            pipeDelete();
    }
    catch(const char* generic_error)
    {
        std::string error_messege = generic_error + getErrorDetails() + "\n";
        std::cerr << error_messege;
    }
}

std::string Named_Pipe::pipeRead()
{
    std::string data;
    
    try
    {
        if (mkfifo(path, READWRITE_MODE) == DIDNT_CREATE && DONT_EXIST)
            throw "[EXCEPTION] Failed to create the pipe";

        readingStream.open(path, std::ios::in);
        
        if (!readingStream.is_open()) 
            throw "[EXCEPTION] Failed to open the pipe for reading";

        getline(readingStream, data);
    
        readingStream.close();

        if (readingStream.is_open())
            throw "[EXCEPTION] Failed to close the pipe after reading";

        if (delete_flag)
            pipeDelete();
    }
    catch(const char* generic_error)
    {
        std::string error_messege = generic_error + getErrorDetails() + "\n";
        std::cerr << error_messege;
        return "ERROR!";
    }
    return data;
}

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

std::string Named_Pipe::reader()
{
    std::string data, buffer;
    int counter = 0;

    while (getline(readingStream, buffer))
    {
        data += buffer + "\n";
        ++counter;

        if (LIMIT_REACHED && !UNTIL_EOF)
            break;
    }

    return data;
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

void Named_Pipe::write_string(std::string data)
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

std::string Named_Pipe::reading_manager()
{
    std::string data = "ERROR!";
    try
    {
        if (mkfifo(path, READWRITE_MODE) == DIDNT_CREATE && DONT_EXIST)
            throw "[EXCEPTION] Failed to create the pipe";

        readingStream.open(path, std::ios::in);
        
        if (!readingStream.is_open()) 
            throw "[EXCEPTION] Failed to open the pipe for reading";
        
        data = reader();
    
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
    }
    return data;
}

std::string Named_Pipe::read_line(const unsigned int number_of_lines)
{
    this->number_of_lines = number_of_lines;
    return reading_manager();
}

std::string Named_Pipe::read_all()
{
    number_of_lines = EOF;
    return reading_manager();
}

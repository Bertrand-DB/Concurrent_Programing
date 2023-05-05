<h1>Named_Pipe Class Documentation</h1>

<h1>Class Description</h1>
<p>The Named_Pipe class simplifies inter-process communication using named pipes by abstracting the communication details and providing an intuitive interface for multiple processes to safely read and write to the same pipe.</p>

<h2>Public Members</h2>

<h3><code>Named_Pipe()</code></h3>
<p>The default constructor for the Named_Pipe class, which sets the file path to the current directory with <b>"Default_Path"</b> as its name that will be automatically deleted.</p>

<h3><code>Named_Pipe(const char* pipe_path)</code></h3>
<p>A constructor that creates a named pipe with the given path and name.</p>
<p><b>Parameters:</b></p>
<ul>
	<li><code>pipe_path</code>: The path and/or name of the pipe, like "/directory1/directory2/pipe_name" or just "pipe_name".</li>
</ul>

<h3><code>~Named_Pipe()</code></h3>
<p>The destructor for the Named_Pipe class. Closes the named pipe if it is open.</p>

<h3><code>void write_string(std::string data)</code></h3>
<p>Writes the specified string to the named pipe. If the named pipe does not exist, it is created with default read and write permissions. If an exception occurs while creating or writing to the pipe, an error message is printed to the standard error output. If the object was created with the default path, the pipe is deleted after writing.</p>
<p><b>Parameters:</b></p>
<ul>
    <li><code>data</code>: The string to be written to the named pipe.</li>
</ul>
<p><b>Example of expected content:</b></p>
<ul>
    <li>"string1\nstring2\n"</li>
</ul>

<h3><code>std::string read_all()</code></h3>
<p>Reads the entire contents of the named pipe and returns them as a single string. If the named pipe does not exist, it is created with default read and write permissions. If an exception occurs while creating or reading from the pipe, an error message is printed to the standard error output. If the object was created with the default path, the pipe is deleted after reading.</p>
<p><b>Example of expected content:</b></p>
<ul>
    <li>"string1"</li>
    <li>"string2"</li>
    <li>"string3"</li>
</ul>
<p><b>Return:</b></p>
<ul>
    <li>"string1\nstring2\nstring3\n"</li>
</ul>

<h3><code>std::string read_line(const unsigned int number_of_lines)</code></h3>
<p>Reads the specified number of lines from the named pipe and returns them as a single string. If the named pipe does not exist, it is created with default read and write permissions. If an exception occurs while creating or reading from the pipe, an error message is printed to the standard error output. If the object was created with the default path, the pipe is deleted after reading.</p>
<p><b>Parameters:</b></p>
<ul>
    <li><code>number_of_lines</code>: The number of lines to be read from the named pipe.</li>
</ul>
<p><b>Example of expected content:</b></p>
<ul>
    <li>"string1"</li>
    <li>"string2"</li>
    <li>"string3"</li>
</ul>
<p><b>Return:</b> (Considering that was passed 2 in number_of_lines)</p>
<ul>
    <li>"string1\nstring2\n"</li>
</ul>

<h3><code>void pipeDelete()</code></h3>
<p>Deletes the named pipe file. If an exception occurs while deleting the pipe, an error message is printed to the standard error output.</p>

<h2>Private Members</h2>
<p>The following member variables are private and cannot be accessed directly from outside the class.</p>

<h3><code>std::string getErrorDetails()</code></h3>
<p>A private member function that returns detailed error information.</p>

<h3><code>std::string reading_manager()</code></h3>
<p>A private member function that is responsible for creating, opening, and closing the named pipe for reading, as well as checking for errors and returning the data read by the function std::string reader().</p>

<h3><code>std::string reader()</code></h3>
<p>A private member function that is responsible for reading the specified number of lines and returning the data in the appropriate format.</p>

<h3><code>std::ofstream writingStream</code></h3>
<p>A private member variable that represents the output stream for writing to the named pipe.</p>

<h3><code>std::ifstream readingStream</code></h3>
<p>A private member variable that represents the input stream for reading from the named pipe.</p>

<h3><code>bool delete_flag</code></h3>
<p>A private member variable that indicates whether the named pipe should be deleted after use.</p>

<h3><code>const char* path</code></h3>
<p>A private member variable that holds the path of the named pipe.</p>

<h3><code>int number_of_lines</code></h3>
<p>A private member variable that stores the number of lines to be read.</p>

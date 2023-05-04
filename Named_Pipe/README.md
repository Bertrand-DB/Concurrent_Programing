<h1>Named_Pipe Class Documentation</h1>

<h1>Class Description</h1>
<p>The Named_Pipe class simplifies inter-process communication using named pipes by abstracting the communication details and providing an intuitive interface for multiple processes to safely read and write to the same pipe.</p>

<h2>Public Members</h2>

<h3><code>Named_Pipe()</code></h3>
<p>The default constructor for the Named_Pipe class, which sets the file path to the current directory with a default name that will be automatically deleted.</p>

<h3><code>Named_Pipe(const char* pipe_path)</code></h3>
<p>A constructor that creates a named pipe with the given path and name.</p>
<p>Parameters:</p>
<ul>
	<li><code>pipe_path</code>: The path and/or name of the pipe, like "/directory1/directory2/pipe_name" or just "pipe_name".</li>
</ul>

<h3><code>~Named_Pipe()</code></h3>
<p>The destructor for the Named_Pipe class. Closes the named pipe if it is open.</p>

<h3><code>void pipeWrite(std::string data)</code></h3>
<p>A member function that writes data to the named pipe.</p>
<p>Parameters:</p>
<ul>
	<li><code>data</code>: The data to be written to the pipe. It must pass only one line at a time, just as the reading is done.</li>
</ul>

<h3><code>std::string pipeRead()</code></h3>
<p>A member function that reads data from the named pipe.</p>
<p>Returns:</p>
<ul>
	<li>The data read from the pipe as a string.</li>
</ul>

<h3><code>void pipeDelete()</code></h3>
<p>A member function that deletes the named pipe.</p>

<h2>Private Members</h2>
<p>The following member variables are private and cannot be accessed directly from outside the class.</p>

<h3><code>std::string getErrorDetails()</code></h3>
<p>A private member function that returns detailed error information.</p>

<h3><code>std::ofstream writingStream</code></h3>
<p>A private member variable that represents the output stream for writing to the named pipe.</p>

<h3><code>std::ifstream readingStream</code></h3>
<p>A private member variable that represents the input stream for reading from the named pipe.</p>

<h3><code>bool delete_flag</code></h3>
<p>A private member variable that indicates whether the named pipe should be deleted after use.</p>

<h3><code>const char* path</code></h3>
<p>A private member variable that holds the path of the named pipe.</p>

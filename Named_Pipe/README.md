<h1>Named_Pipe</h1>

<p>The Named_Pipe class is responsible for <b>CREATING</b> a named pipe, <b>WRITING</b> data to it, <b>READING</b> data from it, <b>CHECKING ERRORS</b>, and <b>DELETING</b> the pipe.</p>

<h3>Its attributes are:</h3>
<ul>
  <li>an ofstream pipeWR (for writing);</li>
  <li>an ifstream pipeRD (for reading);</li>
  <li>an integer error (for storing errors);</li>
  <li>a bool del_flag (for checking if the pipe should be deleted after execution).</li>
</ul>
  
<h3>The methods include:</h3>
<ul>
  <li>A default constructor that allows for the deletion of the named pipe after execution and creates the file in the same directory.</li>
  <li>A constructor that keeps the named pipe after execution and creates the file in the defined directory.</li>
  <li>A default destructor.</li>
  <li>A method <b>pDelete()</b> that removes the created pipe.</li>
  <li>A method <b>pWrite(string data)</b> that writes a string to the pipe.</li>
  <li>A method <b>pRead()</b> that reads a string from the pipe.</li>
  <li>A method <b>getError()</b> that prints an error message based on the error code stored in the error attribute.</li>
</ul>

<h3>The libraries used:</h3>
<ul>
  <li>iostream</li>
  <li>fstream</li>
  <li>sys/stat.h</li>
  <li>errno.h</li>
  <li>cstring</li>
</ul>

<h3>The defined constants:</h3>
 <ul>
   <li>DEFAULT_PATH (default value for the named pipe's path)</li>
 </ul>

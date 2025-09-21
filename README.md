MyGrep

A simple grep-like utility implemented in C++ that searches for patterns in files.
Features

    Search for text patterns in files

    Support for line numbering (-n flag)

    Support for match counting (-c flag)

    Efficient file reading with buffer optimization

    Error handling for common file operations

Usage
bash

./my_grep [OPTIONS] PATTERN FILENAME

Options

    -n : Print line numbers with output lines

    -c : Print only a count of matching lines

Examples

    Basic search:
    bash

./my_grep "search_text" file.txt

Search with line numbers:
bash

./my_grep -n "search_text" file.txt

Count matches:
bash

./my_grep -c "search_text" file.txt

Building

Compile the program with g++:
bash

g++ my_grep.cpp -o my_grep -std=c++11

Implementation Details

    Uses low-level file I/O with open() and read() for efficiency

    Implements buffered reading (4KB buffer) for better performance

    Handles various error conditions including:

        Missing or inaccessible files

        Empty files

        Read errors

    Supports both line-numbered output and match counting

Limitations

    Pattern matching is case-sensitive

    Does not support regular expressions (exact string matching only)

    Limited to searching in single files (no directory traversal)

Error Messages

The program provides descriptive error messages for:

    Insufficient arguments

    File not found or inaccessible

    Empty files

    File reading errors

Contributing

Feel free to submit issues and enhancement requests!

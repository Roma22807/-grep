# MyGrep

A simple grep-like utility implemented in C++.

## Features

- Search for a pattern in a file
- Support for command-line options:
  - `-n`: Print line numbers along with matching lines
  - `-c`: Print only the count of matching lines
- Handles empty files and read errors

## Usage

```bash
./my_grep [OPTIONS] PATTERN FILE

#include <iostream>
#include <unistd.h>
#include <memory>
#include <vector>
#include <string>
#include <fcntl.h>
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "ERROR: too little arguments!\n";
        return 1;
    }
    bool num = false;
    bool count = false;
    std::string filename;
    std::string name;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-n") num = true;
        else if (arg == "-c") count = true;
        else if (name.length() == 0) {
            name += arg;
        } else {
           filename = arg; 
        }
    }
    if (filename.empty()) {
        std::cerr << "ERROR: no such file in directory\n";
        return 1;
    }
    int fd = open(filename.c_str(), O_RDONLY);
        if (fd == -1) {
            std::cerr << "ERROR: problem with opening the file\n";
            return 1;
        }
    ssize_t read_bytes;
    const size_t buffer_size = 4096;
    std::unique_ptr<char[]> buffer = std::make_unique<char[]>(buffer_size);
    std::vector<std::string> arr;
    std::string current_line;
    while ((read_bytes = read(fd, buffer.get(), buffer_size)) > 0) {
        for (ssize_t i = 0; i < read_bytes; i++) {
            if (buffer[i] != '\n') {
                current_line += buffer[i];
            } else {
                arr.push_back(current_line);
                current_line.clear();
            }
        }
    }
    if (read_bytes == -1) {
        std::cerr << "ERROR: problem with reading the file\n";
        close(fd);
        return 1;
    }
    if (!current_line.empty()) {
        arr.push_back(current_line);
        current_line.clear();
    }
    std::vector<std::string> lines;
    std::vector<int> counts;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        std::string str = arr[i];
            if (str.find(name) != std::string::npos) {
                if (count) {
                    sum++;
                }
                if (num) {
                    counts.push_back(i + 1);
                    lines.push_back(arr[i]);
                } else {
                    lines.push_back(arr[i]);
                }
        }
    } 
    if (count) {
        std::cout << sum << "\n";
    } 
    if (num) {
        for (int i = 0; i < counts.size(); i++) {
            std::cout << counts[i] << ": " << lines[i] << "\n";
        }       
    }       
    if (!count && !num) {
    for (int i = 0; i < lines.size(); i++) {
        std::cout << lines[i] << "\n";
}
    }
    close(fd);
    return 0;
}
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <sysinfoapi.h>
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#endif

void printSystemDetails() {
#ifdef _WIN32
    // Windows-specific system details
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(memStatus);
    GlobalMemoryStatusEx(&memStatus);

    std::cout << "Operating System: Windows" << std::endl;
    std::cout << "Processor Architecture: " << sysInfo.wProcessorArchitecture << std::endl;
    std::cout << "Processor Count: " << sysInfo.dwNumberOfProcessors << std::endl;
    std::cout << "Total Physical Memory: " << memStatus.ullTotalPhys / (1024 * 1024) << " MB" << std::endl;
    std::cout << "Available Physical Memory: " << memStatus.ullAvailPhys / (1024 * 1024) << " MB" << std::endl;

#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    // Linux, Unix, and macOS system details
    struct utsname sysInfo;
    if (uname(&sysInfo) != 0) {
        std::cerr << "Unable to get system information!" << std::endl;
        return;
    }

    struct sysinfo memoryInfo;
    sysinfo(&memoryInfo);

    std::cout << "Operating System: " << sysInfo.sysname << std::endl;
    std::cout << "Node Name (Machine Name): " << sysInfo.nodename << std::endl;
    std::cout << "Release: " << sysInfo.release << std::endl;
    std::cout << "Version: " << sysInfo.version << std::endl;
    std::cout << "Machine: " << sysInfo.machine << std::endl;
    std::cout << "Processor Count: " << sysInfo.machine << std::endl;
    std::cout << "Total Physical Memory: " << memoryInfo.totalram / (1024 * 1024) << " MB" << std::endl;
    std::cout << "Available Physical Memory: " << memoryInfo.freeram / (1024 * 1024) << " MB" << std::endl;

#else
    std::cerr << "Unsupported OS!" << std::endl;
#endif
}

int main() {
    printSystemDetails();
    return 0;
}

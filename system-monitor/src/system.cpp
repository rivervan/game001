#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <set>
#include <string>



#include "process.h"
#include "processor.h"
#include "linux_parser.h"
#include <algorithm>
#include <iostream>

using std::set;
using std::size_t;
using std::string;
using std::vector;


// DONE: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// DONE: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
   
    processes_.clear();
    vector<int>  pids = LinuxParser::Pids(); 

    for(auto pid : pids){      
        Process p(pid);
         if(LinuxParser::Ram(pid) != "----")
            processes_.push_back(p);            
    }

    std::sort(processes_.begin(), processes_.end(), [](Process a, Process b ){ return b < a ;}  );       
    return processes_;     
}

// DONE: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel() ; }

// DONE: Return the system's memory utilization
float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization();    
}

// DONE: Return the operating system name
std::string System::OperatingSystem() { 
    return LinuxParser::OperatingSystem(); 
}

// DONE: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// DONE: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// DONE: Return the number of seconds since the system started running
long int System::UpTime() { 
    return LinuxParser::UpTime(); 
    }

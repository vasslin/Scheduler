# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/vasilina/Документы/ITMO/C++/lab9/public version"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/vasilina/Документы/ITMO/C++/lab9/public version/build"

# Include any dependencies generated for this target.
include bin/CMakeFiles/task_scheduler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin/CMakeFiles/task_scheduler.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/task_scheduler.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/task_scheduler.dir/flags.make

bin/CMakeFiles/task_scheduler.dir/main.cpp.o: bin/CMakeFiles/task_scheduler.dir/flags.make
bin/CMakeFiles/task_scheduler.dir/main.cpp.o: /home/vasilina/Документы/ITMO/C++/lab9/public\ version/bin/main.cpp
bin/CMakeFiles/task_scheduler.dir/main.cpp.o: bin/CMakeFiles/task_scheduler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/vasilina/Документы/ITMO/C++/lab9/public version/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/task_scheduler.dir/main.cpp.o"
	cd "/home/vasilina/Документы/ITMO/C++/lab9/public version/build/bin" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/CMakeFiles/task_scheduler.dir/main.cpp.o -MF CMakeFiles/task_scheduler.dir/main.cpp.o.d -o CMakeFiles/task_scheduler.dir/main.cpp.o -c "/home/vasilina/Документы/ITMO/C++/lab9/public version/bin/main.cpp"

bin/CMakeFiles/task_scheduler.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/task_scheduler.dir/main.cpp.i"
	cd "/home/vasilina/Документы/ITMO/C++/lab9/public version/build/bin" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/vasilina/Документы/ITMO/C++/lab9/public version/bin/main.cpp" > CMakeFiles/task_scheduler.dir/main.cpp.i

bin/CMakeFiles/task_scheduler.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/task_scheduler.dir/main.cpp.s"
	cd "/home/vasilina/Документы/ITMO/C++/lab9/public version/build/bin" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/vasilina/Документы/ITMO/C++/lab9/public version/bin/main.cpp" -o CMakeFiles/task_scheduler.dir/main.cpp.s

# Object files for target task_scheduler
task_scheduler_OBJECTS = \
"CMakeFiles/task_scheduler.dir/main.cpp.o"

# External object files for target task_scheduler
task_scheduler_EXTERNAL_OBJECTS =

bin/task_scheduler: bin/CMakeFiles/task_scheduler.dir/main.cpp.o
bin/task_scheduler: bin/CMakeFiles/task_scheduler.dir/build.make
bin/task_scheduler: bin/CMakeFiles/task_scheduler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/vasilina/Документы/ITMO/C++/lab9/public version/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task_scheduler"
	cd "/home/vasilina/Документы/ITMO/C++/lab9/public version/build/bin" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task_scheduler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/task_scheduler.dir/build: bin/task_scheduler
.PHONY : bin/CMakeFiles/task_scheduler.dir/build

bin/CMakeFiles/task_scheduler.dir/clean:
	cd "/home/vasilina/Документы/ITMO/C++/lab9/public version/build/bin" && $(CMAKE_COMMAND) -P CMakeFiles/task_scheduler.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/task_scheduler.dir/clean

bin/CMakeFiles/task_scheduler.dir/depend:
	cd "/home/vasilina/Документы/ITMO/C++/lab9/public version/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/vasilina/Документы/ITMO/C++/lab9/public version" "/home/vasilina/Документы/ITMO/C++/lab9/public version/bin" "/home/vasilina/Документы/ITMO/C++/lab9/public version/build" "/home/vasilina/Документы/ITMO/C++/lab9/public version/build/bin" "/home/vasilina/Документы/ITMO/C++/lab9/public version/build/bin/CMakeFiles/task_scheduler.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : bin/CMakeFiles/task_scheduler.dir/depend


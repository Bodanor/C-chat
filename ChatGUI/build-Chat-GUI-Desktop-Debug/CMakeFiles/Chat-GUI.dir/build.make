# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/Chat-GUI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Chat-GUI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Chat-GUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chat-GUI.dir/flags.make

CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o: CMakeFiles/Chat-GUI.dir/flags.make
CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o: Chat-GUI_autogen/mocs_compilation.cpp
CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o: CMakeFiles/Chat-GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o -MF CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o -c /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/Chat-GUI_autogen/mocs_compilation.cpp

CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/Chat-GUI_autogen/mocs_compilation.cpp > CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.i

CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/Chat-GUI_autogen/mocs_compilation.cpp -o CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.s

CMakeFiles/Chat-GUI.dir/main.cpp.o: CMakeFiles/Chat-GUI.dir/flags.make
CMakeFiles/Chat-GUI.dir/main.cpp.o: /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/main.cpp
CMakeFiles/Chat-GUI.dir/main.cpp.o: CMakeFiles/Chat-GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Chat-GUI.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chat-GUI.dir/main.cpp.o -MF CMakeFiles/Chat-GUI.dir/main.cpp.o.d -o CMakeFiles/Chat-GUI.dir/main.cpp.o -c /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/main.cpp

CMakeFiles/Chat-GUI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chat-GUI.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/main.cpp > CMakeFiles/Chat-GUI.dir/main.cpp.i

CMakeFiles/Chat-GUI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chat-GUI.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/main.cpp -o CMakeFiles/Chat-GUI.dir/main.cpp.s

CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o: CMakeFiles/Chat-GUI.dir/flags.make
CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o: /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/mainwindow.cpp
CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o: CMakeFiles/Chat-GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o -MF CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o.d -o CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o -c /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/mainwindow.cpp

CMakeFiles/Chat-GUI.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chat-GUI.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/mainwindow.cpp > CMakeFiles/Chat-GUI.dir/mainwindow.cpp.i

CMakeFiles/Chat-GUI.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chat-GUI.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI/mainwindow.cpp -o CMakeFiles/Chat-GUI.dir/mainwindow.cpp.s

# Object files for target Chat-GUI
Chat__GUI_OBJECTS = \
"CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Chat-GUI.dir/main.cpp.o" \
"CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o"

# External object files for target Chat-GUI
Chat__GUI_EXTERNAL_OBJECTS =

Chat-GUI: CMakeFiles/Chat-GUI.dir/Chat-GUI_autogen/mocs_compilation.cpp.o
Chat-GUI: CMakeFiles/Chat-GUI.dir/main.cpp.o
Chat-GUI: CMakeFiles/Chat-GUI.dir/mainwindow.cpp.o
Chat-GUI: CMakeFiles/Chat-GUI.dir/build.make
Chat-GUI: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.8
Chat-GUI: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.8
Chat-GUI: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.8
Chat-GUI: CMakeFiles/Chat-GUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Chat-GUI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chat-GUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chat-GUI.dir/build: Chat-GUI
.PHONY : CMakeFiles/Chat-GUI.dir/build

CMakeFiles/Chat-GUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chat-GUI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chat-GUI.dir/clean

CMakeFiles/Chat-GUI.dir/depend:
	cd /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI /home/liwinux/Desktop/chat/ChatGUI/Chat-GUI /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug /home/liwinux/Desktop/chat/ChatGUI/build-Chat-GUI-Desktop-Debug/CMakeFiles/Chat-GUI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chat-GUI.dir/depend


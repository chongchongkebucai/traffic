# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/congxiang/work/TrafficSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/congxiang/work/TrafficSimulator/build

# Include any dependencies generated for this target.
include CMakeFiles/traffic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/traffic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/traffic.dir/flags.make

CMakeFiles/traffic.dir/db/Graph.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/db/Graph.cc.o: ../db/Graph.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/traffic.dir/db/Graph.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/db/Graph.cc.o -c /home/congxiang/work/TrafficSimulator/db/Graph.cc

CMakeFiles/traffic.dir/db/Graph.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/db/Graph.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/db/Graph.cc > CMakeFiles/traffic.dir/db/Graph.cc.i

CMakeFiles/traffic.dir/db/Graph.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/db/Graph.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/db/Graph.cc -o CMakeFiles/traffic.dir/db/Graph.cc.s

CMakeFiles/traffic.dir/db/Map.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/db/Map.cc.o: ../db/Map.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/traffic.dir/db/Map.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/db/Map.cc.o -c /home/congxiang/work/TrafficSimulator/db/Map.cc

CMakeFiles/traffic.dir/db/Map.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/db/Map.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/db/Map.cc > CMakeFiles/traffic.dir/db/Map.cc.i

CMakeFiles/traffic.dir/db/Map.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/db/Map.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/db/Map.cc -o CMakeFiles/traffic.dir/db/Map.cc.s

CMakeFiles/traffic.dir/db/Person.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/db/Person.cc.o: ../db/Person.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/traffic.dir/db/Person.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/db/Person.cc.o -c /home/congxiang/work/TrafficSimulator/db/Person.cc

CMakeFiles/traffic.dir/db/Person.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/db/Person.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/db/Person.cc > CMakeFiles/traffic.dir/db/Person.cc.i

CMakeFiles/traffic.dir/db/Person.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/db/Person.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/db/Person.cc -o CMakeFiles/traffic.dir/db/Person.cc.s

CMakeFiles/traffic.dir/db/Bicycle.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/db/Bicycle.cc.o: ../db/Bicycle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/traffic.dir/db/Bicycle.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/db/Bicycle.cc.o -c /home/congxiang/work/TrafficSimulator/db/Bicycle.cc

CMakeFiles/traffic.dir/db/Bicycle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/db/Bicycle.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/db/Bicycle.cc > CMakeFiles/traffic.dir/db/Bicycle.cc.i

CMakeFiles/traffic.dir/db/Bicycle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/db/Bicycle.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/db/Bicycle.cc -o CMakeFiles/traffic.dir/db/Bicycle.cc.s

CMakeFiles/traffic.dir/db/Tricycle.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/db/Tricycle.cc.o: ../db/Tricycle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/traffic.dir/db/Tricycle.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/db/Tricycle.cc.o -c /home/congxiang/work/TrafficSimulator/db/Tricycle.cc

CMakeFiles/traffic.dir/db/Tricycle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/db/Tricycle.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/db/Tricycle.cc > CMakeFiles/traffic.dir/db/Tricycle.cc.i

CMakeFiles/traffic.dir/db/Tricycle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/db/Tricycle.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/db/Tricycle.cc -o CMakeFiles/traffic.dir/db/Tricycle.cc.s

CMakeFiles/traffic.dir/db/Electrocar.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/db/Electrocar.cc.o: ../db/Electrocar.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/traffic.dir/db/Electrocar.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/db/Electrocar.cc.o -c /home/congxiang/work/TrafficSimulator/db/Electrocar.cc

CMakeFiles/traffic.dir/db/Electrocar.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/db/Electrocar.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/db/Electrocar.cc > CMakeFiles/traffic.dir/db/Electrocar.cc.i

CMakeFiles/traffic.dir/db/Electrocar.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/db/Electrocar.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/db/Electrocar.cc -o CMakeFiles/traffic.dir/db/Electrocar.cc.s

CMakeFiles/traffic.dir/db/Transport.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/db/Transport.cc.o: ../db/Transport.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/traffic.dir/db/Transport.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/db/Transport.cc.o -c /home/congxiang/work/TrafficSimulator/db/Transport.cc

CMakeFiles/traffic.dir/db/Transport.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/db/Transport.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/db/Transport.cc > CMakeFiles/traffic.dir/db/Transport.cc.i

CMakeFiles/traffic.dir/db/Transport.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/db/Transport.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/db/Transport.cc -o CMakeFiles/traffic.dir/db/Transport.cc.s

CMakeFiles/traffic.dir/io/Log.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/io/Log.cc.o: ../io/Log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/traffic.dir/io/Log.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/io/Log.cc.o -c /home/congxiang/work/TrafficSimulator/io/Log.cc

CMakeFiles/traffic.dir/io/Log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/io/Log.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/io/Log.cc > CMakeFiles/traffic.dir/io/Log.cc.i

CMakeFiles/traffic.dir/io/Log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/io/Log.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/io/Log.cc -o CMakeFiles/traffic.dir/io/Log.cc.s

CMakeFiles/traffic.dir/manager/Manager.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/manager/Manager.cc.o: ../manager/Manager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/traffic.dir/manager/Manager.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/manager/Manager.cc.o -c /home/congxiang/work/TrafficSimulator/manager/Manager.cc

CMakeFiles/traffic.dir/manager/Manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/manager/Manager.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/manager/Manager.cc > CMakeFiles/traffic.dir/manager/Manager.cc.i

CMakeFiles/traffic.dir/manager/Manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/manager/Manager.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/manager/Manager.cc -o CMakeFiles/traffic.dir/manager/Manager.cc.s

CMakeFiles/traffic.dir/random/Random.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/random/Random.cc.o: ../random/Random.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/traffic.dir/random/Random.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/random/Random.cc.o -c /home/congxiang/work/TrafficSimulator/random/Random.cc

CMakeFiles/traffic.dir/random/Random.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/random/Random.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/random/Random.cc > CMakeFiles/traffic.dir/random/Random.cc.i

CMakeFiles/traffic.dir/random/Random.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/random/Random.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/random/Random.cc -o CMakeFiles/traffic.dir/random/Random.cc.s

CMakeFiles/traffic.dir/Simulator.cc.o: CMakeFiles/traffic.dir/flags.make
CMakeFiles/traffic.dir/Simulator.cc.o: ../Simulator.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/traffic.dir/Simulator.cc.o"
	/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic.dir/Simulator.cc.o -c /home/congxiang/work/TrafficSimulator/Simulator.cc

CMakeFiles/traffic.dir/Simulator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic.dir/Simulator.cc.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/congxiang/work/TrafficSimulator/Simulator.cc > CMakeFiles/traffic.dir/Simulator.cc.i

CMakeFiles/traffic.dir/Simulator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic.dir/Simulator.cc.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/congxiang/work/TrafficSimulator/Simulator.cc -o CMakeFiles/traffic.dir/Simulator.cc.s

# Object files for target traffic
traffic_OBJECTS = \
"CMakeFiles/traffic.dir/db/Graph.cc.o" \
"CMakeFiles/traffic.dir/db/Map.cc.o" \
"CMakeFiles/traffic.dir/db/Person.cc.o" \
"CMakeFiles/traffic.dir/db/Bicycle.cc.o" \
"CMakeFiles/traffic.dir/db/Tricycle.cc.o" \
"CMakeFiles/traffic.dir/db/Electrocar.cc.o" \
"CMakeFiles/traffic.dir/db/Transport.cc.o" \
"CMakeFiles/traffic.dir/io/Log.cc.o" \
"CMakeFiles/traffic.dir/manager/Manager.cc.o" \
"CMakeFiles/traffic.dir/random/Random.cc.o" \
"CMakeFiles/traffic.dir/Simulator.cc.o"

# External object files for target traffic
traffic_EXTERNAL_OBJECTS =

libtraffic.a: CMakeFiles/traffic.dir/db/Graph.cc.o
libtraffic.a: CMakeFiles/traffic.dir/db/Map.cc.o
libtraffic.a: CMakeFiles/traffic.dir/db/Person.cc.o
libtraffic.a: CMakeFiles/traffic.dir/db/Bicycle.cc.o
libtraffic.a: CMakeFiles/traffic.dir/db/Tricycle.cc.o
libtraffic.a: CMakeFiles/traffic.dir/db/Electrocar.cc.o
libtraffic.a: CMakeFiles/traffic.dir/db/Transport.cc.o
libtraffic.a: CMakeFiles/traffic.dir/io/Log.cc.o
libtraffic.a: CMakeFiles/traffic.dir/manager/Manager.cc.o
libtraffic.a: CMakeFiles/traffic.dir/random/Random.cc.o
libtraffic.a: CMakeFiles/traffic.dir/Simulator.cc.o
libtraffic.a: CMakeFiles/traffic.dir/build.make
libtraffic.a: CMakeFiles/traffic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/congxiang/work/TrafficSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library libtraffic.a"
	$(CMAKE_COMMAND) -P CMakeFiles/traffic.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/traffic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/traffic.dir/build: libtraffic.a

.PHONY : CMakeFiles/traffic.dir/build

CMakeFiles/traffic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/traffic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/traffic.dir/clean

CMakeFiles/traffic.dir/depend:
	cd /home/congxiang/work/TrafficSimulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/congxiang/work/TrafficSimulator /home/congxiang/work/TrafficSimulator /home/congxiang/work/TrafficSimulator/build /home/congxiang/work/TrafficSimulator/build /home/congxiang/work/TrafficSimulator/build/CMakeFiles/traffic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/traffic.dir/depend

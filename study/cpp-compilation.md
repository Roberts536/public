# Visual Studio Code for C++

Remember if you are using the Windows compilers, you need to open VS Code from the Developer Command prompt. This makes sure the relevant environment variables have been set.

- `tasks.json` are the build instructions. 
- `launch.json` are the debugger settings
- `cpp_properties.json` are extra settings, like the compiler path and IntelliSense settings

## Manual setup
This section is about setting up compilation and launch without build management systems like CMake.

### Compilation

From the main menu, choose Terminal -> Configure Default Build Task to create a `tasks.json`.

There are a range of compilers available including:
  - `cl.exe`, provided by Visual Studio
  - `g++`, the GNU Compiler Collective (includes GCC)
  - `cpp.exe`

### Launching

From the man menu, choose Run -> Add Configuration to generate a `launch.json`.

The task will usually include a build instruction, specified in the `preLaunchTask` setting.

From: https://code.visualstudio.com/docs/cpp/config-msvc 

### More settings

To create or open a `cpp_properties.json`, run `C/C++: Edit Configurations ([UI | JSON])` from the Command Palette.

### Useful variables

* `${workspaceFolder}` - the path of the folder opened in VS Code
* `${cwd}` - the task runner's current working directory on startup

You can also reference environment variables through the `${env:Name}` syntax (for example, `${env:USERNAME}`).

## Setup using CMake
The purpose of CMake is to manage the build process in a compiler-independent manner. CMake will create build files appropriate to the host, e.g. Makefiles on UNIX and projects/workspaces for MSVC. (From: https://cmake.org/overview/)

The term CMake is used to refer to a family of tools including CMake itself, and CPack, a packaging tool that prepares a project for distribution.

Some tips on CMake file syntax (including if statements, loops etc.) can be found here: http://mathnathan.com/2010/07/getting-started-with-cmake/

Make sure you have the C/C++ extension and the CMake Tools extension installed before beginning.

### Quick start
* You can select `CMake: Quick Start` to configure a new project quickly. Otherwise you'll need to write the CMakeLists yourself and then run `CMake: Configure` to check the configurations work out.
* Run `CMake: Build` to build the project. The output files will be in a directory whose name corresponds the build variant (e.g. Debug), inside the `build` directory.
* Generate a `launch.json` file in the manner described in the previous section (Run -> Add Configuration), then enter the location of the executable from the previous step into the `program` field.
* Press F5 to run the launch task.
* Note that you shouldn't need `tasks.json` or `cpp_properties.json`, because you can set all of the settings (like compiler location) in the `CMakeLists.txt`.

### Misc
* From within the `build` folder, you can see CMake cached variables by running `cmake -L -N .`. CMake stores variables in the cache if they are expected to stay constant or are expensive to compute, such as the generator.
* There is a GUI version and a console version of CMake, which you can open with the commands `cmake-gui` and `ccmake` respectively.
* There is a good CMake walkthrough on https://preshing.com/20170511/how-to-build-a-cmake-based-project/

### Debugging
* Beware that once CMake runs once with one compiler, it will ignore options like `set(CMAKE_CXX_COMPILER_ID MSVC)` in the `CMakeLists.txt`, so you have to find another way to change the compiler.
* If your C++ program uses system headers that are specific to an OS (like `unistd.h` is specific to UNIX systems), you will need to find a port of those headers for the host system. For example, Cygwin has ports of the UNIX headers. You'll need to use CMake from within Cygwin to do this. See the answer here for an overview of Cygwin: https://stackoverflow.com/questions/771756/what-is-the-difference-between-cygwin-and-mingw?rq=1

### Using Cygwin

If you need Linux utilities like header files, you'll need to run CMake within Cygwin.

Download the Cygwin installer and ensure `cmake` and `make` packages are selected (if you already have Cygwin installed, it will just update existing packages and add the new ones). You might also want to install the packages for `gdb` so that you can run the program once it's built.

CMake doesn't always default to the latest version of C++, so you might want to do `set (CMAKE_CXX_STANDARD 17)` in your root `CMakeLists.txt` to ensure all of your language features work as expected.

Remember that CMake just generates the build scripts; you have to run `make` in the `build` directory afterwards to actually build your system!

If you're using Python and it can't find the files, you may be using the Windows version of Python. See this answer: https://stackoverflow.com/questions/15334201/correct-path-usage-in-cygwin-difference-between-python-c-somefile-py-pyt . You can install the `python37` and `python37-pip` packages from the Cygwin installer. You'll then need to run CMake with the flat `-DPYTHON_EXECUTABLE="[path to python executable]"`

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

### Debugging
* Beware that once CMake runs once with one compiler, it will ignore options like `set(CMAKE_CXX_COMPILER_ID MSVC)` in the `CMakeLists.txt`, so you have to find another way to change the compiler.
* If you use `#include <filesystem>` and compile with MSVC, you may need to `#include <functional>` right below it. The `functional` library concerns function objects, which are objects that behave like functions.

# CoronaSafe Challenge 2020

This CLI App has been made as per the required specs.

## Installation

After Unzipping the content, you'll be greeted with a Source File 'todo.cpp' which needs to be substituted against the files that was provided along with the C++ [repo](https://apply.pupilfirst.org/students/task/cpp) from the Challenge Page.


## Usage (Copied)

### Getting started

1. Install CPP: You should have build support for cpp on your system.

2. You are expected to write the code in `todo.cpp` file.

3. You should be able to build the app by running `make app`.

4. Once you are done with the changes you should be able to execute the todo app by running the following command from the terminal.

   **On Windows:**

   ```
   .\todo.bat
   ```

   **On \*nix:**

   ```
   ./todo.sh
   ```
### Run Automated Tests

#### 1. Install Node.js

You need to have npm installed in your computer for this problem. It comes with Node.js and you can get it by installing Node from https://nodejs.org/en/

#### 2. Install dependencies

Run `npm install` to install all dependencies.

#### 3. Create Create symbolic link to the executable file

#### On Windows

To create a symbolic link on Windows, you'll need to run either the Windows Command Prompt, or Windows Powershell **with administrator privileges**. To do so, right-click on the icon for Command Prompt, or Powershell, and choose the _"Run as Administrator"_ option.

**Command Prompt:**

```
> mklink todo todo.bat
```

**Powershell:**

```
> cmd /c mklink todo todo.bat
```

#### On \*nix:

Run the following command in your shell:

```
$ ln -s todo.sh todo
```

#### 4. Try running tests.

Now run `npm test` and you will see all the tests failing. As you fill in each functionality, you can re-run the tests to see them passing one by one.

## A Note about `/` for Windows Users

In the following sections, you'll see many commands prefixed with `./`, or paths containing the `/` (forward-slash) character.

If you're using the Windows _Command Prompt_, then you'll need to replace `/` with `\` (back-slash) for these commands and paths to work as expected.

On Windows _Powershell_, these substitutions are not required.


## License
[MIT](https://choosealicense.com/licenses/mit/)
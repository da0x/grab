# Grab

## Description
**Grab** is a C++ program designed to automate the process of cloning a Git repository, building it using the 'make' command, and installing the resulting application. It does so within a temporary directory, ensuring a clean and isolated environment for the build process.

## Prerequisites
Before using **Grab**, make sure you have the following prerequisites installed on your system:
- C++ compiler
- Git
- Make

## How to Use
Follow these steps to use the **Grab** program:

1. Clone the repository containing this program to your local machine.

   ```
   git clone <repository_url>
   ```

2. Build the program.

   ```
   g++ -o grab grab.cpp
   ```

3. Execute the program with the desired Git repository path as a command-line argument.

   ```
   ./grab <repository_path>
   ```

   Replace `<repository_path>` with the path to the Git repository you want to clone, build, and install.

4. The program will perform the following steps:
   - Create a temporary directory in your system's temporary directory.
   - Clone the specified Git repository into the temporary directory.
   - Build the project using the 'make' command.
   - Install the application using 'make install.'
   - Clean up the temporary directory.

5. If any of the steps fail, the program will display an error message and exit with a non-zero status code.

6. If the installation process is successful, the program will display "Installation completed."

## Example Usage
Here's an example of how to use the **Grab** program:

```
./grab myusername/my-repo
```

Replace `myusername/my-repo` with the actual Git repository path you want to build and install.

## Note
- This program assumes that the Git repository is accessible via SSH (using the `git@github.com` URL format). If you need to use HTTPS or a different Git URL, you can modify the 'git clone' command in the source code accordingly.
- Be cautious when running this program, as it involves executing shell commands. Ensure that you trust the repositories you are cloning and building.

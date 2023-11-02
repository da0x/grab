#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <cstdio>

using namespace std;
namespace fs = filesystem;

int run(const string& command) {
    int exitStatus = system(command.c_str());
    if (WIFEXITED(exitStatus) && WEXITSTATUS(exitStatus) == 0) {
        return 0;
    }
    return exitStatus;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "usage: " << argv[0] << " <path>" << endl;
        return 1;
    }

    string input_path = argv[1];

    fs::path temp_dir = fs::temp_directory_path();
    fs::path temp_path = temp_dir / input_path;
    fs::create_directories(temp_path);
    fs::path original_path = fs::current_path();
    fs::current_path(temp_path);

    run("pwd");
    int git_clone_result = run("git clone --depth 1 git@github.com:" + input_path + ".git .");

    if (git_clone_result != 0) {
        cerr << "Error during 'git clone' command." << endl;
        fs::current_path(original_path);
        fs::remove_all(temp_path);
        return 1;
    }

    int make_result = run("make");

    if (make_result != 0) {
        cerr << "Error during 'make' command." << endl;
        fs::current_path(original_path);
        fs::remove_all(temp_path);
        return 1;
    }

    int make_install_result = run("make install");

    if (make_install_result != 0) {
        cerr << "Error during 'make install' command." << endl;
        fs::current_path(original_path);
        fs::remove_all(temp_path);
        return 1;
    }

    fs::current_path(original_path);
    fs::remove_all(temp_path);

    cout << "Installation completed." << endl;

    return 0;
}


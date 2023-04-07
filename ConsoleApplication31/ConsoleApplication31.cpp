#include <iostream>
#include <string>
using namespace std;

class FileWorker {
private:
    static FileWorker* instance;
    FileWorker() {}
public:
    static FileWorker* getInstance() {
        if (instance == nullptr) {
            instance = new FileWorker();
        }
        return instance;
    }

    void createFile(string path) {
        cout << "Creating file at " << path << endl;
    }

    void renameFile(string oldPath, string newPath) {
        cout << "Renaming file from " << oldPath << " to " << newPath << endl;
    }

    void deleteFile(string path) {
        cout << "Deleting file at " << path << endl;
    }

    bool checkFile(string path) {
        cout << "Checking for file at " << path << endl;
        return true;
    }
};

FileWorker* FileWorker::instance = nullptr;

int main() {
    FileWorker* fw1 = FileWorker::getInstance();
    FileWorker* fw2 = FileWorker::getInstance();

    fw1->createFile("file1.txt");
    fw2->renameFile("file1.txt", "file2.txt");
    fw1->deleteFile("file1.txt");
    fw2->checkFile("file2.txt");

    delete fw1;
    delete fw2;

    return 0;
}
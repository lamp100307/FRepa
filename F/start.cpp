#include "interpretator.h"

using namespace std;
int main() {
    cout << "write INPUT for input file path, START for start common file: ";
    string bebe;
    cin >> bebe;
    if (bebe == "INPUT") {
        cout << "write file path: ";
        string file_path;
        cin >> file_path;
        cout << "----------------------------------------------" << "\n";
        interpretator::start(file_path);
    } else if (bebe == "START") {
        cout << "----------------------------------------------"  << "\n";
        interpretator::start("C:\\Users\\dimon\\CLionProjects\\untitled\\F\\code.F");
    } else {
        cout << "wrong input";
    }
    // interpretator::start("C:\\Users\\dimon\\CLionProjects\\untitled\\F\\code.F");
    return 0;
}

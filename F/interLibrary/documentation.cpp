#include "documentation.h"
#include "../interpretator.h"
#include <string>
using namespace std;

void documentation::execute_documentation(const string &comman) {
    if (comman.starts_with("/*")) {
        if (comman.ends_with("*/")) {
        } else {
            interpretator::is_doc = true;
        }
    }
    if (interpretator::is_doc == true) {
        if (comman.starts_with("*/")) {
            interpretator::is_doc = false;
        }
    }
}

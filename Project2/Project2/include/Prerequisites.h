#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <json.hpp>

using json = nlohmann::json;

json j = {
    {"name", "John Doe"},
    {"age", 30},
    {"is_student", false},
    {"skills", {"C++", "Python", "JavaScript"}}
};

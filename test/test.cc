#include <cassert>
#include <iostream>
#include "../get_env.h"

using namespace std::string_literals;

auto main() -> int {
  auto r = get_env::getenv("aqwe", 2.2);
  std::cout << r << "\n";
}

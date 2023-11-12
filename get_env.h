#include <concepts>
#include <cstdlib>
#include <string>

namespace get_env {
template <typename T>
concept Value = std::is_same_v<std::string, std::decay_t<T>> ||
                std::is_integral_v<std::decay_t<T>> ||
                std::is_floating_point_v<std::decay_t<T>>;

inline namespace get_env_impl_v1 {
auto getenv(const char *var_name, Value auto default_value)
    -> std::decay_t<decltype(default_value)> {
  const char *tmp_env_var = std::getenv(var_name);
  auto env_var = std::string{tmp_env_var ? tmp_env_var : ""};
  if (env_var.empty()) {
    return default_value;
  }

  if constexpr (std::is_same_v<std::string,
                               std::decay_t<decltype(default_value)>>) {
    return std::string{env_var};
  } else if constexpr (std::is_floating_point_v<
                           std::decay_t<decltype(default_value)>>) {
    return static_cast<decltype(default_value)>(std::stod(env_var));
  } else if constexpr (std::is_integral_v<
                           std::decay_t<decltype(default_value)>>) {
    return static_cast<decltype(default_value)>(std::stoll(env_var));
  } else {
    static_assert(false, "Unsupported type.");
  }
}
} // namespace get_env_impl_v1
} // namespace get_env

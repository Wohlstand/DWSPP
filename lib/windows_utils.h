#ifndef WINDOWS_UTILS_H
#define WINDOWS_UTILS_H

#include <string>

namespace WindowsUtil
{

/**
 * @brief Check is file exists
 * @param filePath Path to file
 * @return true if given file exists
 */
bool fileExists(const std::wstring &filePath);

/**
 * @brief Get a string value from the Windows registry
 * @param path Path to the registry section
 * @param key Key
 * @param defaultValue Default value when registry key is absense
 * @return Requested value or default value
 */
std::wstring getRegistryString(const std::wstring &path, const std::wstring &key, const std::wstring &defaultValue = L"");

/**
 * @brief Returns the build number version
 * @return Windows build number version
 */
int GetWindowsBuildNumber();

/**
 * @brief Get the state of UAC sub-system
 * @return is UAC enabled or not
 */
bool UAC_Status();

/**
 * @brief Get the system restore status
 * @return status of System Restore
 */
int SystemRestore_Status();

/**
 * @brief Get operating system product name
 * @return Product name
 */
std::wstring GetProductName();

/**
 * @brief Get the system build label
 * @return System build label
 */
std::wstring GetSystemBuild();

}

#endif /* WINDOWS_UTILS_H */

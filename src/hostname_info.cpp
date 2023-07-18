#include "../CMakeProject4.h"
#include <cstring>

namespace HardwareInfo
{
#if defined(_WIN64) || defined(_WIN32)
#include <Windows.h>

  std::string getHostName()
  {
    TCHAR infoBuf[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD bufCharCount = MAX_COMPUTERNAME_LENGTH + 1;

    if (!GetComputerName(infoBuf, &bufCharCount))
      return "<unknown>";

    return std::string(infoBuf);
  }
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
#include <unistd.h>
#include <limits.h>

  std::string getHostName()
  {
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);

    if (std::strcmp(hostname, "") == 0)
      return "<unknown>";

    return std::string(hostname);
  }
#endif
}

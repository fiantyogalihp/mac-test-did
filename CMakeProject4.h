// CMakeProject4.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iomanip>
#include <string>
#include <iostream>

// #include <QtCore/qsysinfo.h>
// #include <QtCore/qdebug.h>
// #include <QtNetwork/qhostinfo.h>

namespace HardwareInfo
{
    void getHardwareInfo();
    std::string getHostName();
    std::string machineHash();
}

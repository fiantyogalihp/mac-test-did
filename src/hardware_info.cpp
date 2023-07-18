#include "../CMakeProject4.h"

#include <hwinfo/hwinfo.h>
#include <hwinfo/PCIMapper.h>

namespace HardwareInfo
{
  void getHardwareInfo()
  {
    std::cout << std::endl
              << "Hardware Report:" << std::endl
              << std::endl;

    std::cout << std::left << std::setw(20) << "Machine unique ID:";
    // qDebug().noquote() << QSysInfo::machineUniqueId();
    std::cout << machineHash() << std::endl;

    std::cout << "----------------------------------- CPU -----------------------------------" << std::endl;
    auto sockets = hwinfo::getAllSockets();
    for (auto &s : sockets)
    {
      const auto &cpu = s.CPU();
      std::cout << "Socket " << s.id() << ":\n";
      std::cout << std::left << std::setw(20) << " vendor:";
      std::cout << cpu.vendor() << std::endl;
      std::cout << std::left << std::setw(20) << " model:";
      std::cout << cpu.modelName() << std::endl;
      std::cout << std::left << std::setw(20) << " physical cores:";
      std::cout << cpu.numPhysicalCores() << std::endl;
      std::cout << std::left << std::setw(20) << " logical cores:";
      std::cout << cpu.numLogicalCores() << std::endl;
      std::cout << std::left << std::setw(20) << " cache size:";
      std::cout << cpu.cacheSize_Bytes() << std::endl;
    }

    hwinfo::OS os;
    std::cout << "----------------------------------- OS ------------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << "Operating System:";
    std::cout << os.fullName() << std::endl;

    std::cout << std::left << std::setw(20) << "Host name:";
    // qDebug().noquote() << QHostInfo::localHostName();
    std::cout << getHostName() << std::endl;

    std::cout << std::left << std::setw(20) << "short name:";
    std::cout << os.name() << std::endl;
    std::cout << std::left << std::setw(20) << "version:";
    // qDebug().noquote() << QSysInfo::kernelVersion();
    std::cout << os.version() << std::endl;

    std::cout << std::left << std::setw(20) << "kernel:";
    // qDebug().noquote() << QSysInfo::kernelType();
    std::cout << os.kernel() << std::endl;

    std::cout << std::left << std::setw(20) << "architecture:";
    std::cout << (os.is32bit() ? "32 bit" : "64 bit") << std::endl;
    std::cout << std::left << std::setw(20) << "endianess:";
    std::cout << (os.isLittleEndian() ? "little endian" : "big endian") << std::endl;

    hwinfo::MainBoard main_board;
    std::cout << "------------------------------- Main Board --------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << "vendor:";
    std::cout << main_board.vendor() << std::endl;
    std::cout << std::left << std::setw(20) << "model:";
    std::cout << main_board.name() << std::endl;
    std::cout << std::left << std::setw(20) << "version:";
    std::cout << main_board.version() << std::endl;
    std::cout << std::left << std::setw(20) << "serial-number:";
    std::cout << main_board.serialNumber() << std::endl;
  }
}

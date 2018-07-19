#pragma once
#include <memory>
#include <list>
#include <mutex>                // std::mutex, std::unique_lock
#include "Camera/Camera6467_plate.h"

//#include <thread>
//#include <atomic>
//#include <cctype>
//#include <iostream>
//#include <algorithm>

class DeviceListManager
{
public:
    static DeviceListManager* GetInstance();
public:
    size_t GetDeviceCount();
    void ClearAllDevice();
    void AddOneDevice(std::shared_ptr<Camera6467_plate> obj);
    bool FindIfExsit(std::shared_ptr<Camera6467_plate> obj);
    std::shared_ptr<Camera6467_plate> FindDeviceByCameraIp(const char* IpAddress);
    std::shared_ptr<Camera6467_plate> FindDeviceByCamerPointer(Camera6467_plate* CamerPointer);
    std::shared_ptr<Camera6467_plate> FindDeviceByVideoHandle(const void* videoHandle);
    bool EraseDevice(std::shared_ptr<Camera6467_plate>& obj);
    void ShowAll();

private:
    DeviceListManager();
    ~DeviceListManager();

private:
    std::list<std::shared_ptr<Camera6467_plate>> m_lsDeviceList;
    std::mutex m_tx; // »¥³âËø.
};


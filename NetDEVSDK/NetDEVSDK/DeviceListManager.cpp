#include "stdafx.h"
#include "DeviceListManager.h"
#include <condition_variable>    // std::condition_variable


DeviceListManager* DeviceListManager::GetInstance()
{
    static DeviceListManager g_instant;
    return &g_instant;
}

DeviceListManager::DeviceListManager()
{
    printf("create DeviceListManager.\n");
}
DeviceListManager::~DeviceListManager()
{
    printf("destroy DeviceListManager.\n");
    ClearAllDevice();
}

size_t DeviceListManager::GetDeviceCount()
{
    std::unique_lock <std::mutex> lck(m_tx);
    return m_lsDeviceList.size();
}

void DeviceListManager::ClearAllDevice()
{
    std::unique_lock <std::mutex> lck(m_tx);
    m_lsDeviceList.clear();
}

void DeviceListManager::AddOneDevice(std::shared_ptr<Camera6467_plate> obj)
{
    if (!FindIfExsit(obj))
    {
        std::unique_lock <std::mutex> lck(m_tx);
        m_lsDeviceList.push_back(obj);
    }
}

bool DeviceListManager::FindIfExsit(std::shared_ptr<Camera6467_plate> obj)
{
    std::unique_lock <std::mutex> lck(m_tx);
    for (auto tempIt = m_lsDeviceList.begin(); tempIt != m_lsDeviceList.end(); tempIt++)
    {
        if (*tempIt == obj)
        {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Camera6467_plate> DeviceListManager::FindDeviceByCameraIp(const char* IpAddress)
{
    std::unique_lock <std::mutex> lck(m_tx);
    if (NULL == IpAddress)
    {
        return nullptr;
    }
    for (auto tempIt = m_lsDeviceList.begin(); tempIt != m_lsDeviceList.end(); tempIt++)
    {
        if (0 == strcmp(tempIt->get()->GetCameraIP(), IpAddress))
        {
            return *tempIt;
        }
    }
    return nullptr;
}

std::shared_ptr<Camera6467_plate> DeviceListManager::FindDeviceByCamerPointer(Camera6467_plate* CamerPointer)
{
    std::unique_lock <std::mutex> lck(m_tx);
    if (NULL == CamerPointer)
    {
        return nullptr;
    }
    for (auto tempIt = m_lsDeviceList.begin(); tempIt != m_lsDeviceList.end(); tempIt++)
    {
        if (tempIt->get() == CamerPointer)
        {
            return *tempIt;
        }
    }
    return nullptr;
}

std::shared_ptr<Camera6467_plate> DeviceListManager::FindDeviceByVideoHandle(const void* videoHandle)
{
    std::unique_lock <std::mutex> lck(m_tx);
    if (NULL == videoHandle)
    {
        return nullptr;
    }
    for (auto tempIt = m_lsDeviceList.begin(); tempIt != m_lsDeviceList.end(); tempIt++)
    {
        if (tempIt->get()->GetVideoHandleByChannel(0) == videoHandle || tempIt->get()->GetVideoHandleByChannel(1) == videoHandle)
        {
            return *tempIt;
        }
    }
    return nullptr;
}

bool DeviceListManager::EraseDevice(std::shared_ptr<Camera6467_plate>& obj)
{
    if (FindIfExsit(obj))
    {
        std::unique_lock <std::mutex> lck(m_tx);
        for (auto tempIt = m_lsDeviceList.begin(); tempIt != m_lsDeviceList.end(); tempIt++)
        {
            if (*tempIt == obj)
            {
                m_lsDeviceList.erase(tempIt);
                obj = nullptr;
                return true;
            }
        }
    }
    return false;
}
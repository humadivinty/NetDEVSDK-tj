// NetDEVSDK.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "NetDEVSDK.h"
#include "DeviceListManager.h"
#include "Camera/Camera6467_plate.h"
#include "utilityFunc/ToolFunction.h"



NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Init(void)
{
    g_WriteLog("NETDEV_Init,  begin.");

    g_WriteLog("NETDEV_Init , end.");
    return TRUE;
}

NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Cleanup(void)
{
    g_WriteLog("NETDEV_Cleanup,  begin.");
    DeviceListManager::GetInstance()->ClearAllDevice();

    g_WriteLog("NETDEV_Cleanup , end.");
    return TRUE;
}

NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetSDKVersion(void)
{
    g_WriteLog("NETDEV_GetSDKVersion,  begin.");
    TCHAR szFileName[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, szFileName, MAX_PATH);	//取得包括程序名的全路径
    PathRemoveFileSpec(szFileName);				//去掉程序名
    strcat_s(szFileName, "\\NetDEVSDK.dll");
    std::string strVersion = GetSoftVersion(szFileName);
    std::size_t found = found = strVersion.find_first_of(".");
    int iCount = 0;
    std::string strTemp = strVersion;
    while (found != std::string::npos)
    {
        iCount++;
        strTemp = strTemp.substr(found + 1, strTemp.length() - found);
        found = strTemp.find_first_of(".");          
    }
    INT32 iVersion = 0;
    if (iCount == 3)
    {
        int iVersion1 = 0, iVersion2 = 0, iVersion3 = 0, iVersion4 = 0;
        sscanf_s(strVersion.c_str(), "%d.%d.%d.%d", &iVersion1, &iVersion2, &iVersion3, &iVersion4);
        iVersion = iVersion1 << 16;
        iVersion |= iVersion4;
        g_WriteLog(strVersion.c_str());
    }
    else
    {
        iVersion = (iVersion & 0x1) << 16;
        iVersion |= 0x1;
        g_WriteLog("can not get version use 1.01.0.1");
    }
    g_WriteLog("NETDEV_GetSDKVersion , end.");
    return iVersion;
}

NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login(IN char *pszDevIP, IN INT16 wDevPort, IN char *pszUserName, IN char *pszPassword, OUT LPNETDEV_DEVICE_INFO_S pstDevInfo)
{
    char szLog[512] = { 0 };
    if (NULL == pszDevIP || NULL == pszUserName || NULL == pszPassword
        || (strlen(pszDevIP) + strlen(pszUserName) + strlen(pszPassword) >= sizeof(szLog)))
    {
        g_WriteLog("NETDEV_Login,  NULL == pszDevIP || NULL == pszUserName || NULL == pszPassword, parameters is invalid.");
        return NULL;
    }
    sprintf_s(szLog, sizeof(szLog), "NETDEV_Login, pszDevIP = %s, wDevPort= %d, pszUserName= %s, pszPassword= %s, LPNETDEV_DEVICE_INFO_S= %p ",
        pszDevIP, wDevPort, pszUserName, pszPassword, pstDevInfo);
    g_WriteLog(szLog);

    LPVOID pHandle = NULL;
    std::shared_ptr<Camera6467_plate> CamObj = DeviceListManager::GetInstance()->FindDeviceByCameraIp(pszDevIP);
    if (CamObj == nullptr)
    {
        CamObj = std::shared_ptr<Camera6467_plate>(new Camera6467_plate(pszDevIP, NULL, 0));
        DeviceListManager::GetInstance()->AddOneDevice(CamObj);
    }
    else
    {
        g_WriteLog("NETDEV_Login , the ip address is already exsit, use old handle.");
    }
    if (CamObj != nullptr)
    {
        pHandle = (LPVOID)CamObj.get();
    }
    else
    {
        g_WriteLog("NETDEV_Login , create camera handle failed.");
    }    

    memset(szLog, 0, sizeof(szLog));
    sprintf_s(szLog, sizeof(szLog), "NETDEV_Login  end, return handle = %p", pHandle);
    g_WriteLog(szLog);
    return pHandle;
}

NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Logout(IN LPVOID lpUserID)
{
    char szLog[512] = { 0 };
    if (NULL == lpUserID)
    {
        g_WriteLog("NETDEV_Logout,  NULL == lpUserID, parameters is invalid.");
        return FALSE;
    }
    sprintf_s(szLog, sizeof(szLog), "NETDEV_Logout, lpUserID = %p ", lpUserID);
    g_WriteLog(szLog);

    BOOL bRet = FALSE;
    std::shared_ptr<Camera6467_plate> CameraObj = DeviceListManager::GetInstance()->FindDeviceByCamerPointer((Camera6467_plate*)lpUserID);
    if (!DeviceListManager::GetInstance()->FindIfExsit(CameraObj))
    {
        g_WriteLog("NETDEV_Logout , can not find the camera.");
    }
    else
    {
        g_WriteLog("NETDEV_Logout ,  find the camera and erase it.");
        DeviceListManager::GetInstance()->EraseDevice(CameraObj);
        bRet = TRUE;
    }

    memset(szLog, 0, sizeof(szLog));
    sprintf_s(szLog, sizeof(szLog), "NETDEV_Logout  end, return code = %d", bRet);
    g_WriteLog(szLog);
    return bRet;
}

NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_RealPlay(IN LPVOID lpUserID, IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo, IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack, IN LPVOID lpUserData)
{
    char szLog[512] = { 0 };
    if (NULL == lpUserID || NULL == pstPreviewInfo)
    {
        g_WriteLog("NETDEV_RealPlay,  NULL == lpUserID || NULL == pstPreviewInfo, parameters is invalid.");
        return NULL;
    }
    sprintf_s(szLog, sizeof(szLog), "NETDEV_RealPlay, lpUserID = %p, pstPreviewInfo->dwChannelID= %d,  pstPreviewInfo->dwStreamType= %d,  pstPreviewInfo->dwLinkMode= %d,   pstPreviewInfo->hPlayWnd = %p",
                                lpUserID, \
                                pstPreviewInfo->dwChannelID, \
                                pstPreviewInfo->dwStreamType,\
                                pstPreviewInfo->dwLinkMode, \
                                pstPreviewInfo->hPlayWnd  );
    g_WriteLog(szLog);

    LPVOID hRet = NULL;
    std::shared_ptr<Camera6467_plate> CameraObj = DeviceListManager::GetInstance()->FindDeviceByCamerPointer((Camera6467_plate*)lpUserID);
    if (!DeviceListManager::GetInstance()->FindIfExsit(CameraObj))
    {
        g_WriteLog("NETDEV_RealPlay , can not find the camera.");
    }
    else
    {
        g_WriteLog("NETDEV_RealPlay ,  find the camera and start play video.");
        HWND hWindWnd = (HWND)pstPreviewInfo->hPlayWnd;
        if (IsWindow(hWindWnd))
        {
            printf("is windows.\n");
            if (IsWindowVisible(hWindWnd))
            {
                printf("is visible.\n");
                RECT  rc2;
                GetClientRect(hWindWnd, &rc2);
                memset(szLog, 0, sizeof(szLog));
                sprintf_s(szLog, sizeof(szLog), "GetClientRect, width = %d, height= %d ", rc2.right - rc2.left, rc2.bottom - rc2.top);
                g_WriteLog(szLog);

                //g_WriteLog("Start play video.");
                //if (pstPreviewInfo->dwStreamType == 0)
                //{
                //    CameraObj->StartPlayVideoByChannel(0, (HWND)pstPreviewInfo->hPlayWnd);
                //    hRet = CameraObj->GetVideoHandleByChannel(0);
                //}
                //else
                //{
                //    CameraObj->StartPlayVideoByChannel(1, (HWND)pstPreviewInfo->hPlayWnd);
                //    hRet = CameraObj->GetVideoHandleByChannel(1);
                //}
                //g_WriteLog("Finish play video.");
            }
            else
            {
                g_WriteLog("input window handle can not visible.\n");
            }

            g_WriteLog("Start play video.");
            if (pstPreviewInfo->dwStreamType == 0)
            {
                CameraObj->StartPlayVideoByChannel(0, (HWND)pstPreviewInfo->hPlayWnd);
                hRet = CameraObj->GetVideoHandleByChannel(0);
            }
            else
            {
                CameraObj->StartPlayVideoByChannel(1, (HWND)pstPreviewInfo->hPlayWnd);
                hRet = CameraObj->GetVideoHandleByChannel(1);
            }
            g_WriteLog("Finish play video.");
        }
        else
        {
            g_WriteLog("input window handle was not windows.\n");
        }         
    }

    memset(szLog, 0, sizeof(szLog));
    sprintf_s(szLog, sizeof(szLog), "NETDEV_RealPlay  end, return ID = %p", hRet);
    g_WriteLog(szLog);
    return hRet;
}

NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopRealPlay(IN LPVOID lpRealHandle)
{
    char szLog[512] = { 0 };
    if (NULL == lpRealHandle)
    {
        g_WriteLog("NETDEV_RealPlay,  NULL == lpRealHandle, parameters is invalid.");
        return FALSE;
    }
    sprintf_s(szLog, sizeof(szLog), "NETDEV_StopRealPlay, lpUserID = %p, ", lpRealHandle);
    g_WriteLog(szLog);

    BOOL bRet = FALSE;
    //std::shared_ptr<Camera6467_plate> CameraObj = DeviceListManager::GetInstance()->FindDeviceByCamerPointer((Camera6467_plate*)lpRealHandle);
    std::shared_ptr<Camera6467_plate> CameraObj = DeviceListManager::GetInstance()->FindDeviceByVideoHandle(lpRealHandle);
    if (!DeviceListManager::GetInstance()->FindIfExsit(CameraObj))
    {
        g_WriteLog("NETDEV_RealPlay , can not find the camera.");
    }
    else
    {
        g_WriteLog("NETDEV_RealPlay ,  find the camera and stop play video.");
        int iChannelID = CameraObj->GetChannelIDByHandle(lpRealHandle);
        if (iChannelID >= 0)
        {
            CameraObj->StopPlayVideoByChannel(iChannelID);
            bRet = TRUE;

            memset(szLog, 0, sizeof(szLog));
            sprintf_s(szLog, sizeof(szLog), "find the channel ID = %d", iChannelID);
            g_WriteLog(szLog);
        }
        else
        {
            g_WriteLog("Can not find the video channel by handle.");
        }
    }

    memset(szLog, 0, sizeof(szLog));
    sprintf_s(szLog, sizeof(szLog), "NETDEV_RealPlay  end, return code = %d", bRet);
    g_WriteLog(szLog);
    return bRet;
}

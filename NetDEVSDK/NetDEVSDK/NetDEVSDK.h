// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 NETDEVSDK_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// NETDEVSDK_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#include "NetDEVSDK_CommonDef.h"

#ifdef NETDEVSDK_EXPORTS
#define NETDEVSDK_API __declspec(dllexport)
#else
#define NETDEVSDK_API __declspec(dllimport)
#endif


#ifndef _NETDEV_H_
#define _NETDEV_H_

#ifdef  __cplusplus
extern "C"{
#endif   
    
    /**
    * SDK 初始化  SDK initialization
    * @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
    * @note 线程不安全 Thread not safe
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Init(void);

    /**
    * SDK 清理  SDK cleaning
    * @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
    * @note
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Cleanup(void);

    /**
    * 获取SDK的版本信息 Get SDK version information
    * @return SDK版本信息 SDK version information
    * @note
    * - 2个高字节表示主版本,2个低字节表示次版本。如0x00030000：表示版本为3.0。
    * - The two high bytes indicate the major version, and the two low bytes indicate the minor version. For example, 0x00030000 means version 3.0.
    */
    NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetSDKVersion(void);

    /**
    * 用户登录  User login
    * @param [IN]  pszDevIP         设备IP Device IP
    * @param [IN]  wDevPort         设备服务器端口 Device server port
    * @param [IN]  pszUserName      用户名 Username
    * @param [IN]  pszPassword      密码 Password
    * @param [OUT] pstDevInfo       设备信息结构体指针 Pointer to device information structure
    * @return 返回的用户登录ID,返回 0 表示失败,其他值表示返回的用户ID值。 Returned user login ID. 0 indicates failure, and other values indicate the user ID.
    * @note
    */
    NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login(IN char *pszDevIP,
        IN INT16 wDevPort,
        IN char *pszUserName,
        IN char *pszPassword,
        OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
        );

    /**
    * 用户注销  User logout
    * @param [IN] lpUserID    用户登录ID User login ID
    * @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
    * @note
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Logout(IN LPVOID lpUserID);

    /*************** Begin实况业务  Begin live view services*********************************************/

    /**
    * 启动实时预览  Start live preview
    * @param [IN]  lpUserID             用户登录ID User login ID
    * @param [IN]  pstPreviewInfo       预览参数,参考枚举：NETDEV_PROTOCAL_E,NETDEV_LIVE_STREAM_INDEX_E。 Preview parameter, see enumeration: NETDEV_PROTOCAL_E, NETDEV_LIVE_STREAM_INDEX_E.
    * @param [IN]  cbRealDataCallBack   码流数据回调函数指针 Pointer to callback function of stream data
    * @param [IN]  lpUserData           用户数据 User data
    * @return 返回的用户登录ID,返回 0 表示失败,其他值表示返回的用户ID值。 Returned user login ID. 0 indicates failure, and other values indicate the user ID.
    * @note
    */
    NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_RealPlay(IN LPVOID lpUserID,
        IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
        IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
        IN LPVOID lpUserData
        );

    /**
    * 停止实时预览  Stop live preview
    * @param [IN]  lpRealHandle     预览句柄 Preview handle
    * @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
    * @note 对应关闭NETDEV_RealPlay开启的实况 Stop the live view started by NETDEV_RealPlay
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopRealPlay(IN LPVOID lpRealHandle);

#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif  /* end of _NETDEV_NET_SDK_H_ */
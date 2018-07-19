// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� NETDEVSDK_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// NETDEVSDK_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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
    * SDK ��ʼ��  SDK initialization
    * @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
    * @note �̲߳���ȫ Thread not safe
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Init(void);

    /**
    * SDK ����  SDK cleaning
    * @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
    * @note
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Cleanup(void);

    /**
    * ��ȡSDK�İ汾��Ϣ Get SDK version information
    * @return SDK�汾��Ϣ SDK version information
    * @note
    * - 2�����ֽڱ�ʾ���汾,2�����ֽڱ�ʾ�ΰ汾����0x00030000����ʾ�汾Ϊ3.0��
    * - The two high bytes indicate the major version, and the two low bytes indicate the minor version. For example, 0x00030000 means version 3.0.
    */
    NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetSDKVersion(void);

    /**
    * �û���¼  User login
    * @param [IN]  pszDevIP         �豸IP Device IP
    * @param [IN]  wDevPort         �豸�������˿� Device server port
    * @param [IN]  pszUserName      �û��� Username
    * @param [IN]  pszPassword      ���� Password
    * @param [OUT] pstDevInfo       �豸��Ϣ�ṹ��ָ�� Pointer to device information structure
    * @return ���ص��û���¼ID,���� 0 ��ʾʧ��,����ֵ��ʾ���ص��û�IDֵ�� Returned user login ID. 0 indicates failure, and other values indicate the user ID.
    * @note
    */
    NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login(IN char *pszDevIP,
        IN INT16 wDevPort,
        IN char *pszUserName,
        IN char *pszPassword,
        OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
        );

    /**
    * �û�ע��  User logout
    * @param [IN] lpUserID    �û���¼ID User login ID
    * @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
    * @note
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Logout(IN LPVOID lpUserID);

    /*************** Beginʵ��ҵ��  Begin live view services*********************************************/

    /**
    * ����ʵʱԤ��  Start live preview
    * @param [IN]  lpUserID             �û���¼ID User login ID
    * @param [IN]  pstPreviewInfo       Ԥ������,�ο�ö�٣�NETDEV_PROTOCAL_E,NETDEV_LIVE_STREAM_INDEX_E�� Preview parameter, see enumeration: NETDEV_PROTOCAL_E, NETDEV_LIVE_STREAM_INDEX_E.
    * @param [IN]  cbRealDataCallBack   �������ݻص�����ָ�� Pointer to callback function of stream data
    * @param [IN]  lpUserData           �û����� User data
    * @return ���ص��û���¼ID,���� 0 ��ʾʧ��,����ֵ��ʾ���ص��û�IDֵ�� Returned user login ID. 0 indicates failure, and other values indicate the user ID.
    * @note
    */
    NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_RealPlay(IN LPVOID lpUserID,
        IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
        IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
        IN LPVOID lpUserData
        );

    /**
    * ֹͣʵʱԤ��  Stop live preview
    * @param [IN]  lpRealHandle     Ԥ����� Preview handle
    * @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
    * @note ��Ӧ�ر�NETDEV_RealPlay������ʵ�� Stop the live view started by NETDEV_RealPlay
    */
    NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopRealPlay(IN LPVOID lpRealHandle);

#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif  /* end of _NETDEV_NET_SDK_H_ */
#ifndef NETDEVSDK_COMMONDEF_H
#define NETDEVSDK_COMMONDEF_H

#ifndef STATIC
#define STATIC                  static
#endif

#ifndef CONST
#define CONST                   const
#endif

#ifndef EXTERN
#define EXTERN                  extern
#endif

#ifndef INLINE
#define INLINE                  __inline
#endif

#ifndef UNION
#define UNION                   union
#endif


#if defined(WIN32)  /* windows */
#if defined(NETDEVSDK_EXPORTS)
#define NETDEV_API                  __declspec(dllexport)
#else
#define NETDEV_API                  __declspec(dllimport)
#endif
#else
#define NETDEV_API
#endif

/* ������׼����Լ�� Standard function calling convention */
#ifdef i386
#ifndef STDCALL
#define STDCALL                 __attribute__((stdcall))
#endif
#else
#ifndef WIN32
#ifndef STDCALL
#define STDCALL
#endif
#else
#ifndef STDCALL
#define STDCALL                 __stdcall
#endif
#endif

#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

#ifndef NEWINTERFACE
#define NEWINTERFACE
#endif

#ifndef UCHAR_DEF
#define UCHAR_DEF
typedef unsigned char           UCHAR;
#endif

#ifndef CHAR_DEF
#define CHAR_DEF
typedef char                    CHAR;
#endif

#ifndef BYTE_DEF
#define BYTE_DEF
typedef unsigned char           BYTE;
#endif

#ifndef UINT16_DEF
#define UINT16_DEF
typedef unsigned short          UINT16;
#endif

#ifndef UINT_DEF
#define UINT_DEF
typedef unsigned int            UINT32;
#endif

#ifndef INT16_DEF
#define INT16_DEF
typedef  short                  INT16;
#endif

#ifndef INT32_DEF
#define INT32_DEF
typedef  int                    INT32;
#endif

#ifndef LPVOID_DEF
#define LPVOID_DEF
typedef void*                   LPVOID;
#endif

#ifndef VOID
#ifndef VOID_DEF
#define VOID_DEF
typedef void                    VOID;
#endif
#endif

#ifndef INT64_DEF
#define INT64_DEF
typedef long long               INT64;
#endif

#ifndef BOOL_DEF
#define BOOL_DEF
typedef int                     BOOL;
#endif

#ifndef FLOAT
#ifndef VOID_FLOAT
#define VOID_FLOAT
typedef float                   FLOAT;
#endif
#endif

#ifndef FALSE
#define FALSE                   0
#endif

#ifndef TRUE
#define TRUE                    1
#endif

#ifndef WIN32
typedef LPVOID                 HWND;
#endif


/* BEGIN**************************** ������ Error codes ************************************************************/
#define NETDEV_E_SUCCEED                        0           /* �ɹ�  Succeeded*/
#define NETDEV_E_FAILED                         -1          /* ʧ��  Failed*/

/* ͨ�ô�����  Common error codes */
#define NETDEV_E_COMMON_FAILED                  1           /* ͨ�ô���  Common error */
#define NETDEV_E_DEV_COMMON_FAILED              2           /* ���豸���ص�ͨ�ô���  Common error returned by device */
#define NETDEV_E_SYSCALL_FALIED                 3           /* ϵͳ��������ʧ��,��鿴errno  Failed to call system function. See errno */
#define NETDEV_E_NULL_POINT                     4           /* ��ָ��  Null pointer */
#define NETDEV_E_INVALID_PARAM                  5           /* ��Ч����  Invalid parameter */
#define NETDEV_E_INVALID_MODULEID               6           /* ��Чģ��ID  Invalid module ID */
#define NETDEV_E_NO_MEMORY                      7           /* �ڴ����ʧ��  Failed to allocate memory */
#define NETDEV_E_NOT_SUPPORT                    8           /* �豸��֧��  Not supported by device */
#define NETDEV_E_SDK_SOCKET_LSN_FAIL            9           /* ����socket listenʧ��  Failed to create socket listen */
#define NETDEV_E_INIT_MUTEX_FAIL                10          /* ��ʼ����ʧ��  Failed to initialize lock */
#define NETDEV_E_INIT_SEMA_FAIL                 11          /* ��ʼ���ź���ʧ��  Failed to initialize semaphore */
#define NETDEV_E_ALLOC_RESOURCE_ERROR           12          /* SDK��Դ�������  Error occurred during SDK resource allocation */
#define NETDEV_E_SDK_NOINTE_ERROR               13          /* SDKδ��ʼ��  SDK not initialized */
#define NETDEV_E_ALREDY_INIT_ERROR              14          /* SDK�Ѿ���ʼ����  SDK already initialized */
#define NETDEV_E_HAVEDATA                       15          /* ��������   Data not all sent */
#define NETDEV_E_NEEDMOREDATA                   16          /* ��Ҫ��������  More data required  */
#define NETDEV_E_CONNECT_ERROR                  17          /* ��������ʧ��  Failed to create connection */
#define NETDEV_E_SEND_MSG_ERROR                 18          /* ����������Ϣʧ��  Failed to send request message */
#define NETDEV_E_TIMEOUT                        19          /* ��Ϣ��ʱ  Message timeout */
#define NETDEV_E_DECODE_RSP_ERROR               20          /* ������Ӧ��Ϣʧ��  Failed to decode response message */
#define NETDEV_E_SOCKET_RECV_ERROR              21          /* Socket������Ϣʧ��  Socket failed to receive message */
#define NETDEV_E_NUM_MAX_ERROR                  22          /* �����ﵽ��󡣷����ע����������Ԥ������������SDK֧�ֵ������  Maximum number reached. The assigned numbers of registration connections and preview connections reached the maximum supported by SDK */
#define NETDEV_E_GET_PORT_ERROR                 24          /* ��ȡ���ض˿ں�ʧ��  Failed to obtain local port number */
#define NETDEV_E_CREATE_THREAD_FAIL             25          /* �����߳�ʧ��  Failed to create thread */
#define NETDEV_E_NOENOUGH_BUF                   26          /* ������̫С: �����豸���ݵĻ�����  Buffer is too small for receiving device data */
#define NETDEV_E_GETLOCALIPANDMACFAIL           27          /* ��ñ���PC��IP��ַ�������ַʧ��  Failed to obtain the IP or MAC address of the local PC */
#define NETDEV_E_RESCODE_NO_EXIST               28          /* ��Դ���벻����  Resource code not exist */
#define NETDEV_E_MSG_DATA_INVALID               31          /* ��Ϣ���ݴ���  Incorrect message content */
#define NETDEV_E_GET_CAPABILITY_ERROR           32          /* ��ȡ������ʧ��  Failed to obtain capabilities */
#define NETDEV_E_USER_NOT_BIND                  33          /* ���û�û�ж��ĸ澯   User not subscribed to alarms */
#define NETDEV_E_AUTHORIZATIONFAIL              34          /* �û���Ȩʧ��  User authentication failed */
#define NETDEV_E_BINDNOTIFY_FAIL                35          /* �󶨸澯ʧ��  Failed to bind alarms*/
#define NETDEV_E_NOTADMIN                       36          /* ����Ȩ�޲���,windows��һ��Ϊ�ǹ���Ա�ʺŲ������� Not enough permission. In Windows, it is normally because the operator is not an administrator. */
#define NETDEV_E_DEVICE_FACTURER_ERR            37          /* ��֧�ֵ��豸���� Manufacturers that are not supported */
#define NETDEV_E_NONSUPPORT                     38          /* �ù��ܲ�֧��  Function not supported */
#define NETDEV_E_TRANSFILE_FAIL                 39          /* �ļ�����ʧ��  File transmission failed */
#define NETDEV_E_JSON_ERROR                     40          /* Json ͨ�ô���  Json common error */
#define NETDEV_E_NO_RESULT                      41          /* ���޽��   No result */

/* �û���ش�����  User-related error codes */
#define NETDEV_E_USER_WRONG_PASSWD              101         /* �û��������  Incorrect password */
#define NETDEV_E_USER_LOGIN_MAX_NUM             102         /* �û���¼���Ѵ�����  Number of login users reached the upper limit */
#define NETDEV_E_USER_NOT_ONLINE                103         /* �û�������  User not online */
#define NETDEV_E_USER_NO_SUCH_USER              104         /* û�и��û�  User not online */
#define NETDEV_E_USER_NO_AUTH                   105         /* �û���Ȩ��  User has no rights */
#define NETDEV_E_USER_MAX_NUM                   106         /* �û�����-�����ٱ����  Reached the upper limit�Cno more users can be added */
#define NETDEV_E_USER_EXIST                     107         /* �û��Ѵ���  User already exists */
#define NETDEV_E_USER_PASSWORD_CHANGE           108         /* �û������޸�  Password changed */
#define NETDEV_E_REMOTE_USER_WITH_WEAK_PASSWD   109         /* Զ���û����������  Remote user with weak password */


/*********************** Player ��Դ���********************************/
#define NETDEV_E_FAIL_TO_INIT_EZPLAYER              1257        /* ��ʼ��������ʧ��  Failed to initialize the player */
#define NETDEV_E_FAIL_TO_ALLOC_PORT_RES             1258        /* ���䲥��ͨ����Դʧ��  Failed to allocate playing channel resources */
#define NETDEV_E_FAIL_TO_GET_PORT_RES               1259        /* ��ò���ͨ����Դʧ��  Failed to get playing channel resources */
#define NETDEV_E_BUFFER_QUEUE_FULL                  1260        /* �����������  Cache queue full */
#define NETDEV_E_BUFFER_QUEUE_EMPTY                 1261        /* ������п�  Cache queue empty */
#define NETDEV_E_OPEN_FILE_FAILED                   1262        /* ���ļ�ʧ��  Failed to open the file */
#define NETDEV_E_FILE_READ_END                      1263        /* �ļ��Ѿ���ȡ���  The file is read */
#define NETDEV_E_FILE_DISKSPACE_FULL                1264        /* ���̿ռ���  Disk space full */
#define NETDEV_E_FILE_READ_FAIL                     1265        /* ��ȡʧ��  Failed to read */
#define NETDEV_E_MCM_MIC_NOT_EXIST                  1266        /* ��˷粻����  The microphone does not exist */
#define NETDEV_E_TS_PACKET_IN_THE_ROUGH             1267        /* TS���δ���  TS packing not finished */
#define NETDEV_E_FILE_RECORD_FINISH                 1268        /* ¼�񱣴����  Recording saved */

#define NETDEV_E_FAIL_TO_OPEN_STREAM                1513        /* ����ý��������ʧ��  Failed to start media streaming */
#define NETDEV_E_FAIL_TO_CLOSE_STREAM               1514        /* �ر�ý��������ʧ��  Failed to close media streaming */
#define NETDEV_E_FAIL_TO_RECV_DATA                  1515        /* ������ϵ��½�������ʧ��  Failed to receive data due to network error */
#define NETDEV_E_FAIL_TO_PROCESS_MEDIA_DATA         1516        /* ý�����ݴ���ʧ��  Failed to handle media data */
#define NETDEV_E_NOT_START_PLAY                     1517        /* ����ͨ��δ��ʼ���Ų���  Playing not started in playing channel */
#define NETDEV_E_FAIL_TO_INPUT_DATA                 1518        /* ����ý��������ʧ��  Failed to enter media stream data */
#define NETDEV_E_INPUTDATA_BUFFER_FULL              1519        /* �������ݻ�����  Input data cache full */
#define NETDEV_E_FAIL_TO_SET_PROCESS_DATA_CB        1520        /* ����ý�������ݻص�����ʧ��  Failed to set media stream data callback function */
#define NETDEV_E_VOICE_RUNNING                      1521        /* ����ҵ�����й����г���  Error occurred when running voice service */
#define NETDEV_E_FAIL_TO_OPEN_VOICE_SVC             1522        /* ��������ҵ��ʧ��  Failed to start voice service */
#define NETDEV_E_FAIL_TO_CLOSE_VOICE_SVC            1523        /* �ر�����ҵ��ʧ��  Failed to close voice service */
#define NETDEV_E_UNKNOWN_STREAM_TYPE                1524        /* δ֪ý����  Unknown media stream */
#define NETDEV_E_PACKET_LOSE                        1525        /* ����  Packet loss */
#define NETDEV_E_NEED_MORE_PACKET                   1526        /* ƴ��δ���,��Ҫ�����  More packets are needed for the packing */
#define NETDEV_E_FAIL_TO_CREATE_DECODE              1527        /* ����������ʧ��  Failed to create the decoder */
#define NETDEV_E_FAIL_TO_DECODE                     1528        /* ����ʧ�� Failed to decode */
#define NETDEV_E_RECV_DATA_NOTENOUGH                1529        /* �������ݲ���  Not enough data received */
#define NETDEV_E_RENDER_RES_FULL                    1530        /* ��ʾ��Դ��  Display resources full */
#define NETDEV_E_RENDER_RES_NOT_EXIST               1531        /* ��ʾ��Դ������  Display resources do not exist */
#define NETDEV_E_CREATE_DEV_FAILED                  1532        /* ��Դ����ʧ��  Failed to create the resources */
#define NETDEV_E_AUDIO_RES_NOT_EXIST                1533        /* ��Ƶ��Դ������  Audio resources do not exist */
#define NETDEV_E_IHW265D_NEED_MORE_BITS             1534        /* ��������Ҫ��������  Decoder requires more data */
#define NETDEV_E_FAIL_TO_CREATE_ENCODE              1535        /* ����������ʧ��  Failed to create encoder */
#define NETDEV_E_CAPTURE_RES_EXIST                  1536        /* �ɼ���Դ������  Capture resources do not exist */
#define NETDEV_E_RECORD_STARTED                     1537        /* ¼���Ѵ�  Recording already opened */
#define NETDEV_E_NEED_WAIT_DECODEC                  1538        /* δ�������,��Ҫ�ȴ�  Decoding in progress, please wait */
#define NETDEV_E_MORE_DATA_NEED_PACKET              1539        /* ���ݹ���,����Ҫ�������  Too much data, still need packing */

/* BEGIN:****************** ö��ֵ  Enumeration value ***************************************************** */


/**
* @enum tagNETDEVLiveStreamIndex
* @brief ʵ��ҵ�������� ö�ٶ� �� Live stream index Enumeration definition
* @attention �� None
*/
typedef enum tagNETDEVLiveStreamIndex
{
    NETDEV_LIVE_STREAM_INDEX_MAIN = 0,   /* ����  Main stream */
    NETDEV_LIVE_STREAM_INDEX_AUX = 1,   /* ����  Sub stream */
    NETDEV_LIVE_STREAM_INDEX_THIRD = 2,   /* ������  Third stream */

    NETDEV_LIVE_STREAM_INDEX_BUTT
}NETDEV_LIVE_STREAM_INDEX_E;


/**
* @enum tagNETDEVProtocal
* @brief ý�崫��Э�� ö�ٶ���  Media transport protocol Enumeration definition
* @attention �� None
*/
typedef enum tagNETDEVProtocal
{
    NETDEV_TRANSPROTOCAL_RTPTCP = 1,         /* TCP */
    NETDEV_TRANSPROTOCAL_RTPUDP = 2          /* UDP */
}NETDEV_PROTOCAL_E;


/**
* @enum tagNETDEVVideoCodeType
* @brief ��Ƶ�����ʽ ö�ٶ���  Video encoding format Enumeration definition
* @attention �� None
*/
typedef enum tagNETDEVVideoCodeType
{
    NETDEV_VIDEO_CODE_MJPEG = 0,          /* MJPEG */
    NETDEV_VIDEO_CODE_H264 = 1,          /* H.264 */
    NETDEV_VIDEO_CODE_H265 = 2,          /* H.265 */
    NETDEV_VIDEO_CODE_BUTT
}NETDEV_VIDEO_CODE_TYPE_E;

/**
* @enum tagNETDEVVideoFrameType
* @brief ��Ƶ֡���� ö�ٶ���  Video frame type Enumeration definition
* @attention �� None
*/
typedef enum tagNETDEVVideoFrameType
{
    NETDEV_VIDEO_FRAME_I = 0,               /* ��Ƶ֡ΪI֡  I-frame */
    NETDEV_VIDEO_FRAME_P = 1,               /* ��Ƶ֡ΪP֡  P-frame */
    NETDEV_VIDEO_FRAME_B = 2                /* ��Ƶ֡ΪB֡  B-frame */
}NETDEV_VIDEO_FRAME_TYPE_E;

/**
* @enum tagNETDEVRenderScale
* @brief ��Ƶ��ʾ���� ö�ٶ���  Video display ratio Enumeration definition
* @attention �� None
*/
typedef enum tagNETDEVRenderScale
{
    NETDEV_RENDER_SCALE_FULL = 0,                  /* ͼ������������� ����  Stretch */
    NETDEV_RENDER_SCALE_PROPORTION = 1,                  /* ͼ�񰴱�����ʾ  Scale */

    NETDEV_RENDER_SCALE_BUTT = 0xFF
}NETDEV_RENDER_SCALE_E;



/**
* @enum tagNETDEVVideoQuality
* @brief ��Ƶͼ������ ö�ٶ���  Video image quality Enumeration definition
* @attention �� None
*/
typedef enum tagNETDEVVideoQuality
{
    NETDEV_VQ_L0 = 0,                    /* ���  Highest */
    NETDEV_VQ_L1 = 1,
    NETDEV_VQ_L2 = 4,                    /* �ϸ�  Higher */
    NETDEV_VQ_L3 = 8,
    NETDEV_VQ_L4 = 12,                   /* ��  Medium */
    NETDEV_VQ_L5 = 16,
    NETDEV_VQ_L6 = 20,                   /* ��  Low */
    NETDEV_VQ_L7 = 24,
    NETDEV_VQ_L8 = 28,                   /* �ϵ�  Lower */
    NETDEV_VQ_L9 = 31,                   /* ���  Lowest */

    NETDEV_VQ_LEVEL_INVALID = -1,        /* ��Ч  Valid */
}NETDEV_VIDEO_QUALITY_E;

/**
* @enum tagNETDEVPictureSize
* @brief ͼ��ֱ��� ö�ٶ��� Image resolution Enumeration definition
* @attention �� None
*/
typedef enum tagNETDEVPictureSize
{
    NETDEV_PICTURE_SIZE_D1 = 0,           /* D1 */
    NETDEV_PICTURE_SIZE_4CIF = 1,           /* 4CIF */
    NETDEV_PICTURE_SIZE_2CIF = 2,           /* 2CIF */
    NETDEV_PICTURE_SIZE_CIF = 3,           /* CIF */
    NETDEV_PICTURE_SIZE_960H = 4,           /* 960H */
    NETDEV_PICTURE_SIZE_QCIF = 5,           /* QCIF */
    NETDEV_PICTURE_SIZE_HALFD1 = 6,           /* HALFD1 */
    NETDEV_PICTURE_SIZE_720 = 7,           /* 720 */
    NETDEV_PICTURE_SIZE_1080 = 8,           /* 1080 */
    NETDEV_PICTURE_SIZE_XGA = 9,           /* 1024*768 */
    NETDEV_PICTURE_SIZE_SXGA = 10,          /* 1280*1024 */

    NETDEV_PICTURE_SIZE_INVALID               /* ��Чֵ  Invalid value */
}NETDEV_PICTURE_SIZE_E;

/**
* @enum tagNETDEVProtocolType
* @brief Э������
* @attention ��
*/
typedef enum tagNETDEVProtocolType
{
    NETDEV_PROTOCOL_TYPE_HTTP = 0,
    NETDEV_PROTOCOL_TYPE_HTTPS = 1,
    NETDEV_PROTOCOL_TYPE_RTSP = 2
}NETDEV_PROTOCOL_TYPE_E;

/* END************* ö��ֵ  Enumeration value *************************** */

/* BEGIN*********** �ṹ��  Structure *********************************** */

/**
* @struct tagNETDEVDeviceInfo
* @brief �豸��Ϣ �ṹ�嶨�� Device information Structure definition
* @attention �� None
*/
typedef struct tagNETDEVDeviceInfo
{
    INT32   dwDevType;                          /* �豸����,�μ�ö��#NETDEV_DEVICETYPE_E  Device type, see enumeration #NETDEV_DEVICETYPE_E */
    INT16   wAlarmInPortNum;                    /* �����������  Number of alarm inputs */
    INT16   wAlarmOutPortNum;                   /* �����������  Number of alarm outputs */
    INT32   dwChannelNum;                       /* ͨ������  Number of Channels */
    BYTE    byRes[48];                          /* �����ֶ�  Reserved */
}NETDEV_DEVICE_INFO_S, *LPNETDEV_DEVICE_INFO_S;


/**
* @struct tagNETDEVPriviewInfo
* @brief ʵ��Ԥ������ �ṹ�嶨�� Live view parameter Structure definition
* @attention �� None
*/
typedef struct tagNETDEVPriviewInfo
{
    INT32   dwChannelID;                    /* ͨ��ID  Channel ID */
    INT32   dwStreamType;                   /* ��������,�μ�ö��#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwLinkMode;                     /* ����Э��,�μ�ö��#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /* ���Ŵ��ھ�� Play window handle */
    BYTE    byRes[264];                     /* �����ֶ�  Reserved */
}NETDEV_PREVIEWINFO_S, *LPNETDEV_PREVIEWINFO_S;

/**
* ƴ֡ǰý�������ݻص�������ָ������  Type of pointer to media stream data callback function before being framed
* @param [IN] lpRealHandle      ��ǰ��ʵ�����ž�� Current live playing handle
* @param [IN] pucBuffer         ���ƴ֡ǰý�������ݻ�����ָ�� Pointer to buffer that stores stream data that is not framed
* @param [IN] dwBufSize         ��������С Buffer size
* @param [IN] dwMediaDataType   ý����������,�μ�ý������ö�ٶ���#NETDEV_MEDIAFORMAT_E Media data type, see definitions of enumeration #NETDEV_MEDIA_DATA_TYPE_E
* @param [IN] lpUserParam       �û����ò���,���û��ڵ���#NDPlayer_SetSourceMediaDataCB����ʱָ�����û����� User-set parameters, specified by users when they call the #NDPlayer_SetSourceMediaDataCB function
* @return �ޡ� None.
* @note  �û�Ӧ��ʱ���������ý��������,ȷ���������췵��,�����Ӱ�첥�����ڵ�ý�������� Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_SOURCE_DATA_CALLBACK_PF)(IN LPVOID        lpRealHandle,
    IN const BYTE    *pucBuffer,
    IN INT32         dwBufSize,
    IN INT32         dwMediaDataType,
    IN LPVOID        lpUserParam
    );

/**
* ��ʾ���ݻص�������ָ������ Type of pointer to display data callback function
* @param [IN] lpHandle       ��ǰ��ʵ�����ž�� Current live playing handle
* @param [IN] hdc            ��ʾ�����hdc,�û����������hdc ��ͼ Display superficial hdc which can be used for drawing graphics.
* @param [IN] lpUserParam    �û����ò���,���û��ڵ���#NETDEV_SetPlayDisplayCB����ʱָ�����û����� User-set parameters, specified by users when they call the #NETDEV_SetPlayDisplayCB
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ�����������Ƶ������,ȷ���������췵��,�����Ӱ�첥�����ڵ�ý��������
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DISPLAY_CALLBACK_PF)(IN LPVOID lpHandle,
    IN LPVOID hdc,
    IN LPVOID lpUserParam
    );

#endif
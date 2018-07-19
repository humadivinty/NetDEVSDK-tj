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

/* 函数标准调用约定 Standard function calling convention */
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


/* BEGIN**************************** 错误码 Error codes ************************************************************/
#define NETDEV_E_SUCCEED                        0           /* 成功  Succeeded*/
#define NETDEV_E_FAILED                         -1          /* 失败  Failed*/

/* 通用错误码  Common error codes */
#define NETDEV_E_COMMON_FAILED                  1           /* 通用错误  Common error */
#define NETDEV_E_DEV_COMMON_FAILED              2           /* 由设备返回的通用错误  Common error returned by device */
#define NETDEV_E_SYSCALL_FALIED                 3           /* 系统函数调用失败,请查看errno  Failed to call system function. See errno */
#define NETDEV_E_NULL_POINT                     4           /* 空指针  Null pointer */
#define NETDEV_E_INVALID_PARAM                  5           /* 无效参数  Invalid parameter */
#define NETDEV_E_INVALID_MODULEID               6           /* 无效模块ID  Invalid module ID */
#define NETDEV_E_NO_MEMORY                      7           /* 内存分配失败  Failed to allocate memory */
#define NETDEV_E_NOT_SUPPORT                    8           /* 设备不支持  Not supported by device */
#define NETDEV_E_SDK_SOCKET_LSN_FAIL            9           /* 创建socket listen失败  Failed to create socket listen */
#define NETDEV_E_INIT_MUTEX_FAIL                10          /* 初始化锁失败  Failed to initialize lock */
#define NETDEV_E_INIT_SEMA_FAIL                 11          /* 初始化信号量失败  Failed to initialize semaphore */
#define NETDEV_E_ALLOC_RESOURCE_ERROR           12          /* SDK资源分配错误  Error occurred during SDK resource allocation */
#define NETDEV_E_SDK_NOINTE_ERROR               13          /* SDK未初始化  SDK not initialized */
#define NETDEV_E_ALREDY_INIT_ERROR              14          /* SDK已经初始化。  SDK already initialized */
#define NETDEV_E_HAVEDATA                       15          /* 还有数据   Data not all sent */
#define NETDEV_E_NEEDMOREDATA                   16          /* 需要更多数据  More data required  */
#define NETDEV_E_CONNECT_ERROR                  17          /* 创建连接失败  Failed to create connection */
#define NETDEV_E_SEND_MSG_ERROR                 18          /* 发送请求消息失败  Failed to send request message */
#define NETDEV_E_TIMEOUT                        19          /* 消息超时  Message timeout */
#define NETDEV_E_DECODE_RSP_ERROR               20          /* 解析响应消息失败  Failed to decode response message */
#define NETDEV_E_SOCKET_RECV_ERROR              21          /* Socket接收消息失败  Socket failed to receive message */
#define NETDEV_E_NUM_MAX_ERROR                  22          /* 个数达到最大。分配的注册连接数、预览连接数超过SDK支持的最大数  Maximum number reached. The assigned numbers of registration connections and preview connections reached the maximum supported by SDK */
#define NETDEV_E_GET_PORT_ERROR                 24          /* 获取本地端口号失败  Failed to obtain local port number */
#define NETDEV_E_CREATE_THREAD_FAIL             25          /* 创建线程失败  Failed to create thread */
#define NETDEV_E_NOENOUGH_BUF                   26          /* 缓冲区太小: 接收设备数据的缓冲区  Buffer is too small for receiving device data */
#define NETDEV_E_GETLOCALIPANDMACFAIL           27          /* 获得本地PC的IP地址或物理地址失败  Failed to obtain the IP or MAC address of the local PC */
#define NETDEV_E_RESCODE_NO_EXIST               28          /* 资源编码不存在  Resource code not exist */
#define NETDEV_E_MSG_DATA_INVALID               31          /* 消息内容错误  Incorrect message content */
#define NETDEV_E_GET_CAPABILITY_ERROR           32          /* 获取能力级失败  Failed to obtain capabilities */
#define NETDEV_E_USER_NOT_BIND                  33          /* 该用户没有订阅告警   User not subscribed to alarms */
#define NETDEV_E_AUTHORIZATIONFAIL              34          /* 用户鉴权失败  User authentication failed */
#define NETDEV_E_BINDNOTIFY_FAIL                35          /* 绑定告警失败  Failed to bind alarms*/
#define NETDEV_E_NOTADMIN                       36          /* 操作权限不足,windows下一般为非管理员帐号操作导致 Not enough permission. In Windows, it is normally because the operator is not an administrator. */
#define NETDEV_E_DEVICE_FACTURER_ERR            37          /* 不支持的设备厂商 Manufacturers that are not supported */
#define NETDEV_E_NONSUPPORT                     38          /* 该功能不支持  Function not supported */
#define NETDEV_E_TRANSFILE_FAIL                 39          /* 文件传输失败  File transmission failed */
#define NETDEV_E_JSON_ERROR                     40          /* Json 通用错误  Json common error */
#define NETDEV_E_NO_RESULT                      41          /* 查无结果   No result */

/* 用户相关错误码  User-related error codes */
#define NETDEV_E_USER_WRONG_PASSWD              101         /* 用户密码错误  Incorrect password */
#define NETDEV_E_USER_LOGIN_MAX_NUM             102         /* 用户登录数已达上限  Number of login users reached the upper limit */
#define NETDEV_E_USER_NOT_ONLINE                103         /* 用户不在线  User not online */
#define NETDEV_E_USER_NO_SUCH_USER              104         /* 没有该用户  User not online */
#define NETDEV_E_USER_NO_AUTH                   105         /* 用户无权限  User has no rights */
#define NETDEV_E_USER_MAX_NUM                   106         /* 用户上限-不能再被添加  Reached the upper limit–no more users can be added */
#define NETDEV_E_USER_EXIST                     107         /* 用户已存在  User already exists */
#define NETDEV_E_USER_PASSWORD_CHANGE           108         /* 用户密码修改  Password changed */
#define NETDEV_E_REMOTE_USER_WITH_WEAK_PASSWD   109         /* 远程用户弱密码错误  Remote user with weak password */


/*********************** Player 资源相关********************************/
#define NETDEV_E_FAIL_TO_INIT_EZPLAYER              1257        /* 初始化播放器失败  Failed to initialize the player */
#define NETDEV_E_FAIL_TO_ALLOC_PORT_RES             1258        /* 分配播放通道资源失败  Failed to allocate playing channel resources */
#define NETDEV_E_FAIL_TO_GET_PORT_RES               1259        /* 获得播放通道资源失败  Failed to get playing channel resources */
#define NETDEV_E_BUFFER_QUEUE_FULL                  1260        /* 缓存队列已满  Cache queue full */
#define NETDEV_E_BUFFER_QUEUE_EMPTY                 1261        /* 缓存队列空  Cache queue empty */
#define NETDEV_E_OPEN_FILE_FAILED                   1262        /* 打开文件失败  Failed to open the file */
#define NETDEV_E_FILE_READ_END                      1263        /* 文件已经读取完毕  The file is read */
#define NETDEV_E_FILE_DISKSPACE_FULL                1264        /* 磁盘空间满  Disk space full */
#define NETDEV_E_FILE_READ_FAIL                     1265        /* 读取失败  Failed to read */
#define NETDEV_E_MCM_MIC_NOT_EXIST                  1266        /* 麦克风不存在  The microphone does not exist */
#define NETDEV_E_TS_PACKET_IN_THE_ROUGH             1267        /* TS打包未完成  TS packing not finished */
#define NETDEV_E_FILE_RECORD_FINISH                 1268        /* 录像保存完毕  Recording saved */

#define NETDEV_E_FAIL_TO_OPEN_STREAM                1513        /* 启动媒体流播放失败  Failed to start media streaming */
#define NETDEV_E_FAIL_TO_CLOSE_STREAM               1514        /* 关闭媒体流播放失败  Failed to close media streaming */
#define NETDEV_E_FAIL_TO_RECV_DATA                  1515        /* 网络故障导致接收数据失败  Failed to receive data due to network error */
#define NETDEV_E_FAIL_TO_PROCESS_MEDIA_DATA         1516        /* 媒体数据处理失败  Failed to handle media data */
#define NETDEV_E_NOT_START_PLAY                     1517        /* 播放通道未开始播放操作  Playing not started in playing channel */
#define NETDEV_E_FAIL_TO_INPUT_DATA                 1518        /* 输入媒体流数据失败  Failed to enter media stream data */
#define NETDEV_E_INPUTDATA_BUFFER_FULL              1519        /* 输入数据缓存满  Input data cache full */
#define NETDEV_E_FAIL_TO_SET_PROCESS_DATA_CB        1520        /* 设置媒体流数据回调函数失败  Failed to set media stream data callback function */
#define NETDEV_E_VOICE_RUNNING                      1521        /* 语音业务运行过程中出错  Error occurred when running voice service */
#define NETDEV_E_FAIL_TO_OPEN_VOICE_SVC             1522        /* 启动语音业务失败  Failed to start voice service */
#define NETDEV_E_FAIL_TO_CLOSE_VOICE_SVC            1523        /* 关闭语音业务失败  Failed to close voice service */
#define NETDEV_E_UNKNOWN_STREAM_TYPE                1524        /* 未知媒体流  Unknown media stream */
#define NETDEV_E_PACKET_LOSE                        1525        /* 丢包  Packet loss */
#define NETDEV_E_NEED_MORE_PACKET                   1526        /* 拼包未完成,需要更多包  More packets are needed for the packing */
#define NETDEV_E_FAIL_TO_CREATE_DECODE              1527        /* 创建解码器失败  Failed to create the decoder */
#define NETDEV_E_FAIL_TO_DECODE                     1528        /* 解码失败 Failed to decode */
#define NETDEV_E_RECV_DATA_NOTENOUGH                1529        /* 接收数据不足  Not enough data received */
#define NETDEV_E_RENDER_RES_FULL                    1530        /* 显示资源满  Display resources full */
#define NETDEV_E_RENDER_RES_NOT_EXIST               1531        /* 显示资源不存在  Display resources do not exist */
#define NETDEV_E_CREATE_DEV_FAILED                  1532        /* 资源创建失败  Failed to create the resources */
#define NETDEV_E_AUDIO_RES_NOT_EXIST                1533        /* 音频资源不存在  Audio resources do not exist */
#define NETDEV_E_IHW265D_NEED_MORE_BITS             1534        /* 解码器需要更多数据  Decoder requires more data */
#define NETDEV_E_FAIL_TO_CREATE_ENCODE              1535        /* 创建编码器失败  Failed to create encoder */
#define NETDEV_E_CAPTURE_RES_EXIST                  1536        /* 采集资源不存在  Capture resources do not exist */
#define NETDEV_E_RECORD_STARTED                     1537        /* 录像已打开  Recording already opened */
#define NETDEV_E_NEED_WAIT_DECODEC                  1538        /* 未解码完成,需要等待  Decoding in progress, please wait */
#define NETDEV_E_MORE_DATA_NEED_PACKET              1539        /* 数据过多,还需要继续打包  Too much data, still need packing */

/* BEGIN:****************** 枚举值  Enumeration value ***************************************************** */


/**
* @enum tagNETDEVLiveStreamIndex
* @brief 实况业务流索引 枚举定 义 Live stream index Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVLiveStreamIndex
{
    NETDEV_LIVE_STREAM_INDEX_MAIN = 0,   /* 主流  Main stream */
    NETDEV_LIVE_STREAM_INDEX_AUX = 1,   /* 辅流  Sub stream */
    NETDEV_LIVE_STREAM_INDEX_THIRD = 2,   /* 第三流  Third stream */

    NETDEV_LIVE_STREAM_INDEX_BUTT
}NETDEV_LIVE_STREAM_INDEX_E;


/**
* @enum tagNETDEVProtocal
* @brief 媒体传输协议 枚举定义  Media transport protocol Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVProtocal
{
    NETDEV_TRANSPROTOCAL_RTPTCP = 1,         /* TCP */
    NETDEV_TRANSPROTOCAL_RTPUDP = 2          /* UDP */
}NETDEV_PROTOCAL_E;


/**
* @enum tagNETDEVVideoCodeType
* @brief 视频编码格式 枚举定义  Video encoding format Enumeration definition
* @attention 无 None
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
* @brief 视频帧类型 枚举定义  Video frame type Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVVideoFrameType
{
    NETDEV_VIDEO_FRAME_I = 0,               /* 视频帧为I帧  I-frame */
    NETDEV_VIDEO_FRAME_P = 1,               /* 视频帧为P帧  P-frame */
    NETDEV_VIDEO_FRAME_B = 2                /* 视频帧为B帧  B-frame */
}NETDEV_VIDEO_FRAME_TYPE_E;

/**
* @enum tagNETDEVRenderScale
* @brief 视频显示比例 枚举定义  Video display ratio Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVRenderScale
{
    NETDEV_RENDER_SCALE_FULL = 0,                  /* 图像填充整个播放 窗格  Stretch */
    NETDEV_RENDER_SCALE_PROPORTION = 1,                  /* 图像按比例显示  Scale */

    NETDEV_RENDER_SCALE_BUTT = 0xFF
}NETDEV_RENDER_SCALE_E;



/**
* @enum tagNETDEVVideoQuality
* @brief 视频图像质量 枚举定义  Video image quality Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVVideoQuality
{
    NETDEV_VQ_L0 = 0,                    /* 最高  Highest */
    NETDEV_VQ_L1 = 1,
    NETDEV_VQ_L2 = 4,                    /* 较高  Higher */
    NETDEV_VQ_L3 = 8,
    NETDEV_VQ_L4 = 12,                   /* 中  Medium */
    NETDEV_VQ_L5 = 16,
    NETDEV_VQ_L6 = 20,                   /* 低  Low */
    NETDEV_VQ_L7 = 24,
    NETDEV_VQ_L8 = 28,                   /* 较低  Lower */
    NETDEV_VQ_L9 = 31,                   /* 最低  Lowest */

    NETDEV_VQ_LEVEL_INVALID = -1,        /* 无效  Valid */
}NETDEV_VIDEO_QUALITY_E;

/**
* @enum tagNETDEVPictureSize
* @brief 图像分辨率 枚举定义 Image resolution Enumeration definition
* @attention 无 None
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

    NETDEV_PICTURE_SIZE_INVALID               /* 无效值  Invalid value */
}NETDEV_PICTURE_SIZE_E;

/**
* @enum tagNETDEVProtocolType
* @brief 协议类型
* @attention 无
*/
typedef enum tagNETDEVProtocolType
{
    NETDEV_PROTOCOL_TYPE_HTTP = 0,
    NETDEV_PROTOCOL_TYPE_HTTPS = 1,
    NETDEV_PROTOCOL_TYPE_RTSP = 2
}NETDEV_PROTOCOL_TYPE_E;

/* END************* 枚举值  Enumeration value *************************** */

/* BEGIN*********** 结构体  Structure *********************************** */

/**
* @struct tagNETDEVDeviceInfo
* @brief 设备信息 结构体定义 Device information Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVDeviceInfo
{
    INT32   dwDevType;                          /* 设备类型,参见枚举#NETDEV_DEVICETYPE_E  Device type, see enumeration #NETDEV_DEVICETYPE_E */
    INT16   wAlarmInPortNum;                    /* 报警输入个数  Number of alarm inputs */
    INT16   wAlarmOutPortNum;                   /* 报警输出个数  Number of alarm outputs */
    INT32   dwChannelNum;                       /* 通道个数  Number of Channels */
    BYTE    byRes[48];                          /* 保留字段  Reserved */
}NETDEV_DEVICE_INFO_S, *LPNETDEV_DEVICE_INFO_S;


/**
* @struct tagNETDEVPriviewInfo
* @brief 实况预览参数 结构体定义 Live view parameter Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVPriviewInfo
{
    INT32   dwChannelID;                    /* 通道ID  Channel ID */
    INT32   dwStreamType;                   /* 码流类型,参见枚举#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwLinkMode;                     /* 传输协议,参见枚举#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /* 播放窗口句柄 Play window handle */
    BYTE    byRes[264];                     /* 保留字段  Reserved */
}NETDEV_PREVIEWINFO_S, *LPNETDEV_PREVIEWINFO_S;

/**
* 拼帧前媒体流数据回调函数的指针类型  Type of pointer to media stream data callback function before being framed
* @param [IN] lpRealHandle      当前的实况播放句柄 Current live playing handle
* @param [IN] pucBuffer         存放拼帧前媒体流数据缓冲区指针 Pointer to buffer that stores stream data that is not framed
* @param [IN] dwBufSize         缓冲区大小 Buffer size
* @param [IN] dwMediaDataType   媒体数据类型,参见媒体类型枚举定义#NETDEV_MEDIAFORMAT_E Media data type, see definitions of enumeration #NETDEV_MEDIA_DATA_TYPE_E
* @param [IN] lpUserParam       用户设置参数,即用户在调用#NDPlayer_SetSourceMediaDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetSourceMediaDataCB function
* @return 无。 None.
* @note  用户应及时处理输出的媒体流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理。 Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_SOURCE_DATA_CALLBACK_PF)(IN LPVOID        lpRealHandle,
    IN const BYTE    *pucBuffer,
    IN INT32         dwBufSize,
    IN INT32         dwMediaDataType,
    IN LPVOID        lpUserParam
    );

/**
* 显示数据回调函数的指针类型 Type of pointer to display data callback function
* @param [IN] lpHandle       当前的实况播放句柄 Current live playing handle
* @param [IN] hdc            显示表面的hdc,用户可以用这个hdc 作图 Display superficial hdc which can be used for drawing graphics.
* @param [IN] lpUserParam    用户设置参数,即用户在调用#NETDEV_SetPlayDisplayCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NETDEV_SetPlayDisplayCB
* @return 无。
* @note
* -     用户应及时处理输出的音频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理。
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DISPLAY_CALLBACK_PF)(IN LPVOID lpHandle,
    IN LPVOID hdc,
    IN LPVOID lpUserParam
    );

#endif
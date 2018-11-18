#ifndef CONSTTYPE_H_
#define CONSTTYPE_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

///////////////////////////////////

//*** 常量定义信息:

// !!! 注意常量值由于已经运用到程序中，所以绝对不能改动。
// 顺序及值不能改动

// LIB_CONST_INFO s_ConstInfo [] =
// {
// 	{	_WT("取源码"),		_WT("水星异步"),	NULL,	LVL_SIMPLE,	CT_NUM,	NULL,	0,	},
// 	{	_WT("取文本"),		_WT("水星异步"),	NULL,	LVL_SIMPLE,	CT_NUM,	NULL,	1,	},
// 	{	_WT("执行表达式"),	_WT("水星异步"),	NULL,	LVL_SIMPLE,	CT_NUM,	NULL,	2,	},
// 
// };

static LIB_DATA_TYPE_ELEMENT s_dtAquaAsyncElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("取源码"),
        /*m_szEgName*/          _T("GetSource"),
        /*m_szExplain*/         _T("获取框架中的HTML源代码"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("取文本"),
        /*m_szEgName*/          _T("GetSource"),
        /*m_szExplain*/         _T("获取框架中的HTML文本"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("执行表达式"),
        /*m_szEgName*/          _T("Eval"),
        /*m_szExplain*/         _T("在框架中执行表达式。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaWodElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("未知的"),
        /*m_szEgName*/          _T("WOD_UNKNOWN"),
        /*m_szExplain*/         _T("WOD_UNKNOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("在当前标签窗口打开"),
        /*m_szEgName*/          _T("WOD_CURRENT_TAB"),
        /*m_szExplain*/         _T("WOD_CURRENT_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("从新的标签窗口打开"),
        /*m_szEgName*/          _T("WOD_SINGLETON_TAB"),
        /*m_szExplain*/         _T("WOD_SINGLETON_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("在前一个标签窗口打开"),
        /*m_szEgName*/          _T("WOD_NEW_FOREGROUND_TAB"),
        /*m_szExplain*/         _T("WOD_NEW_FOREGROUND_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("在后一个标签窗口打开"),
        /*m_szEgName*/          _T("WOD_NEW_BACKGROUND_TAB"),
        /*m_szExplain*/         _T("WOD_NEW_BACKGROUND_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          4
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("在新的对话框窗口打开"),
        /*m_szEgName*/          _T("WOD_NEW_POPUP"),
        /*m_szExplain*/         _T("WOD_NEW_POPUP"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          5
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("在新的顶层窗口打开"),
        /*m_szEgName*/          _T("WOD_NEW_WINDOW"),
        /*m_szExplain*/         _T("WOD_NEW_WINDOW"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          6
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("保存到磁盘"),
        /*m_szEgName*/          _T("WOD_SAVE_TO_DISK"),
        /*m_szExplain*/         _T("WOD_SAVE_TO_DISK"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          7
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("关闭记录"),
        /*m_szEgName*/          _T("WOD_OFF_THE_RECORD"),
        /*m_szExplain*/         _T("WOD_OFF_THE_RECORD"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          8
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("忽略动作"),
        /*m_szEgName*/          _T("WOD_IGNORE_ACTION"),
        /*m_szExplain*/         _T("WOD_IGNORE_ACTION"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          9
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaURLRequestFlagsElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("默认设置"),
        /*m_szEgName*/          _T("UR_FLAG_NONE"),
        /*m_szExplain*/         _T("默认行为。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("跳过缓存"),
        /*m_szEgName*/          _T("UR_FLAG_SKIP_CACHE"),
        /*m_szExplain*/         _T("如果设置，则在处理请求时将跳过缓存。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("包含饼干信息"),
        /*m_szEgName*/          _T("UR_FLAG_ALLOW_CACHED_CREDENTIALS"),
        /*m_szExplain*/         _T("如果设置用户名，密码和cookie可能随请求一起发送，则可以从响应中保存cookie。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("开启上传事件进度回调"),
        /*m_szEgName*/          _T("UR_FLAG_REPORT_UPLOAD_PROGRESS"),
        /*m_szExplain*/         _T("如果设置上传进度事件将在请求具有正文时生成。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("关闭下载回调"),
        /*m_szEgName*/          _T("UR_FLAG_NO_DOWNLOAD_DATA"),
        /*m_szExplain*/         _T("如果设置，则不会调用CefURLRequestClient :: OnDownloadData方法。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 6
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("忽略5XX错误"),
        /*m_szEgName*/          _T("UR_FLAG_NO_RETRY_ON_5XX"),
        /*m_szExplain*/         _T("如果设置5XX重定向错误将传播给观察者而不是自动重新尝试。 这当前仅适用于源自浏览器进程的请求。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 7
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaPostTypeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("空字段"),
        /*m_szEgName*/          _T("PDE_TYPE_EMPTY"),
        /*m_szExplain*/         _T("空值。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("字节集字段"),
        /*m_szEgName*/          _T("PDE_TYPE_BYTES"),
        /*m_szExplain*/         _T("字节集值。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("文件字段"),
        /*m_szEgName*/          _T("PDE_TYPE_FILE"),
        /*m_szExplain*/         _T("文件值。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaUrlRequestStatusElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("未知状态"),
        /*m_szEgName*/          _T("UR_UNKNOWN"),
        /*m_szExplain*/         _T("未知状态。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("加载成功"),
        /*m_szEgName*/          _T("UR_SUCCESS"),
        /*m_szExplain*/         _T("加载成功!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("仍在加载中"),
        /*m_szEgName*/          _T("UR_IO_PENDING"),
        /*m_szExplain*/         _T("资源仍在加载中!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("已被取消"),
        /*m_szEgName*/          _T("UR_CANCELED"),
        /*m_szExplain*/         _T("已被取消!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("加载失败"),
        /*m_szEgName*/          _T("UR_FAILED"),
        /*m_szExplain*/         _T("由于某种原因请求失败!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          4
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaResourceTypeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("主框架资源"),
        /*m_szEgName*/          _T("RT_MAIN_FRAME"),
        /*m_szExplain*/         _T("Top level page."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("子框架资源"),
        /*m_szEgName*/          _T("RT_SUB_FRAME"),
        /*m_szExplain*/         _T("Frame or iframe."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("层叠样式表资源"),
        /*m_szEgName*/          _T("RT_STYLESHEET"),
        /*m_szExplain*/         _T("CSS stylesheet."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("脚本资源"),
        /*m_szEgName*/          _T("RT_SCRIPT"),
        /*m_szExplain*/         _T("External script."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("图像资源"),
        /*m_szEgName*/          _T("RT_IMAGE"),
        /*m_szExplain*/         _T("Image (jpg/gif/png/etc)."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          4
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("字体资源"),
        /*m_szEgName*/          _T("RT_FONT_RESOURCE"),
        /*m_szExplain*/         _T("Font."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          5
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("其它资源"),
        /*m_szEgName*/          _T("RT_SUB_RESOURCE"),
        /*m_szExplain*/         _T("Some other subresource. This is the default type if the actual type is unknown."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          6
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("插件资源"),
        /*m_szEgName*/          _T("RT_OBJECT"),
        /*m_szExplain*/         _T("Object (or embed) tag for a plugin, or a resource that a plugin requested."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          7
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("多媒体资源"),
        /*m_szEgName*/          _T("RT_MEDIA"),
        /*m_szExplain*/         _T("Media resource."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          8
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("主要工作资源"),
        /*m_szEgName*/          _T("RT_WORKER"),
        /*m_szExplain*/         _T("Main resource of a dedicated worker.."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          9
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("共享工作资源"),
        /*m_szEgName*/          _T("RT_SHARED_WORKER"),
        /*m_szExplain*/         _T("Main resource of a shared worker."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          10
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("预请求资源"),
        /*m_szEgName*/          _T("RT_PREFETCH"),
        /*m_szExplain*/         _T("Explicitly requested prefetch."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          11
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("FAVICON资源"),
        /*m_szEgName*/          _T("RT_FAVICON"),
        /*m_szExplain*/         _T("Favicon."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          12
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("XHR资源"),
        /*m_szEgName*/          _T("RT_XHR"),
        /*m_szExplain*/         _T("XMLHttpRequest."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          13
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("PING资源"),
        /*m_szEgName*/          _T("RT_PING"),
        /*m_szExplain*/         _T("A request for a <ping>."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          14
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("服务工作资源"),
        /*m_szEgName*/          _T("RT_SERVICE_WORKER"),
        /*m_szExplain*/         _T("Main resource of a service worker."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          15
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CSP资源"),
        /*m_szEgName*/          _T("RT_CSP_REPORT"),
        /*m_szExplain*/         _T("A report of Content Security Policy violations."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          16
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("插件请求资源"),
        /*m_szEgName*/          _T("RT_PLUGIN_RESOURCE"),
        /*m_szExplain*/         _T("A resource that a plugin requested."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          17
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaKeyEventTypeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("原始键按下"),
        /*m_szEgName*/          _T("RAWKEYDOWN"),
        /*m_szExplain*/         _T("通知键从\"向上\"转换为\"向下\"。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("键按下"),
        /*m_szEgName*/          _T("KEYDOWN"),
        /*m_szExplain*/         _T("按下按键的通知。 这不一定对应取决于键和语言的字符。 使用KEYEVENT_CHAR字符输入。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("键弹起"),
        /*m_szEgName*/          _T("KEYUP"),
        /*m_szExplain*/         _T("通知按键已释放。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("字符输入"),
        /*m_szEgName*/          _T("CHAR"),
        /*m_szExplain*/         _T("键入字符的通知。 用于文本输入。 键down事件可能会产生0,1或多个字符事件在密钥，区域设置和操作系统上。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaMouseButtonElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("鼠标左键"),
        /*m_szEgName*/          _T("MBT_LEFT"),
        /*m_szExplain*/         _T("鼠标左键"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("鼠标中键"),
        /*m_szEgName*/          _T("MBT_MIDDLE"),
        /*m_szExplain*/         _T("鼠标中键"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("鼠标右键"),
        /*m_szEgName*/          _T("MBT_RIGHT"),
        /*m_szExplain*/         _T("鼠标右键"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaJsDialogElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ALERT"),
        /*m_szEgName*/          _T("ALERT"),
        /*m_szExplain*/         _T("ALERT"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CONFIRM"),
        /*m_szEgName*/          _T("CONFIRM"),
        /*m_szExplain*/         _T("CONFIRM"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("PROMPT"),
        /*m_szEgName*/          _T("PROMPT"),
        /*m_szExplain*/         _T("PROMPT"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaFileDialogCallbackElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("打开文件"),
        /*m_szEgName*/          _T("FILE_DIALOG_OPEN"),
        /*m_szExplain*/         _T("在允许用户选择文件之前，要求文件存在。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("打开文件可多选"),
        /*m_szEgName*/          _T("FILE_DIALOG_OPEN_MULTIPLE"),
        /*m_szExplain*/         _T("像Open一样，但允许选择打开多个文件。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("打开文件夹"),
        /*m_szEgName*/          _T("FILE_DIALOG_OPEN_FOLDER"),
        /*m_szExplain*/         _T("与Open一样，但选择要打开的文件夹。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("保存文件"),
        /*m_szEgName*/          _T("FILE_DIALOG_SAVE"),
        /*m_szExplain*/         _T("允许选择不存在的文件，并提示覆盖文件是否已存在。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("对话框类型标志位"),
        /*m_szEgName*/          _T("FILE_DIALOG_TYPE_MASK"),
        /*m_szExplain*/         _T("定义用于类型值的位的通用掩码。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0xFF
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("是否需要覆盖提示"),
        /*m_szEgName*/          _T("FILE_DIALOG_OVERWRITEPROMPT_FLAG"),
        /*m_szExplain*/         _T("如果用户使用“保存”对话框选择现有文件，则提示覆盖。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0x01000000
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("不显示只读文件"),
        /*m_szEgName*/          _T("FILE_DIALOG_HIDEREADONLY_FLAG"),
        /*m_szExplain*/         _T("不显示只读文件。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0x02000000
    },

};

static LIB_DATA_TYPE_ELEMENT s_dtAquaEventFlagsElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("无"),
        /*m_szEgName*/          _T("NONE"),
        /*m_szExplain*/         _T("NONE。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CAPS_LOCK键已按下"),
        /*m_szEgName*/          _T("CAPS_LOCK_ON"),
        /*m_szExplain*/         _T("CAPS_LOCK_ON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("SHIFT键已按下"),
        /*m_szEgName*/          _T("SHIFT_DOWN"),
        /*m_szExplain*/         _T("SHIFT_DOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CTRL键已按下"),
        /*m_szEgName*/          _T("CONTROL_DOWN"),
        /*m_szExplain*/         _T("CONTROL_DOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ALT键已按下"),
        /*m_szEgName*/          _T("ALT_DOWN"),
        /*m_szExplain*/         _T("ALT_DOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("鼠标左键已按下"),
        /*m_szEgName*/          _T("LEFT_MOUSE_BUTTON"),
        /*m_szExplain*/         _T("LEFT_MOUSE_BUTTON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 4
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("鼠标中键已按下"),
        /*m_szEgName*/          _T("MIDDLE_MOUSE_BUTTON"),
        /*m_szExplain*/         _T("MIDDLE_MOUSE_BUTTON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 5
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("鼠标右键已按下"),
        /*m_szEgName*/          _T("RIGHT_MOUSE_BUTTON"),
        /*m_szExplain*/         _T("RIGHT_MOUSE_BUTTON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 6
    },
};

#endif

#endif
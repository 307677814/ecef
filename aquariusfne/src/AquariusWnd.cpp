// AquariusWnd.cpp: implementation of the CAquariusWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AquariusWnd.h"
#include "dispatch.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern PFN_NOTIFY_SYS g_fnAquaNotifySys;

BEGIN_MESSAGE_MAP(CAquariusApp, CWinApp)
//{{AFX_MSG_MAP(CHtmlViewApp)
// NOTE - the ClassWizard will add and remove mapping macros here.
//    DO NOT EDIT what you see in these blocks of generated code!
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CAquariusWnd, CWnd)
//{{AFX_MSG_MAP(CHHCtrl)
ON_WM_SETFOCUS()
ON_WM_SIZE()
ON_WM_PAINT()
ON_WM_DESTROY()
ON_WM_TIMER()
ON_MESSAGE(AQUA_MSG_INITIAL,CAquariusWnd::OnInitial)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CAquariusWnd, CWnd)

END_EVENTSINK_MAP()

namespace Local{
	CAquariusWnd *pMainWnd;
}

CAquariusApp::CAquariusApp()
{
}

#ifndef __E_STATIC_LIB

CAquariusApp theApp;

#endif

// 注意顺序不可改变!!!
UNIT_PROPERTY g_aquariusWndProperty [] =
{
	FIXED_WIN_UNIT_PROPERTY,
	{
		/*m_szName*/			_WT("边框"),
		/*m_szEgName*/			_WT("border"),
		/*m_szExplain*/			_WT(""),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("无边框\0凹入式\0凸出式\0浅凹入式\0镜框式\0单线边框式\0"),
	},
	{
		/*m_szName*/			_WT("适配环境"),
		/*m_szEgName*/			_WT("adapter"),
		/*m_szExplain*/			_WT("浏览器运行适配环境包。"),
		/*m_shtType*/			UD_TEXT,
			/*m_wState*/		NULL,
			/*m_szzPickStr*/	_WT(""),
	},{
		/*m_szName*/			_WT("默认编码"),
		/*m_szEgName*/			_WT("default_encoding"),
		/*m_szExplain*/			_WT("Web内容的默认编码,如果为空则使用\"ISO-8859-1\""),
		/*m_shtType*/			UD_TEXT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT(""),
	},{
		/*m_szName*/			_WT("运行脚本"),
		/*m_szEgName*/			_WT("javascript"),
		/*m_szExplain*/			_WT("是否允许浏览器加载并运行页面中的脚本资源。"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("默认\0允许\0禁止\0"),
	},{
		/*m_szName*/			_WT("加载插件"),
		/*m_szEgName*/			_WT("plugins"),
		/*m_szExplain*/			_WT("是否允许浏览器加载扩展插件。"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("默认\0允许\0禁止\0"),
	},{
		/*m_szName*/			_WT("跨域访问"),
		/*m_szEgName*/			_WT(""),
		/*m_szExplain*/			_WT("是否允许关闭浏览器同源站点限制策略以现实跨域访问支持。"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("默认\0允许\0禁止\0"),
	},{
		/*m_szName*/			_WT("无图模式"),
		/*m_szEgName*/			_WT("image_loading"),
		/*m_szExplain*/			_WT("是否允许阻止浏览器从目标网络中加载图像资源。"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("默认\0允许\0禁止\0"),
	},
	{
		/*m_szName*/			_WT("WEBGL"),
		/*m_szEgName*/			_WT("webgl"),
		/*m_szExplain*/			_WT("控制是否可以使用WebGL,请注意,WebGL需要硬件支持,即使启用,也可能无法在所有系统上运行。"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("默认\0允许\0禁止\0"),
	}
};

INT g_aquariusWndPropertyCount = sizeof(g_aquariusWndProperty) / sizeof(g_aquariusWndProperty[0]);

static EVENT_ARG_INFO2 s_aquariusWndArgInfo [] = {
//****** 组件初始化	0
	{
/*name*/	_WT("选项"),
/*explain*/	_WT("该参数值用于对水星浏览器进行初始化设置。"),
/*state*/	EAS_BY_REF,
			MAKELONG(6,0)
	},
//****** 命令行初始化	1
	{
/*name*/	_WT("命令行"),
/*explain*/	_WT("该参数值用于查看或修改命令行信息。"),
/*state*/	EAS_BY_REF,
			MAKELONG(9,0)
	},
//****** 地址被改变	2
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 地址被改变	3
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("该参数值指向框架对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 地址被改变	4
	{
/*name*/	_WT("地址文本"),
/*explain*/	_WT("该参数值指向新的地址(URL)信息。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 地址被改变	5
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 标题被改变	6
	{
/*name*/	_WT("标题文本"),
/*explain*/	_WT("该参数值指向新的标题信息。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 页面图标被改变	7
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 页面图标被改变	8
	{
/*name*/	_WT("图标列表"),
/*explain*/	_WT("该参数值指向页面图标URL列表。"),
/*state*/	NULL,
			MAKELONG(2,0)
	},
//****** 显示模式被改变	9
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 显示模式被改变	10
	{
/*name*/	_WT("全屏"),
/*explain*/	_WT("该参数值指示当前是否为全屏状态"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** 状态文本被改变	11
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 状态文本被改变	12
	{
/*name*/	_WT("值"),
/*explain*/	_WT("该参数值指向状态文本。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 控制台	13
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 控制台	14
	{
/*name*/	_WT("消息类型"),
/*explain*/	_WT("该参数值表明消息的类型。"),
/*state*/	NULL,
			SDT_INT
	},
//****** 控制台	15
	{
/*name*/	_WT("消息文本"),
/*explain*/	_WT("消息文本"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 控制台	16
	{
/*name*/	_WT("消息源"),
/*explain*/	_WT("消息源"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 控制台	17
	{
/*name*/	_WT("行号"),
/*explain*/	_WT("行号"),
/*state*/	NULL,
			SDT_INT
	},
//****** 创建完毕 18
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 即将打开新窗口 19
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 即将打开新窗口 20
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("该参数值指向框架对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 即将打开新窗口 21
	{
/*name*/	_WT("目标地址"),
/*explain*/	_WT("目标地址。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 即将打开新窗口 22
	{
/*name*/	_WT("目标框架名称"),
/*explain*/	_WT("目标框架名称。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 即将打开新窗口 23
	{
/*name*/	_WT("打开方式"),
/*explain*/	_WT("链接的打开方式,与常量集合\"#窗口打开方式常量.xxx\"所匹配。"),
/*state*/	NULL,
			SDT_INT
	},
//****** 即将打开新窗口 24
	{
/*name*/	_WT("手势"),
/*explain*/	_WT("手势。"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** 即将打开新窗口 25
	{
/*name*/	_WT("保留参数"),
/*explain*/	_WT("保留参数"),
/*state*/	NULL,
			SDT_INT
	},
//****** 即将打开新窗口 26
	{
/*name*/	_WT("窗口信息"),
/*explain*/	_WT("窗口信息。"),
/*state*/	EAS_BY_REF,
			MAKELONG(7,0)
	},
//****** 即将打开新窗口 27
	{
/*name*/	_WT("禁用脚本"),
/*explain*/	_WT("禁用脚本。"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
//****** 载入状态被改变 28
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 载入状态被改变 29
	{
/*name*/	_WT("载入中"),
/*explain*/	_WT("当前页面是否仍在载入中"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** 载入状态被改变 30
	{
/*name*/	_WT("可否后退"),
/*explain*/	_WT("可否后退"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** 载入状态被改变 31
	{
/*name*/	_WT("可否前进"),
/*explain*/	_WT("可否前进"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** 载入开始 32
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 载入开始 33
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("该参数值指向框架对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 载入开始 34
	{
/*name*/	_WT("源类型"),
/*explain*/	_WT("请求的转换类型。 由一个源值和0或更多组成预选赛。"),
/*state*/	NULL,
			SDT_INT
	},
//****** 载入结束 35
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 载入结束 36
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("该参数值指向框架对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 载入结束 37
	{
/*name*/	_WT("状态码"),
/*explain*/	_WT("HTTP请求响应码"),
/*state*/	NULL,
			SDT_INT
	},
//****** 载入失败 38
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("该参数值指向浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 载入失败 39
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("该参数值指向框架对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 载入失败 40
	{
/*name*/	_WT("错误代码"),
/*explain*/	_WT("错误代码"),
/*state*/	NULL,
			SDT_INT
	},
//****** 载入失败 41
	{
/*name*/	_WT("错误文本"),
/*explain*/	_WT("错误文本"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 载入失败 42
	{
/*name*/	_WT("失败地址"),
/*explain*/	_WT("失败地址"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 异步执行结果 43
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 异步执行结果 44
	{
/*name*/	_WT("执行标记"),
/*explain*/	_WT("用于表示当前接收到的执行结果是由谁发出的,为以下常量之一: "
				"0 : #异步调用类型常量.取源码;  1 : #异步调用类型常量.取文本;  2 : #异步调用类型常量.执行表达式"),
/*state*/	NULL,
			SDT_INT
	},
//****** 异步执行结果 45
	{
/*name*/	_WT("自定义参数1"),
/*explain*/	_WT("在调用异步函数时所传入的自定义参数。"),
/*state*/	NULL,
			SDT_INT
	},
//****** 异步执行结果 46
	{
/*name*/	_WT("自定义参数2"),
/*explain*/	_WT("在调用异步函数时所传入的自定义参数。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 异步执行结果 47
	{
/*name*/	_WT("自定义参数3"),
/*explain*/	_WT("在调用异步函数时所传入的自定义参数。"),
/*state*/	NULL,
			SDT_BIN
	},
//****** 异步执行结果 48
	{
/*name*/	_WT("结果1"),
/*explain*/	_WT("异步模式下的函数调用结果。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 异步执行结果 49
	{
/*name*/	_WT("结果2"),
/*explain*/	_WT("异步模式下的函数调用结果。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本上下文创建完毕 50
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器对象。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 脚本注册变量被赋值 51
	{
/*name*/	_WT("类名"),
/*explain*/	_WT("类名称。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本注册变量被赋值 52
	{
/*name*/	_WT("变量名"),
/*explain*/	_WT("变量名称。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本注册变量被赋值 53
	{
/*name*/	_WT("新值"),
/*explain*/	_WT("被赋予的新值。"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** 脚本注册变量被取值 54
	{
/*name*/	_WT("类名"),
/*explain*/	_WT("类名称。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本注册变量被取值 55
	{
/*name*/	_WT("变量名"),
/*explain*/	_WT("变量名称。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本注册变量被取值 56
	{
/*name*/	_WT("返回值"),
/*explain*/	_WT("返回给调用者的值。"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** 脚本注册函数被调用 57
	{
/*name*/	_WT("类名"),
/*explain*/	_WT("类名称。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本注册函数被调用 58
	{
/*name*/	_WT("函数名"),
/*explain*/	_WT("函数名称。"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本注册函数被调用 59
	{
/*name*/	_WT("参数数量"),
/*explain*/	_WT("参数数量。"),
/*state*/	NULL,
			SDT_INT
	},
//****** 脚本注册函数被调用 60
	{
/*name*/	_WT("参数值"),
/*explain*/	_WT("参数值。"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** 脚本注册函数被调用 61
	{
/*name*/	_WT("返回值"),
/*explain*/	_WT("返回的值"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** 资源载入开始 62
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 资源载入开始 63
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("框架"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 资源载入开始 64
	{
/*name*/	_WT("request"),
/*explain*/	_WT("request"),
/*state*/	EAS_BY_REF,
			MAKELONG(24,0)
	},
//****** 资源载入开始 65
	{
/*name*/	_WT("拷贝资源数据"),
/*explain*/	_WT("如果设置为真且则当资源顺利载入完成时会在\"资源载入结束\"事件中的\"有效载荷\"参数上提供该资源的副本数据。"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
//****** 资源重定向 66
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 资源重定向 67
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("框架"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 资源重定向 68
	{
/*name*/	_WT("HTTP请求"),
/*explain*/	_WT("request"),
/*state*/	EAS_BY_REF,
			MAKELONG(24,0)
	},
//****** 资源载入结束 69
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 资源载入结束 70
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("框架"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 资源载入结束 71
	{
/*name*/	_WT("HTTP请求"),
/*explain*/	_WT("request"),
/*state*/	EAS_BY_REF,
			MAKELONG(24,0)
	},
//****** 资源载入结束 72
	{
/*name*/	_WT("HTTP回应"),
/*explain*/	_WT("response"),
/*state*/	EAS_BY_REF,
			MAKELONG(25,0)
	},
//****** 资源载入结束 73
	{
/*name*/	_WT("加载结果"),
/*explain*/	_WT("反映资源的加载情况,参考常量列表:#资源加载结果常量.xxx"),
/*state*/	NULL,
			SDT_INT
	},
//****** 资源载入结束 74
	{
/*name*/	_WT("接收资源大小"),
/*explain*/	_WT("接收到的资源大小"),
/*state*/	NULL,
			SDT_INT
	},
//****** 资源载入结束 75
	{
/*name*/	_WT("有效载荷"),
/*explain*/	_WT("存放资源的拷贝副本,当\"资源载入开始\"事件中将\"拷贝资源数据\"参数设置为真时,才会创建资源的副本镜像。"),
/*state*/	EAS_BY_REF,
			SDT_BIN
	},
//****** 脚本弹出对话框 76
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器。"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 脚本弹出对话框 77
	{
/*name*/	_WT("Url"),
/*explain*/	_WT("Url"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本弹出对话框 78
	{
/*name*/	_WT("lang"),
/*explain*/	_WT("lang"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本弹出对话框 79
	{
/*name*/	_WT("对话框类型"),
/*explain*/	_WT("对话框类型,参考常量集合: #J脚本对话框常量.xxx"),
/*state*/	NULL,
			SDT_INT
	},
//****** 脚本弹出对话框 80
	{
/*name*/	_WT("提示文本"),
/*explain*/	_WT("提示文本"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本弹出对话框 81
	{
/*name*/	_WT("默认文本"),
/*explain*/	_WT("默认文本"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 脚本弹出对话框 82
	{
/*name*/	_WT("按钮"),
/*explain*/	_WT("按钮"),
/*state*/	EAS_BY_REF,
			MAKELONG(33,0)
	},
//****** 文件对话框将被打开 83
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 文件对话框将被打开 84
	{
/*name*/	_WT("打开方式"),
/*explain*/	_WT("打开方式,参考常量集合: #文件对话框常量.xxx"),
/*state*/	NULL,
			SDT_INT
	},
//****** 文件对话框将被打开 85
	{
/*name*/	_WT("标题文本"),
/*explain*/	_WT("标题文本"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 文件对话框将被打开 86
	{
/*name*/	_WT("初始目录"),
/*explain*/	_WT("初始目录"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 文件对话框将被打开 87
	{
/*name*/	_WT("过滤器列表"),
/*explain*/	_WT("过滤器列表"),
/*state*/	EAS_BY_REF,
			MAKELONG(2,0)
	},
//****** 文件对话框将被打开 88
	{
/*name*/	_WT("选择的过滤器索引"),
/*explain*/	_WT("选择的过滤器索引"),
/*state*/	NULL,
			SDT_INT
	},
//****** 文件对话框将被打开 89
	{
/*name*/	_WT("按钮"),
/*explain*/	_WT("按钮"),
/*state*/	EAS_BY_REF,
			MAKELONG(34,0)
	},
//****** 按键事件 90
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 按键事件 91
	{
/*name*/	_WT("按键消息"),
/*explain*/	_WT("按键消息"),
/*state*/	EAS_BY_REF,
			MAKELONG(36,0)
	},
//****** 按键事件 92
	{
/*name*/	_WT("是否置为快捷键"),
/*explain*/	_WT("是否置为快捷键"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
//****** 文件将被下载 93
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 文件将被下载 94
	{
/*name*/	_WT("下载信息"),
/*explain*/	_WT("下载信息"),
/*state*/	EAS_BY_REF,
			MAKELONG(39,0)
	},
//****** 文件将被下载 95
	{
/*name*/	_WT("推荐文件名"),
/*explain*/	_WT("推荐文件名"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 文件将被下载 96
	{
/*name*/	_WT("选项"),
/*explain*/	_WT("选项"),
/*state*/	EAS_BY_REF,
			MAKELONG(40,0)
	},
//****** 下载进度被更新 97
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 下载进度被更新 98
	{
/*name*/	_WT("下载信息"),
/*explain*/	_WT("下载信息"),
/*state*/	EAS_BY_REF,
			MAKELONG(39,0)
	},
//****** 下载进度被更新 99
	{
/*name*/	_WT("选项"),
/*explain*/	_WT("选项"),
/*state*/	EAS_BY_REF,
			MAKELONG(41,0)
	},
//****** 右键菜单即将弹出 100
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 右键菜单即将弹出 101
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("框架"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 右键菜单即将弹出 102
	{
/*name*/	_WT("横向位置"),
/*explain*/	_WT("横向位置"),
/*state*/	NULL,
			SDT_INT
	},
//****** 右键菜单即将弹出 103
	{
/*name*/	_WT("纵向位置"),
/*explain*/	_WT("纵向位置"),
/*state*/	NULL,
			SDT_INT
	},
//****** 授权认证事件 104
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("浏览器"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** 授权认证事件 105
	{
/*name*/	_WT("框架"),
/*explain*/	_WT("框架"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** 授权认证事件 106
	{
/*name*/	_WT("是否为代理服务器"),
/*explain*/	_WT("是否为代理服务器"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** 授权认证事件 107
	{
/*name*/	_WT("主机地址"),
/*explain*/	_WT("主机地址"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 授权认证事件 108
	{
/*name*/	_WT("主机端口"),
/*explain*/	_WT("主机端口"),
/*state*/	NULL,
			SDT_INT
	},
//****** 授权认证事件 109
	{
/*name*/	_WT("realm"),
/*explain*/	_WT("|realm| is the realm of the challenge and may be empty."),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 授权认证事件 110
	{
/*name*/	_WT("scheme"),
/*explain*/	_WT("|scheme| is the authentication scheme used such as \"basic\" or \"digest\", and will be empty if the source of the request is an FTP server."),
/*state*/	NULL,
			SDT_TEXT
	},
//****** 授权认证事件 111
	{
/*name*/	_WT("登录"),
/*explain*/	_WT("登录"),
/*state*/	NULL,
			MAKELONG(42,0)
	},
};

EVENT_INFO2 g_aquariusWndEvent [] = {
	{
			_WT("组件初始化"),
			_WT("在组件包加载完成后被调用,在此事件中可以执行相关的初始化代码。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[0],
			_SDT_NULL
	},
	{
			_WT("命令行初始化"),
			_WT("在浏览器初始化时被调用,在此事件中获得查看以及修改命令行配置项的机会。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[1],
			_SDT_NULL
	},
	{
			_WT("初始化完毕"),
			_WT("在浏览器初始化初始化完毕后被调用,在此事件中可以执行程序的相关初始化代码。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			0,
			/*m_pBeginArgInfo*/		NULL,
			_SDT_NULL
	},
	{
			_WT("地址被改变"),
			_WT("当地址发生变化时调用该事件。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[2],
			_SDT_NULL
	},
	{
			_WT("标题被改变"),
			_WT("当页面标题改变时调用。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[5],
			_SDT_NULL
	},
	{
			_WT("页面图标被改变"),
			_WT("当页面图标发生变化时调用。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[7],
			_SDT_NULL
	},
	{
			_WT("显示模式被改变"),
			_WT("当页面中的网页内容切换为全屏模式时调用。"
				"如果|全屏| 该内容将自动调整大小以填充浏览器内容区域。"
				"如果|全屏| 是错误的内容将自动返回到其原始大小和位置。 如果需要，客户端负责调整浏览器的大小。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[9],
			_SDT_NULL
	},
	{
			_WT("状态文本被改变"),
			_WT("当浏览器收到状态消息时调用。|值| 包含将在状态消息中显示的文本。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[11],
			_SDT_NULL
	},
	{
			_WT("控制台"),
			_WT("调用以显示控制台消息。 返回true以停止将消息输出到控制台。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			5,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[13],
			SDT_BOOL
	},
	{
			_WT("创建完毕"),
			_WT("调用以显示控制台消息。 返回true以停止将消息输出到控制台。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[18],
			_SDT_NULL
	},
	{
			_WT("即将打开新窗口"),
			_WT("在创建新的弹出式浏览器之前调用UI线程。"
				"该|浏览器|和| 框架 |值代表弹出请求的来源。"
				"| 目标地址 |和| 目标框架名 |值表示弹出的位置"
				"浏览器应该导航，如果未与请求一起指定，则可能为空。"
				"| 目标位置 |值表示用户打算打开的位置"
				"弹出窗口（例如当前标签，新标签等）。 | 手势 |价值会"
				"如果通过明确的用户手势打开了弹出式窗口"
				"（例如，单击\"链接\"），如果弹出式窗口自动打开（例如通过DomContentLoaded事件）。"
				"关于所请求的弹出窗口的信息。允许创建弹出浏览器可以选择修改| 窗口信息 |，"
				"和| no_javascript_access |并返回false。取消创建弹出窗口浏览器返回true。"
				"客户端|和|设置|值将默认为源浏览器的值。如果| no_javascript_access |值设置为"
				"假新的浏览器不会被编写脚本，并且可能不会被托管与源浏览器相同的渲染器进程。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			9,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[19],
			SDT_BOOL
	},
	{
			_WT("可否被关闭"),
			_WT("当浏览器收到关闭请求时调用。"
				"这可能会导致直接从调用CefBrowserHost::*CloseBrowser()"
				"浏览器将成为由CEF和用户创建的顶级窗口的父级尝试关闭该窗口（例如，通过单击“X”）。该"
				"在'onunload'事件发生后，DoClose（）方法会被调用被解雇。"
				"应用程序应该通过。处理顶层所有者窗口关闭通知调用CefBrowserHost :: TryCloseBrowser（）或"
				"CefBrowserHost :: CloseBrowser（false）而不是允许窗口关闭"
				"立即（见下面的例子）。 这给了CEF一个机会"
				"处理'onbeforeunload'事件并有选择地取消关闭DoClose（）被调用。"
				"当启用窗口渲染时，CEF将在内部创建窗口或查看托管浏览器。 在这种情况下，从DoClose（）返回false将会发生"
				"向浏览器的顶级所有者发送标准关闭通知"
				"窗口（例如Windows上的WM_CLOSE，执行关闭：在OS X上，“delete_event”开启"
				"从视图的Linux或CefWindowDelegate :: CanClose（）回调）。 如果"
				"浏览器的主窗口/视图已经被销毁（通过视图层次结构"
				"例如拆卸），那么DoClose（）将不会被该浏览器调用因为不再可能取消关闭请求。"
				"当窗口渲染被禁用时，将从DoClose（）返回false导致浏览器对象被立即销毁。"
				"如果浏览器的顶级所有者窗口需要非标准关闭通知然后从DoClose（）发送该通知并返回true。"
				"CefLifeSpanHandler :: OnBeforeClose()方法将在之后调用DoClose()(如果调用DoClose())并且在浏览器之前对象被破坏。"
				"应用程序只应在OnBeforeClose()后退出已被所有现有浏览器调用。"
				"下面的例子描述了在关闭窗口时应该发生什么浏览器是由应用程序提供的顶层窗口生成的。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[18],
			SDT_BOOL
	},
	{
			_WT("即将被销毁"),
			_WT("在浏览器被销毁之前调用。"
				"释放所有的引用浏览器对象，并且不要尝试在浏览器上执行任何方法此回调返回后的对象。"
				"这个回调将是最后一次通知引用|浏览器|。 请参阅DoClose()文档额外的使用信息。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[18],
			_SDT_NULL
	},
	{
			_WT("载入状态被改变"),
			_WT("加载状态发生变化时调用。 "
				"此回调将被执行两次 - 以编程方式或由用户启动加载时行动，一旦加载因完成而终止时，取消的失败。"
				"它将在任何调用OnLoadStart之前调用，毕竟调用OnLoadError和/或OnLoadEnd。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[28],
			_SDT_NULL
	},
	{
			_WT("载入开始"),
			_WT("在提交导航之后并在浏览器开始之前调用在框架中加载内容。"
				"调用IsMain（）方法来检查这个frame是否是mainframe。"
				"| transition_type| 提供关于导航源的信息并且准确的值仅在浏览器进程中可用。"
				"多frame可能同时被加载。子frame可能会开始或继续在主框架加载结束后加载。这个方法不会被调用"
				" 为相同的页面导航（片段，历史状态等）或for导航失败或在提交之前取消。 通知"
				"整体浏览器负载状态改为使用OnLoadingStateChange。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[32],
			_SDT_NULL
	},
	{
			_WT("载入结束"),
			_WT("当浏览器完成加载帧时调用。 |框架| 价值会"
				"永远不为空 - 调用IsMain（）方法来检查这个帧是否为空"
				"主框架。 多个frame可能同时加载。 子frame可能"
				"在mainframe加载结束后启动或继续加载。 这种方法"
				"将不会被调用相同的页面导航（片段，历史状态，等等）或导航失败或提交前被取消。 对于"
				"整体浏览器负载状态通知使用OnLoadingStateChange代替。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[35],
			_SDT_NULL
	},
	{
			_WT("载入失败"),
			_WT("当导航失败或被取消时调用。 这种方法可能会被调用"
				"本身如果在提交之前或与OnLoadStart / OnLoadEnd结合使用的话"
				"提交后。|的errorCode|是错误代码号,|errorText| 是个"
				"错误文本和| failedUrl|是未能加载的网址。"
				"有关错误代码的完整说明，请参见net\\base\\net_error_list.h。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			5,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[38],
			_SDT_NULL
	},
	{
			_WT("异步调用结果"),
			_WT("该事件用于接收异步模式下的函数调用结果。"
				"支持异步模式的函数有: \"水星框架.取源码()\",\"水星框架.取文本()\",\"水星框架.执行表达式()\","
				"在事件中调用这些函数的时,必须使用异步模式,否则无法获得结果。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[43],
			_SDT_NULL
	},
	{
			_WT("异步计算结果"),
			_WT("该事件用于接收异步模式下的函数调用结果。"
				"支持异步模式的函数有: \"水星框架.取源码()\",\"水星框架.取文本()\",\"水星文档.执行表达式()\","
				"在事件中调用这些函数的时,必须使用异步模式,否则无法获得结果。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[43],
			_SDT_NULL
	},
	{
			_WT("脚本上下文创建完毕"),
			_WT("在创建完成框架中的V8上下文执行环境后调用该事件。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[50],
			_SDT_NULL
	},
	{
			_WT("脚本上下文将被销毁"),
			_WT("在框架中的V8上下文执行环境即将被销毁前调用。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[50],
			_SDT_NULL
	},
	{
			_WT("注册类属性被赋值"),
			_WT("当注册于脚本上下文环境中的变量被赋值时调用。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[51],
			SDT_BOOL
	},
	{
			_WT("注册类属性被取值"),
			_WT("当注册于脚本上下文环境中的变量被取值时调用。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[54],
			SDT_BOOL
	},
	{
			_WT("注册类方法被调用"),
			_WT("当注册于脚本上下文环境中的函数被调用时响应该事件。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			5,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[57],
			SDT_BOOL
	},
	{
			_WT("资源载入开始"),
			_WT("在即将加载页面资源前调用该事件,如果返回假阻止该资源的加载,默认情况下返回真,允许载入该资源。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[62],
			SDT_BOOL
	},
	{
			_WT("资源重定向"),
			_WT("是否需要重新定向资源的加载URL,返回\"\"表示不进行重定向,非空时提供需要重新定向到的新URL地址。 "),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[66],
			SDT_TEXT
	},
	{
			_WT("资源载入结束"),
			_WT("在页面资源加载完成后调用该事件."),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[69],
			_SDT_NULL
	},
	{
			_WT("脚本弹出对话框"),
			_WT("当脚本弹出对话框时调用该事件,如果返回真将阻止对话框的弹出。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[76],
			SDT_BOOL
	},
	{
			_WT("文件对话框将被打开"),
			_WT("当文件对话框被访问时调用该事件,如果返回真将阻止对话框的弹出。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[83],
			SDT_BOOL
	},
	{
			_WT("按键事件"),
			_WT("当在浏览器中产生键盘事件时调用该事件,如果返回真将阻止该事件传递至渲染器。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[90],
			SDT_BOOL
	},
	{
			_WT("资源文件将被下载"),
			_WT("在下载开始之前调用。| suggested_name| 是下载文件的建议名称。 "
				"默认情况下，下载将被取消。 执行|回调| 异步或以此方法继续下载（如果需要）。 "
				"不要保留对| download_item |的引用 在这种方法之外。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[93],
			_SDT_NULL
	},
	{
			_WT("下载进度被更新"),
			_WT("在下载的状态或进度信息已更新时调用。"
					"这可以在OnBeforeDownload（）之前和之后多次调用。"
					"执行|回调| 要么异步，要么在此方法中取消"
					"如果需要下载。 不要保留对| download_item |的引用 在外面这种方法。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[97],
			_SDT_NULL
	},
	{
			_WT("右键菜单即将弹出"),
			_WT("调用以允许自定义显示上下文菜单。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[100],
			SDT_BOOL
	},
	{
			_WT("代理认证"),
			_WT("当浏览器需要来自用户的凭据时调用该事件,返回真接受认证,返回假取消认证,默认返回假。"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			8,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[104],
			SDT_BOOL
	},
};

INT g_nAquariusWndEventCount = sizeof(g_aquariusWndEvent) / sizeof(g_aquariusWndEvent[0]);
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAquariusWnd::CAquariusWnd()
{
	Local::pMainWnd=this;
}

CAquariusWnd::~CAquariusWnd()
{
	Local::pMainWnd=NULL;
}

BOOL CAquariusWnd::Create (HWND hParentWnd, DWORD dwStyle, UINT nID,
			 INT x, INT y, INT cx, INT cy){
	if (!CWnd::CreateEx (NULL, AfxRegisterWndClass (CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
		::LoadCursor (NULL, IDC_ARROW), HBRUSH (::GetStockObject (WHITE_BRUSH))),
		_T(""), dwStyle, x, y, cx, cy, hParentWnd, (HMENU)nID, NULL))
		return FALSE;
	
	AfxEnableControlContainer();
	return TRUE;
}

void CAquariusWnd::ChangeBroder(void){
	DWORD dwStyle = NULL, dwExStyle = NULL;
	switch (m_info.m_nBorderStyle)
	{
	case 0:		// 无边框
		break;
	case 1:		// 凹入式
		dwExStyle = WS_EX_CLIENTEDGE;
		break;
	case 2:		// 凸出式
		dwExStyle = WS_EX_DLGMODALFRAME;
		break;
	case 3:		// 浅凹入式
		dwExStyle = WS_EX_STATICEDGE;
		break;
	case 4:		// 镜框式
		dwExStyle = WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME;
		break;
	case 5:
		dwStyle = WS_BORDER;
		break;
	}
	this->ModifyStyleEx (WS_EX_STATICEDGE | WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME,
		dwExStyle, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
		SWP_FRAMECHANGED | SWP_DRAWFRAME);
	this->ModifyStyle (WS_BORDER, dwStyle,
		SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
			SWP_FRAMECHANGED | SWP_DRAWFRAME);
}

BOOL CAquariusWnd::OnWndMsg(UINT message,WPARAM wParam,LPARAM lParam,LRESULT *pResult){
	if(message == WM_CREATE){
		if(m_blInDesignMode == FALSE){
			
		}
	}
	else if(message == AQUA_MSG_INITIAL){
		return this->OnInitial(0,0);
	}
	else if(message == WM_EXITSIZEMOVE){
	}
	else if(message == WM_CLOSE){
	}
	return CWnd::OnWndMsg(message,wParam,lParam,pResult);
}

void CAquariusWnd::OnClose(){
	CWnd::OnClose();
	return;
}

LRESULT CAquariusWnd::OnInitial(WPARAM wParam,LPARAM lParam){
	if(m_info.m_package.GetLength()>0){
		dispEventer::OnInitial(this,m_info.m_package);
	}
	return TRUE;
}


void CAquariusWnd::OnDestroy()
{
	CWnd::OnDestroy();
}

void CAquariusWnd::PostNcDestroy()
{
	CWnd::PostNcDestroy();
	g_fnAquaNotifySys (NRS_UNIT_DESTROIED, m_dwWinFormID, m_dwUnitID);
	delete this;
}

void CAquariusWnd::OnSize(UINT nType, int cx, int cy){
	CWnd::OnSize(nType,cx,cy);
	if(m_blInDesignMode == FALSE){
		dispEventer::OnResized(this);
	}
}

void CAquariusWnd::OnPaint()
{
	Default();
}

void CAquariusWnd::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);
}

afx_msg void CAquariusWnd::OnTimer(UINT nIDEvent){
	if(nIDEvent == AQUA_TIMER_INITIAL){
		KillTimer(AQUA_TIMER_INITIAL);
		PostMessage(AQUA_MSG_INITIAL);
		return;
	}
	CWnd::OnTimer(nIDEvent);
}

CAquariusWnd* CAquariusWnd::GetMainWnd(void){
	return Local::pMainWnd;
}
#ifndef ARGINFO_H_
#define ARGINFO_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static ARG_INFO s_ArgInfo[] = {
//****** 文本向量->添加（成员）	**	0
	{
/*name*/	_WT("待添加的文本"),
/*explain*/	_WT("将要添加到文本向量中的文本数据。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本向量->替换（成员）/ 删除（成员）/ 取内容（成员）	**	1
	{
/*name*/	_WT("索引"),
/*explain*/	_WT("用以关联文本数据的索引数值,从0开始。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本向量->替换（成员）	**	2
	{
/*name*/	_WT("用作替换的文本"),
/*explain*/	_WT("用以替换到向量中索引值指向的文本数据。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 长整数向量->添加（成员）	**	3
	{
/*name*/	_WT("待添加的数值"),
/*explain*/	_WT("将要添加到向量中的长整数值。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT64,
/*default*/	0,
/*state*/	NULL,
	},
//****** 长整数向量->替换（成员）/ 删除（成员）/ 取内容（成员）	**	4
	{
/*name*/	_WT("索引"),
/*explain*/	_WT("用以关联长整数数据的索引数值,从0开始。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 长整数向量->替换（成员）	**	5
	{
/*name*/	_WT("用作替换的数值"),
/*explain*/	_WT("用以替换到向量中索引值指向的长整数数据。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT64,
/*default*/	0,
/*state*/	NULL,
	},
//****** 适配器->载入组件包	**	6
	{
/*name*/	_WT("组件包路径"),
/*explain*/	_WT("指向水星浏览器(Aquariuscef)组件包的绝对路径。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典->插入	**	7
	{
/*name*/	_WT("欲插入的键名"),
/*explain*/	_WT("用作关联键值的名称索引"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典->插入	**	8
	{
/*name*/	_WT("欲插入的键值"),
/*explain*/	_WT("键值数据"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典->查找	**	9
	{
/*name*/	_WT("欲查找的键名"),
/*explain*/	_WT("关联着键值数据的名称索引"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典->取下个成员	**	10
	{
/*name*/	_WT("成员指针"),
/*explain*/	_WT("用于进行迭代的成员位置指针,首个位置指针可使用函数\"取首个成员\"获得"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典->删除	**	11
	{
/*name*/	_WT("欲删除的键名"),
/*explain*/	_WT("关联着键值数据的名称索引"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->插入	**	12
	{
/*name*/	_WT("欲插入的键名"),
/*explain*/	_WT("用作关联键值的名称索引"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->插入	**	13
	{
/*name*/	_WT("欲插入的键值"),
/*explain*/	_WT("键值数据"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->查找	**	14		//废弃
	{
/*name*/	_WT("欲查找的键名"),
/*explain*/	_WT("关联着键值数据的名称索引"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->取下个成员	**	15
	{
/*name*/	_WT("成员指针"),
/*explain*/	_WT("用于进行迭代的成员位置指针,首个位置指针可使用函数\"取首个成员\"获得"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->删除	**	16
	{
/*name*/	_WT("欲删除的键名"),
/*explain*/	_WT("关联着键值数据的名称索引"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->创建浏览器作为子窗口	**	17
	{
/*name*/	_WT("父窗口句柄"),
/*explain*/	_WT("欲嵌入到的窗口"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->创建浏览器作为子窗口	**	18
	{
/*name*/	_WT("左边位置"),
/*explain*/	_WT("左边位置"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->创建浏览器作为子窗口	**	19
	{
/*name*/	_WT("顶边位置"),
/*explain*/	_WT("顶边位置"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->创建浏览器作为子窗口	**	20
	{
/*name*/	_WT("宽度"),
/*explain*/	_WT("宽度"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->创建浏览器作为子窗口	**	21
	{
/*name*/	_WT("高度"),
/*explain*/	_WT("高度"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->创建浏览器作为弹出窗口	**	22
	{
/*name*/	_WT("父窗口句柄"),
/*explain*/	_WT("父窗口句柄"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->创建浏览器作为弹出窗口	**	23
	{
/*name*/	_WT("窗口标题"),
/*explain*/	_WT("窗口标题"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->调整风格样式	**	24
	{
/*name*/	_WT("样式"),
/*explain*/	_WT("样式"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 窗口设置->调整风格样式	**	25
	{
/*name*/	_WT("扩展样式"),
/*explain*/	_WT("扩展样式"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** HTTP环境设置->缓存路径	**	26
	{
/*name*/	_WT("位置"),
/*explain*/	_WT("用于存储浏览器缓存数据的路径位置。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** HTTP环境设置->保持会话	**	27
	{
/*name*/	_WT("是否启用"),
/*explain*/	_WT("如果启用此项功能则设置为真,否则为假。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 适配器->载入组件包	**	28
	{
/*name*/	_WT("组件包路径"),
/*explain*/	_WT("指向水星浏览器(Aquariuscef)组件包的绝对路径。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 适配器->载入组件包	**	29
	{
/*name*/	_WT("载入完毕"),
/*explain*/	_WT("提供一个回调子程序在组件包加载完成后被调用,用以执行相关的初始化代码。子程序签名: <无返回值> 子程序()"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_SUB_PTR,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 适配器->载入组件包	**	30
	{
/*name*/	_WT("命令行处理"),
/*explain*/	_WT("提供一个回调子程序在浏览器初始化时被调用,用以获得查看以及修改命令行配置项的机会。"
				"如果当前为浏览器进程则|进程类型|为空。子程序签名: <无返回值> 子程序(文本型 进程类型,整数型 命令行)"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_SUB_PTR,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 适配器->初始化环境配置	**	31
	{
/*name*/	_WT("初始化信息"),
/*explain*/	_WT(""),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(6,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星命令行->从指针初始化	**	32
	{
/*name*/	_WT("源对象"),
/*explain*/	_WT("欲创建副本的源对象"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星命令行->是否存在指定项 / 取项值 /置项值	**	33
	{
/*name*/	_WT("项名"),
/*explain*/	_WT("命令行配置项名,命令行配置项格式: --项名=[项值] ,其中\"[项值]\"可忽略不写。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星命令行->是否存在指定项	**	34
	{
/*name*/	_WT("值"),
/*explain*/	_WT("与命令行配置项所关联的值。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星命令行->从字符串初始化	**	35
	{
/*name*/	_WT("命令行字符串"),
/*explain*/	_WT("用于初始化命令行对象的字符串。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星领航员->创建浏览器	**	36
	{
/*name*/	_WT("url"),
/*explain*/	_WT("浏览器创建完成后将要访问的地址(URL),默认为空时将为\"about:blank\"。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星领航员->创建浏览器	**	37
	{
/*name*/	_WT("窗口信息"),
/*explain*/	_WT("提供浏览器窗口的样式信息；默认为空时将嵌入到领航员的客户区中。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(7,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星领航员->创建浏览器	**	38
	{
/*name*/	_WT("私有环境"),
/*explain*/	_WT("提供浏览器的HTTP上下文访问环境; 默认为空时将使用全局配置。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(8,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星领航员->查询浏览器	**	39
	{
/*name*/	_WT("浏览器句柄"),
/*explain*/	_WT("用于关联浏览器实例对象的数值标识符。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星浏览器->从标识符取框架	**	40
	{
/*name*/	_WT("框架标识符"),
/*explain*/	_WT("用于关联框架实例对象的数值标识符。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT64,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星浏览器->从标识符取框架	**	41
	{
/*name*/	_WT("名称"),
/*explain*/	_WT("用于关联框架实例对象的名称(路径描述信息)。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->关闭浏览器	**	42
	{
/*name*/	_WT("强制关闭"),
/*explain*/	_WT("是否用强制措施来关闭浏览器。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->设置焦点	**	43
	{
/*name*/	_WT("是否拥有焦点"),
/*explain*/	_WT("是否拥有焦点。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->置缩放比例	**	44
	{
/*name*/	_WT("比例"),
/*explain*/	_WT("页面缩放比例,小于0时将缩小页面,大于0时将放大页面。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_DOUBLE,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->置缩放比例	**	45
	{
/*name*/	_WT("URL"),
/*explain*/	_WT("需要下载的文件地址。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->打开开发者工具	**	46
	{
/*name*/	_WT("窗口信息"),
/*explain*/	_WT("开发者工具的窗口信息"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(7,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->打开开发者工具	**	47
	{
/*name*/	_WT("元素位置X"),
/*explain*/	_WT("提供一个坐标交由开发者工具以定位到该元素所在的dom。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->打开开发者工具	**	48
	{
/*name*/	_WT("元素位置Y"),
/*explain*/	_WT("提供一个坐标交由开发者工具以定位到该元素所在的dom。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->禁止更改光标	**	49
	{
/*name*/	_WT("禁止"),
/*explain*/	_WT("是否禁止更改鼠标光标。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->通知浏览器可见状态被更改	**	50
	{
/*name*/	_WT("是否隐藏"),
/*explain*/	_WT("是否隐藏。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->置离屏渲染刷新频率	**	51
	{
/*name*/	_WT("刷新频率"),
/*explain*/	_WT("刷新频率。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星窗口->置为前台	**	52
	{
/*name*/	_WT("欲设置到前台的浏览器对象"),
/*explain*/	_WT("可以为窗口句柄(非领航员句柄),水星浏览器,水星窗口等对象。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	_SDT_ALL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星框架->取源码	**	53
	{
/*name*/	_WT("异步执行"),
/*explain*/	_WT("是否以异步模式执行,执行结果将会发送至\"异步调用结果\"事件中,默认为假以同步模式执行,"
				"当在事件中调用时则必须设置为真时,才能获得执行结果。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星框架->取源码	**	54
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的浏览器对象,如果为空,则不传递该参数。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(10,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星框架->取源码	**	55
	{
/*name*/	_WT("自定义参数1"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的自定义参数信息,如果为空,则不传递该参数。"
				"只能为基本数据类型(逻辑型,小数型,短整数型,整数型,长整数型,双精度小数型,文本型,字节集型,子程序指针),"
				"以及本支持库中的数据类型(不包含:水星领航员)。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星框架->取源码	**	56
	{
/*name*/	_WT("自定义参数2"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的自定义参数信息,如果为空,则不传递该参数。"
				"只能为基本数据类型(逻辑型,小数型,短整数型,整数型,长整数型,双精度小数型,文本型,字节集型,子程序指针),"
				"以及本支持库中的数据类型(不包含:水星领航员)。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星框架->取源码	**	57
	{
/*name*/	_WT("自定义参数3"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的自定义参数信息,如果为空,则不传递该参数。"
				"只能为基本数据类型(逻辑型,小数型,短整数型,整数型,长整数型,双精度小数型,文本型,字节集型,子程序指针),"
				"以及本支持库中的数据类型(不包含:水星领航员)。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BIN,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星框架->导航	**	58
	{
/*name*/	_WT("地址"),
/*explain*/	_WT("URL。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星框架->载入HTML	**	59
	{
/*name*/	_WT("欲载入的HTML代码"),
/*explain*/	_WT("欲载入的HTML代码。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星框架->载入HTML	**	60
	{
/*name*/	_WT("关联的URL"),
/*explain*/	_WT("代表这份代码的URL。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星框架->执行脚本	**	61
	{
/*name*/	_WT("欲执行的脚本代码"),
/*explain*/	_WT("欲执行的脚本代码。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星框架->执行脚本	**	62
	{
/*name*/	_WT("关联的URL"),
/*explain*/	_WT("当脚本出现错误时用于表示该代码的虚拟URL"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星框架->执行脚本	**	63
	{
/*name*/	_WT("关联的行号"),
/*explain*/	_WT("当脚本出现错误时用于表示该代码的虚拟行号"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星文档->执行表达式	**	64
	{
/*name*/	_WT("表达式"),
/*explain*/	_WT("表达式代码。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星文档->执行表达式	**	65
	{
/*name*/	_WT("关联的URL"),
/*explain*/	_WT("当脚本出现错误时用于表示该代码的虚拟URL"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星文档->执行表达式	**	66
	{
/*name*/	_WT("关联的行号"),
/*explain*/	_WT("当脚本出现错误时用于表示该代码的虚拟行号"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星文档->执行表达式	**	67
	{
/*name*/	_WT("错误信息"),
/*explain*/	_WT("当脚本出现错误时的异常信息。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR,
	},
//****** 水星文档->执行表达式	**	68
	{
/*name*/	_WT("异步执行"),
/*explain*/	_WT("是否以异步模式执行,执行结果将会发送至\"异步调用结果\"事件中,默认为假以同步模式执行,"
				"当在事件中调用时则必须设置为真时,才能获得执行结果。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星文档->执行表达式	**	69
	{
/*name*/	_WT("浏览器"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的浏览器对象,如果为空,则不传递该参数。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(10,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星文档->执行表达式	**	70
	{
/*name*/	_WT("自定义参数1"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的自定义参数信息,如果为空,则不传递该参数。"
				"只能为基本数据类型(逻辑型,小数型,短整数型,整数型,长整数型,双精度小数型,文本型,字节集型,子程序指针),"
				"以及本支持库中的数据类型(不包含:水星领航员)。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星文档->执行表达式	**	71
	{
/*name*/	_WT("自定义参数2"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的自定义参数信息,如果为空,则不传递该参数。"
				"只能为基本数据类型(逻辑型,小数型,短整数型,整数型,长整数型,双精度小数型,文本型,字节集型,子程序指针),"
				"以及本支持库中的数据类型(不包含:水星领航员)。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** 水星文档->执行表达式	**	72
	{
/*name*/	_WT("自定义参数3"),
/*explain*/	_WT("异步模式下传到到异步接收事件中的自定义参数信息,如果为空,则不传递该参数。"
				"只能为基本数据类型(逻辑型,小数型,短整数型,整数型,长整数型,双精度小数型,文本型,字节集型,子程序指针),"
				"以及本支持库中的数据类型(不包含:水星领航员)。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BIN,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->GetURLCookie	**	73
	{
/*name*/	_WT("url"),
/*explain*/	_WT("需要检索的URL地址。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->GetURLCookie	**	74
	{
/*name*/	_WT("includeHttpOnly"),
/*explain*/	_WT("是否包含带有httponly标记的cookie。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	75
	{
/*name*/	_WT("url"),
/*explain*/	_WT("给定一个有效的URL地址,cookie将关联在该URL地址下。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookie	**	76
	{
/*name*/	_WT("name"),
/*explain*/	_WT("name"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookie	**	77
	{
/*name*/	_WT("value"),
/*explain*/	_WT("value"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookie	**	78
	{
/*name*/	_WT("secure"),
/*explain*/	_WT("secure"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	79
	{
/*name*/	_WT("httponly"),
/*explain*/	_WT("httponly"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	80
	{
/*name*/	_WT("has_expires"),
/*explain*/	_WT("has_expires"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	81
	{
/*name*/	_WT("expires"),
/*explain*/	_WT("expires"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(18 ,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->DeleteCookie	**	82
	{
/*name*/	_WT("url"),
/*explain*/	_WT("给定一个有效的URL地址,如果为空将会删除管理器中所有的cookie。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->DeleteCookie	**	83
	{
/*name*/	_WT("name"),
/*explain*/	_WT("cookie名称,如果为空将会删除url路径下的所有cookie。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->GetCookieMerge	**	84
	{
/*name*/	_WT("url"),
/*explain*/	_WT("给定一个有效的URL地址。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookieMerge	**	85
	{
/*name*/	_WT("url"),
/*explain*/	_WT("给定一个有效的URL地址。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookieMerge	**	86
	{
/*name*/	_WT("cookies"),
/*explain*/	_WT("以\"name=value; \"形式合并的cookie子集字符串。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->查找	**	87
	{
/*name*/	_WT("欲查找的键名"),
/*explain*/	_WT("关联着键值数据的名称索引"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->查找	**	88
	{
/*name*/	_WT("接收成员指针"),
/*explain*/	_WT("用于接收匹配到的首个成员指针。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_VAR,
	},
//****** 文本字典增强版->取下个成员	**	89
	{
/*name*/	_WT("成员指针"),
/*explain*/	_WT("用于进行迭代的成员位置指针,首个位置指针可使用函数\"取首个成员\"获得"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 文本字典增强版->插入	**	90
	{
/*name*/	_WT("用作替换的键值"),
/*explain*/	_WT("键值数据"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** V8Value->取值	**	91
	{
/*name*/	_WT("索引"),
/*explain*/	_WT("索引,从0开始。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** V8Value->置值	**	92
	{
/*name*/	_WT("值"),
/*explain*/	_WT("欲置入的值,可以为: #逻辑型、#整数型、#小数型、#文本型"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	_SDT_ALL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星领航员->注册脚本类	**	93
	{
/*name*/	_WT("类名"),
/*explain*/	_WT("欲注册的类名"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星领航员->注册脚本变量	**	94
	{
/*name*/	_WT("类"),
/*explain*/	_WT("欲注册变量的类"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(21,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星领航员->注册脚本变量	**	95
	{
/*name*/	_WT("变量名"),
/*explain*/	_WT("欲注册的变量名"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星领航员->注册脚本变量	**	96
	{
/*name*/	_WT("类"),
/*explain*/	_WT("欲注册函数的类"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(21,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 水星领航员->注册脚本变量	**	97
	{
/*name*/	_WT("函数名"),
/*explain*/	_WT("欲注册的函数名"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->提交文件	**	98
	{
/*name*/	_WT("文件名"),
/*explain*/	_WT("欲提交的文件名"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->提交字节集	**	99
	{
/*name*/	_WT("数据"),
/*explain*/	_WT("欲提交的字节集数据。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BIN,
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->删除提交项	**	100
	{
/*name*/	_WT("欲删除的提交项"),
/*explain*/	_WT("欲删除的提交项。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(22,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->加入提交项	**	101
	{
/*name*/	_WT("欲加入的提交项"),
/*explain*/	_WT("欲加入的提交项。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(22,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetURL	**	102
	{
/*name*/	_WT("Url"),
/*explain*/	_WT("Url"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetMethod	**	103
	{
/*name*/	_WT("method"),
/*explain*/	_WT("method"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetReferrer	**	104
	{
/*name*/	_WT("Url"),
/*explain*/	_WT("Url"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetReferrer	**	105
	{
/*name*/	_WT("policy"),
/*explain*/	_WT("policy"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetPostData	**	106
	{
/*name*/	_WT("预设置的HTTP正文"),
/*explain*/	_WT("postdata"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(23,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetHeaderMap	**	107
	{
/*name*/	_WT("预设置的HTTP标头"),
/*explain*/	_WT("header"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(5,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetFlag	**	108
	{
/*name*/	_WT("标志位"),
/*explain*/	_WT("flag"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetFirstPartyForCookies	**	109
	{
/*name*/	_WT("url"),
/*explain*/	_WT("url"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Response->SetStatus	**	110
	{
/*name*/	_WT("HTTP状态码"),
/*explain*/	_WT("statusCode"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Response->SetStatusText	**	111
	{
/*name*/	_WT("HTTP状态文本"),
/*explain*/	_WT("statusText"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Response->SetMimeType	**	112
	{
/*name*/	_WT("MIME类型"),
/*explain*/	_WT("mimeType"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** JSDialogCallback->确认	**	113
	{
/*name*/	_WT("OK"),
/*explain*/	_WT("设置该对话框是否以OK按钮的状态结束。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** JSDialogCallback->确认	**	114
	{
/*name*/	_WT("输入文本"),
/*explain*/	_WT("当对话框类型为: prompt,时为其提供输入文本。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** FileDialogCallback->确认	**	115
	{
/*name*/	_WT("过滤器索引"),
/*explain*/	_WT(" |过滤器索引| 应该是从传递给CefDialogHandler::OnFileDialog的accept filters数组中选择的值的从0开始的索引。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** FileDialogCallback->确认	**	116
	{
/*name*/	_WT("接收的文件名列表"),
/*explain*/	_WT("| 接收的文件名列表| 应该是单个值或值列表，具体取决于对话框模式。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(2,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送按键事件	**	117
	{
/*name*/	_WT("按键消息"),
/*explain*/	_WT("欲发送的按键消息"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(36,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标点击事件	**	118
	{
/*name*/	_WT("鼠标消息"),
/*explain*/	_WT("欲发送的鼠标消息"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(37,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标点击事件	**	119
	{
/*name*/	_WT("按键类型"),
/*explain*/	_WT("欲发送的按键类型,参考常量集合: #MOUSE_BUTTON_TYPE.xxx"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标点击事件	**	120
	{
/*name*/	_WT("是否弹起"),
/*explain*/	_WT("是否弹起鼠标按键"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标点击事件	**	121
	{
/*name*/	_WT("点击次数"),
/*explain*/	_WT("点击次数"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标移动事件	**	122
	{
/*name*/	_WT("鼠标消息"),
/*explain*/	_WT("欲发送的鼠标消息"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(37,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标移动事件	**	123
	{
/*name*/	_WT("是否离开"),
/*explain*/	_WT("是否离开"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标滚轮事件	**	124
	{
/*name*/	_WT("鼠标消息"),
/*explain*/	_WT("欲发送的鼠标消息"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(37,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标滚轮事件	**	125
	{
/*name*/	_WT("X增量"),
/*explain*/	_WT("横向位置的滚动距离"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** 浏览器后台->发送鼠标滚轮事件	**	126
	{
/*name*/	_WT("Y增量"),
/*explain*/	_WT("纵向位置的滚动距离"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** BeforeDownloadCallback->确认	**	127
	{
/*name*/	_WT("存放位置"),
/*explain*/	_WT("设置目标下载文件存放于磁盘上的位置。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** BeforeDownloadCallback->确认	**	128
	{
/*name*/	_WT("弹出对话框"),
/*explain*/	_WT("是否弹出文件对话框获取存放位置。"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** Frame->LoadRequest	**	129
	{
/*name*/	_WT("request"),
/*explain*/	_WT("欲载入的request"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(24,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** AuthCallback->确认	**	130
	{
/*name*/	_WT("用户名"),
/*explain*/	_WT("用作浏览器登录凭证"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** AuthCallback->确认	**	131
	{
/*name*/	_WT("密码"),
/*explain*/	_WT("用作浏览器登录凭证"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
};

#endif
#endif
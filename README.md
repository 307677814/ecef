# 易语言水星浏览器支持库

​     水星浏览器支持库(Aquariuscef)是一款基于  [CEF(Chromium Embedded Framework)](https://bitbucket.org/chromiumembedded/cef) 框架而实现的简易版易语言Chromium浏览器支持库。



## 下载

[Github](https://github.com/kirino17/ecef)



## 使用说明

### 安装方法:

* 将文件包内的"aquarius.fne"文件复制到易语言安装目录下的"lib"文件夹, "aquarius_static.lib"文件复制到易语言安装目录下的"static_lib"文件夹, 启动易语言从工具菜单, 选择"支持库配置"选项打开易语言支持库安装窗口,并在支持库列表中找到"水星浏览器支持库"勾选安装。

* 新建易语言窗口程序,并在组件箱中找到"水星领航员"组件,并将其拖入到窗口设计区中,选择组件打开属性设置窗口找到参数"适配环境"选项,并将其值设置为水星浏览器适配环境包安装路径(如: c:\Aquariuscef for CEF3.2623.1401 Adapter) , 添加以下代码, 创建你的第一个水星浏览器吧！

  ```
  .版本 2
  .支持库 aquarius
  
  .程序集 窗口程序集_启动窗口
  
  .子程序 __启动窗口_创建完毕
  
  水星领航员1.初始化 ()
  
  
  .子程序 _水星领航员1_初始化完毕
  
  水星领航员1.创建浏览器 (“http://www.baidu.com”, )
  
  ```


## 更新日志

### v1.01 2018-11-18 [P1]

* 1.取消水星领航员组件的部分属性参数,并新增以下属性:

  * **适配环境** , 设置适用于水星浏览器的CEF运行环境包路径。
  * **运行脚本** , 设置是否允许浏览器加载并运行脚本资源。
  * **加载插件** , 设置是否允许浏览器加载扩展插件(ppapi 插件)。
  * **跨域访问** , 设置是否开启浏览器跨域访问设置,默认是关闭的。
  * **无图模式** , 设置浏览器为无图浏览模式。
  * **WEBGL** , 设置是否允许浏览器开启WebGL。

* 2.修复当网页中出现未被GBK编码定义的字符调用取网页文本/源码, 执行脚本等函数以及部分事件时出现崩溃的问题。

* 3.取消HyperText数据类型。

* 4.更改了部分数据类型和函数的定义名称,具体如下: 

  | 原类型名称              | 新类型名称       |
  | ----------------------- | ---------------- |
  | StringArray             | 字符串列表       |
  | Int64Array              | 长整数列表       |
  | StringMap               | 键值表           |
  | StringMultimap          | 增强键值表       |
  | 浏览器                  | 水星超文本框     |
  | 浏览器后台              | 水星超文本窗口   |
  | 超文本框架              | 水星超文本框架   |
  | 异步调度标记            | 异步调用类型常量 |
  | WINDOW_OPEN_DISPOSITION | 窗口打开方式常量 |
  | CookieManager           | COOKIE管理器     |
  | V8Value                 | 局部存储表       |
  | V8Accessor              | V8类             |
  | PostDataElement         | HTTP提交字段     |
  | PostData                | HTTP提交正文     |
  | Request                 | HTTP提交         |
  | Response                | HTTP响应         |
  | URLFLAG                 | HTTP提交常量     |
  | URLQUERSTSTATUS         | 资源加载结果常量 |
  | RESOURCETYPE            | 资源类型常量     |
  | KEYEVENT                | 按键类型常量     |
  | MOUSE_BUTTON_TYPE       | 鼠标类型常量     |
  | JSDIALOG                | 脚本对话框常量   |
  | JSDialogCallback        | 脚本对话框       |
  | FileDialogCallback      | 文件对话框       |
  | FILEDIALOG              | 文件对话框常量   |
  | EVENTFLAG               | 功能键状态常量   |
  | DownloadItem            | 下载目标         |
  | BeforeDownloadCallback  | 下载选项         |
  | DownloadItemCallback    | 下载管理器       |

* 5.**水星超文本框架**类型新增 *执行脚本_求值* 方法,用于获得脚本的执行返回结果。

* 6.修复**HTTP提交**类型 *取字段数*  方法返回逻辑值的问题。

* 7.修复**水星超文本框架**类型执行到错误脚本时, 可能会发生崩溃的问题。 

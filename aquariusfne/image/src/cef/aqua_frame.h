#ifndef AQUA_FRAME_H_
#define AQUA_FRAME_H_
#include "utils\aqua_utils.h"

namespace AquaCef {
	
	/**
	  *	用于在浏览器窗口中表示框架的类。 在使用时
	  * 浏览器进程可能会在任何线程上调用此类的方法，除非
	  * 否则在评论中指出。 在渲染过程中使用时
	  * 这个类的方法只能在主线程中调用。
	  * * * * * * * * * * * * * * * * * * * */

	///
	//	如果此对象当前附加到有效框架，则为真。
	///
	AQUAENTRYFULL(BOOL, Frame, IsValid)(LPVOID object);

	///
	//	在此框架中执行撤销。
	///
	AQUAENTRYFULL(void, Frame, Undo)(LPVOID object);

	///
	//	在此框架中执行重做。
	///
	AQUAENTRYFULL(void, Frame, Redo)(LPVOID object);

	///
	//	在此框架中执行剪切。
	///
	AQUAENTRYFULL(void, Frame, Cut)(LPVOID object);

	///
	//	在这个框架中执行复制。
	///
	AQUAENTRYFULL(void, Frame, Copy)(LPVOID object);

	///
	//	在这个框架中执行粘贴。
	///
	AQUAENTRYFULL(void, Frame, Paste)(LPVOID object);

	///
	//	在此框中执行删除。
	///
	AQUAENTRYFULL(void, Frame, Delete)(LPVOID object);

	///
	//	执行在此框中选择全部。
	///
	AQUAENTRYFULL(void, Frame, SelectAll)(LPVOID object);

	///
	//	以发送到指定访问者的字符串检索此框架的HTML源代码。
	///
	AQUAENTRYFULL(BOOL, Frame, GetSourceA)(LPVOID object, LPVOID callback,LPVOID params,BOOL async);

	///
	//	以发送到指定访问者的字符串检索此框架的HTML文本。
	///
	AQUAENTRYFULL(BOOL, Frame, GetTextA)(LPVOID object, LPVOID callback, LPVOID params, BOOL async);

	///
	//	加载指定的| url |。
	///
	AQUAENTRYFULL(BOOL, Frame, LoadURLA)(LPVOID object, LPCSTR url);

	///
	//	加载| string_val |的内容 使用指定的虚拟| url |。|网址|
	//	应该有一个标准的方案（例如，http方案）或类似的行为
	//	链接点击次数和网络安全限制可能无法按预期运行。
	///
	AQUAENTRYFULL(BOOL, Frame, LoadStringA)(LPVOID object, LPCSTR html,LPCSTR url);

	AQUAENTRYFULL(void, Frame, LoadRequest)(LPVOID object,LPVOID request);

	///
	//	在此框架中执行一串JavaScript代码。 | script_url |
	//	参数是可以找到有问题的脚本的URL，如果有的话。
	//	渲染器可能会请求此URL以向开发人员显示
	//	错误。 | start_line | 参数是用于出错的基线号
	//	报告。
	///
	AQUAENTRYFULL(BOOL, Frame, ExecuteJavaScriptA)(LPVOID object,LPCSTR code,LPCSTR url,int line);

	///
	//	如果这是主（顶级）框架，则返回true。
	///
	AQUAENTRYFULL(BOOL, Frame, IsMain)(LPVOID object);

	///
	//	如果这是聚焦框架，则返回true。
	///
	AQUAENTRYFULL(BOOL, Frame, IsFocused)(LPVOID object);

	///
	//	返回此帧的名称。 如果框架有一个分配的名称（对于
	//	例如，通过iframe“name”属性设置），那么该值将是
	//	回。 否则，将根据该框架构造唯一的名称
	//	父层次结构。 主（顶级）框架将始终有一个空的名称
	//	值。
	///
	AQUAENTRYFULL(int, Frame, GetNameA)(LPVOID object, LPSTR buf, int len);

	///
	//	返回此帧的全局唯一标识符，如果底层帧尚不存在，则返回<0。
	///
	AQUAENTRYFULL(__int64, Frame, GetIdentifier)(LPVOID object);

	///
	//	返回此帧的父元素或NULL，如果这是主（顶级）帧。
	///
	AQUAENTRYFULL(LPVOID, Frame, GetParent)(LPVOID object);

	///
	//	返回当前在此框架中加载的URL。
	///
	AQUAENTRYFULL(int, Frame, GetURLA)(LPVOID object, LPSTR buf, int len);

	///
	//	返回此帧所属的浏览器。
	///
	AQUAENTRYFULL(LPVOID, Frame, GetBrowser)(LPVOID object);

	///
	//	执行表达式
	///
	AQUAENTRYFULL(void,Frame,EvalA)(LPVOID object,LPCSTR code,LPCSTR url,int line,LPVOID callback,LPVOID params,BOOL async);
}

#endif
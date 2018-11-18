#ifndef KEYEVENT_H_
#define KEYEVENT_H_
#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtKeyEventElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("类型"),
        /*m_szEgName*/          _T("type"),
        /*m_szExplain*/         _T("键盘事件的类型,参考常量集合: #KEYEVENT.xxx"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("标志位"),
        /*m_szEgName*/          _T("modifiers"),
        /*m_szExplain*/         _T("描述任何按下的修改键的位标志。 有关值，请参阅常量集合: #EVENTFLAG.xxx 。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("键代码"),
        /*m_szEgName*/          _T("windows_key_code"),
        /*m_szExplain*/         _T("键事件的Windows键代码。DOM规范使用此值。有时它直接来自事件（即在Windows上），有时它是使用映射函数确定"
									"的。有关值列表,请参阅WebCore/platform/chromium/KeyboardCodes.h"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("实际键代码"),
        /*m_szEgName*/          _T("native_key_code"),
        /*m_szExplain*/         _T("由平台生成的实际键代码。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("是否为系统键"),
        /*m_szEgName*/          _T("is_system_key"),
        /*m_szExplain*/         _T("指示事件是否被视为“系统键”事件有关详细信息，请参阅http://msdn.microsoft.com/en-us/library/ms646286(VS.85).aspx）。"
									"此值在非非永远是false -Windows平台。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("字符码"),
        /*m_szEgName*/          _T("character"),
        /*m_szExplain*/         _T("击键产生的字符。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("原始字符码"),
        /*m_szEgName*/          _T("unmodified_character"),
        /*m_szExplain*/         _T("与|character|相同 但不会被任何并发保持的修饰符修改（除了shift）。 这对于计算快捷键很有用。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("是否位于焦点元素"),
        /*m_szEgName*/          _T("focus_on_editable_field"),
        /*m_szExplain*/         _T("如果焦点当前位于页面上的可编辑字段，则为True。 这对于确定是否应截取标准键事件很有用。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtMouseElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("x"),
        /*m_szEgName*/          _T("x"),
        /*m_szExplain*/         _T("相对于视图左侧的X坐标。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("y"),
        /*m_szEgName*/          _T("y"),
        /*m_szExplain*/         _T("相对于视图左侧的Y坐标。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("标志位"),
        /*m_szEgName*/          _T("modifiers"),
        /*m_szExplain*/         _T("描述任何按下的修改键的位标志。 有关值，请参阅常量集合: #EVENTFLAG.xxx 。"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
};

#endif

#endif
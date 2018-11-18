#include "StdAfx.h"
#include <windows.h>
#include "lib2.h"
#include "lang.h"
#include "datatype.h"
#include "cmdinfo.h"
#include "func.h"


/////////////////////////////////////////////////////////////////////////////

INT g_nLastNotifyResult;
PFN_NOTIFY_SYS g_fnAquaNotifySys = NULL;

INT WINAPI AquaNotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	if (g_fnAquaNotifySys != NULL)
		return g_nLastNotifyResult = g_fnAquaNotifySys (nMsg, dwParam1, dwParam2);
	else
		return g_nLastNotifyResult = 0;
}

/////////////////////////////////////////////////////////////////////////////

INT WINAPI ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	INT nRet = NR_OK;
	switch (nMsg)
	{
	case NL_SYS_NOTIFY_FUNCTION:
		g_fnAquaNotifySys = (PFN_NOTIFY_SYS)dwParam1;
		break;
	default:
		nRet = NR_ERR;
		break;
	}

	return nRet;
}

EXTERN_C INT WINAPI aquarius_ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if(nMsg == NL_GET_CMD_FUNC_NAMES)
		return (INT) g_CmdNames;
	else if(nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME)
		return (INT) "aquarius_ProcessNotifyLib";
	else if(nMsg == NL_GET_DEPENDENT_LIBS)
		return NULL;
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
}

#ifndef __E_STATIC_LIB
/////////////////////////////////////////////////////////////////////////////

//////////// 库定义开始
static LIB_INFO s_LibInfo =
{
/*Lib Format Ver*/		LIB_FORMAT_VER,		// 保留未用。

// 本支持库的GUID串：
// guid: {5014D8FA-6DCA-40b6-8FA6-26D8183666EB}
#define		LI_LIB_GUID_STR	"7153EF3B37294f4993DDCE8EB90617FD"
/*guid str*/			_T (LI_LIB_GUID_STR),

/*m_nMajorVersion*/		1,
/*m_nMinorVersion*/		0,

//!!!	注意：凡是增删或更改了命令、窗口组件、数据类型、帮助信息等，只要对帮助
//!!! 文件生成会产生影响，都必须升级版本号，而不能只修改BuildNumber。
//!!!   改动后尽量升级版本号!!!
/*m_nBuildNumber*/		51,	// 1: 2.5;  2: 2.5补遗版; 3: 3.0版;  50: 3.39; 51: 4.11
		// 构建版本号，无需对此版本号作任何处理。
		//   本版本号仅用作区分相同正式版本号的库（譬如仅仅修改了几个 BUG）。
		// 任何公布过给用户使用的版本其此版本号都应该不一样。
		//   赋值时应该顺序递增。

/*m_nRqSysMajorVer*/		3,
/*m_nRqSysMinorVer*/		0,
/*m_nRqSysKrnlLibMajorVer*/	3,
/*m_nRqSysKrnlLibMinorVer*/	0,

/*name*/				_T ("水星浏览器支持库"),
/*lang*/				__GBK_LANG_VER,
/*explain*/				_WT("本支持库实现了对水星浏览器(Aquariuscef)框架的支持"),
/*dwState*/				NULL,

/*szAuthor*/	_WT("黑猫"),
/*szZipCode*/	_WT("518108"),
/*szAddress*/	_WT("广东省深圳市"),
/*szPhoto*/		_WT("00000000000"),
/*szFax*/		_WT("00000000000"),
/*szEmail*/		_WT("kirino17@hotmail.com"),
/*szHomePage*/	_WT("http://www.ps-works.cc"),
/*szOther*/		_WT("祝您一帆风顺，心想事成！"),

/*type count*/			sizeof (s_DataType) / sizeof (s_DataType[0]),
/*PLIB_DATA_TYPE_INFO*/	s_DataType,

/*CategoryCount*/ 1,	// 加了类别需加此值。
/*category*/_WT("0000适配器\0"	// 类别说明表每项为一字符串,前四位数字表示图象索引号(从1开始,0无).
				"0000xxxx\0"
				"\0"),
/*CmdCount*/				sizeof (s_CmdInfo) / sizeof (s_CmdInfo [0]),
/*BeginCmd*/				s_CmdInfo,
/*m_pCmdsFunc*/             s_RunFunc,
/*pfnRunAddInFn*/			NULL,
/*szzAddInFnInfo*/			NULL,

/*pfnNotify*/				aquarius_ProcessNotifyLib,

/*pfnRunSuperTemplate*/		NULL,
/*szzSuperTemplateInfo*/	NULL,

/*nLibConstCount*/			0,//sizeof (s_ConstInfo) / sizeof (s_ConstInfo [0]),
/*pLibConst*/				NULL,//s_ConstInfo,

/*szzDependFiles*/			NULL,
};

PLIB_INFO WINAPI GetNewInf ()
{
	return &s_LibInfo;
}

#endif

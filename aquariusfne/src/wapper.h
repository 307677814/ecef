#ifndef WAPPER_H_
#define WAPPER_H_

#include <windows.h>

#define AQUAINLINE
#define PPTR	*pArgInf->m_ppCompoundData

#include "utils\aqua_utils.h"
#include "cef\aqua_v8.h"
#include "cef\aqua_window.h"
#include "cef\aqua_types.h"
#include "launch\aqua_launch_main.h"
#include "cef\aqua_command_line.h"
#include "cef\aqua_browser.h"
#include "cef\aqua_browser_host.h"
#include "cef\aqua_frame.h"
#include "cef\aqua_cookie.h"
#include "cef\aqua_postdata.h"
#include "cef\aqua_request.h"
#include "cef\aqua_response.h"
#include "cef\aqua_download.h"
#include "cef\aqua_callback.h"
#include "eventsfunc.h"
#include "lib2.h"
#include <string>
#include <SSTREAM>

using namespace AquaUtils;
using namespace AquaWindow;
using namespace AquaTypes;
using namespace AquaTypes::BrowserSettings;
using namespace AquaTypes::RequestContextSettings;
using namespace AquaTypes::PopupFeatures;
using namespace AquaLaunch;
using namespace AquaHandler;
using namespace AquaCef;

extern PFN_NOTIFY_SYS g_fnAquaNotifySys;

#define AQUA_ASSERT()	if(AquaAddRef == NULL) return

namespace wapper {

	void DoAllowFunctional(HMODULE lib){
*(DWORD*)&AquaAddRef = (DWORD)::GetProcAddress(lib,"AquaAddRef");
*(DWORD*)&AquaRelease = (DWORD)::GetProcAddress(lib,"AquaRelease");
*(DWORD*)&AquaHasOenRef = (DWORD)::GetProcAddress(lib,"AquaHasOenRef");
*(DWORD*)&AquaGetAdapter = (DWORD)::GetProcAddress(lib,"AquaGetAdapter");
*(DWORD*)&AquaQuitProcess = (DWORD)::GetProcAddress(lib,"AquaQuitProcess");
*(DWORD*)&AquaStrVectorAlloc = (DWORD)::GetProcAddress(lib,"AquaStrVectorAlloc");
*(DWORD*)&AquaStrVectorCopy = (DWORD)::GetProcAddress(lib,"AquaStrVectorCopy");
*(DWORD*)&AquaStrVectorAppendA = (DWORD)::GetProcAddress(lib,"AquaStrVectorAppendA");
*(DWORD*)&AquaStrVectorAppendW = (DWORD)::GetProcAddress(lib,"AquaStrVectorAppendW");
*(DWORD*)&AquaStrVectorReplaceA = (DWORD)::GetProcAddress(lib,"AquaStrVectorReplaceA");
*(DWORD*)&AquaStrVectorReplaceW = (DWORD)::GetProcAddress(lib,"AquaStrVectorReplaceW");
*(DWORD*)&AquaStrVectorRemove = (DWORD)::GetProcAddress(lib,"AquaStrVectorRemove");
*(DWORD*)&AquaStrVectorClear = (DWORD)::GetProcAddress(lib,"AquaStrVectorClear");
*(DWORD*)&AquaStrVectorGetBound = (DWORD)::GetProcAddress(lib,"AquaStrVectorGetBound");
*(DWORD*)&AquaStrVectorGetElementA = (DWORD)::GetProcAddress(lib,"AquaStrVectorGetElementA");
*(DWORD*)&AquaStrVectorGetElementW = (DWORD)::GetProcAddress(lib,"AquaStrVectorGetElementW");
*(DWORD*)&AquaStrVectorDestory = (DWORD)::GetProcAddress(lib,"AquaStrVectorDestory");
*(DWORD*)&AquaStrDictAlloc = (DWORD)::GetProcAddress(lib,"AquaStrDictAlloc");
*(DWORD*)&AquaStrDictCopy = (DWORD)::GetProcAddress(lib,"AquaStrDictCopy");
*(DWORD*)&AquaStrDictInsertA = (DWORD)::GetProcAddress(lib,"AquaStrDictInsertA");
*(DWORD*)&AquaStrDictInsertW = (DWORD)::GetProcAddress(lib,"AquaStrDictInsertW");
*(DWORD*)&AquaStrDictFindA = (DWORD)::GetProcAddress(lib,"AquaStrDictFindA");
*(DWORD*)&AquaStrDictFindW = (DWORD)::GetProcAddress(lib,"AquaStrDictFindW");
*(DWORD*)&AquaStrDictGetBound = (DWORD)::GetProcAddress(lib,"AquaStrDictGetBound");
*(DWORD*)&AquaStrDictGetFirst = (DWORD)::GetProcAddress(lib,"AquaStrDictGetFirst");
*(DWORD*)&AquaStrDictGetNext = (DWORD)::GetProcAddress(lib,"AquaStrDictGetNext");
*(DWORD*)&AquaStrDictErase = (DWORD)::GetProcAddress(lib,"AquaStrDictErase");
*(DWORD*)&AquaStrDictGetKeyA = (DWORD)::GetProcAddress(lib,"AquaStrDictGetKeyA");
*(DWORD*)&AquaStrDictGetKeyW = (DWORD)::GetProcAddress(lib,"AquaStrDictGetKeyW");
*(DWORD*)&AquaStrDictGetValueA = (DWORD)::GetProcAddress(lib,"AquaStrDictGetValueA");
*(DWORD*)&AquaStrDictSetValueA = (DWORD)::GetProcAddress(lib,"AquaStrDictSetValueA");
*(DWORD*)&AquaStrDictGetValueW = (DWORD)::GetProcAddress(lib,"AquaStrDictGetValueW");
*(DWORD*)&AquaStrDictRemoveA = (DWORD)::GetProcAddress(lib,"AquaStrDictRemoveA");
*(DWORD*)&AquaStrDictRemoveW = (DWORD)::GetProcAddress(lib,"AquaStrDictRemoveW");
*(DWORD*)&AquaStrDictClear = (DWORD)::GetProcAddress(lib,"AquaStrDictClear");
*(DWORD*)&AquaStrDictAtA = (DWORD)::GetProcAddress(lib,"AquaStrDictAtA");
*(DWORD*)&AquaStrDictAtW = (DWORD)::GetProcAddress(lib,"AquaStrDictAtW");
*(DWORD*)&AquaStrDictDestory = (DWORD)::GetProcAddress(lib,"AquaStrDictDestory");
*(DWORD*)&AquaStrDictExAlloc = (DWORD)::GetProcAddress(lib,"AquaStrDictExAlloc");
*(DWORD*)&AquaStrDictExCopy = (DWORD)::GetProcAddress(lib,"AquaStrDictExCopy");
*(DWORD*)&AquaStrDictExInsertA = (DWORD)::GetProcAddress(lib,"AquaStrDictExInsertA");
*(DWORD*)&AquaStrDictExInsertW = (DWORD)::GetProcAddress(lib,"AquaStrDictExInsertW");
*(DWORD*)&AquaStrDictExFindA = (DWORD)::GetProcAddress(lib,"AquaStrDictExFindA");
*(DWORD*)&AquaStrDictExFindW = (DWORD)::GetProcAddress(lib,"AquaStrDictExFindW");
*(DWORD*)&AquaStrDictExReplaceA = (DWORD)::GetProcAddress(lib,"AquaStrDictExReplaceA");
*(DWORD*)&AquaStrDictExReplaceW = (DWORD)::GetProcAddress(lib,"AquaStrDictExReplaceW");
*(DWORD*)&AquaStrDictExGetBound = (DWORD)::GetProcAddress(lib,"AquaStrDictExGetBound");
*(DWORD*)&AquaStrDictExGetFirst = (DWORD)::GetProcAddress(lib,"AquaStrDictExGetFirst");
*(DWORD*)&AquaStrDictExGetNext = (DWORD)::GetProcAddress(lib,"AquaStrDictExGetNext");
*(DWORD*)&AquaStrDictExErase = (DWORD)::GetProcAddress(lib,"AquaStrDictExErase");
*(DWORD*)&AquaStrDictExGetKeyA = (DWORD)::GetProcAddress(lib,"AquaStrDictExGetKeyA");
*(DWORD*)&AquaStrDictExGetKeyW = (DWORD)::GetProcAddress(lib,"AquaStrDictExGetKeyW");
*(DWORD*)&AquaStrDictExGetValueA = (DWORD)::GetProcAddress(lib,"AquaStrDictExGetValueA");
*(DWORD*)&AquaStrDictExSetValueA = (DWORD)::GetProcAddress(lib,"AquaStrDictExSetValueA");
*(DWORD*)&AquaStrDictExGetValueW = (DWORD)::GetProcAddress(lib,"AquaStrDictExGetValueW");
*(DWORD*)&AquaStrDictExRemoveA = (DWORD)::GetProcAddress(lib,"AquaStrDictExRemoveA");
*(DWORD*)&AquaStrDictExRemoveW = (DWORD)::GetProcAddress(lib,"AquaStrDictExRemoveW");
*(DWORD*)&AquaStrDictExClear = (DWORD)::GetProcAddress(lib,"AquaStrDictExClear");
*(DWORD*)&AquaStrDictExDestory = (DWORD)::GetProcAddress(lib,"AquaStrDictExDestory");
*(DWORD*)&AquaInt64VectorAlloc = (DWORD)::GetProcAddress(lib,"AquaInt64VectorAlloc");
*(DWORD*)&AquaInt64VectorCopy = (DWORD)::GetProcAddress(lib,"AquaInt64VectorCopy");
*(DWORD*)&AquaInt64VectorAppend = (DWORD)::GetProcAddress(lib,"AquaInt64VectorAppend");
*(DWORD*)&AquaInt64VectorReplace = (DWORD)::GetProcAddress(lib,"AquaInt64VectorReplace");
*(DWORD*)&AquaInt64VectorRemove = (DWORD)::GetProcAddress(lib,"AquaInt64VectorRemove");
*(DWORD*)&AquaInt64VectorClear = (DWORD)::GetProcAddress(lib,"AquaInt64VectorClear");
*(DWORD*)&AquaInt64VectorGetBound = (DWORD)::GetProcAddress(lib,"AquaInt64VectorGetBound");
*(DWORD*)&AquaInt64VectorGetElement = (DWORD)::GetProcAddress(lib,"AquaInt64VectorGetElement");
*(DWORD*)&AquaInt64VectorDestory = (DWORD)::GetProcAddress(lib,"AquaInt64VectorDestory");
*(DWORD*)&AquaWindowCreate = (DWORD)::GetProcAddress(lib,"AquaWindowCreate");
*(DWORD*)&AquaWindowCopy = (DWORD)::GetProcAddress(lib,"AquaWindowCopy");
*(DWORD*)&AquaWindowSetAsChild = (DWORD)::GetProcAddress(lib,"AquaWindowSetAsChild");
*(DWORD*)&AquaWindowSetAsPopupA = (DWORD)::GetProcAddress(lib,"AquaWindowSetAsPopupA");
*(DWORD*)&AquaWindowSetAsPopupW = (DWORD)::GetProcAddress(lib,"AquaWindowSetAsPopupW");
*(DWORD*)&AquaWindowSetAsWindowless = (DWORD)::GetProcAddress(lib,"AquaWindowSetAsWindowless");
*(DWORD*)&AquaWindowModifyStyle = (DWORD)::GetProcAddress(lib,"AquaWindowModifyStyle");
*(DWORD*)&AquaWindowDestoryed = (DWORD)::GetProcAddress(lib,"AquaWindowDestoryed");
*(DWORD*)&AquaTypeBsCreate = (DWORD)::GetProcAddress(lib,"AquaTypeBsCreate");
*(DWORD*)&AquaTypeBsCopy = (DWORD)::GetProcAddress(lib,"AquaTypeBsCopy");
*(DWORD*)&AquaTypeBsDestoryed = (DWORD)::GetProcAddress(lib,"AquaTypeBsDestoryed");
*(DWORD*)&AquaTypeBsWindowlessFrameRate = (DWORD)::GetProcAddress(lib,"AquaTypeBsWindowlessFrameRate");
*(DWORD*)&AquaTypeBsStandardFontFamilyA = (DWORD)::GetProcAddress(lib,"AquaTypeBsStandardFontFamilyA");
*(DWORD*)&AquaTypeBsFixedFontFamilyA = (DWORD)::GetProcAddress(lib,"AquaTypeBsFixedFontFamilyA");
*(DWORD*)&AquaTypeBsSerifFontFamilyA = (DWORD)::GetProcAddress(lib,"AquaTypeBsSerifFontFamilyA");
*(DWORD*)&AquaTypeBsSansSerifFontFamilyA = (DWORD)::GetProcAddress(lib,"AquaTypeBsSansSerifFontFamilyA");
*(DWORD*)&AquaTypeBsCursiveFontFamilyA = (DWORD)::GetProcAddress(lib,"AquaTypeBsCursiveFontFamilyA");
*(DWORD*)&AquaTypeBsFantasyFontFamilyA = (DWORD)::GetProcAddress(lib,"AquaTypeBsFantasyFontFamilyA");
*(DWORD*)&AquaTypeBsStandardFontFamilyW = (DWORD)::GetProcAddress(lib,"AquaTypeBsStandardFontFamilyW");
*(DWORD*)&AquaTypeBsFixedFontFamilyW = (DWORD)::GetProcAddress(lib,"AquaTypeBsFixedFontFamilyW");
*(DWORD*)&AquaTypeBsSerifFontFamilyW = (DWORD)::GetProcAddress(lib,"AquaTypeBsSerifFontFamilyW");
*(DWORD*)&AquaTypeBsSansSerifFontFamilyW = (DWORD)::GetProcAddress(lib,"AquaTypeBsSansSerifFontFamilyW");
*(DWORD*)&AquaTypeBsCursiveFontFamilyW = (DWORD)::GetProcAddress(lib,"AquaTypeBsCursiveFontFamilyW");
*(DWORD*)&AquaTypeBsFantasyFontFamilyW = (DWORD)::GetProcAddress(lib,"AquaTypeBsFantasyFontFamilyW");
*(DWORD*)&AquaTypeBsDefaultFontSize = (DWORD)::GetProcAddress(lib,"AquaTypeBsDefaultFontSize");
*(DWORD*)&AquaTypeBsDefaultFixedFontFize = (DWORD)::GetProcAddress(lib,"AquaTypeBsDefaultFixedFontFize");
*(DWORD*)&AquaTypeBsMinimumFontSize = (DWORD)::GetProcAddress(lib,"AquaTypeBsMinimumFontSize");
*(DWORD*)&AquaTypeBsMinimumLogicalFontSize = (DWORD)::GetProcAddress(lib,"AquaTypeBsMinimumLogicalFontSize");
*(DWORD*)&AquaTypeBsDefaultEncodingA = (DWORD)::GetProcAddress(lib,"AquaTypeBsDefaultEncodingA");
*(DWORD*)&AquaTypeBsDefaultEncodingW = (DWORD)::GetProcAddress(lib,"AquaTypeBsDefaultEncodingW");
*(DWORD*)&AquaTypeBsRemoteFonts = (DWORD)::GetProcAddress(lib,"AquaTypeBsRemoteFonts");
*(DWORD*)&AquaTypeBsJavaScript = (DWORD)::GetProcAddress(lib,"AquaTypeBsJavaScript");
*(DWORD*)&AquaTypeBsJavaScriptCloseWindows = (DWORD)::GetProcAddress(lib,"AquaTypeBsJavaScriptCloseWindows");
*(DWORD*)&AquaTypeBsJavascriptAccessClipboard = (DWORD)::GetProcAddress(lib,"AquaTypeBsJavascriptAccessClipboard");
*(DWORD*)&AquaTypeBsJavascriptDomPaste = (DWORD)::GetProcAddress(lib,"AquaTypeBsJavascriptDomPaste");
*(DWORD*)&AquaTypeBsPlugins = (DWORD)::GetProcAddress(lib,"AquaTypeBsPlugins");
*(DWORD*)&AquaTypeBsUniversalAccessFromFileUrls = (DWORD)::GetProcAddress(lib,"AquaTypeBsUniversalAccessFromFileUrls");
*(DWORD*)&AquaTypeBsFileAccessFromFileUrls = (DWORD)::GetProcAddress(lib,"AquaTypeBsFileAccessFromFileUrls");
*(DWORD*)&AquaTypeBsWebSecurity = (DWORD)::GetProcAddress(lib,"AquaTypeBsWebSecurity");
*(DWORD*)&AquaTypeBsImageLoading = (DWORD)::GetProcAddress(lib,"AquaTypeBsImageLoading");
*(DWORD*)&AquaTypeBsImageShrinkStandaloneToFit = (DWORD)::GetProcAddress(lib,"AquaTypeBsImageShrinkStandaloneToFit");
*(DWORD*)&AquaTypeBsTextAreaResize = (DWORD)::GetProcAddress(lib,"AquaTypeBsTextAreaResize");
*(DWORD*)&AquaTypeBsTabToLinks = (DWORD)::GetProcAddress(lib,"AquaTypeBsTabToLinks");
*(DWORD*)&AquaTypeBsLocalStorage = (DWORD)::GetProcAddress(lib,"AquaTypeBsLocalStorage");
*(DWORD*)&AquaTypeBsDatabases = (DWORD)::GetProcAddress(lib,"AquaTypeBsDatabases");
*(DWORD*)&AquaTypeBsApplicationCache = (DWORD)::GetProcAddress(lib,"AquaTypeBsApplicationCache");
*(DWORD*)&AquaTypeBsWebGL = (DWORD)::GetProcAddress(lib,"AquaTypeBsWebGL");
*(DWORD*)&AquaTypeBsBackgroundColor = (DWORD)::GetProcAddress(lib,"AquaTypeBsBackgroundColor");
*(DWORD*)&AquaTypeBsAcceptLanguageListA = (DWORD)::GetProcAddress(lib,"AquaTypeBsAcceptLanguageListA");
*(DWORD*)&AquaTypeBsAcceptLanguageListW = (DWORD)::GetProcAddress(lib,"AquaTypeBsAcceptLanguageListW");
*(DWORD*)&AquaTypeRcsCreate = (DWORD)::GetProcAddress(lib,"AquaTypeRcsCreate");
*(DWORD*)&AquaTypeRcsCopy = (DWORD)::GetProcAddress(lib,"AquaTypeRcsCopy");
*(DWORD*)&AquaTypeRcsDestoryed = (DWORD)::GetProcAddress(lib,"AquaTypeRcsDestoryed");
*(DWORD*)&AquaTypeRcsCachePathA = (DWORD)::GetProcAddress(lib,"AquaTypeRcsCachePathA");
*(DWORD*)&AquaTypeRcsCachePathW = (DWORD)::GetProcAddress(lib,"AquaTypeRcsCachePathW");
*(DWORD*)&AquaTypeRcsPersistSessionCookies = (DWORD)::GetProcAddress(lib,"AquaTypeRcsPersistSessionCookies");
*(DWORD*)&AquaTypeRcsPersistUserPreferences = (DWORD)::GetProcAddress(lib,"AquaTypeRcsPersistUserPreferences");
*(DWORD*)&AquaTypeRcsIgnoreCertificateErrors = (DWORD)::GetProcAddress(lib,"AquaTypeRcsIgnoreCertificateErrors");
*(DWORD*)&AquaTypeRcsEnableNetSecurityExpiration = (DWORD)::GetProcAddress(lib,"AquaTypeRcsEnableNetSecurityExpiration");
*(DWORD*)&AquaTypeRcsAcceptLanguageListA = (DWORD)::GetProcAddress(lib,"AquaTypeRcsAcceptLanguageListA");
*(DWORD*)&AquaTypeRcsAcceptLanguageListW = (DWORD)::GetProcAddress(lib,"AquaTypeRcsAcceptLanguageListW");
*(DWORD*)&AquaTypePfSetFeatures = (DWORD)::GetProcAddress(lib,"AquaTypePfSetFeatures");
*(DWORD*)&AquaInitCachePathA = (DWORD)::GetProcAddress(lib,"AquaInitCachePathA");
*(DWORD*)&AquaInitCachePathW = (DWORD)::GetProcAddress(lib,"AquaInitCachePathW");
*(DWORD*)&AquaInitUserDataA = (DWORD)::GetProcAddress(lib,"AquaInitUserDataA");
*(DWORD*)&AquaInitUserDataW = (DWORD)::GetProcAddress(lib,"AquaInitUserDataW");
*(DWORD*)&AquaInitWindowlessRenderingEnabled = (DWORD)::GetProcAddress(lib,"AquaInitWindowlessRenderingEnabled");
*(DWORD*)&AquaInitPersistSessionCookies = (DWORD)::GetProcAddress(lib,"AquaInitPersistSessionCookies");
*(DWORD*)&AquaInitPersistUserPreferences = (DWORD)::GetProcAddress(lib,"AquaInitPersistUserPreferences");
*(DWORD*)&AquaInitUserAgentA = (DWORD)::GetProcAddress(lib,"AquaInitUserAgentA");
*(DWORD*)&AquaInitUserAgentW = (DWORD)::GetProcAddress(lib,"AquaInitUserAgentW");
*(DWORD*)&AquaInitProductVersionA = (DWORD)::GetProcAddress(lib,"AquaInitProductVersionA");
*(DWORD*)&AquaInitProductVersionW = (DWORD)::GetProcAddress(lib,"AquaInitProductVersionW");
*(DWORD*)&AquaInitLocaleA = (DWORD)::GetProcAddress(lib,"AquaInitLocaleA");
*(DWORD*)&AquaInitLocaleW = (DWORD)::GetProcAddress(lib,"AquaInitLocaleW");
*(DWORD*)&AquaInitJavascriptFlagsA = (DWORD)::GetProcAddress(lib,"AquaInitJavascriptFlagsA");
*(DWORD*)&AquaInitJavascriptFlagsW = (DWORD)::GetProcAddress(lib,"AquaInitJavascriptFlagsW");
*(DWORD*)&AquaInitPackloadingDisabled = (DWORD)::GetProcAddress(lib,"AquaInitPackloadingDisabled");
*(DWORD*)&AquaInitRemoteDebuggingPort = (DWORD)::GetProcAddress(lib,"AquaInitRemoteDebuggingPort");
*(DWORD*)&AquaInitUncaughtExceptionStackSize = (DWORD)::GetProcAddress(lib,"AquaInitUncaughtExceptionStackSize");
*(DWORD*)&AquaInitIgnoreCertificateErrors = (DWORD)::GetProcAddress(lib,"AquaInitIgnoreCertificateErrors");
*(DWORD*)&AquaInitEnableNetSecurityExpiration = (DWORD)::GetProcAddress(lib,"AquaInitEnableNetSecurityExpiration");
*(DWORD*)&AquaInitBackgroundColor = (DWORD)::GetProcAddress(lib,"AquaInitBackgroundColor");
*(DWORD*)&AquaInitAcceptLanguageListA = (DWORD)::GetProcAddress(lib,"AquaInitAcceptLanguageListA");
*(DWORD*)&AquaInitAcceptLanguageListW = (DWORD)::GetProcAddress(lib,"AquaInitAcceptLanguageListW");
*(DWORD*)&AquaDoWinMain = (DWORD)::GetProcAddress(lib,"AquaDoWinMain");
*(DWORD*)&AquaDoMessageLoop = (DWORD)::GetProcAddress(lib,"AquaDoMessageLoop");
*(DWORD*)&AquaBind = (DWORD)::GetProcAddress(lib,"AquaBind");
*(DWORD*)&AquaCreateCommandLine = (DWORD)::GetProcAddress(lib,"AquaCreateCommandLine");
*(DWORD*)&AquaGetGlobalCommandLine = (DWORD)::GetProcAddress(lib,"AquaGetGlobalCommandLine");
*(DWORD*)&AquaCommandLineIsValid = (DWORD)::GetProcAddress(lib,"AquaCommandLineIsValid");
*(DWORD*)&AquaCommandLineIsReadOnly = (DWORD)::GetProcAddress(lib,"AquaCommandLineIsReadOnly");
*(DWORD*)&AquaCommandLineCopy = (DWORD)::GetProcAddress(lib,"AquaCommandLineCopy");
*(DWORD*)&AquaCommandLineInitFromArgv = (DWORD)::GetProcAddress(lib,"AquaCommandLineInitFromArgv");
*(DWORD*)&AquaCommandLineInitFromStringA = (DWORD)::GetProcAddress(lib,"AquaCommandLineInitFromStringA");
*(DWORD*)&AquaCommandLineInitFromStringW = (DWORD)::GetProcAddress(lib,"AquaCommandLineInitFromStringW");
*(DWORD*)&AquaCommandLineReset = (DWORD)::GetProcAddress(lib,"AquaCommandLineReset");
*(DWORD*)&AquaCommandLineGetArgv = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetArgv");
*(DWORD*)&AquaCommandLineGetCommandLineStringA = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetCommandLineStringA");
*(DWORD*)&AquaCommandLineGetCommandLineStringW = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetCommandLineStringW");
*(DWORD*)&AquaCommandLineGetProgramA = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetProgramA");
*(DWORD*)&AquaCommandLineGetProgramW = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetProgramW");
*(DWORD*)&AquaCommandLineSetProgramA = (DWORD)::GetProcAddress(lib,"AquaCommandLineSetProgramA");
*(DWORD*)&AquaCommandLineSetProgramW = (DWORD)::GetProcAddress(lib,"AquaCommandLineSetProgramW");
*(DWORD*)&AquaCommandLineHasSwitches = (DWORD)::GetProcAddress(lib,"AquaCommandLineHasSwitches");
*(DWORD*)&AquaCommandLineHasSwitchA = (DWORD)::GetProcAddress(lib,"AquaCommandLineHasSwitchA");
*(DWORD*)&AquaCommandLineHasSwitchW = (DWORD)::GetProcAddress(lib,"AquaCommandLineHasSwitchW");
*(DWORD*)&AquaCommandLineGetSwitchValueA = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetSwitchValueA");
*(DWORD*)&AquaCommandLineGetSwitchValueW = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetSwitchValueW");
*(DWORD*)&AquaCommandLineGetSwitches = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetSwitches");
*(DWORD*)&AquaCommandLineAppendSwitchA = (DWORD)::GetProcAddress(lib,"AquaCommandLineAppendSwitchA");
*(DWORD*)&AquaCommandLineAppendSwitchW = (DWORD)::GetProcAddress(lib,"AquaCommandLineAppendSwitchW");
*(DWORD*)&AquaCommandLineAppendSwitchWithValueA = (DWORD)::GetProcAddress(lib,"AquaCommandLineAppendSwitchWithValueA");
*(DWORD*)&AquaCommandLineAppendSwitchWithValueW = (DWORD)::GetProcAddress(lib,"AquaCommandLineAppendSwitchWithValueW");
*(DWORD*)&AquaCommandLineHasArguments = (DWORD)::GetProcAddress(lib,"AquaCommandLineHasArguments");
*(DWORD*)&AquaCommandLineGetArguments = (DWORD)::GetProcAddress(lib,"AquaCommandLineGetArguments");
*(DWORD*)&AquaCommandLineAppendArgumentA = (DWORD)::GetProcAddress(lib,"AquaCommandLineAppendArgumentA");
*(DWORD*)&AquaCommandLineAppendArgumentW = (DWORD)::GetProcAddress(lib,"AquaCommandLineAppendArgumentW");
*(DWORD*)&AquaCommandLinePrependWrapperA = (DWORD)::GetProcAddress(lib,"AquaCommandLinePrependWrapperA");
*(DWORD*)&AquaCommandLinePrependWrapperW = (DWORD)::GetProcAddress(lib,"AquaCommandLinePrependWrapperW");
*(DWORD*)&AquaBrowserGetHost = (DWORD)::GetProcAddress(lib,"AquaBrowserGetHost");
*(DWORD*)&AquaBrowserCanGoBack = (DWORD)::GetProcAddress(lib,"AquaBrowserCanGoBack");
*(DWORD*)&AquaBrowserGoBack = (DWORD)::GetProcAddress(lib,"AquaBrowserGoBack");
*(DWORD*)&AquaBrowserCanGoForward = (DWORD)::GetProcAddress(lib,"AquaBrowserCanGoForward");
*(DWORD*)&AquaBrowserGoForward = (DWORD)::GetProcAddress(lib,"AquaBrowserGoForward");
*(DWORD*)&AquaBrowserIsLoading = (DWORD)::GetProcAddress(lib,"AquaBrowserIsLoading");
*(DWORD*)&AquaBrowserReload = (DWORD)::GetProcAddress(lib,"AquaBrowserReload");
*(DWORD*)&AquaBrowserReloadIgnoreCache = (DWORD)::GetProcAddress(lib,"AquaBrowserReloadIgnoreCache");
*(DWORD*)&AquaBrowserStopLoad = (DWORD)::GetProcAddress(lib,"AquaBrowserStopLoad");
*(DWORD*)&AquaBrowserGetIdentifier = (DWORD)::GetProcAddress(lib,"AquaBrowserGetIdentifier");
*(DWORD*)&AquaBrowserIsSame = (DWORD)::GetProcAddress(lib,"AquaBrowserIsSame");
*(DWORD*)&AquaBrowserIsPopup = (DWORD)::GetProcAddress(lib,"AquaBrowserIsPopup");
*(DWORD*)&AquaBrowserHasDocument = (DWORD)::GetProcAddress(lib,"AquaBrowserHasDocument");
*(DWORD*)&AquaBrowserGetMainFrame = (DWORD)::GetProcAddress(lib,"AquaBrowserGetMainFrame");
*(DWORD*)&AquaBrowserGetFocusedFrame = (DWORD)::GetProcAddress(lib,"AquaBrowserGetFocusedFrame");
*(DWORD*)&AquaBrowserGetFrameFromId = (DWORD)::GetProcAddress(lib,"AquaBrowserGetFrameFromId");
*(DWORD*)&AquaBrowserGetFrameFromNameA = (DWORD)::GetProcAddress(lib,"AquaBrowserGetFrameFromNameA");
*(DWORD*)&AquaBrowserGetFrameFromNameW = (DWORD)::GetProcAddress(lib,"AquaBrowserGetFrameFromNameW");
*(DWORD*)&AquaBrowserGetFrameCount = (DWORD)::GetProcAddress(lib,"AquaBrowserGetFrameCount");
*(DWORD*)&AquaBrowserGetFrameIdentifiers = (DWORD)::GetProcAddress(lib,"AquaBrowserGetFrameIdentifiers");
*(DWORD*)&AquaBrowserGetFrameNames = (DWORD)::GetProcAddress(lib,"AquaBrowserGetFrameNames");
*(DWORD*)&AquaBrowserSendProcessMessageA = (DWORD)::GetProcAddress(lib,"AquaBrowserSendProcessMessageA");
*(DWORD*)&AquaBrowserHostCreateBrowserA = (DWORD)::GetProcAddress(lib,"AquaBrowserHostCreateBrowserA");
*(DWORD*)&AquaBrowserHostCreateBrowserW = (DWORD)::GetProcAddress(lib,"AquaBrowserHostCreateBrowserW");
*(DWORD*)&AquaBrowserHostGetBrowser = (DWORD)::GetProcAddress(lib,"AquaBrowserHostGetBrowser");
*(DWORD*)&AquaBrowserHostCloseBrowser = (DWORD)::GetProcAddress(lib,"AquaBrowserHostCloseBrowser");
*(DWORD*)&AquaBrowserHostTryCloseBrowser = (DWORD)::GetProcAddress(lib,"AquaBrowserHostTryCloseBrowser");
*(DWORD*)&AquaBrowserHostSetFocus = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSetFocus");
*(DWORD*)&AquaBrowserHostGetWindowHandle = (DWORD)::GetProcAddress(lib,"AquaBrowserHostGetWindowHandle");
*(DWORD*)&AquaBrowserHostGetZoomLevel = (DWORD)::GetProcAddress(lib,"AquaBrowserHostGetZoomLevel");
*(DWORD*)&AquaBrowserHostSetZoomLevel = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSetZoomLevel");
*(DWORD*)&AquaBrowserHostStartDownloadA = (DWORD)::GetProcAddress(lib,"AquaBrowserHostStartDownloadA");
*(DWORD*)&AquaBrowserHostStartDownloadW = (DWORD)::GetProcAddress(lib,"AquaBrowserHostStartDownloadW");
*(DWORD*)&AquaBrowserHostPrint = (DWORD)::GetProcAddress(lib,"AquaBrowserHostPrint");
*(DWORD*)&AquaBrowserHostShowDevTools = (DWORD)::GetProcAddress(lib,"AquaBrowserHostShowDevTools");
*(DWORD*)&AquaBrowserHostCloseDevTools = (DWORD)::GetProcAddress(lib,"AquaBrowserHostCloseDevTools");
*(DWORD*)&AquaBrowserHostHasDevTools = (DWORD)::GetProcAddress(lib,"AquaBrowserHostHasDevTools");
*(DWORD*)&AquaBrowserHostSetMouseCursorChangeDisabled = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSetMouseCursorChangeDisabled");
*(DWORD*)&AquaBrowserHostIsMouseCursorChangeDisabled = (DWORD)::GetProcAddress(lib,"AquaBrowserHostIsMouseCursorChangeDisabled");
*(DWORD*)&AquaBrowserHostIsWindowRenderingDisabled = (DWORD)::GetProcAddress(lib,"AquaBrowserHostIsWindowRenderingDisabled");
*(DWORD*)&AquaBrowserHostWasResized = (DWORD)::GetProcAddress(lib,"AquaBrowserHostWasResized");
*(DWORD*)&AquaBrowserHostWasHidden = (DWORD)::GetProcAddress(lib,"AquaBrowserHostWasHidden");
*(DWORD*)&AquaBrowserHostNotifyScreenInfoChanged = (DWORD)::GetProcAddress(lib,"AquaBrowserHostNotifyScreenInfoChanged");
*(DWORD*)&AquaBrowserHostInvalidate = (DWORD)::GetProcAddress(lib,"AquaBrowserHostInvalidate");
*(DWORD*)&AquaBrowserHostSendFocusEvent = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSendFocusEvent");
*(DWORD*)&AquaBrowserHostSendCaptureLostEvent = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSendCaptureLostEvent");
*(DWORD*)&AquaBrowserHostNotifyMoveOrResizeStarted = (DWORD)::GetProcAddress(lib,"AquaBrowserHostNotifyMoveOrResizeStarted");
*(DWORD*)&AquaBrowserHostGetWindowlessFrameRate = (DWORD)::GetProcAddress(lib,"AquaBrowserHostGetWindowlessFrameRate");
*(DWORD*)&AquaBrowserHostSetWindowlessFrameRate = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSetWindowlessFrameRate");
*(DWORD*)&AquaManagerMoveOrResized = (DWORD)::GetProcAddress(lib,"AquaManagerMoveOrResized");
*(DWORD*)&AquaManagerSetMainHeroine = (DWORD)::GetProcAddress(lib,"AquaManagerSetMainHeroine");
*(DWORD*)&AquaManagerQueryActor = (DWORD)::GetProcAddress(lib,"AquaManagerQueryActor");
*(DWORD*)&AquaManagerGetCount = (DWORD)::GetProcAddress(lib,"AquaManagerGetCount");
*(DWORD*)&AquaManagerCloseAllBrowser = (DWORD)::GetProcAddress(lib,"AquaManagerCloseAllBrowser");
*(DWORD*)&AquaFrameIsValid = (DWORD)::GetProcAddress(lib,"AquaFrameIsValid");
*(DWORD*)&AquaFrameUndo = (DWORD)::GetProcAddress(lib,"AquaFrameUndo");
*(DWORD*)&AquaFrameRedo = (DWORD)::GetProcAddress(lib,"AquaFrameRedo");
*(DWORD*)&AquaFrameCut = (DWORD)::GetProcAddress(lib,"AquaFrameCut");
*(DWORD*)&AquaFrameCopy = (DWORD)::GetProcAddress(lib,"AquaFrameCopy");
*(DWORD*)&AquaFramePaste = (DWORD)::GetProcAddress(lib,"AquaFramePaste");
*(DWORD*)&AquaFrameDelete = (DWORD)::GetProcAddress(lib,"AquaFrameDelete");
*(DWORD*)&AquaFrameSelectAll = (DWORD)::GetProcAddress(lib,"AquaFrameSelectAll");
*(DWORD*)&AquaFrameGetSourceA = (DWORD)::GetProcAddress(lib,"AquaFrameGetSourceA");
*(DWORD*)&AquaFrameGetTextA = (DWORD)::GetProcAddress(lib,"AquaFrameGetTextA");
*(DWORD*)&AquaFrameLoadURLA = (DWORD)::GetProcAddress(lib,"AquaFrameLoadURLA");
*(DWORD*)&AquaFrameLoadStringA = (DWORD)::GetProcAddress(lib,"AquaFrameLoadStringA");
*(DWORD*)&AquaFrameExecuteJavaScriptA = (DWORD)::GetProcAddress(lib,"AquaFrameExecuteJavaScriptA");
*(DWORD*)&AquaFrameIsMain = (DWORD)::GetProcAddress(lib,"AquaFrameIsMain");
*(DWORD*)&AquaFrameIsFocused = (DWORD)::GetProcAddress(lib,"AquaFrameIsFocused");
*(DWORD*)&AquaFrameGetNameA = (DWORD)::GetProcAddress(lib,"AquaFrameGetNameA");
*(DWORD*)&AquaFrameGetIdentifier = (DWORD)::GetProcAddress(lib,"AquaFrameGetIdentifier");
*(DWORD*)&AquaFrameGetParent = (DWORD)::GetProcAddress(lib,"AquaFrameGetParent");
*(DWORD*)&AquaFrameGetURLA = (DWORD)::GetProcAddress(lib,"AquaFrameGetURLA");
*(DWORD*)&AquaFrameGetBrowser = (DWORD)::GetProcAddress(lib,"AquaFrameGetBrowser");
*(DWORD*)&AquaFrameEvalA = (DWORD)::GetProcAddress(lib,"AquaFrameEvalA");
*(DWORD*)&AquaFrameLoadRequest = (DWORD)::GetProcAddress(lib,"AquaFrameLoadRequest");
*(DWORD*)&AquaBrowserHostGetCookieManager = (DWORD)::GetProcAddress(lib,"AquaBrowserHostGetCookieManager");
*(DWORD*)&AquaCookieInitFromGlobal = (DWORD)::GetProcAddress(lib,"AquaCookieInitFromGlobal");
*(DWORD*)&AquaCookieGetUrlCookies = (DWORD)::GetProcAddress(lib,"AquaCookieGetUrlCookies");
*(DWORD*)&AquaCookieGetAllCookies = (DWORD)::GetProcAddress(lib,"AquaCookieGetAllCookies");
*(DWORD*)&AquaCookieSetCookie = (DWORD)::GetProcAddress(lib,"AquaCookieSetCookie");
*(DWORD*)&AquaCookieDeleteCookie = (DWORD)::GetProcAddress(lib,"AquaCookieDeleteCookie");
*(DWORD*)&AquaCookieSetStoragePath = (DWORD)::GetProcAddress(lib,"AquaCookieSetStoragePath");
*(DWORD*)&AquaCookieFlushStore = (DWORD)::GetProcAddress(lib,"AquaCookieFlushStore");
*(DWORD*)&AquaCookieGetCookieMerge = (DWORD)::GetProcAddress(lib,"AquaCookieGetCookieMerge");
*(DWORD*)&AquaCookieSetCookieMerge = (DWORD)::GetProcAddress(lib,"AquaCookieSetCookieMerge");
*(DWORD*)&AquaV8ValueAlloc = (DWORD)::GetProcAddress(lib,"AquaV8ValueAlloc");
*(DWORD*)&AquaV8ValueCopy = (DWORD)::GetProcAddress(lib,"AquaV8ValueCopy");
*(DWORD*)&AquaV8ValueDestory = (DWORD)::GetProcAddress(lib,"AquaV8ValueDestory");
*(DWORD*)&AquaV8ValueGetType = (DWORD)::GetProcAddress(lib,"AquaV8ValueGetType");
*(DWORD*)&AquaV8ValueGetValue = (DWORD)::GetProcAddress(lib,"AquaV8ValueGetValue");
*(DWORD*)&AquaV8ValueSetValue = (DWORD)::GetProcAddress(lib,"AquaV8ValueSetValue");
*(DWORD*)&AquaV8SpecCreateAccessor = (DWORD)::GetProcAddress(lib,"AquaV8SpecCreateAccessor");
*(DWORD*)&AquaV8SpecRegisterVar = (DWORD)::GetProcAddress(lib,"AquaV8SpecRegisterVar");
*(DWORD*)&AquaV8SpecRegisterFunction = (DWORD)::GetProcAddress(lib,"AquaV8SpecRegisterFunction");
*(DWORD*)&AquaPostDataCreate = (DWORD)::GetProcAddress(lib,"AquaPostDataCreate");
*(DWORD*)&AquaPostDataCopy = (DWORD)::GetProcAddress(lib,"AquaPostDataCopy");
*(DWORD*)&AquaPostDataDestory = (DWORD)::GetProcAddress(lib,"AquaPostDataDestory");
*(DWORD*)&AquaPostDataIsReadOnly = (DWORD)::GetProcAddress(lib,"AquaPostDataIsReadOnly");
*(DWORD*)&AquaPostDataHasExcludedElements = (DWORD)::GetProcAddress(lib,"AquaPostDataHasExcludedElements");
*(DWORD*)&AquaPostDataGetElementCount = (DWORD)::GetProcAddress(lib,"AquaPostDataGetElementCount");
*(DWORD*)&AquaPostDataGetElements = (DWORD)::GetProcAddress(lib,"AquaPostDataGetElements");
*(DWORD*)&AquaPostDataRemoveElement = (DWORD)::GetProcAddress(lib,"AquaPostDataRemoveElement");
*(DWORD*)&AquaPostDataAddElement = (DWORD)::GetProcAddress(lib,"AquaPostDataAddElement");
*(DWORD*)&AquaPostDataRemoveElements = (DWORD)::GetProcAddress(lib,"AquaPostDataRemoveElements");
*(DWORD*)&AquaPostDataElementCreate = (DWORD)::GetProcAddress(lib,"AquaPostDataElementCreate");
*(DWORD*)&AquaPostDataElementCopy = (DWORD)::GetProcAddress(lib,"AquaPostDataElementCopy");
*(DWORD*)&AquaPostDataElementDestory = (DWORD)::GetProcAddress(lib,"AquaPostDataElementDestory");
*(DWORD*)&AquaPostDataElementIsReadOnly = (DWORD)::GetProcAddress(lib,"AquaPostDataElementIsReadOnly");
*(DWORD*)&AquaPostDataElementSetToEmpty = (DWORD)::GetProcAddress(lib,"AquaPostDataElementSetToEmpty");
*(DWORD*)&AquaPostDataElementSetToFile = (DWORD)::GetProcAddress(lib,"AquaPostDataElementSetToFile");
*(DWORD*)&AquaPostDataElementSetToBytes = (DWORD)::GetProcAddress(lib,"AquaPostDataElementSetToBytes");
*(DWORD*)&AquaPostDataElementGetType = (DWORD)::GetProcAddress(lib,"AquaPostDataElementGetType");
*(DWORD*)&AquaPostDataElementGetFile = (DWORD)::GetProcAddress(lib,"AquaPostDataElementGetFile");
*(DWORD*)&AquaPostDataElementGetBytes = (DWORD)::GetProcAddress(lib,"AquaPostDataElementGetBytes");
*(DWORD*)&AquaPostDataElementGetBytesCount = (DWORD)::GetProcAddress(lib,"AquaPostDataElementGetBytesCount");
*(DWORD*)&AquaRequestCreate = (DWORD)::GetProcAddress(lib,"AquaRequestCreate");
*(DWORD*)&AquaRequestIsReadOnly = (DWORD)::GetProcAddress(lib,"AquaRequestIsReadOnly");
*(DWORD*)&AquaRequestGetURL = (DWORD)::GetProcAddress(lib,"AquaRequestGetURL");
*(DWORD*)&AquaRequestSetURL = (DWORD)::GetProcAddress(lib,"AquaRequestSetURL");
*(DWORD*)&AquaRequestGetMethod = (DWORD)::GetProcAddress(lib,"AquaRequestGetMethod");
*(DWORD*)&AquaRequestSetMethod = (DWORD)::GetProcAddress(lib,"AquaRequestSetMethod");
*(DWORD*)&AquaRequestGetReferrer = (DWORD)::GetProcAddress(lib,"AquaRequestGetReferrer");
*(DWORD*)&AquaRequestsetReferrerURL = (DWORD)::GetProcAddress(lib,"AquaRequestsetReferrerURL");
*(DWORD*)&AquaRequestGetReferrerPolicy = (DWORD)::GetProcAddress(lib,"AquaRequestGetReferrerPolicy");
*(DWORD*)&AquaRequestGetPostData = (DWORD)::GetProcAddress(lib,"AquaRequestGetPostData");
*(DWORD*)&AquaRequestSetPostData = (DWORD)::GetProcAddress(lib,"AquaRequestSetPostData");
*(DWORD*)&AquaRequestGetHeaderMap = (DWORD)::GetProcAddress(lib,"AquaRequestGetHeaderMap");
*(DWORD*)&AquaRequestSetHeaderMap = (DWORD)::GetProcAddress(lib,"AquaRequestSetHeaderMap");
*(DWORD*)&AquaRequestGetFlags = (DWORD)::GetProcAddress(lib,"AquaRequestGetFlags");
*(DWORD*)&AquaRequestSetFlags = (DWORD)::GetProcAddress(lib,"AquaRequestSetFlags");
*(DWORD*)&AquaRequestGetFirstPartyForCookies = (DWORD)::GetProcAddress(lib,"AquaRequestGetFirstPartyForCookies");
*(DWORD*)&AquaRequestSetFirstPartyForCookies = (DWORD)::GetProcAddress(lib,"AquaRequestSetFirstPartyForCookies");
*(DWORD*)&AquaRequestGetResourceType = (DWORD)::GetProcAddress(lib,"AquaRequestGetResourceType");
*(DWORD*)&AquaResponseCreate = (DWORD)::GetProcAddress(lib,"AquaResponseCreate");
*(DWORD*)&AquaResponseIsReadOnly = (DWORD)::GetProcAddress(lib,"AquaResponseIsReadOnly");
*(DWORD*)&AquaResponseGetStatus = (DWORD)::GetProcAddress(lib,"AquaResponseGetStatus");
*(DWORD*)&AquaResponseSetStatus = (DWORD)::GetProcAddress(lib,"AquaResponseSetStatus");
*(DWORD*)&AquaResponseGetStatusText = (DWORD)::GetProcAddress(lib,"AquaResponseGetStatusText");
*(DWORD*)&AquaResponseSetStatusText = (DWORD)::GetProcAddress(lib,"AquaResponseSetStatusText");
*(DWORD*)&AquaResponseGetMimeType = (DWORD)::GetProcAddress(lib,"AquaResponseGetMimeType");
*(DWORD*)&AquaResponseSetMimeType = (DWORD)::GetProcAddress(lib,"AquaResponseSetMimeType");
*(DWORD*)&AquaResponseGetHeaderMap = (DWORD)::GetProcAddress(lib,"AquaResponseGetHeaderMap");
*(DWORD*)&AquaResponseSetHeaderMap = (DWORD)::GetProcAddress(lib,"AquaResponseSetHeaderMap");
*(DWORD*)&AquaJSDialogContinue = (DWORD)::GetProcAddress(lib,"AquaJSDialogContinue");
*(DWORD*)&AquaFileDialogContinue = (DWORD)::GetProcAddress(lib,"AquaFileDialogContinue");
*(DWORD*)&AquaFileDialogCancel = (DWORD)::GetProcAddress(lib,"AquaFileDialogCancel");
*(DWORD*)&AquaBrowserHostSendKeyEvent = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSendKeyEvent");
*(DWORD*)&AquaBrowserHostSendMouseClickEvent = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSendMouseClickEvent");
*(DWORD*)&AquaBrowserHostSendMouseMoveEvent = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSendMouseMoveEvent");
*(DWORD*)&AquaBrowserHostSendMouseWheelEvent = (DWORD)::GetProcAddress(lib,"AquaBrowserHostSendMouseWheelEvent");
*(DWORD*)&AquaDownloadIsValid = (DWORD)::GetProcAddress(lib,"AquaDownloadIsValid");
*(DWORD*)&AquaDownloadIsInProgress = (DWORD)::GetProcAddress(lib,"AquaDownloadIsInProgress");
*(DWORD*)&AquaDownloadIsComplete = (DWORD)::GetProcAddress(lib,"AquaDownloadIsComplete");
*(DWORD*)&AquaDownloadIsCanceled = (DWORD)::GetProcAddress(lib,"AquaDownloadIsCanceled");
*(DWORD*)&AquaDownloadGetCurrentSpeed = (DWORD)::GetProcAddress(lib,"AquaDownloadGetCurrentSpeed");
*(DWORD*)&AquaDownloadGetPercentComplete = (DWORD)::GetProcAddress(lib,"AquaDownloadGetPercentComplete");
*(DWORD*)&AquaDownloadGetTotalBytes = (DWORD)::GetProcAddress(lib,"AquaDownloadGetTotalBytes");
*(DWORD*)&AquaDownloadGetReceivedBytes = (DWORD)::GetProcAddress(lib,"AquaDownloadGetReceivedBytes");
*(DWORD*)&AquaDownloadGetStartTime = (DWORD)::GetProcAddress(lib,"AquaDownloadGetStartTime");
*(DWORD*)&AquaDownloadGetEndTime = (DWORD)::GetProcAddress(lib,"AquaDownloadGetEndTime");
*(DWORD*)&AquaDownloadGetFullPath = (DWORD)::GetProcAddress(lib,"AquaDownloadGetFullPath");
*(DWORD*)&AquaDownloadGetId = (DWORD)::GetProcAddress(lib,"AquaDownloadGetId");
*(DWORD*)&AquaDownloadGetURL = (DWORD)::GetProcAddress(lib,"AquaDownloadGetURL");
*(DWORD*)&AquaDownloadGetOriginalUrl = (DWORD)::GetProcAddress(lib,"AquaDownloadGetOriginalUrl");
*(DWORD*)&AquaDownloadGetSuggestedFileName = (DWORD)::GetProcAddress(lib,"AquaDownloadGetSuggestedFileName");
*(DWORD*)&AquaDownloadGetContentDisposition = (DWORD)::GetProcAddress(lib,"AquaDownloadGetContentDisposition");
*(DWORD*)&AquaDownloadGetMimeType = (DWORD)::GetProcAddress(lib,"AquaDownloadGetMimeType");
*(DWORD*)&AquaDownloadCallbackContinue = (DWORD)::GetProcAddress(lib,"AquaDownloadCallbackContinue");
*(DWORD*)&AquaDownloadItemCallbackCancel = (DWORD)::GetProcAddress(lib,"AquaDownloadItemCallbackCancel");
*(DWORD*)&AquaDownloadItemCallbackPause = (DWORD)::GetProcAddress(lib,"AquaDownloadItemCallbackPause");
*(DWORD*)&AquaDownloadItemCallbackResume = (DWORD)::GetProcAddress(lib,"AquaDownloadItemCallbackResume");
*(DWORD*)&AquaAuthCallbackContinue = (DWORD)::GetProcAddress(lib,"AquaAuthCallbackContinue");
*(DWORD*)&AquaAuthCallbackCancel = (DWORD)::GetProcAddress(lib,"AquaAuthCallbackCancel");
	}


	BOOL DoLoadLibrary(LPCSTR path) {
		int len = GetEnvironmentVariable("path",NULL,0);
		if(len > 0){
			char *pszEnvVal = new char[len+1];
			GetEnvironmentVariable("path",pszEnvVal,len);
			pszEnvVal[len]=0;
			std::string buf;
			buf = pszEnvVal;
			buf += "; ";
			buf += path;
			SetEnvironmentVariable("path",buf.c_str());
			delete []pszEnvVal;
			SetCurrentDirectory(path);
			HMODULE library = ::LoadLibrary("libaquarius.dll");
			if(library!=NULL){
				DoAllowFunctional(library);
				return TRUE;
			}
		}
		return FALSE;
	}
}


// 绝对不会返回NULL或者窗口句柄无效的CWnd*指针。
CWnd* AquaGetWndPtr (PMDATA_INF pInf)
{
	return (CWnd*)g_fnAquaNotifySys (NRS_GET_AND_CHECK_UNIT_PTR, pInf->m_unit.m_dwFormID,
		pInf->m_unit.m_dwUnitID);
}

// 使用指定文本数据建立易程序中使用的文本数据。
//   nTextLen用作指定文本部分的长度（不包含结束零），
// 如果为-1，则取ps的全部长度。
char* AquaCloneTextData (const char* ps, INT nTextLen = 0)
{
    if (nTextLen <= 0)
        nTextLen = strlen(ps);
	
    char* pd = (char*)g_fnAquaNotifySys (NRS_MALLOC, (DWORD)(nTextLen + 1), 0);
    memcpy (pd, ps, nTextLen);
    pd [nTextLen] = '\0';
    return pd;
}

// 使用指定数据建立易程序中使用的字节集数据。
LPBYTE AquaCloneBinData (LPBYTE pData, INT nDataSize)
{
    if (nDataSize == 0)
        return NULL;
    LPBYTE pd = (LPBYTE)g_fnAquaNotifySys (NRS_MALLOC, (DWORD)(sizeof (INT) * 2 + nDataSize), 0);
    *(LPINT)pd = 1;
    *(LPINT)(pd + sizeof (INT)) = nDataSize;
    memcpy (pd + sizeof (INT) * 2, pData, nDataSize);
    return pd;
}

#define TOWNDPTR(inf)	AquaGetWndPtr(inf)
#define COPYSTRING(ps,len)	AquaCloneTextData(ps,len)
#define COPYBIN(pd,len)	AquaCloneBinData(pd,len)

//初始化设置参数
struct AQUA_INIT_INFO {
	char *pszCachePath;
	char *pszUserDataPath;
	int	  nWindowlessRate;
	BOOL  bPersistSessionCookies;
	BOOL  bPersistUserPreferences;
	char *pszUserAgent;
	char *pszProductVersion;
	char *pszLocale;
	int   nRemoteDebuggingPort;
	BOOL  bIgnoreCertificateErrors;
	char  *pszAcceptLanguageList;
};

//异步执行参数
struct AQUA_ASYNC_CALLING{
	PMDATA_INF pRetData;
	LPVOID pBi;
	int params1;
	char *params2;
	BYTE *params3;
	int cmd;
};

//异步计算表达式
struct AQUA_ASYNC_EVAL{
	PMDATA_INF pRetData;
	LPVOID pBi;
	PMDATA_INF pExcept; 
	int params1;
	char *params2;
	BYTE *params3;
};

//窗口特性
struct AQUA_POPUP_FEATURES{
	int x;
	int xSet;
	int y;
	int ySet;
	int width;
	int widthSet;
	int height;
	int heightSet;
	int menuBarVisible;
	int statusBarVisible;
	int toolBarVisible;
	int scrollbarsVisible;
};

struct AQUA_TIME {
	int year;          // Four digit year "2007"
	int month;         // 1-based month (values 1 = January, etc.)
	int day_of_week;   // 0-based day of week (0 = Sunday, etc.)
	int day_of_month;  // 1-based day of month (1-31)
	int hour;          // Hour within the current day (0-23)
	int minute;        // Minute within the current hour (0-59)
	int second;        // Second within the current minute (0-59 plus leap
	//   seconds which may take it up to 60).
	int millisecond;   // Milliseconds within the current second (0-999)
};

struct AQUA_COOKIE{
	LPCSTR name;
	LPCSTR value;
	LPCSTR domain;
	BOOL secure;
	BOOL httponly;
	BOOL has_expires;
	AQUA_TIME *expires;
};



struct AQUA_COOKIE_CALLING{
	LPINT pAddr;
	int total;
	PMDATA_INF pRetData;
};

struct AQUA_COOKIE_CALLING_MEGER{
	std::stringstream buf;
	PMDATA_INF pRetData;
};

struct AQUA_COOKIE_CALLING_SETCOOKIE {
	LPCSTR domain;
	LPVOID object;
};

struct AQUA_REQUEST_CONTEXT_SETTINGS {
	LPCSTR cachePath;
	BOOL persistSessionCookies;
	BOOL persistUserPreferences;
	BOOL ignoreCertificateErrors;
};

struct AQUA_POSTDATA_CALLING{
	PMDATA_INF pRetData;
	int total;
	LPINT pAddr;
	int index;
};

struct AQUA_KEYEVENT_STRUCT{
	int type;
	UINT32 modifiers;
	int window_key_codev;
	int native_key_code;
	int is_system_key;
	int character;
	int unmodified_character;
	int focus_on_editable_field;
};

struct AQUA_KEYEVENT_ORG_STRUCT{
	int type;
	UINT32 modifiers;
	int window_key_codev;
	int native_key_code;
	int is_system_key;
	WCHAR character;
	WCHAR unmodified_character;
	int focus_on_editable_field;
};

struct AQUA_MOUSEEVENT_STRUCT{
	int x;
	int y;
	UINT32 modifiers; 
};

#endif
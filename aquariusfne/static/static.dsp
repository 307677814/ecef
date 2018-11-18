# Microsoft Developer Studio Project File - Name="static" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=static - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "static.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "static.mak" CFG="static - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "static - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "static - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "static - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /Zp4 /MT /W3 /GX /Od /I "E:\aquariusfne\src" /I "E:\aquariusfne\image\src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "__E_STATIC_LIB" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../out/aquarius_static.lib"

!ELSEIF  "$(CFG)" == "static - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "static - Win32 Release"
# Name "static - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\fne\fne.cpp
# End Source File
# Begin Source File

SOURCE=..\fne\StdAfx.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\fne\fne.h
# End Source File
# Begin Source File

SOURCE=..\fne\Resource.h
# End Source File
# Begin Source File

SOURCE=..\fne\StdAfx.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\aquarius.cpp
# End Source File
# Begin Source File

SOURCE=..\src\aquariuseventer.h
# End Source File
# Begin Source File

SOURCE=..\src\aquariusfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\AquariusWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\src\AquariusWnd.h
# End Source File
# Begin Source File

SOURCE=..\src\arginfo.h
# End Source File
# Begin Source File

SOURCE=..\src\browser.h
# End Source File
# Begin Source File

SOURCE=..\src\browserfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\callback.h
# End Source File
# Begin Source File

SOURCE=..\src\callbackfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\cmdinfo.h
# End Source File
# Begin Source File

SOURCE=..\src\commandline.h
# End Source File
# Begin Source File

SOURCE=..\src\commandlinefunc.h
# End Source File
# Begin Source File

SOURCE=..\src\consttype.h
# End Source File
# Begin Source File

SOURCE=..\src\cookie.h
# End Source File
# Begin Source File

SOURCE=..\src\cookiefunc.h
# End Source File
# Begin Source File

SOURCE=..\src\datatype.h
# End Source File
# Begin Source File

SOURCE=..\src\dispatch.h
# End Source File
# Begin Source File

SOURCE=..\src\document.h
# End Source File
# Begin Source File

SOURCE=..\src\documentfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\eventsfunc.cpp
# End Source File
# Begin Source File

SOURCE=..\src\eventsfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\filedialogcallback.h
# End Source File
# Begin Source File

SOURCE=..\src\filedialogcallbackfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\frame.h
# End Source File
# Begin Source File

SOURCE=..\src\framefunc.h
# End Source File
# Begin Source File

SOURCE=..\src\func.h
# End Source File
# Begin Source File

SOURCE=..\src\host.h
# End Source File
# Begin Source File

SOURCE=..\src\hostfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\initial.h
# End Source File
# Begin Source File

SOURCE=..\src\initialfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\int64vector.h
# End Source File
# Begin Source File

SOURCE=..\src\int64vectorfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\jsdialog.h
# End Source File
# Begin Source File

SOURCE=..\src\jsdialogfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\keyevent.h
# End Source File
# Begin Source File

SOURCE=..\src\popupfeatures.h
# End Source File
# Begin Source File

SOURCE=..\src\postdata.h
# End Source File
# Begin Source File

SOURCE=..\src\postdatafunc.h
# End Source File
# Begin Source File

SOURCE=..\src\request.h
# End Source File
# Begin Source File

SOURCE=..\src\requestcontext.h
# End Source File
# Begin Source File

SOURCE=..\src\requestcontextfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\requestfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\Resource.h
# End Source File
# Begin Source File

SOURCE=..\src\response.h
# End Source File
# Begin Source File

SOURCE=..\src\responsefunc.h
# End Source File
# Begin Source File

SOURCE=..\src\schemes.h
# End Source File
# Begin Source File

SOURCE=..\src\schemesfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\src\strdict.h
# End Source File
# Begin Source File

SOURCE=..\src\strdictex.h
# End Source File
# Begin Source File

SOURCE=..\src\strdictexfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\strdictfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\strvector.h
# End Source File
# Begin Source File

SOURCE=..\src\strvectorfunc.h
# End Source File
# Begin Source File

SOURCE=..\src\v8.h
# End Source File
# Begin Source File

SOURCE=..\src\v8func.h
# End Source File
# Begin Source File

SOURCE=..\src\wapper.h
# End Source File
# Begin Source File

SOURCE=..\src\windowinfo.h
# End Source File
# Begin Source File

SOURCE=..\src\windowinfofunc.h
# End Source File
# End Group
# End Target
# End Project

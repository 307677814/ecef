#ifndef AQUA_HANDLER_RENDERER_H_
#define AQUA_HANDLER_RENDERER_H_
#include "utils\aqua_utils.h"

namespace AquaHandler {


	struct aqua_handler_renderer_t {

		///
		//	在CEF上下文初始化后立即调用浏览器进程UI线程。
		///
		void (__stdcall *OnBeforeCommandLineProcessing) (const char *process_type, void *cmd);

		///
		//	在CEF上下文初始化后立即调用浏览器进程UI线程。
		///
		void(__stdcall *OnContextInitialized)(void);

		///
		//	当Frame的地址发生变化时调用。
		///
		void(__stdcall *OnAddressChange)(LPVOID browser,LPVOID frame,const char *url);

		///
		//	当页面标题改变时调用。
		///
		void(__stdcall *OnTitleChange)(LPVOID browser,const char *title);

		///
		//	当页面图标发生变化时调用。
		///
		void(__stdcall *OnFaviconURLChange)(LPVOID browser, LPVOID icon_urls);

		///
		//	当页面中的网页内容切换为全屏模式时调用。 如果|全屏| 该内容将自动调整大小以填充浏览器内容区域。
		//	如果|全屏| 是错误的内容将自动返回到其原始大小和位置。 如果需要，客户端负责调整浏览器的大小。
		///
		void(__stdcall *OnFullscreenModeChange)(LPVOID browser, bool fullscreen);

		///
		//	当浏览器收到状态消息时调用。|值| 包含将在状态消息中显示的文本。
		///
		void(__stdcall *OnStatusMessage)(LPVOID browser, const char *value);

		///
		//	调用以显示控制台消息。 返回true以停止将消息输出到控制台。
		///
		bool(__stdcall *OnConsoleMessage)(LPVOID browser, int level, const char *message, const char *source, int len);

		bool(__stdcall *OnBeforePopup)(LPVOID browser,LPVOID frame,
			const char *target_url,const char *target_frame_name,
			int target_disposition,bool user_gesture,
			LPVOID popupFeatures,LPVOID windowInfo,LPVOID bs,bool *no_javascript_access);

		void(__stdcall *OnAfterCreated)(LPVOID browser);

		bool(__stdcall *DoClose)(LPVOID browser);

		void(__stdcall *OnBeforeClose)(LPVOID browser);

		void(__stdcall *OnLoadingStateChange)(LPVOID browser,
			bool isLoading,
			bool canGoBack,
			bool canGoForward);

		void(__stdcall *OnLoadStart)(LPVOID browser,LPVOID frame,int transition_type);

		void(__stdcall *OnLoadEnd)(LPVOID browser, LPVOID frame, int httpStatusCode);

		void(__stdcall *OnLoadError)(LPVOID browser, LPVOID frame, int errorCode,
			const char* errorText, const char* failedUrl);

		void(__stdcall *OnContextCreated)(LPVOID browser);

		void(__stdcall *OnContextRelease)(LPVOID browser);

		bool(__stdcall *OnV8AccessorGet)(LPCSTR mainName,LPCSTR childName,LPVOID retval);

		bool(__stdcall *OnV8AccessorSet)(LPCSTR mainName, LPCSTR childName, LPVOID value);

		bool(__stdcall *OnV8AccessorExecute)(LPCSTR mainName, LPCSTR childName, int count, LPVOID argv, LPVOID retval);

		bool(__stdcall *OnBeforeResourceLoad)(LPVOID browser, LPVOID frame, LPVOID request, BOOL *is_coped);

		typedef void(CALLBACK *LPFN_REDIRECT_NEW_URL)(LPCSTR new_url,LPVOID params);
		void (__stdcall *OnResourceRedirect)(LPVOID browser,LPVOID frame,LPVOID request, LPFN_REDIRECT_NEW_URL callback,LPVOID params);


		void (__stdcall *OnResourceLoadComplete)(LPVOID browser,LPVOID frame,LPVOID request,LPVOID response,
			int status, __int64 received_content_length,void *data);

		bool(__stdcall *OnJSDialog)(LPVOID browser,
			LPCSTR origin_url,
			LPCSTR accept_lang,
			int dialog_type,
			LPCSTR message_text,
			LPCSTR default_prompt_text,
			LPVOID callback);

		bool(__stdcall *OnFileDialog)(LPVOID browser,
			int mode,
			LPCSTR title,
			LPCSTR default_file_path,
			LPVOID accept_filters,
			int selected_accept_filter,
			LPVOID callback);

		bool (__stdcall *OnPreKeyEvent)(LPVOID browser, LPVOID keyevent, bool* is_keyboard_shortcut);

		void (__stdcall *OnBeforeDownload)(LPVOID browser,LPVOID download_item,LPCSTR suggested_name,LPVOID callback);

		void (__stdcall *OnDownloadUpdated)(LPVOID browser,LPVOID download_item,LPVOID callback);

		bool (__stdcall *RunContextMenu)(LPVOID browser, LPVOID frame, int x, int y);

		bool (__stdcall *GetAuthCredentials)(LPVOID browser,LPVOID frame,bool isProxy,LPCSTR host,int port,LPCSTR realm,LPCSTR scheme,LPVOID callback);
	};

	extern aqua_handler_renderer_t renderInterface;

	AQUAENTRY(void , Bind)(aqua_handler_renderer_t *renderEvents);
	

}
#endif
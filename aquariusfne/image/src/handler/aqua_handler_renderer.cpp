#include "aqua_handler_renderer.h"

AquaHandler::aqua_handler_renderer_t AquaHandler::renderInterface;

using namespace AquaHandler;

AQUAENTRY(void, Bind)(aqua_handler_renderer_t *renderEvents) {
	ZeroMemory(&renderInterface, sizeof(aqua_handler_renderer_t));
	if (renderEvents) {
		memcpy(&renderInterface, renderEvents, sizeof(aqua_handler_renderer_t));
	}
}

#pragma once

#include "RE/H/HeldStateHandler.h"

namespace RE
{
	struct SprintHandler : public HeldStateHandler
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_SprintHandler;

		~SprintHandler() override;  // 00

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                  // 01
		void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 04
	};
	static_assert(sizeof(SprintHandler) == 0x18);
}

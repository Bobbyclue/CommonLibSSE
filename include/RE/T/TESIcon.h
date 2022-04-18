#pragma once

#include "RE/T/TESTexture.h"

namespace RE
{
	class TESIcon : public TESTexture
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_TESTexture;

		~TESIcon() override;  // 00

		// override (TESTexture)
		[[nodiscard]] const char* GetDefaultPath() const override;  // 06 - { return "Textures"; }
	};
	static_assert(sizeof(TESIcon) == 0x10);
}

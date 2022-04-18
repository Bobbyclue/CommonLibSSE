#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class BGSTextureModel : public TESModel
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_BGSTextureModel;

		~BGSTextureModel() override;  // 00

		// override (TESModel)
		void SetModel(const char* a_model) override;  // 05
	};
	static_assert(sizeof(BGSTextureModel) == 0x28);
}

#pragma once

#include "RE/B/BGSLoadGameSubBuffer.h"
#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraSavedHavokData : public BSExtraData
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_ExtraSavedHavokData;
		inline static auto EXTRADATATYPE = ExtraDataType::kSavedHavokData;

		virtual ~ExtraSavedHavokData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;  // 01 - { return kSavedHavokData; }

		// members
		BGSLoadGameSubBuffer havokBuffer;  // 10
	};
	static_assert(sizeof(ExtraSavedHavokData) == 0x18);
}

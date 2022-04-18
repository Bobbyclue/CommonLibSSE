#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class bhkWorld;
	class CellMopp;

	class ExtraHavok : public BSExtraData
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_ExtraHavok;
		inline static auto      EXTRADATATYPE = ExtraDataType::kHavok;

		~ExtraHavok() override;  // 00

		// override (BSExtraData)
		[[nodiscard]] ExtraDataType GetType() const override;  // 01 - { return kHavok; }

		// members
		NiPointer<bhkWorld> world;     // 10
		NiPointer<CellMopp> cellMopp;  // 18
	};
	static_assert(sizeof(ExtraHavok) == 0x20);
}

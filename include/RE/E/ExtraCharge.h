#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraCharge : public BSExtraData
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_ExtraCharge;
		SKYRIM_ADDR static auto VTABLE = VTABLE_ExtraCharge;
		inline static auto      EXTRADATATYPE = ExtraDataType::kCharge;

		ExtraCharge();
		~ExtraCharge() override = default;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kCharge; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return charge != a_rhs->charge; }

		// members
		float         charge;  // 10
		std::uint32_t pad14;   // 14
	};
	static_assert(sizeof(ExtraCharge) == 0x18);
}

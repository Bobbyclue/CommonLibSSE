#pragma once

#include "RE/B/bhkPhantom.h"

namespace RE
{
	class bhkShapePhantom : public bhkPhantom
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_bhkShapePhantom;
		inline static auto      Ni_RTTI = NiRTTI_bhkShapePhantom;

		~bhkShapePhantom() override;  // 00

		// override (bhkPhantom)
		const NiRTTI* GetRTTI() const override;                 // 02
		void          LinkObject(NiStream& a_stream) override;  // 19 - { bhkWorldObject::LinkObject(a_stream); }
	};
	static_assert(sizeof(bhkShapePhantom) == 0x30);
}

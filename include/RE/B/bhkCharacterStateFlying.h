#pragma once

#include "RE/B/bhkCharacterState.h"

namespace RE
{
	class bhkCharacterStateFlying : public bhkCharacterState
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_bhkCharacterStateFlying;

		~bhkCharacterStateFlying() override;  // 00

		// override (bhkCharacterState)
		hkpCharacterStateType GetType() const override;  // 03 - { return kFlying; }
		void                  Unk_08(void) override;     // 08
	};
	static_assert(sizeof(bhkCharacterStateFlying) == 0x10);
}

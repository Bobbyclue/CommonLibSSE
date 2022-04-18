#pragma once

#include "RE/B/bhkSerializable.h"

namespace RE
{
	class bhkWorldObject : public bhkSerializable
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_bhkWorldObject;
		inline static auto      Ni_RTTI = NiRTTI_bhkWorldObject;

		~bhkWorldObject() override;  // 00

		// override (bhkSerializable)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		void          AdjustRefCount(bool a_increment) override;         // 26
		hkpWorld*     GetWorld1() override;                              // 27 - { return world; }
		ahkpWorld*    GetWorld2() override;                              // 28 - { return world; }
		void          Unk_29(void) override;                             // 29

		// add
		virtual void Unk_32(void);  // 32 - { return Unk_29(); }

		// members
		hkpWorld* world;  // 20
	};
	static_assert(sizeof(bhkWorldObject) == 0x28);
}

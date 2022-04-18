#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"
#include "RE/N/NiColor.h"

namespace RE
{
	class BSLightingShaderMaterialSnow : public BSLightingShaderMaterialBase
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_BSLightingShaderMaterialSnow;
		SKYRIM_ADDR static auto VTABLE = VTABLE_BSLightingShaderMaterialSnow;
		inline static auto FEATURE = Feature::kMultiIndexTriShapeSnow;

		~BSLightingShaderMaterialSnow() override;  // 00

		// override (BSLightingShaderMaterialBase)
		BSShaderMaterial* Create() override;                              // 01
		void              CopyMembers(BSShaderMaterial* a_src) override;  // 02
		std::uint32_t     ComputeCRC32(void) override;                    // 04
		Feature           GetFeature() const override;                    // 06 - { return Feature::kMultiIndexTriShapeSnow; }
		void              SaveBinary(NiStream& a_stream) override;        // 0C
		void              LoadBinary(NiStream& a_stream) override;        // 0D

		// members
		NiColorA sparkleParams;  // A0

	protected:
		BSLightingShaderMaterialSnow* Ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterialSnow::Ctor);
			REL::Relocation<func_t> func{ REL::RelocationID(100118, 106825) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterialSnow) == 0xB0);
}

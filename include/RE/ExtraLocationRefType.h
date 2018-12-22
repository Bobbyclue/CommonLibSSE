#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // BGSLocationRefType


namespace RE
{
	class ExtraLocationRefType : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kLocationRefType };


		virtual ~ExtraLocationRefType();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLocationRefType; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BGSLocationRefType* refType;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLocationRefType) == 0x18);
}

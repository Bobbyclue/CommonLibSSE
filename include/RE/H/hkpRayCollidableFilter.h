#pragma once

namespace RE
{
	class hkpCollidable;

	struct hkpWorldRayCastInput;

	class hkpRayCollidableFilter
	{
	public:
		SKYRIM_ADDR static auto RTTI = RTTI_hkpRayCollidableFilter;

		virtual ~hkpRayCollidableFilter();  // 00

		// add
		virtual bool IsCollisionEnabled(const hkpWorldRayCastInput& a_input, const hkpCollidable& a_collidable) const = 0;  // 01
	};
	static_assert(sizeof(hkpRayCollidableFilter) == 0x08);
}

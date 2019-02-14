#include "RE/TESContainer.h"

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class ItemCounter
	{
	public:
		constexpr ItemCounter(TESForm* a_item) :
			_count(0),
			_item(a_item)
		{}


		bool Accept(TESContainer::Entry* a_entry)
		{
			if (a_entry->form == _item) {
				_count += a_entry->count;
			}
			return true;
		}


		constexpr UInt32 Count() const
		{
			return _count;
		}

	private:
		UInt32		_count;
		TESForm*	_item;
	};


	bool TESContainer::GetContainerItemAt(UInt32 a_idx, Entry*& a_entry) const
	{
		if (a_idx < numEntries) {
			a_entry = entries[a_idx];
			return true;
		} else {
			return false;
		}
	}


	UInt32 TESContainer::CountItem(TESForm* a_item) const
	{
		ItemCounter v(a_item);
		Visit(v);
		return v.Count();
	}


	bool TESContainer::GetContainerLevItemAt(UInt32 a_idx, TESContainer::Entry*& a_entry) const
	{
		UInt32 n = 0;

		for (UInt32 i = 0; i < numEntries; ++i) {
			Entry* p = entries[i];
			if (p->form->Is(FormType::LeveledItem)) {
				if (n == a_idx) {
					a_entry = p;
					return true;
				}
				++n;
			}
		}

		return false;
	}
}

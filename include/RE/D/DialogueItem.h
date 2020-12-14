#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSString.h"
#include "RE/B/BSTList.h"
#include "RE/M/MemoryManager.h"


namespace RE
{
	class Actor;
	class BGSSoundDescriptorForm;
	class ExtraSayToTopicInfo;
	class TESIdleForm;
	class TESQuest;
	class TESTopic;
	class TESTopicInfo;


	class DialogueResponse
	{
	public:
		enum class EmotionType
		{
			kNeutral = 0,
			kAnger = 1,
			kDisgust = 2,
			kFear = 3,
			kSad = 4,
			kHappy = 5,
			kSurprise = 6,
			kPuzzled = 7
		};


		// members
		BSString									 text;				// 00
		stl::enumeration<EmotionType, std::uint32_t> animFaceArchType;	// 10
		std::uint16_t								 percent;			// 14
		std::uint16_t								 pad16;				// 16
		BSFixedString								 voice;				// 18
		TESIdleForm*								 speakerIdle;		// 20
		TESIdleForm*								 listenIdle;		// 28
		BGSSoundDescriptorForm*						 voiceSound;		// 30
		bool										 useEmotion;		// 38
		bool										 soundLip;			// 39
		std::uint16_t								 pad3A;				// 3A
		std::uint32_t								 pad3C;				// 3C
	};
	static_assert(sizeof(DialogueResponse) == 0x40);


	class DialogueItem : public BSIntrusiveRefCounted
	{
	public:
		DialogueItem(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker);
		~DialogueItem() = default;

		TES_HEAP_REDEFINE_NEW();


		// members
		std::uint32_t						   pad04;			 // 04
		BSSimpleList<DialogueResponse*>		   responses;		 // 08
		BSSimpleList<DialogueResponse*>::Node* currentResponse;	 // 18
		TESTopicInfo*						   info;			 // 20
		TESTopic*							   topic;			 // 28
		TESQuest*							   quest;			 // 30
		TESObjectREFR*						   speaker;			 // 38
		ExtraSayToTopicInfo*				   extraData;		 // 40

	private:
		DialogueItem* Ctor(TESQuest* a_quest, TESTopic* a_topic, TESTopicInfo* a_topicInfo, Actor* a_speaker);
	};
	static_assert(sizeof(DialogueItem) == 0x48);
}

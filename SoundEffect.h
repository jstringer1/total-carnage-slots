#pragma once
#include <string>

class SoundController {
public:
	SoundController();
	void playGoodLuck();
	void playBigMoney();
	void playBigPrizes();
	void playILoveIt();
	void playTotalCarnage();
private:
	bool goodluckopen = false;
	bool bigmoneyopen = false;
	bool bigprizesopen = false;
	bool iloveitopen = false;
	bool totalcarnageopen = false;
	void unpackSoundEffect(int id, const wchar_t* name);
	void openSoundEffect(const wchar_t* name);
	std::wstring getSoundEffectPath(const wchar_t* name);
	void closeanyopen();
};
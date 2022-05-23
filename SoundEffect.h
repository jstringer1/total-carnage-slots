#pragma once

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
	void loadSoundEffect(int id, const wchar_t* name);
	void closeanyopen();
};
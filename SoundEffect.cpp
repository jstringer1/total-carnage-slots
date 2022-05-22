#include "SoundEffect.h"
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")

void playBackgroundMusic() {
	mciSendString(L"open \"C:\\Users\\john.stringer\\Downloads\\Music.mp3\" type mpegvideo alias BACKGROUND_MUSIC", NULL, 0, NULL);
	mciSendString(L"play BACKGROUND_MUSIC repeat", NULL, 0, NULL);
}

bool goodluckopen = false;
bool bigmoneyopen = false;
bool bigprizesopen = false;
bool iloveitopen = false;
bool totalcarnageopen = false;

void closeanyopen() {
	if (goodluckopen) mciSendString(L"close GOOD_LUCK", NULL, 0, NULL);
	if (bigmoneyopen) mciSendString(L"close BIG_MONEY", NULL, 0, NULL);
	if (bigprizesopen) mciSendString(L"close BIG_PRIZES", NULL, 0, NULL);
	if (iloveitopen) mciSendString(L"close LOVE_IT", NULL, 0, NULL);
	if(totalcarnageopen) mciSendString(L"close TOTAL_CARNAGE", NULL, 0, NULL);
	goodluckopen = false;
	bigmoneyopen = false;
	bigprizesopen = false;
	iloveitopen = false;
	totalcarnageopen = false;
}

void playGoodLuck() {
	closeanyopen();
	mciSendString(L"open \"C:\\Users\\john.stringer\\Downloads\\GoodLuckYoullNeedIt.mp3\" type mpegvideo alias GOOD_LUCK", NULL, 0, NULL);
	mciSendString(L"play GOOD_LUCK", NULL, 0, NULL);
	goodluckopen = true;
}

void playBigMoney() {
	closeanyopen();
	mciSendString(L"open \"C:\\Users\\john.stringer\\Downloads\\BigMoney.mp3\" type mpegvideo alias BIG_MONEY", NULL, 0, NULL);
	mciSendString(L"play BIG_MONEY", NULL, 0, NULL);
	bigmoneyopen = true;
}

void playBigPrizes() {
	closeanyopen();
	mciSendString(L"open \"C:\\Users\\john.stringer\\Downloads\\BigPrizes.mp3\" type mpegvideo alias BIG_PRIZES", NULL, 0, NULL);
	mciSendString(L"play BIG_PRIZES", NULL, 0, NULL);
	bigprizesopen = true;
}

void playILoveIt() {
	closeanyopen();
	mciSendString(L"open \"C:\\Users\\john.stringer\\Downloads\\BigMoneyBigPrizesILoveIt.mp3\" type mpegvideo alias LOVE_IT", NULL, 0, NULL);
	mciSendString(L"play LOVE_IT", NULL, 0, NULL);
	iloveitopen = true;
}

void playTotalCarnage() {
	closeanyopen();
	mciSendString(L"open \"C:\\Users\\john.stringer\\Downloads\\TotalCarnage.mp3\" type mpegvideo alias TOTAL_CARNAGE", NULL, 0, NULL);
	mciSendString(L"play TOTAL_CARNAGE", NULL, 0, NULL);
	totalcarnageopen = true;
}
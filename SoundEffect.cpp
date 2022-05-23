#include "SoundEffect.h"
#include "resource.h"
#include <Windows.h>
#include <fstream>
#pragma comment(lib, "Winmm.lib")

SoundController::SoundController() {
	unpackSoundEffect(IDR_MUSIC, L"MUSIC");
	openSoundEffect(L"MUSIC");
	mciSendString(L"play MUSIC repeat", NULL, 0, NULL);

	unpackSoundEffect(IDR_BIGMONEY, L"BIG_MONEY");
	unpackSoundEffect(IDR_BIGPRIZES, L"BIG_PRIZES");
	unpackSoundEffect(IDR_CARNAGE, L"TOTAL_CARNAGE");
	unpackSoundEffect(IDR_GOODLUCK, L"GOOD_LUCK");
	unpackSoundEffect(IDR_ILOVEIT, L"LOVE_IT");
}

void SoundController::playGoodLuck() {
	openSoundEffect(L"GOOD_LUCK");
	mciSendString(L"play GOOD_LUCK", NULL, 0, NULL);
	goodluckopen = true;
}

void SoundController::playBigMoney() {
	openSoundEffect(L"BIG_MONEY");
	mciSendString(L"play BIG_MONEY", NULL, 0, NULL);
	bigmoneyopen = true;
}

void SoundController::playBigPrizes() {
	openSoundEffect(L"BIG_PRIZES");
	mciSendString(L"play BIG_PRIZES", NULL, 0, NULL);
	bigprizesopen = true;
}

void SoundController::playILoveIt() {
	openSoundEffect(L"LOVE_IT");
	mciSendString(L"play LOVE_IT", NULL, 0, NULL);
	iloveitopen = true;
}

void SoundController::playTotalCarnage() {
	openSoundEffect(L"TOTAL_CARNAGE");
	mciSendString(L"play TOTAL_CARNAGE", NULL, 0, NULL);
	totalcarnageopen = true;
}

void SoundController::closeanyopen() {
	if (goodluckopen) mciSendString(L"close GOOD_LUCK", NULL, 0, NULL);
	if (bigmoneyopen) mciSendString(L"close BIG_MONEY", NULL, 0, NULL);
	if (bigprizesopen) mciSendString(L"close BIG_PRIZES", NULL, 0, NULL);
	if (iloveitopen) mciSendString(L"close LOVE_IT", NULL, 0, NULL);
	if (totalcarnageopen) mciSendString(L"close TOTAL_CARNAGE", NULL, 0, NULL);
	goodluckopen = false;
	bigmoneyopen = false;
	bigprizesopen = false;
	iloveitopen = false;
	totalcarnageopen = false;
}

void SoundController::openSoundEffect(const wchar_t* name) {
	closeanyopen();
	wchar_t command[1024];
	swprintf_s(command, 1024, L"open \"%s\" type mpegvideo alias %s", getSoundEffectPath(name).c_str(), name);
	mciSendString(&command[0], NULL, 0, NULL);
}

void SoundController::unpackSoundEffect(int id, const wchar_t* name) {
	HRSRC res = FindResource(NULL, MAKEINTRESOURCE(id), RT_RCDATA);
	char* data = (char*)LockResource(LoadResource(NULL, res));
	DWORD size = SizeofResource(NULL, res);

	std::ofstream out;
	out.open(getSoundEffectPath(name).c_str(), std::ios::binary | std::ios::out);
	out.write(data, size);
	out.close();
}

std::wstring SoundController::getSoundEffectPath(const wchar_t* name) {
	wchar_t path[MAX_PATH];
	GetTempPath(MAX_PATH, path);
	wchar_t fullpath[MAX_PATH];
	swprintf_s(fullpath, MAX_PATH, L"%s%s.mp3", path, name);
	return std::wstring(fullpath);
}
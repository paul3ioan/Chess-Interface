// Exemplu program parinte, care lanseaza copilul si comunica cu el (in cazul nostru GUI-ul)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Subprocess.h"
/*
int main()
{
	//Windows test
	//const char* cmd[] = { R"(C:\Users\teodo\source\repos\RandomProjects\x64\Debug\TestProgram.exe)", nullptr };
	//
	//Linux test
	const char* cmd[] = { R"(../TestProgram/main)", nullptr };
	Utlils::Subprocess proc(cmd);
	char s[100];
	proc.read(s);
	std::cout << s << '\n';
	proc.write("%d %s\n", 3, "georgell");
	proc.read(s);
	std::cout << s << '\n';
	proc.read(s);
	std::cout << s << '\n';
	return 0;
}*/
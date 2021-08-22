#ifndef SUBPROCESS_H_INCLUDED
#define SUBPROCESS_H_INCLUDED

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdarg>

#include "subproc_lib.h"

namespace Utlils
{
	class Subprocess
	{
		subprocess_s proc;
		FILE* proc_stdin;
		FILE* proc_stdout;
		FILE* proc_stderr;

	public:
		// cmd[0] -> procesul
		// cmd[1...] -> argumentele
		// ultimul element obligatoriu nullptr
		Subprocess(const char* cmd[])
		{
			int res = subprocess_create(cmd, subprocess_option_enable_async, &proc);
			if (res)
				throw "Error creating process";
			proc_stdin = subprocess_stdin(&proc);
			proc_stdout = subprocess_stdout(&proc);
			proc_stderr = subprocess_stderr(&proc);
		}

		Subprocess(const Subprocess&) = delete;
		Subprocess(Subprocess&&) = delete;

		// cand stim cat vrem sa citim dam buffer + size
		// cand nu stim cat vrem sa citim, lasam size default si se va citi pana la '\n'
		void read(char* buffer, int size = -1)
		{
			if (size != -1)
				subprocess_read_stdout(&proc, buffer, size);
			else
			{
				int pos = 0;
				char c;
				subprocess_read_stdout(&proc, &c, 1);
				while (c != '\n')
				{
					//pos++;
					buffer[pos++] = c;
					subprocess_read_stdout(&proc, &c, 1);
				}
//				buffer[pos++] = 'a';
				buffer[pos] = '\0';
			}
		}

		void write(const char* format, ...)
		{
			va_list arglist;
			va_start(arglist, format);
			vfprintf(proc_stdin, format, arglist);
			fprintf(proc_stdin, "\n");
			fflush(proc_stdin);
			va_end(arglist);
		}

		~Subprocess()
		{
			subprocess_destroy(&proc);
		}
	};
}

#endif


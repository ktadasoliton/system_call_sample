  // Copyright 2018 Kota Tada
#include "systemcall/system_call.h"
#include <windows.h>
#include <stdio.h>
#include <string>

void FileWrite(std::string event_message) {
  FILE *fp;
  errno_t err_no;
  std::string path = "system_call_out.txt";

  err_no = fopen_s(&fp, path.c_str(), "a");
  if (err_no == 0) {
    fprintf(fp, event_message.c_str());
    fclose(fp);
  }
}

BOOL CtrlHandler(DWORD fdwCtrlType) {
  std::string message;
  switch (fdwCtrlType) {
  case CTRL_C_EVENT:
    message = "Ctrl-C event\n";
    printf("%s", message.c_str());
    FileWrite(message);
    return TRUE;
  case CTRL_CLOSE_EVENT:
    message = "Ctrl-Close event\n";
    printf("%s", message.c_str());
    FileWrite(message);
    return TRUE;
  case CTRL_BREAK_EVENT:
    message = "Ctrl-Break event\n";
    printf("%s", message.c_str());
    FileWrite(message);
    return TRUE;
  case CTRL_LOGOFF_EVENT:
    message = "Ctrl-Logoff event\n";
    printf("%s", message.c_str());
    FileWrite(message);
    return TRUE;
  case CTRL_SHUTDOWN_EVENT:
    message = "Ctrl-Shutdown event\n";
    printf("%s", message.c_str());
    FileWrite(message);
    return TRUE;
  default:
    return FALSE;
  }
}

int main(void) {
  if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE) == FALSE) {
    printf("faild set CtrlHandler\n");
  }

  while (1) {
    printf("main is Working...\n");
    Sleep(1000);
  }
}

  // Copyright 2018 Kota Tada
#include "systemcall/system_call.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

void FileWrite(std::string message) {
  FILE *fp;
  errno_t err_no;
  std::string path = "system_call_out.txt";
  if ((fp = fopen(path.c_str(), "a")) != NULL) {
    fprintf(fp, "%s", message.c_str());
    fclose(fp);
  }
}

void SignalHandler(int signal_value) {
  std::string message, value;
  switch (signal_value) {
  case SIGINT:
    message = "catch signal SIGINT";
    printf("%s\n", message.c_str());
    FileWrite(message+"\n");
    break;
  case SIGHUP:
    message = "catch signal SIGHUP";
    printf("%s\n", message.c_str());
    FileWrite(message+"\n");
    break;
  case SIGQUIT:
    message = "catch signal SIGQUIT";
    printf("%s\n", message.c_str());
    FileWrite(message+"\n");
    break;
  case SIGABRT:
    message = "catch signal SIGABRT";
    printf("%s\n", message.c_str());
    FileWrite(message+"\n");
    break;
  case SIGKILL:
    message = "catch signal SIGKILL";
    printf("%s\n", message.c_str());
    FileWrite(message+"\n");
    break;
  case SIGTERM:
    message = "catch signal SIGTERM";
    printf("%s\n", message.c_str());
    FileWrite(message+"\n");
    break;
  }
}

void SetSignal() {
  signal(SIGINT, SignalHandler);
  signal(SIGHUP, SignalHandler);
  signal(SIGQUIT, SignalHandler);
  signal(SIGABRT, SignalHandler);
  signal(SIGKILL, SignalHandler);
  signal(SIGTERM, SignalHandler);
  return;
}

int main(void) {
  SetSignal();
  while (1) {
    printf("main is Working...\n");
    sleep(1);
  }
}

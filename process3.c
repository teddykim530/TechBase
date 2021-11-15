#include <iostream>
#include <cstring>
#include <cstdlib>
#include <proc/readproc.h>

using std::cout;

int main()
{
  PROCTAB* proc = openproc(PROC_FILLMEM | PROC_FILLSTAT | PROC_FILLSTATUS);

  proc_t proc_info;
  memset(&proc_info, 0, sizeof(proc_info));
  cout << "Program\tPID\tPPID\tMEM\tutime\tstime\n";
  while (readproc(proc, &proc_info) != NULL) {
      cout << proc_info.cmd << "\t" << proc_info.tid;
      cout << proc_info.ppid << "\t" << proc_info.resident;
      cout << proc_info.utime << "\t" << proc_info.stime << "\n";
  }

  closeproc(proc);

  return 0;
}

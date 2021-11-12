#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h>

void hardware_info() 
{
        struct utsname un;
        struct sysinfo sys;

        if(sysinfo(&sys) < 0) {
                fprintf(stderr, "sysinfo() function error.\n");
                exit(1);
        }
        fprintf(stdout, "\tHardware information \n");
        fprintf(stdout, "===================================== \n");
        fprintf(stdout,
                        "업타임: %ld days\n"
                        "메모리 총계: %ld KB\n"
                        "사용가능 메모리: %ldKB\n"
                        "현재 프로세스 갯수: %d\n"
                        "CPU 갯수: %d\n\n",
                        ((sys.uptime/60)/60)/24, sys.totalram/1024, sys.freeram/1024,
                        sys.procs, get_nprocs_conf());

        if(uname(&un) < 0) {
                fprintf(stderr, "uname() function error.\n");
                exit(1);
        }
        fprintf(stdout,
                        "시스템 이름: %s\n"
                        "노드명: %s\n"
                        "커널버전: %s\n"
                        "릴리즈버전: %s\n"
                        "프로세서타입: %s\n",
                        un.sysname, un.nodename, un.release, un.version, un.machine);
}

void process_info()
{  
   fprintf(stdout, "\tProcess information \n");
   fprintf(stdout, "===================================== \n");
   int r=system("ps");   
}

void file_info()
{
	fprintf(stdout, "\tfile list information \n");
   	fprintf(stdout, "===================================== \n");
	DIR *dir;
	struct dirent *ent;
	dir = opendir("./");
	if(dir)
	{
		while (ent = readdir (dir))
		printf("%s\n", ent->d_name);
	}
	closedir(dir);
}

void network_info()
{
	fprintf(stdout, "\tnetwork information \n");
   	fprintf(stdout, "===================================== \n");
	struct ifreq ifr;
	char ipstr[40];
	int s;
	
	s = socket(AF_INET, SOCK_DGRAM, 0);
	strncpy(ifr.ifr_name, "enp0s3", IFNAMSIZ);
	
	if(ioctl(s, SIOCGIFADDR, &ifr) < 0) 
		printf("no network");
	
	inet_ntop(AF_INET, ifr.ifr_addr.sa_data+2, ipstr, sizeof(struct sockaddr));
	
	printf("IP Address : %s\n", ipstr);
}


int main(void)
{
		hardware_info();
		fprintf(stdout, "\n===================================== \n");
		process_info();
		fprintf(stdout, "\n===================================== \n");
		file_info();
		fprintf(stdout, "\n===================================== \n");
		network_info();
}

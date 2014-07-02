#include <stdio.h>
#include <string.h>

long long int s_boot_time() {
	
	char buf[1024], bbuf[1024];
	FILE *f = NULL;
	char *path = "/proc/stat";
	long long int btime;

	f = fopen(path, "r");

        while (f && fgets(buf, sizeof(buf), f) != NULL) {
                if (strstr(buf, "btime")) {
                        strtok(buf, "\n");
                        snprintf(bbuf, sizeof(bbuf), "%s", buf);
                }
        }
        if (f)
                fclose(f);

	sscanf(bbuf, "btime %lld", &btime); 

	return btime;
}

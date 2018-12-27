#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <switch.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

char* MainPath = "/themes/hbshuffle/";
int folders = 1, GenRand = 1;
bool loop = true;

FILE *fp;
char buff[255];

void Write3var(const char* Var1, const int Var2, const char* Var3){
fp = fopen("/themes/hbshuffle/temp.txt", "w");
fprintf(fp, "%s%d%s", Var1, Var2, Var3);
fclose(fp);
}

void Write2var(const char* Var1, const int Var2){
fp = fopen("/themes/hbshuffle/temp.txt", "w");
fprintf(fp, "%s%d", Var1, Var2);
fclose(fp);
}

void copy(const char* src, const char* dst)
{
    FILE* in = fopen(src, "rb");
    FILE* out = fopen(dst, "wb");
    if(in == NULL || out == NULL)
    {
        printf("An error occured");
    }
    else
    {
        size_t len = 0;
        char buffer[BUFSIZ];
        while((len = fread(buffer, 1, BUFSIZ, in)) > 0)
        {
            fwrite(buffer, 1, len, out);
        }
    }
    if(in)
        fclose(in);
    if(out)
        fclose(out);
}

int foldertest(const char* Path){
	DIR* dir = opendir(Path);
if (dir) {
	closedir(dir);
	return 0;
}

else if (ENOENT == errno) {
/* Directory does not exist. */
	return -1;
}
else {
	return -2;
} }

int boundRand(int min, int max){
	int delta = max - min;
	int randd = rand();
	int x = randd % delta;
	return (x+min); } 

void txttobuff(){
fp = fopen("/themes/hbshuffle/temp.txt", "r");
   	fgets(buff, 255, (FILE*)fp);
   	fclose(fp);
}



int main(int argc, char **argv)
{
	consoleInit(NULL);
    srand(time(0));


    printf("\x1b[32m-- Theme Randomiser - By Such Meme, Many Skill --\x1b[0m");
    printf("\n//This code is retarded it supports the apache flight-helicopter community\n\n");

    printf("Doing init: Please wait\n");

  	while(loop){
   	Write2var("/themes/hbshuffle/", folders);

   	txttobuff();

   	printf("\rCurrent folder amount: %d", folders);

   	if (foldertest(buff) == 0) folders++;
   	if (foldertest(buff) == -1){ folders = folders-1; printf("\r\x1b[31mEnd Of folders, Final foldercount: %d\x1b[0m", folders); break;}
   	if (foldertest(buff) == -2){ printf("\rSomething went wrong!"); break;}
    }

    folders = folders + 1;

    GenRand = boundRand(1, folders);
    printf("\nRandom number between folders: %d\n", GenRand);

    printf("\x1b[32mReady!\n\n");
    printf("\x1b[33mInstalling Folder %d\n", GenRand);
    
    Write3var(MainPath, GenRand, "/ResidentMenu.szs");
    txttobuff();

    consoleUpdate(NULL);

    if (access(buff, F_OK ) != -1){
    	printf("\x1b[32mResidentmenu found! Copying...\n");
    	copy(buff, "/atmosphere/titles/0100000000001000/romfs/lyt/ResidentMenu.szs");
    }
    else printf("\x1b[31mResidentmenu Missing!\n");

    Write3var(MainPath, GenRand, "/Entrance.szs");
    txttobuff();

    consoleUpdate(NULL);

    if (access(buff, F_OK ) != -1){
    	printf("\x1b[32mEntrance found! Copying...\n");
    	copy(buff, "/atmosphere/titles/0100000000001000/romfs/lyt/Entrance.szs");
    }
    else printf("\x1b[31mEntrance Missing!\n");

    Write3var(MainPath, GenRand, "/common.szs");
    txttobuff();

    consoleUpdate(NULL);

    if (access(buff, F_OK ) != -1){
    	printf("\x1b[32mCommon found! Copying...\n");
    	copy(buff, "/atmosphere/titles/0100000000001000/romfs/lyt/common.szs");
    }
    else printf("\x1b[31mCommon Missing!\n");

    Write3var(MainPath, GenRand, "/Set.szs");
    txttobuff();

    consoleUpdate(NULL);

    if (access(buff, F_OK ) != -1){
    	printf("\x1b[32mSet found! Copying...\n");
    	copy(buff, "/atmosphere/titles/0100000000001000/romfs/lyt/Set.szs");
    }
    else printf("\x1b[31mSet Missing!\n");

    Write3var(MainPath, GenRand, "/FLaunch.szs");
    txttobuff();

    consoleUpdate(NULL);

    if (access(buff, F_OK ) != -1){
    	printf("\x1b[32mFlaunch found! Copying...\n");
    	copy(buff, "/atmosphere/titles/0100000000001000/romfs/lyt/FLaunch.szs");
    }
    else printf("\x1b[31mFlaunch Missing!\n");

    consoleUpdate(NULL);

    printf("\n\x1b[34mDone! Press + to exit!");
    while(appletMainLoop())
    {
    	hidScanInput();
    	u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
    	if (kDown & KEY_PLUS) break;
    	consoleUpdate(NULL); }

    consoleExit(NULL);
    return 0;
}
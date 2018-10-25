#include <dirent.h>
#include <w32api/rpc.h>
#include <fakesu/sys/stat.h>
//windows system libs

int main() {

    char* folder_loc = "./tmp/";
    DIR* root_dir = opendir("./tmp");
    if (root_dir == NULL) return (ERROR);

    struct dirent* entry;
    struct stat* stat;

    while ((entry = readdir(root_dir)) != NULL) {


        char* entry_name = entry->d_name;
        char* entry_address;
        entry_address = malloc(strlen(folder_loc)+strlen(entry_name)+1);
        strcpy(entry_address, folder_loc);
        strcat(entry_address, entry_name);

        stat(entry_address, stat);

        unsigned short i_node_count = (unsigned short) stat->st_nlink;
        if (i_node_count >= 2) {
            //???
        }
    }

}
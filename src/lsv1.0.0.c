/*
* Programming Assignment 02: lsv1.1.0
* Feature Added: -l (Long Listing Format)
* Extends ls-v1.0.0 while preserving the base functionality.
*/
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>   // <-- For mode_t
#include <sys/stat.h>    // <-- For lstat, struct stat
#include <pwd.h>         // <-- For getpwuid()
#include <grp.h>         // <-- For getgrgid()
#include <time.h>        // <-- For time formatting
#include <getopt.h>      // <-- For getopt()

extern int errno;

/* --- Function Prototypes --- */
void do_ls(const char *dir, int long_format);
void print_long_listing(const char *dir);
void print_permissions(mode_t mode);

/* -------------------- main() -------------------- */
int main(int argc, char const *argv[])
{
    int long_format = 0;
    int opt;

    // Parse -l option using getopt
    while ((opt = getopt(argc, (char * const *)argv, "l")) != -1)
    {
        switch (opt)
        {
        case 'l':
            long_format = 1;
            break;
        default:
            fprintf(stderr, "Usage: %s [-l] [directory...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    // No directory provided → list current directory
    if (optind == argc)
    {
        do_ls(".", long_format);
    }
    else
    {
        for (int i = optind; i < argc; i++)
        {
            printf("Directory listing of %s : \n", argv[i]);
            do_ls(argv[i], long_format);
            puts("");
        }
    }

    return 0;
}

/* -------------------- do_ls() -------------------- */
void do_ls(const char *dir, int long_format)
{
    if (long_format)
        print_long_listing(dir);
    else
    {
        struct dirent *entry;
        DIR *dp = opendir(dir);
        if (dp == NULL)
        {
            fprintf(stderr, "Cannot open directory : %s\n", dir);
            return;
        }

        errno = 0;
        while ((entry = readdir(dp)) != NULL)
        {
            if (entry->d_name[0] == '.')
                continue;
            printf("%s\n", entry->d_name);
        }

        if (errno != 0)
        {
            perror("readdir failed");
        }

        closedir(dp);
    }
}

/* -------------------- print_permissions() -------------------- */
void print_permissions(mode_t mode)
{
    char perms[11];
    perms[0] = S_ISDIR(mode) ? 'd' : '-';
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';
    perms[10] = '\0';
    printf("%s ", perms);
}

/* -------------------- print_long_listing() -------------------- */
void print_long_listing(const char *dir)
{
    struct dirent *entry;
    DIR *dp = opendir(dir);
    if (dp == NULL)
    {
        fprintf(stderr, "Cannot open directory : %s\n", dir);
        return;
    }

    errno = 0;
    char path[1024];
    struct stat sb;

    while ((entry = readdir(dp)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;

        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

        if (lstat(path, &sb) == -1)
        {
            perror("stat");
            continue;
        }

        // Permissions
        print_permissions(sb.st_mode);

        // Link count
        printf("%2ld ", sb.st_nlink);

        // Owner and group
        struct passwd *pw = getpwuid(sb.st_uid);
        struct group *gr = getgrgid(sb.st_gid);
        printf("%-8s %-8s ", pw ? pw->pw_name : "?", gr ? gr->gr_name : "?");

        // File size
        printf("%8ld ", sb.st_size);

        // Modification time
        char timebuf[64];
        struct tm *tm_info = localtime(&sb.st_mtime);
        strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", tm_info);
        printf("%s ", timebuf);

        // File name
        printf("%s\n", entry->d_name);
    }

    if (errno != 0)
    {
        perror("readdir failed");
    }

    closedir(dp);
}

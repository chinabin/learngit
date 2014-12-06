#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define BUFFER    1024
Elf32_Ehdr *ehdr = NULL;
Elf32_Phdr *phdr = NULL;
Elf32_Shdr *shdr = NULL;
Elf32_Shdr        *shstrtab = NULL;
Elf32_Sym        *dynsym_ptr = NULL;
Elf32_Sym *symtab_ptr = NULL;
Elf32_Sym        *dynstr_ptr = NULL;
struct stat elf_stat;

void elf_header(char *elf_file)
{
    int fd = open(elf_file,O_RDWR);
    if( fd == -1 )
    {
        perror("elf_file");
        exit(1);
    }
    if( fstat(fd,&elf_stat) == -1 )
    {
        perror("fstat");
        exit(1);
    }
    ehdr = mmap(0, elf_stat.st_size, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    if(ehdr == MAP_FAILED)
    {
        perror("mmap ehdr");
        return;
    }

    phdr = (Elf32_Phdr *)( (unsigned long)ehdr + ehdr->e_phoff );
    shdr = (Elf32_Shdr *)( (unsigned long)ehdr + ehdr->e_shoff );

    Elf32_Shdr tmp;
    int i =3;
    while( i >= 0)
    {
        memcpy(&tmp , shdr , 40);
        printf("%s\n" , tmp.sh_name);
        shdr++;
        i--;
    }
}

int main()
{
    elf_header("FileRead.o");
    return 0;
}

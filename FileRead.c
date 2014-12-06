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
int                shstrtab_off,shstrtab_len,shstrtab_num;
char            *Real_strtab = NULL;
char            *dynstr = NULL;
char            *strtab_ptr = NULL;
char            buffer[BUFFER];

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

    // get section string location
    shstrtab = &shdr[ehdr->e_shstrndx];
    // from section get real string table location
    shstrtab_off = (unsigned int)shstrtab->sh_offset;
    // get string table size
    shstrtab_len = shstrtab->sh_size;
    // endr is base address , and shstrtab_off is offset address
    Real_strtab = (char *)( (unsigned long)ehdr + shstrtab_off );
    memcpy(buffer,Real_strtab,shstrtab_len + 1);

    int i = 0;
    printf("[num]     name          from     to     size\n");
    while( i < ehdr->e_shnum )
    {
        printf(" %2d%-10s%-24d%-33d%-40d\n" ,i , buffer + (shdr + i)->sh_name,(shdr+i)->sh_offset , (shdr+i)->sh_offset , (shdr+i)->sh_size );
        i++;
    }
}

int main()
{
    elf_header("FileRead.o");
    return 0;
}

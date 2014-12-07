/*
    ELF Reader V 0.1.0 Show ELF Information
    by wzt 
*/
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
    
char            *Real_strtab = NULL;
char            *dynstr = NULL;
char            *strtab_ptr = NULL;
char            buffer[BUFFER];
    
int phdr_len;
int shdr_len;
int                shstrtab_off,shstrtab_len,shstrtab_num;
int fd;
int                flag_h = 0;
int                flag_s = 0;
void usage(char *pro);
void elf_header(char *elf_file);
void elf_phdr();
void elf_shdr();
void elf_symbols();
void usage(char *pro)
{
    fprintf(stdout,"Relf V 0.1.0 by wzt    \r\n\n");
    fprintf(stdout,"usage:%s  \r\n\n",pro);
    fprintf(stdout,":\r\n");
    fprintf(stdout,"-h ELF Header Info\n");
    fprintf(stdout,"-p ELF Program Header Info\n");
    fprintf(stdout,"-s ELF Section Header Info\n");
    fprintf(stdout,"-S ELF Symbols Info\n\n");
    exit(0);
}
void elf_header(char *elf_file)
{
    fd = open(elf_file,O_RDWR);
    if( fd == -1 ){
        perror("elf_file");
        exit(1);
    }
    if( fstat(fd,&elf_stat) == -1 ){
        perror("fstat");
        exit(1);
    }
    ehdr = mmap(0, elf_stat.st_size, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    if(ehdr == MAP_FAILED) {
        perror("mmap ehdr");
        goto err;
    }
    if(ehdr->e_ident[EI_MAG0] != 0x7f
    || ehdr->e_ident[EI_MAG1] != 'E'
    || ehdr->e_ident[EI_MAG2] != 'L'
    || ehdr->e_ident[EI_MAG3] != 'F'
    || ehdr->e_ident[EI_CLASS] != ELFCLASS32
    || ehdr->e_ident[EI_DATA] != ELFDATA2LSB
    || ehdr->e_ident[EI_VERSION] != EV_CURRENT
    || ehdr->e_type != ET_EXEC
    || ehdr->e_machine != EM_386
    || ehdr->e_version != EV_CURRENT
    ) {
    
        printf("File type not supported\n");
        goto err;
    }        
    phdr = (Elf32_Phdr *)( (unsigned long)ehdr + ehdr->e_phoff );
    shdr = (Elf32_Shdr *)( (unsigned long)ehdr + ehdr->e_shoff );
/* ELF Header Info */
    if( flag_h == 1 ){
    fprintf(stdout,"\n[+] ELF Header Info:\n\n");
    fprintf(stdout,"Magic : %s\n",
                    ehdr->e_ident);
    fprintf(stdout,"Type : %d\n",
                    ehdr->e_type);
    fprintf(stdout,"Machine : %d\n",
                    ehdr->e_machine);
    fprintf(stdout,"Version : %d\n",
                    ehdr->e_version);
    fprintf(stdout,"Entry point address : 0x%x\n",
                    ehdr->e_entry);
    fprintf(stdout,"Start of program headers : %d ( 0x%x )\n",
                    ehdr->e_phoff,ehdr->e_phoff);
    fprintf(stdout,"start of section headers : %d ( 0x%x )\n",
                    ehdr->e_shoff,ehdr->e_shoff);
    fprintf(stdout,"Flags : %d\n",
                    ehdr->e_flags);
    fprintf(stdout,"Size of this header : %d\n",
                    ehdr->e_ehsize);
    fprintf(stdout,"Size of program headers : %d\n",
                    ehdr->e_phentsize);
    fprintf(stdout,"Number of program headers : %d\n",
                    ehdr->e_phnum);
    fprintf(stdout,"Size of section headers : %d\n",
                    ehdr->e_shentsize);
    fprintf(stdout,"Number of section headers : %d\n",
                    ehdr->e_shnum);
    fprintf(stdout,"Section header string table index : %d (0x%x)\n\n",
                    ehdr->e_shstrndx,ehdr->e_shstrndx);
    err:
    if (ehdr)
        munmap(ehdr, elf_stat.st_size);
    if (fd != -1)
        close(fd);
    }
}
/* ELF Program Header Table Info */
void elf_phdr()
{
    int i;
    fprintf(stdout,"\n[+] ELF Program Header Table Info:\n\n");
    fprintf(stdout,"Type Offset VirtAddr PhysAddr FileSiz MemSiz Flg Align\r\n");
    for(i = 0 ; i < ehdr->e_phnum ; i++){
        fprintf(stdout,"0x%06x 0x%08x 0x%08x 0x%08x 0x%06x 0x%06x 0x%02x 0x%02x\r\n",
                        phdr->p_type,
                        phdr->p_offset,
                        phdr->p_vaddr,
                        phdr->p_paddr,
                        phdr->p_filesz,
                        phdr->p_memsz,
                        phdr->p_flags,
                        phdr->p_align);
    }
    printf("\n");
    err:
    if (ehdr)
        munmap(ehdr, elf_stat.st_size);
    if (fd != -1)
        close(fd);
}
/* ELF Section Header Table Info */
void elf_shdr()
{
    int        i;
    shstrtab = &shdr[ehdr->e_shstrndx];
    shstrtab_off = (unsigned int)shstrtab->sh_offset;
    shstrtab_len = shstrtab->sh_size;
    Real_strtab = (char *)( (unsigned long)ehdr + shstrtab_off );
    memcpy(buffer,Real_strtab,shstrtab_len + 1);
    if( flag_s == 1 ){
        fprintf(stdout,"\n[+] ELF Section Header Table Info:\n\n");
        fprintf(stdout,"[NR] Name     Type Flag Addr Off Size Link Info Ali Ent\n");
        shdr_len = ehdr->e_shoff;
        for(i = 0 ; i < ehdr->e_shnum ; i++){
            fprintf(stdout,"[%2d] %-15s %d 0x%02x 0x%08x 0x%06x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\r\n",
                        i,
                        buffer + shdr->sh_name,
                        shdr->sh_type,
                        shdr->sh_flags,
                        shdr->sh_addr,
                        shdr->sh_offset,
                        shdr->sh_size,
                        shdr->sh_link,
                        shdr->sh_info,
                        shdr->sh_addralign,
                        shdr->sh_entsize);
        }
    
        printf("\n");
        err:
        if (ehdr)
            munmap(ehdr, elf_stat.st_size);
        if (fd != -1)
            close(fd);
    }
}
/* ELF Symbols Info */
void elf_symbols()
{
    char dynstr_buffer[2048];
    char strtab_buffer[4096];
    int symtab_off,symtab_num;
    int dynsym_off,dynsym_size,dynsym_num;
    int dynstr_off,dynstr_size;
    int i;
    unsigned int strtab_off,strtab_size;
    for(i = 0 ; i < (int)ehdr->e_shnum ; i++){
        if( strcmp(buffer + shdr->sh_name,".symtab") == 0 ){
            symtab_off = (unsigned int)shdr->sh_offset;
            symtab_num = (int )(shdr->sh_size / shdr->sh_entsize);
            printf("[+] .symtab off : 0x%x num :%d\n",symtab_off,symtab_num);
        }
        if( strcmp(buffer + shdr->sh_name,".strtab") == 0){
            strtab_off = (unsigned int)shdr->sh_offset;
            strtab_size = (unsigned int)shdr->sh_size;
            printf("[+] .strtab off : 0x%x num : %d\n",strtab_off,strtab_size);
        }
          if( strcmp(buffer + shdr->sh_name,".dynsym") == 0 ){
            dynsym_off = shdr->sh_offset;
            dynsym_size = shdr->sh_size;
            dynsym_num = (int)(shdr->sh_size / shdr->sh_entsize);
            printf("[+] .dynsym Off: 0x%x num : %d\n",dynsym_off,dynsym_num);
        }        
        if( strcmp(buffer + shdr->sh_name,".dynstr") == 0 ){
            dynstr_off = (unsigned int)shdr->sh_offset;
            dynstr_size = (unsigned int)shdr->sh_size;
            printf("[+] .dynstr Off: 0x%x size : %d\n",dynstr_off,dynstr_size);
        }
    }
    strtab_ptr = (char *)( (unsigned long)ehdr + strtab_off );
    
    memcpy(strtab_buffer,strtab_ptr,strtab_size + 1);
    symtab_ptr = (Elf32_Sym *)( (unsigned long)ehdr + symtab_off );
    fprintf(stdout,"[NR]        st_name         st_value st_size st_info     st_shndx\n");
    for(i = 0; i < symtab_num; i++){
        fprintf(stdout,"%4d    %25s    0x%08x x%08x 0x%02x %4d\n",
                i,
                strtab_buffer + symtab_ptr->st_name,
                symtab_ptr->st_value,
                symtab_ptr->st_size,
                symtab_ptr->st_info,
                symtab_ptr->st_shndx);
    }

    dynsym_ptr = (Elf32_Sym *)( (unsigned long)ehdr + dynsym_off );
    dynstr = (char *)( (unsigned long)ehdr + dynstr_off );
    
    memcpy(dynstr_buffer,dynstr,dynstr_size+1);
    err:
    if (ehdr)
        munmap(ehdr, elf_stat.st_size);
    if (fd != -1)
        close(fd);
}
int main(int argc,char **argv)
{
    if( argc !=  3 ){
        usage(argv[0]);
    }
    if( !strcmp(argv[1],"-h") ){
        flag_h = 1;
          elf_header(argv[2]);
    }
    else if( !strcmp(argv[1],"-p") ){
        elf_header(argv[2]);
        elf_phdr();
    }
    else if( !strcmp(argv[1],"-s") ){
        flag_s = 1;
        elf_header(argv[2]);
        elf_shdr();
    }
    else if( !strcmp(argv[1],"-S") ){
        elf_header(argv[2]);
        elf_shdr();
         elf_symbols();
    }
    else{
        printf("\n[-] Bad options\n\n");
    }
    return 0;
}

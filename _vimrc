"���ò�������
set nocompatible
"���ļ����ⲿ���޸ĵ�ʱ���Զ�����
set autoread
"�ڲ��ҵ�ʱ����Դ�Сд
set ignorecase
"ֻ��ƥ��
set smartcase
"��ʾ�����������
set showcmd
"�����ļ����к�
set nu
"Ϊɫ������ solarized ����Ҫ��
"�����﷨����
syntax enable
set background=dark
"colorscheme solarized
colorscheme MountainDew
"colorscheme molokai
"����״̬������ɫ
"highlight StatusLine guifg=SlateBlue guibg=Yellow 
"������ʾƥ�������
set showmatch
"������ʷ��¼��Ŀ
set history=1000
"���ò���Ҫ�����ļ�
set nobackup
setlocal noswapfile
"������ģʽ��ʹ��tab�Զ���ȫ��ʱ�򣬽���ȫ�����ò˵�����ʽ��ʾ����
set wildmenu
"��ʾ���½ǵ�״̬��
set ruler
"������а�
set clipboard+=unnamed
"������ʾ�������
set hlsearch
"ʵʱ��ʾ�������
set incsearch
"ʹ�ù����������������Ļ���˻��ߵͶ�5��
set scrolloff=5
"��겻��˸
set novisualbell
"�Զ�ƥ�䣬ֻ��ƥ�䣬C���Է���ƥ��
set autoindent
set smartindent
set cindent
"�����������
"����һ��tab��Ӧ4���ո�
set tabstop=4
"�ڰ��˸����ʱ�����ǰ�����ĸ��ո���һ��ɾ��
set softtabstop=4
"��������
set shiftwidth=4
"����tab
set smarttab
set expandtab
"��Ҫ��tab������ʾ����
set nolist
"ȥ��toolbar
set go=
"�����һ����������δ��ɵ����Ѿ�������β��ʱ���Զ�����ĵ���������ʾ������
set wrap
set linebreak
"����״̬������ʾ��Ϣ
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [ASCII=\%03.3b]\ [HEX=%02.2B]\ [POS=%04l,%04v]\ [%p%%]\ [LEN=%L]
"ͨ��ʹ��: commands������������ļ�����һ�б��ı�� 
set report=0
"�ڱ��ָ�Ĵ��ڼ���ʾ�հף������Ķ� 
set fillchars=vert:\ ,stl:\ ,stlnc:\ 

"��������
"set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
"set termencoding=utf-8
"set encoding=utf-8

"������ʾ��ǰ��
set cursorline
hi CursorLine cterm=NONE   ctermbg=DarkRed ctermfg=White
hi CursorColumn cterm=NONE ctermbg=DarkRed ctermfg=White
"ͬ��Ŀ��һ������Ȼ��ֻ��һ���ļ���ʱ���ܿ�����ǰ�и���
set laststatus=2

    "********************************************************************
    "*                                                                  *
    "*                      MY_MAP                                      *
    "*                                                                  *
    "********************************************************************
"my map
let mapleader = ","
"���뵱ǰ���ļ�����Ŀ¼
nmap <leader>cd :cd %:h<cr>
"�ı�Y����
nnoremap Y y$
"change to light background
nmap <leader>l :set background=light<cr>
nmap <leader>d :set background=dark<cr>

nnoremap <leader>ev :vsplit $MYVIMRC<cr>
nnoremap <leader>sv :source $MYVIMRC<cr>

"C Compiler and Run
map <F5> :call CompileRunGcc()<CR> 
func! CompileRunGcc() 
    exec "w" 
    exec "!gcc % -o %<" 
    exec "!./%<" 
endfunc 

"ȥ��������Ĺ���
nnoremap <UP> <NOP>
nnoremap <DOWN> <NOP>
nnoremap <LEFT> <NOP>
nnoremap <RIGHT> <NOP>

inoremap <UP> <NOP>
inoremap <DOWN> <NOP>
inoremap <LEFT> <NOP>
inoremap <RIGHT> <NOP>

nnoremap <F4> :noh<cr>

"��һ��̫����ʾ���е�ʱ����Ȼ���߼��Ͽ����������ƶ�
map <A-UP> gk
map <A-DOWN> gj


    "********************************************************************
    "*                                                                  *
    "*                      pathogen                                    *
    "*                                                                  *
    "********************************************************************
execute pathogen#infect()
"������ָ���﷨������ɫ�����滻Ĭ�Ϸ���
syntax on
filetype plugin indent on
"�����ļ��������
filetype on

    "********************************************************************
    "*                                                                  *
    "*                      Ctags                                       *
    "*                                                                  *
    "********************************************************************
nnoremap <c-F7>  :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<cr>
set tags=tags;

    "********************************************************************
    "*                                                                  *
    "*                      TagList                                     *
    "*                                                                  *
    "********************************************************************
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_Ctags_Cmd='C:\Users\Nibnat\ctags'
let Tlist_WinWidth=50
let Tlist_Use_Right_Window=1
"let Tlist_Close_On_Select=1
"let Tlist_GainFocus_On_ToggleOpen=1

nnoremap <F3> :TlistToggle<cr>

    "********************************************************************
    "*                                                                  *
    "*                      NERDTree                                    *
    "*                                                                  *
    "********************************************************************
nnoremap <F2> :NERDTreeToggle<cr>

    "********************************************************************
    "*                                                                  *
    "*                   MiniBufExplorer                                *
    "*                                                                  *
    "********************************************************************
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapWindowNavArrows = 1
let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplModSelTarget = 1

nnoremap <F9> :TMiniBufExplorer<cr>

    "********************************************************************
    "*                                                                  *
    "*                         a                                        *
    "*                                                                  *
    "********************************************************************
nnoremap <leader>ih :IHS<cr>
nnoremap <leader>is :AS<cr>

    "********************************************************************
    "*                                                                  *
    "*                        CtrlP                                    *
    "*                                                                  *
    "********************************************************************
let g:ctrlp_map=',,'
let g:ctrlp_cmd='CtrlP'
let g:ctrlp_working_path_mode=0
let g:ctrlp_by_filename = 1

nnoremap <leader>tt :!kdiff3 % C:\Users\Nibnat\Desktop\xixi\_vimrc<cr>


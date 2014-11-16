"设置不兼容性
set nocompatible
"当文件在外部被修改的时候自动载入
set autoread
"在查找的时候忽略大小写
set ignorecase
"只能匹配
set smartcase
"显示所键入的命令
set showcmd
"设置文件序列号
set nu
"为色彩主题 solarized 所需要的
"开启语法高亮
syntax enable
set background=dark
"colorscheme solarized
colorscheme MountainDew
"colorscheme molokai
"设置状态栏的颜色
"highlight StatusLine guifg=SlateBlue guibg=Yellow 
"高亮显示匹配的括号
set showmatch
"设置历史记录数目
set history=1000
"设置不需要备份文件
set nobackup
setlocal noswapfile
"在命令模式下使用tab自动补全的时候，将补全内容用菜单的形式显示出来
set wildmenu
"显示右下角的状态栏
set ruler
"共享剪切板
set clipboard+=unnamed
"高亮显示搜索结果
set hlsearch
"实时显示搜索结果
set incsearch
"使得光标所在行总是离屏幕顶端或者低端5行
set scrolloff=5
"光标不闪烁
set novisualbell
"自动匹配，只能匹配，C语言风格的匹配
set autoindent
set smartindent
set cindent
"设置相关缩进
"设置一个tab对应4个空格
set tabstop=4
"在按退格键的时候如果前面有四个空格则一起删除
set softtabstop=4
"智能缩进
set shiftwidth=4
"设置tab
set smarttab
set expandtab
"不要将tab符号显示出来
set nolist
"去掉toolbar
set go=
"当你的一个单词输入未完成但是已经到达行尾的时候自动把你的单词完整显示到行首
set wrap
set linebreak
"设置状态栏的显示信息
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [ASCII=\%03.3b]\ [HEX=%02.2B]\ [POS=%04l,%04v]\ [%p%%]\ [LEN=%L]
"通过使用: commands命令，告诉我们文件的哪一行被改变过 
set report=0
"在被分割的窗口间显示空白，便于阅读 
set fillchars=vert:\ ,stl:\ ,stlnc:\ 

"设置语言
"set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
"set termencoding=utf-8
"set encoding=utf-8

"高亮显示当前行
set cursorline
hi CursorLine cterm=NONE   ctermbg=DarkRed ctermfg=White
hi CursorColumn cterm=NONE ctermbg=DarkRed ctermfg=White
"同上目的一样，不然当只有一个文件的时候不能看到当前行高亮
set laststatus=2

    "********************************************************************
    "*                                                                  *
    "*                      MY_MAP                                      *
    "*                                                                  *
    "********************************************************************
"my map
let mapleader = ","
"进入当前打开文件所在目录
nmap <leader>cd :cd %:h<cr>
"改变Y命令
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

"去掉方向键的功能
nnoremap <UP> <NOP>
nnoremap <DOWN> <NOP>
nnoremap <LEFT> <NOP>
nnoremap <RIGHT> <NOP>

inoremap <UP> <NOP>
inoremap <DOWN> <NOP>
inoremap <LEFT> <NOP>
inoremap <RIGHT> <NOP>

nnoremap <F4> :noh<cr>

"当一行太长显示多行的时候仍然在逻辑上看做多行来移动
map <A-UP> gk
map <A-DOWN> gj


    "********************************************************************
    "*                                                                  *
    "*                      pathogen                                    *
    "*                                                                  *
    "********************************************************************
execute pathogen#infect()
"允许用指定语法高亮配色方案替换默认方案
syntax on
filetype plugin indent on
"开启文件类型侦测
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


set nocompatible
set nu
syntax enable
filetype plugin indent on
filetype on
colorscheme desert
highlight StatusLine guifg=SlateBlue guibg=Yellow 
set showmatch
set nobackup
setlocal noswapfile
set wildmenu
set ruler
set backspace=2
set hlsearch
"make search can show with input
set incsearch
set scrolloff=5
set novisualbell
set autoindent
set smartindent
set cindent
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set nolist

"for hightlight current line
set cursorline
hi CursorLine cterm=NONE ctermbg=Yellow ctermfg=DarkGrey
hi CursorColumn cterm=NONE ctermbg=Yellow ctermfg=DarkGrey

"my map
let mapleader = ","
nnoremap <leader>ev :vsplit $MYVIMRC<cr>
nnoremap <leader>sv :source $MYVIMRC<cr>

"for status line
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [ASCII=\%03.3b]\ [HEX=%02.2B]\ [POS=%04l,%04v]\ [%p%%]\ [LEN=%L]

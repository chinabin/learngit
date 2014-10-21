set nocompatible
set ignorecase
set smartcase
"make command show to see clearev
set showcmd
set nu
" for solarized
syntax enable
set background=dark
colorscheme solarized

filetype plugin indent on
filetype on
highlight StatusLine guifg=SlateBlue guibg=Yellow 
set showmatch
set history=1000
set nobackup
setlocal noswapfile
set wildmenu
set ruler
set backspace=2
set hlsearch
"make search can show with input
set incsearch
"make cursor line has 5 line between bottom or
set scrolloff=5
set novisualbell
set autoindent
set smartindent
set cindent
set tabstop=4
set softtabstop=4
set shiftwidth=4
"set tab when begin on line or paragraph
set smarttab
set expandtab
"not show tab
set nolist
"get toolbar away
set go=
"insert '\n' automally and with whole word
set wrap
set linebreak

"for hightlight current line
set cursorline
hi CursorLine cterm=NONE   ctermbg=DarkRed ctermfg=White
hi CursorColumn cterm=NONE ctermbg=DarkRed ctermfg=White

"my map
let mapleader = ","
"cd to the directory where current file is
nmap <leader>cd :cd %:h<cr>
"change command Y
nmap Y y$
"change to light background
nmap <leader>l :set background=light<cr>
nmap <leader>d :set background=dark<cr>

nnoremap <leader>ev :vsplit $MYVIMRC<cr>
nnoremap <leader>sv :source $MYVIMRC<cr>
nnoremap <F7> :!gcc % -o def_by_me<cr>
nnoremap <F5> :!./def_by_me
nnoremap <UP> <NOP>
nnoremap <DOWN> <NOP>
nnoremap <LEFT> <NOP>
nnoremap <RIGHT> <NOP>

inoremap <UP> <NOP>
inoremap <DOWN> <NOP>
inoremap <LEFT> <NOP>
inoremap <RIGHT> <NOP>

inoremap <F4> [Esc]:noh<cr>
nnoremap <F4> :noh<cr>

"move line by line in wraped line
map <A-UP> gk
map <A-DOWN> gj
"for status line
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [ASCII=\%03.3b]\ [HEX=%02.2B]\ [POS=%04l,%04v]\ [%p%%]\ [LEN=%L]
"for we can see statusline always,:help laststatus
set laststatus=2

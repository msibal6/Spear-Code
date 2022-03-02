syntax on
"set smarttab
set ruler
"set number
" allows mouse to visually select in VIM
set mouse=a
set tabstop=4
set shiftwidth=4
set expandtab
set ruler
set wrap
set textwidth=80

" Creates a color column to mark 80 chars
set colorcolumn=80

" file navigation
set path+=**
set wildmenu
noremap <leader>cd :lcd %:h<CR>
noremap <leader><Right> gt

" Whitespace detection
set listchars+=space:•
" search for visually selected

vnoremap <leader>s y/\V<C-R>=escape(@",'/\')<CR><CR>
" vnoremap <leader>r "ry/\V<C-R>=escape(@",'/\')<CR><CR>

filetype plugin indent on

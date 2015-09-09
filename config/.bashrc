# .bashrc

# User specific aliases and functions

alias rm='rm -i'
alias cp='cp -i'
alias mv='mv -i'


# Misc aliases
alias sgrep='grep -rIn --color=auto --include=\*.{c,cpp,h} --exclude-dir="*\.{svn,git}" --exclude="*\tags"'

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

__git_ps1 ()
{
    local b="$(git symbolic-ref HEAD 2>/dev/null)";
    if [ -n "$b" ]; then
        printf " (%s)" "${b##refs/heads/}";
    fi
}
PS1='\[\e]0;\w\a\]\[\e[7;30m\]\u@\h \[\e[0;34m\]\w \[\e[0;35m\]$(__git_ps1 "(%s) ")\[\e[1;0m\]\$ '

source ~/bin/git-completion.sh
source ~/bin/git-flow-completion.sh
export PATH=/usr/local/lib:/usr/local/lib64:$PATH
export PDSH_RCMD_TYPE=ssh
